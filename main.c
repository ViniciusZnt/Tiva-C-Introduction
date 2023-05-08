#include <stdint.h>
#include <stdbool.h>
#include "C:\ti\TivaWare_C_Series-2.2.0.295\inc\hw_memmap.h"
#include "C:\ti\TivaWare_C_Series-2.2.0.295\inc\hw_types.h"
#include "C:\ti\TivaWare_C_Series-2.2.0.295\driverlib\sysctl.h"
#include "C:\ti\TivaWare_C_Series-2.2.0.295\driverlib\gpio.h"

uint8_t ui8PinData=2;

int main(void){
    //Clock Configuration
    SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
    //GPIO Configuration
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);


    while(1){
        //On and off basic from LED
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, ui8PinData);
        SysCtlDelay(2000000);
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0x00);
        SysCtlDelay(2000000);
        if(ui8PinData==8) {
            ui8PinData=2;
        } else {
            ui8PinData=ui8PinData*2;
        }
    }

}
