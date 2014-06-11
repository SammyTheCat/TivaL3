/*
 * main.c
 */

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"    // macros like GPIO_PORTF_BASE, contains all memory map macros
#include "inc/hw_types.h"     // macros like HWREG and others
#include "driverlib/sysctl.h" // smth like SysCtlClockSet, System Control API of driverlib
#include "driverlib/gpio.h"   // smth like GPIOPinWrite and port configuration functions - for GPIO

uint8_t ui8PinData=2;         // unsigned 8-bit int like char in monkeystyle C I've used to in Keil

int main(void) {
	
	return 0;
}
