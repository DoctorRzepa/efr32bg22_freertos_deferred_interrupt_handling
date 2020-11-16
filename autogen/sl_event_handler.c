#include "sl_event_handler.h"

#include "em_chip.h"
#include "sl_device_init_dcdc.h"
#include "sl_device_init_clocks.h"
#include "sl_device_init_emu.h"
#include "sl_sleeptimer.h"
#include "sl_simple_led_instances.h"
#include "freertos_sl_system.h"
#include "sl_power_manager.h"

void sl_platform_init(void)
{
  CHIP_Init();
  sl_device_init_dcdc();
  sl_device_init_clocks();
  sl_device_init_emu();
  sl_power_manager_init();
}

void sl_kernel_start(void)
{
  vTaskStartScheduler();
}

void sl_driver_init(void)
{
  sl_simple_led_init_instances();
}

void sl_service_init(void)
{
  sl_sleeptimer_init();
}

void sl_stack_init(void)
{
}

void sl_internal_app_init(void)
{
}

