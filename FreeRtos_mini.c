
#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "fsl_debug_console.h"

#include "FreeRTOS.h"
#include "task.h"

void dummy_task1(void)
{
    TickType_t xLastWakeTime;
    const TickType_t xPeriod = pdMS_TO_TICKS(2000);
    uint8_t counter = 0;
    xLastWakeTime = xTaskGetTickCount();
    for (;;)
    {
        PRINTF("IN TASK 1: %i +++++++++++++++\r\n", counter);
        counter++;
        vTaskDelayUntil(&xLastWakeTime, xPeriod);
    }
}

void dummy_task2(void)
{
    TickType_t xLastWakeTime;
    const TickType_t xPeriod = pdMS_TO_TICKS(1000);
    uint8_t counter = 0;
    xLastWakeTime = xTaskGetTickCount();
    for (;;)
    {
        PRINTF("IN TASK 2: %i ***************\r\n", counter);
        counter++;
        vTaskDelayUntil(&xLastWakeTime, xPeriod);
    }
}

void dummy_task3(void)
{
    TickType_t xLastWakeTime;
    const TickType_t xPeriod = pdMS_TO_TICKS(4000);
    uint8_t counter = 0;
    xLastWakeTime = xTaskGetTickCount();
    for (;;)
    {
        PRINTF("IN TASK 3: %i ---------------\r\n", counter);
        counter++;
        vTaskDelayUntil(&xLastWakeTime, xPeriod);
    }
}

int main(void)
{
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();
    TaskHandle_t dummy1_taskhandle;
    TaskHandle_t dummy2_taskhandle;
    TaskHandle_t dummy3_taskhandle;

    xTaskCreate(dummy_task1, "dummy1", 110, NULL, 1, &dummy1_taskhandle);
    xTaskCreate(dummy_task2, "dummy2", 110, NULL, 2, &dummy2_taskhandle);
    xTaskCreate(dummy_task3, "dummy3", 110, NULL, 1, &dummy3_taskhandle);
    vTaskStartScheduler();

    while(1)
    {

    }
    return 0;
}
