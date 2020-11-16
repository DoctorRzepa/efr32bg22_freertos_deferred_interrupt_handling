# efr32bg22_freertos_deferred_interrupt_handling
Simplicity Studio 5 project for testing FreeRTOS deferred interrupt handling on EFR32BG22 processor

This is a C project for EFR32BG22 processor written using Simplicity Studio 5.
Application is supposed to toggle one gpio every 100ms (at PB00) and another one every 250us (at PC02).
It's goal is to test deferred interrupt handling, which is one of FreeRTOS features:
https://www.freertos.org/deferred_interrupt_processing.html

It uses Timer ISR to switch context on demand.
The main reason for testing this feature is to implement microsecond delay for tasks.
Microsecond timing is desired for controlling thermal printer head and motor.

It doesn't work properly in FreeRTOS implementation available for this processor.
Usually application gets into Default Handler.
Sometimes ISR-driven task hangs and another task does not keep proper timing.

The same method used in another processor (different manufacturer) works as intended.
Is there a bug in current FreeRTOS implementation for EFR32BG22?
How to make this work?

Also, in FreeRTOSConfig comment regarding configMAX_SYSCALL_INTERRUPT_PRIORITY is misleading.
__NVIC_PRIO_BITS is 4, so 96 or 0x60 is equivalent for priority 6, not 3.
