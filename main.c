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
	
	// setting clock source, dividers, frequency...
	SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

	// we must enable clock for PortF before using it and there is a delay of 3 to 6 cycles
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	// set pins 1,2,3 in PORTF as outputs
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);

    while(1){

    	// delay for 3 cycles 2000000 times: 1/40`000`000 * 3 * 2000000 = 0.15 seconds
    	SysCtlDelay(2000000);
    	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, ui8PinData);
    	SysCtlDelay(2000000);
    	if(ui8PinData == 8){
    		ui8PinData = 2;
    	}else{
    		ui8PinData*=2;
    	}
    }
}
