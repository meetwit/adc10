#ifndef __ADC2_H
#define __ADC2_H	

#include "stm32f1xx_hal.h"	   
   
	   									   
void Adc_Init(void); 				//ADCͨ����ʼ��
u16  Get_Adc(u8 ch); 				//���ĳ��ͨ��ֵ  
u16 Get_Adc_Average(u8 ch,u8 times);

#endif 















