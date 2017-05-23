/************************************************
 *Random Forest Program
 *Function:		read mnist dataset and do preprocess
 *Author:		handspeaker@163.com
 *CreateTime:	2014.7.10
 *Version:		V0.1
 *************************************************/

#ifndef MNISTPREPROCESS_H
#define MNISTPREPROCESS_H

#define TRAIN_NUM 176
#define TEST_NUM 143
#define FEATURE 6
#define NUMBER_OF_CLASSES 4
#include<stdio.h>

inline void revertInt(int&x)
{
	x=((x&0x000000ff)<<24)|((x&0x0000ff00)<<8)|((x&0x00ff0000)>>8)|((x&0xff000000)>>24);
};
void readData(float** dataset,float*labels,const char* dataPath,const char*labelPath);
void readData2(float** dataset, float*labels, const char* dataPath);

#endif//MNISTPREPROCESS_H
