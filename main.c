/***************************************************************************//**
 * @file main.c
 * @brief main() function.
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/
#include "sl_component_catalog.h"
#include "sl_system_init.h"
#include "app.h"
#if defined(SL_CATALOG_POWER_MANAGER_PRESENT)
#include "sl_power_manager.h"
#endif
#if defined(SL_CATALOG_KERNEL_PRESENT)
#include "sl_system_kernel.h"
#else // SL_CATALOG_KERNEL_PRESENT
#include "sl_system_process_action.h"
#endif // SL_CATALOG_KERNEL_PRESENT

#include "FreeRTOS.h"
#include "task.h"
#include "sl_simple_led.h"
#include "sl_simple_led_instances.h"
#include "em_timer.h"
#include "em_cmu.h"

#define OUT_FREQ 2000

static void led_blinks1(void *pvParameters);
static void led_blinks2(void *pvParameters);

TaskHandle_t led_blinks1_handle = NULL;
TaskHandle_t led_blinks2_handle = NULL;

int main(void)
{
  // Initialize Silicon Labs device, system, service(s) and protocol stack(s).
  // Note that if the kernel is present, processing task(s) will be created by
  // this call.
  sl_system_init();

  // Initialize the application. For example, create periodic timer(s) or
  // task(s) if the kernel is present.
  app_init();

  xTaskCreate(led_blinks1, (char *) "blk_led1", 2*configMINIMAL_STACK_SIZE, NULL, 2, &led_blinks1_handle);
  xTaskCreate(led_blinks2, (char *) "blk_led2", 5*configMINIMAL_STACK_SIZE, NULL, 3, &led_blinks2_handle);

#if defined(SL_CATALOG_KERNEL_PRESENT)
  // Start the kernel. Task(s) created in app_init() will start running.
  sl_system_kernel_start();
#else // SL_CATALOG_KERNEL_PRESENT
  while (1) {
    // Do not remove this call: Silicon Labs components process action routine
    // must be called from the super loop.
    sl_system_process_action();

    // Application process.
    app_process_action();

#if defined(SL_CATALOG_POWER_MANAGER_PRESENT)
    // Let the CPU go to sleep if the system allows it.
    sl_power_manager_sleep();
#endif
  }
#endif // SL_CATALOG_KERNEL_PRESENT
}

static void led_blinks1( void *pvParameters )
{
  (void)pvParameters;

  for( ;; ){

      sl_led_turn_on(&sl_led_led1);
      vTaskDelay(100);

      sl_led_turn_off(&sl_led_led1);
      vTaskDelay(100);
  }
}

static void led_blinks2( void *pvParameters )
{
  (void)pvParameters;

  sl_power_manager_add_em_requirement(SL_POWER_MANAGER_EM1);
  CMU_ClockEnable(cmuClock_TIMER1, true);

  uint32_t timerFreq = 0;
  TIMER_Init_TypeDef timerInit = TIMER_INIT_DEFAULT;

  timerInit.prescale = timerPrescale1;
  timerInit.enable = false;
  //  timerInit.oneShot = true;

  TIMER_Init(TIMER1, &timerInit);

  timerFreq = CMU_ClockFreqGet(cmuClock_TIMER1)/(timerInit.prescale + 1);
  int compareValue = timerFreq / (2*OUT_FREQ) - 1;

  TIMER_TopSet (TIMER1, compareValue);
  TIMER_IntEnable(TIMER1, TIMER_IF_OF);
  NVIC_EnableIRQ(TIMER1_IRQn);
  NVIC_SetPriority(TIMER1_IRQn, 7);

  TIMER_Enable(TIMER1, true);

  for( ;; ){

      ulTaskNotifyTake(pdTRUE, 250000);

      sl_led_toggle(&sl_led_led2);

  }
}

void TIMER1_IRQHandler(void)
{
  BaseType_t xHigherPriorityTaskWoken;
  uint32_t flags = TIMER_IntGet(TIMER1);
  TIMER_IntClear(TIMER1, flags);

  xHigherPriorityTaskWoken = pdFALSE;

  vTaskNotifyGiveFromISR(led_blinks2_handle, &xHigherPriorityTaskWoken);
  portYIELD_FROM_ISR(xHigherPriorityTaskWoken);

}
