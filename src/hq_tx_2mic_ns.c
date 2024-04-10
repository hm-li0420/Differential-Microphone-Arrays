#include "hq_tx_2mic_ns.h"
#include <math.h>
#include "hq_malloc.h"
#ifdef BES_PLATFORM
#include "hal_trace.h"
#endif
#define ZERO_OUT_FREQ_END_INDEX 3 //设置输出为0的低频截止上限，对应频率是该值乘以sample_rate/fft_size

short *mic0_input_buffer , *mic1_input_buffer;
proc_datatype  *mic0_out, *mic1_out;
proc_datatype *mic0_pre;
proc_datatype *windows;

proc_datatype* hdma1_imag, *hdma2_real, *hdma2_imag;
proc_datatype hdma1_real = 0.5; //直接计算解析解 H1(W)的实部其实恒为0.5，为节省空间，不用数组存放
/*
	麦克风阵列的参数：
	* mic_distance：麦克风间距 m
	* c：声速 343m/s
	* alfa11: null方向的余弦值
*/
float mic_distance = 0.0173;
int c = 343;
float alpha11 = -0.5;

hdma_state* hq_tx_2mic_ns_st = NULL;

void hq_tx_2mic_ns_init(int frame_size, int sample_rate)
{
	int fft_size = 2 * frame_size;
	int set_zerofreq = ZERO_OUT_FREQ_END_INDEX;
	int hdma_length = fft_size / 2 + 1;
	float tau = mic_distance / c;

	mic0_input_buffer = hq_malloc(fft_size * sizeof(short));
	mic1_input_buffer = hq_malloc(fft_size * sizeof(short));
	mic0_out = hq_malloc(fft_size * sizeof(proc_datatype));
	mic1_out = hq_malloc(fft_size * sizeof(proc_datatype));
	mic0_pre = hq_malloc(fft_size/2 * sizeof(proc_datatype));
	
	hq_tx_2mic_ns_st = (hdma_state*)hq_malloc(sizeof(hdma_state));

	hq_tx_2mic_ns_st->mic0 = hq_malloc(fft_size * sizeof(kiss_fft_scalar));
	hq_tx_2mic_ns_st->mic1 = hq_malloc(fft_size * sizeof(kiss_fft_scalar));

	hq_tx_2mic_ns_st->mic0_cout = hq_malloc(fft_size * sizeof(kiss_fft_cpx));
	hq_tx_2mic_ns_st->mic1_cout = hq_malloc(fft_size * sizeof(kiss_fft_cpx));

	hq_tx_2mic_ns_st->mic0_hdma_out = hq_malloc(fft_size * sizeof(kiss_fft_cpx));
	hq_tx_2mic_ns_st->mic1_hdma_out = hq_malloc(fft_size * sizeof(kiss_fft_cpx));
	hq_tx_2mic_ns_st->kiss_fftr_state = kiss_fftr_alloc_hq(fft_size, 0, 0, 0);
	hq_tx_2mic_ns_st->kiss_ifftr_state = kiss_fftr_alloc_hq(fft_size, 1, 0, 0);
	
	windows = hq_malloc(fft_size * sizeof(proc_datatype));
	for (int i = 0; i < fft_size; i++) {
        windows[i] = sqrtf(0.5f - 0.5f*cosf((float)(M_PI * 2 * ((float)i) / fft_size)));
	}

	// 初始化麦克风阵列滤波器参数
	hdma1_imag = hq_malloc(hdma_length * sizeof(proc_datatype));
	hdma2_real = hq_malloc(hdma_length * sizeof(proc_datatype));
	hdma2_imag = hq_malloc(hdma_length * sizeof(proc_datatype));
	for(int i = 0;i< hdma_length;i++){
		if(i < set_zerofreq){
			hdma1_imag[i] = 0;
			hdma2_real[i] = 0;
			hdma2_imag[i] = 0;
		}
		else{
			hdma1_imag[i] = 0.5 * sinf(2*M_PI*i*((float)sample_rate/fft_size)*tau*(1-alpha11)) / (1-(cosf(2*M_PI*i*((float)sample_rate/fft_size)*tau*(1-alpha11))));
			hdma2_real[i] = -0.5 * sinf(M_PI*i*((float)sample_rate/fft_size)*tau*(1+alpha11)) / sinf(M_PI*i*((float)sample_rate/fft_size)*tau*(1-alpha11));
			hdma2_imag[i] = -0.5 * cosf(M_PI*i*((float)sample_rate/fft_size)*tau*(1+alpha11)) / sinf(M_PI*i*((float)sample_rate/fft_size)*tau*(1-alpha11));
		}

	}
	
}

