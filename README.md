# Differential-Microphone-Arrays
这是一个C语言代码实现的差分麦克风(DMA)双通道增强算法。
## 目录

1. [背景](#背景)
2. [安装](#安装)
3. [使用方法](#使用方法)


## 背景  

这是一个C语言实现的差分麦克风(DMA)语音增强，与加性麦克风不一样的是差分麦克风不可以调相，存在唯一的端射方向（0/180）

## 使用方法  
### 文件路径 
```bash 
DMA
│  CMakeLists.txt
│  README.md
│
├─build
│  │  CMakeCache.txt
│  │  cmake_install.cmake
│  │  compile_commands.json
│  │  Makefile
│  └─ mic_array
│
├─include
│      general_def.h
│      hq_malloc.h
│      hq_tx_2mic_ns.h
│      kiss_fft.h
│      kiss_fftr.h
│      kiss_fft_log.h
│      _kiss_fft_guts.h
│
└─src
        hq_malloc.c
        hq_tx_2mic_ns.c
        kiss_fft.c
        kiss_fftr.c
        main.c
```
### 运行方法
在build中找到可执行文件mic_array, 超参数mic0.pcm是离端射方向最近的麦克风采集到的音频，mic1.pcm是离端射方向最远的麦克风采集到的音频，sample_rate为采样率
```bash
mic_array mic0.pcm mic1.pcm output.pcm sample_rate
```  
## 安装
项目环境为CMakeLists，需要使用者自己搭建好cmake环境
```bash
$ git clone git@github.com:hm-li0420/MVDR-Speech-Enhancement.git
```
## 邮箱
1632509441@qq.com