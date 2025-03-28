/*
 * main.c
 *
 *  Created on: 19.03.2025
 *      Author: Lenovo
 */

#include "stm32f30x.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"
#include "semphr.h"
#include "SysTasks.h"


int main(void)
{
	SystemInit();

	TaskHandle_t HtBtHandle = NULL;

	xTaskCreate(HeartBeatTask,
	            "HeartBeat",
				HEART_BEAT_STACK_SIZE,
	            NULL,
				HEART_BEAT_TASK_PRIORITY,
	            &HtBtHandle);

	xPortStartScheduler();

	return 0;
}
