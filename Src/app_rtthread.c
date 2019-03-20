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

void MX_RT_Thread_Init(void)
{

}

void MX_RT_Thread_Process(void)
{

}

void adc_m(void){
	uint8_t adc1Buffer[200]={0};
	for(u8 i=0;i<10;i++){
			HAL_ADC_Start(&hadc1); //开始转换
			HAL_ADC_PollForConversion(&hadc1, 1000); //等待转换完成
			sprintf((char*)adc1Buffer, "%s\r\nadc%d=%d", adc1Buffer,i,(uint16_t)HAL_ADC_GetValue(&hadc1));
		}
		HAL_ADC_Stop(&hadc1);
		printf("%s\r\n",adc1Buffer);
}
FINSH_FUNCTION_EXPORT(adc_m, hello thread);
MSH_CMD_EXPORT(adc_m, hello thread);
