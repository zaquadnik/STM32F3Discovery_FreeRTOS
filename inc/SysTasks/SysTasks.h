/*
 * SysTasks.h
 *
 *  Created on: 26.03.2025
 *      Author: Lenovo
 */

#ifndef SYSTASKS_SYSTASKS_H_
#define SYSTASKS_SYSTASKS_H_

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"
#include "semphr.h"

#define HEART_BEAT_TASK_PRIORITY  (tskIDLE_PRIORITY)
#define HEART_BEAT_STACK_SIZE (configMINIMAL_STACK_SIZE)

typedef struct SysCtx_t* SysCtxHandle_t;

SysCtxHandle_t GetSysCtxHande(void);

void vApplicationIdleHook(void);
void vApplicationMallocFailedHook(void);
void HeartBeatTask(void *pvParameters);

#endif /* SYSTASKS_SYSTASKS_H_ */
