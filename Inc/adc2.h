#ifndef __ADC2_H
#define __ADC2_H	

#include "stm32f1xx_hal.h"	   
   
	   									   
void Adc_Init(void); 				//ADC通道初始化
u16  Get_Adc(u8 ch); 				//获得某个通道值  
u16 Get_Adc_Average(u8 ch,u8 times);

#endif 















