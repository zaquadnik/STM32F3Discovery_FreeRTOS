/*
 * SysTasks.c
 *
 *  Created on: 26.03.2025
 *      Author: Lenovo
 */

#include "SysTasks.h"
#include "stm32f30x_gpio.h"

struct SysCtx_t{
	uint32_t IdleCounter;
	uint32_t HeartBeatState : 1,
	         Reserved       : 31;
};

struct SysCtx_t SysCtx;

SysCtxHandle_t GetSysCtxHande(void)
{
	return &SysCtx;
}

void ResetIdleCnt(SysCtxHandle_t SysCtxHandle)
{
	SysCtxHandle->IdleCounter = 0;
}

void IncIdleCnt(SysCtxHandle_t SysCtxHandle)
{
	SysCtxHandle->IdleCounter++;
}

void vApplicationIdleHook(void)
{
	IncIdleCnt(GetSysCtxHande());
}

void vApplicationMallocFailedHook(void)
{
	uint32_t i;
	GPIO_InitTypeDef GpioInit;

	GPIO_StructInit(&GpioInit);
	GpioInit.GPIO_Pin = GPIO_Pin_9;
	GpioInit.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init(GPIOE, &GpioInit);

	while(1)
	{
		GPIO_SetBits(GPIOE,GPIO_Pin_9);
		for(i=1000000; i>0; i--);
		GPIO_ResetBits(GPIOE,GPIO_Pin_9);
		for(i=1000000; i>0; i--);
	}
}

void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
	uint32_t i;
	GPIO_InitTypeDef GpioInit;

	GPIO_StructInit(&GpioInit);
	GpioInit.GPIO_Pin = GPIO_Pin_10;
	GpioInit.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init(GPIOE, &GpioInit);

	while(1)
	{
		GPIO_SetBits(GPIOE,GPIO_Pin_10);
		for(i=1000000; i>0; i--);
		GPIO_ResetBits(GPIOE,GPIO_Pin_10);
		for(i=1000000; i>0; i--);
	}
}

void HeartBeatTask(void *pvParameters)
{
	const TickType_t xDelay = 500 / portTICK_PERIOD_MS;
	GPIO_InitTypeDef GpioInit;

	GPIO_StructInit(&GpioInit);
	GpioInit.GPIO_Pin = GPIO_Pin_8;
	GpioInit.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init(GPIOE, &GpioInit);

	while(1)
	{
		GPIO_SetBits(GPIOE,GPIO_Pin_8);
		vTaskDelay(xDelay);
		GPIO_ResetBits(GPIOE,GPIO_Pin_8);
		vTaskDelay(xDelay);
	}
}
