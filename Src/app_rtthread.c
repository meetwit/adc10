/*
 * File      : app_rtthread.c
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2012 - 2018, RT-Thread Development Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Change Logs:
 * Date           Author       Notes
 */

#include <rtthread.h>
#include <adc.h>
#include "ANO.h"
#include "adc2.h"

void MX_RT_Thread_Init(void)
{

}

void MX_RT_Thread_Process(void)
{
//	int adcBuffer[10];
	static float adc_v[2]={0};
	static int last_adc[3] = {0};
	static int last_adc2[3] = {0};
	while(1){
//		rt_interrupt_enter();
//			for(u8 i=0;i<10;i++){
//				HAL_ADC_Start(&hadc1); //开始转换
//				HAL_ADC_PollForConversion(&hadc1, 0xffff); //等待转换完成
//				adcBuffer[i]=HAL_ADC_GetValue(&hadc1);
//			}
//		HAL_ADC_Stop(&hadc1);
//			rt_interrupt_leave();
//			ANO_send(0xf2,(unsigned char *)adcBuffer,sizeof(int),sizeof(adcBuffer));
//			rt_thread_delay(5);
		rt_interrupt_enter();
		last_adc[0] = Get_Adc_Average(7,10);
		adc_v[0] = last_adc[0]*0.5+last_adc[1]*0.3+last_adc[2]*0.2;
		last_adc2[0] = Get_Adc_Average(6,10);
		adc_v[1] = last_adc2[0]*0.5+last_adc2[1]*0.3+last_adc2[2]*0.2;
//		adc_v[1] = 2000;
//		adc_v[2] = 3200;
//		adc_v[3] = last_adc[0]-1000;
//		adc_v[4] = Get_Adc_Average(7,10)+1000;
		rt_interrupt_leave();
		
		ANO_send(0xf2,(unsigned char *)adc_v,sizeof(float),sizeof(adc_v));
		last_adc[2] = last_adc[2];
		last_adc[1] = last_adc[0];
		last_adc2[2] = last_adc[2];
		last_adc2[1] = last_adc[0];
		rt_thread_delay(5);
	}
	
}

void adc_m(void){
	uint8_t adc1Buffer[200]={0};
	for(u8 i=0;i<10;i++){
			HAL_ADC_Start(&hadc1); //开始转换
			HAL_ADC_PollForConversion(&hadc1, 0xffff); //等待转换完成
			sprintf((char*)adc1Buffer, "%s\r\nadc%d=%d", adc1Buffer,i+1,(uint16_t)HAL_ADC_GetValue(&hadc1));
		}
		HAL_ADC_Stop(&hadc1);
		printf("%s\r\n\r\n",adc1Buffer);
}
FINSH_FUNCTION_EXPORT(adc_m, hello thread);
MSH_CMD_EXPORT(adc_m, hello thread);

void send(void){
	int adcBuffer[5];
	for(u8 i=0;i<5;i++){
//			HAL_ADC_Start(&hadc1); //开始转换
//			HAL_ADC_PollForConversion(&hadc1, 1000); //等待转换完成
//			adcBuffer[i]=HAL_ADC_GetValue(&hadc1);
		adcBuffer[i]=i;
		}
//		HAL_ADC_Stop(&hadc1);
			ANO_send(0xf2,(unsigned char *)adcBuffer,sizeof(int),sizeof(adcBuffer));
}
FINSH_FUNCTION_EXPORT(send, hello thread);
MSH_CMD_EXPORT(send, hello thread);