void hq_tx_2mic_ns_deinit(void)
{
	hq_free(hq_tx_2mic_ns_st->mic0);
	hq_free(hq_tx_2mic_ns_st->mic1);
	hq_free(hq_tx_2mic_ns_st->mic0_cout);
	hq_free(hq_tx_2mic_ns_st->mic1_cout);
	hq_free(hq_tx_2mic_ns_st->mic0_hdma_out);
	hq_free(hq_tx_2mic_ns_st->mic1_hdma_out);
	kiss_fftr_free(hq_tx_2mic_ns_st->kiss_fftr_state);
	kiss_fftr_free(hq_tx_2mic_ns_st->kiss_ifftr_state);
	hq_free(hq_tx_2mic_ns_st);

	hq_free(hdma1_imag);
	hq_free(hdma2_imag);
	hq_free(hdma2_real);

	hq_free(mic0_input_buffer);
	hq_free(mic1_input_buffer);
	hq_free(mic0_out);
	hq_free(mic1_out);
	hq_free(mic0_pre);
	hq_free(windows);

}

void hdma(short *pcm_buff,int pcm_len, hdma_state* hdma_st) 
{
	int fft_size  =2 * pcm_len / CHAN_NUM;
	int step = fft_size / 2;
	memcpy(mic0_input_buffer, &mic0_input_buffer[step], sizeof(short) * (fft_size - step));
	memcpy(mic1_input_buffer, &mic1_input_buffer[step], sizeof(short) * (fft_size - step));
   
    for(int i = 0;i < pcm_len/CHAN_NUM;i++){
	 mic0_input_buffer[step + i] = pcm_buff[i*CHAN_NUM];
	 mic1_input_buffer[step + i] = pcm_buff[i*CHAN_NUM + 1];
   }

	// 语音加窗
	for (int i = 0; i < fft_size; i++)
	{
		mic0_out[i] = (float)mic0_input_buffer[i] * windows[i];
		mic1_out[i] = (float)mic1_input_buffer[i] * windows[i];
	}
	kiss_fft_scalar zero;
	memset(&zero, 0, sizeof(zero));


	for (int i = 0; i < fft_size; ++i)
	{
		hdma_st->mic0[i] = mic0_out[i];
		hdma_st->mic1[i] = mic1_out[i];
	}
	
	kiss_fftr_hq(hdma_st->kiss_fftr_state, hdma_st->mic0, hdma_st->mic0_cout);
	kiss_fftr_hq(hdma_st->kiss_fftr_state, hdma_st->mic1, hdma_st->mic1_cout);
	for (int k = 0; k < fft_size; k++)
	{
		if (k < ZERO_OUT_FREQ_END_INDEX){
			hdma_st->mic0_hdma_out[k].r = 0;
			hdma_st->mic0_hdma_out[k].i = 0;
		}
		else if(k < (fft_size / 2 + 1))
		{
			hdma_st->mic0_hdma_out[k].r = ((hdma1_real * hdma_st->mic0_cout[k].r + hdma1_imag[k] * hdma_st->mic0_cout[k].i) + (hdma2_real[k] * hdma_st->mic1_cout[k].r + hdma2_imag[k] * hdma_st->mic1_cout[k].i)) / fft_size;
			hdma_st->mic0_hdma_out[k].i = ((hdma1_real * hdma_st->mic0_cout[k].i - hdma1_imag[k] * hdma_st->mic0_cout[k].r) + (hdma2_real[k] * hdma_st->mic1_cout[k].i - hdma2_imag[k] * hdma_st->mic1_cout[k].r)) / fft_size;
		}
		else
		{
			hdma_st->mic0_hdma_out[k].r = hdma_st->mic0_hdma_out[fft_size - k].r;
			hdma_st->mic0_hdma_out[k].i = -1 * hdma_st->mic0_hdma_out[fft_size - k].i;
		}
	}	
	memset(hdma_st->mic0_cout, 0, sizeof(short) * fft_size);
	kiss_fftri_hq(hdma_st->kiss_ifftr_state, hdma_st->mic0_hdma_out, hdma_st->mic0);

	for (int k = 0; k < fft_size; k++)
	{
		mic0_out[k] = hdma_st->mic0[k] * windows[k];
	}
	// 重叠相加还原为一帧语音
	for (int i = 0; i < step; i++)
	{
		pcm_buff[i] =(short)(mic0_pre[i] + mic0_out[i]);
	}
	for (int i = 0;i <fft_size - step; i++)
	{
		mic0_pre[i] = mic0_out[i + step];
	}

}

void hq_tx_2mic_ns_process(short *pcm_buff, int pcm_len)
{
	if (hq_tx_2mic_ns_st != NULL) {
		hdma(pcm_buff, pcm_len, hq_tx_2mic_ns_st);
	} else {
		//TRACE(0,"denoise not init");
	}
}

