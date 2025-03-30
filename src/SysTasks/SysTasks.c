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
}

void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
}

void HeartBeatTask(void *pvParameters)
{

	const TickType_t xDelay = 500 / portTICK_PERIOD_MS;

	while(1)
	{

		vTaskDelay(xDelay);
	}
}
