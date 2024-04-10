#ifndef HQ_TX_2MIC_NS_H
#define HQ_TX_2MIC_NS_H
#include <stdio.h>
#include "kiss_fftr.h"
#include "complex.h"

#ifdef FIXED_POINT
#define proc_datatype short
#else
#define proc_datatype float
#endif

#define CHAN_NUM 2


typedef struct HDMA_State {
	kiss_fft_scalar* mic0;
	kiss_fft_scalar* mic1;
	kiss_fft_cpx* mic0_cout;
	kiss_fft_cpx* mic1_cout;
	kiss_fft_cpx* mic0_hdma_out;
	kiss_fft_cpx* mic1_hdma_out;
	kiss_fftr_cfg kiss_fftr_state;
	kiss_fftr_cfg kiss_ifftr_state;
}hdma_state;

void hq_tx_2mic_ns_init(int frame_size, int sample_rate);
void hq_tx_2mic_ns_process(short *pcm_buff,int pcm_len);
void hq_tx_2mic_ns_deinit(void);
#endif