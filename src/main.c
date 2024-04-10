#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include "hq_tx_2mic_ns.h"
//#include "complex.h"
#define MIC_BUFF_LEN 240 //for WB
//#define MIC_BUFF_LEN 120 //for NB
//short *mic0_input_buffer , *mic1_input_buffer;
//proc_datatype  *mic0_out, *mic1_out;
//proc_datatype *mic0_pre;

int main(int argc, char **argv)
{

	int sample_rate = 16000;

	if (4 == argc)
		printf("sample rate not speecified? use dafault 16000, usage:mic_array mic0.pcm mic1.pcm output.pcm sample_rate\n");
	else if(5 == argc){
		sample_rate = atoi(argv[4]);
	}
	else{
		fprintf(stderr, "\n");
		exit(1);mic_array mic0.pcm mic1.pcm output.pcm sample_rate
	}
	int frame_len =(sample_rate * 15) / 1000;

	/*从命令行打开两个通道的语音， 其中mic0和mic1对应的麦克风可以参考说明文档中的 第4点 hdma.h hdma.c说明中的照片所示
	红色圈对应mic0_mic，;蓝色圈对应mic1*/ 
	FILE* mic0_input_file = fopen(argv[1], "rb");
	if(mic0_input_file == NULL){
		printf("Cannot open mic0.pcm files, check input:mic_array mic0.pcm mic1.pcm output.pcm sample_rate \n");
		return -1;
	}
	FILE* mic1_input_file = fopen(argv[2], "rb");
	if(mic1_input_file == NULL){
		printf("Cannot open mic1.pcm files, check input:mic_array mic0.pcm mic1.pcm output.pcm sample_rate \n");
		fclose(mic0_input_file);
		return -1;
	}
	FILE* mic0_output_file = fopen(argv[3], "wb");
	if(mic0_output_file == NULL){
		printf("Cannot open output.pcm files, check input:mic_array mic0.pcm mic1.pcm output.pcm sample_rate \n");
		fclose(mic0_input_file);
		fclose(mic0_output_file);
		return -1;
	}	

	// 初始化麦克风阵列结构体
	hq_tx_2mic_ns_init(frame_len, sample_rate);
	
	//定义PC仿真用的外部buffer
	int16_t mic0_external_buff[MIC_BUFF_LEN];
	int16_t mic1_external_buff[MIC_BUFF_LEN];
	int16_t pcm_external_buff[MIC_BUFF_LEN * CHAN_NUM];
	int _pcm_len = MIC_BUFF_LEN * CHAN_NUM;

	while (!feof(mic0_input_file) && !feof(mic1_input_file))
	{
		int pcm_len = _pcm_len;
		fread(mic0_external_buff, sizeof(short), MIC_BUFF_LEN, mic0_input_file);
		fread(mic1_external_buff, sizeof(short), MIC_BUFF_LEN, mic1_input_file);

		//将两个mic的输入信号依次间隔放入pcm_buff, 模拟BES平台的处理输入信号
		for (int i = 0; i< MIC_BUFF_LEN;i++){
			pcm_external_buff[i*CHAN_NUM] = mic0_external_buff[i];
			pcm_external_buff[i*CHAN_NUM +1] = mic1_external_buff[i];
		}
		
		// 麦克风阵列函数，输入为两个通道的语音,输出为单通道，_pcm_len 应为每个通道样点数*通道数,参考BES平台的定义
		hq_tx_2mic_ns_process(pcm_external_buff, pcm_len);
		pcm_len /=CHAN_NUM;
		
		/*******
		后续如果有单通道处理在这里完成
		denoise_process(pcm_external_buff,pcm_len);
		****/
		
		// 数据写入PCM文件
		fwrite(pcm_external_buff, sizeof(short), MIC_BUFF_LEN, mic0_output_file);
	}
	hq_tx_2mic_ns_deinit();
	fclose(mic0_input_file);
	fclose(mic1_input_file);
	fclose(mic0_output_file);
	return 0;
}

