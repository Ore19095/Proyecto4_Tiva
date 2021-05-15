/**
 * ANGEL ORELLANA
 * PROYECTO 4
 * PARQUEO MATIC: SISTEMA DE ESTACIONAMIENTOS
 */
#include <stdint.h>
#include <stdbool.h>
#include <inc/hw_memmap.h>
#include <inc/hw_types.h>
#include <inc/hw_gpio.h>
#include <driverlib/sysctl.h>
#include <driverlib/gpio.h>

// variable que se usara para el 7 segmentos
static uint8_t tabla[] = {
                        0b11100111, // 0
                        0b10000010, // 1
                        0b01101011, // 2
                        0b11001011, //3
                        0b10001110 //4
};
uint8_t parqueosDisponibles;

int main(void){
    // configuracion: reloj con entrada principal de 16MHZ usando pll con una frecuencia de 40MHZ
    SysCtlClockSet(SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ| SYSCTL_SYSDIV_5);

    // conectando los puertos al reloj del sistema :D
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); // ENTRADAS DE LOS SENSORES(DIP SWITCH)
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA); // SALIDA PARA EL 7 SEGMENTOS
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB); // SALIDA PARA LOS LEDS
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD); // SALIDA PARA EL 7 SEGMENTOS
    //configurar los pines
    HWREG(GPIO_PORTD_BASE+GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTD_BASE+GPIO_O_CR) |= GPIO_PIN_7;
    GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_5); // para el 7 segmentos
    GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1| GPIO_PIN_2 |
                                           GPIO_PIN_3 |GPIO_PIN_4 | GPIO_PIN_5 |
                                           GPIO_PIN_6 | GPIO_PIN_7); // para las luces de encendido
    GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_0 | GPIO_PIN_1| GPIO_PIN_2 |
                                           GPIO_PIN_3 |GPIO_PIN_6 | GPIO_PIN_7); // para llos 7 segmentos
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_1| GPIO_PIN_2 |
                                         GPIO_PIN_3 |GPIO_PIN_4 );
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_1| GPIO_PIN_2 |
                                         GPIO_PIN_3 |GPIO_PIN_4, ui32Strength, ui32PadType)

    GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0 | GPIO_PIN_1| GPIO_PIN_2 |
                                               GPIO_PIN_3 |GPIO_PIN_6 | GPIO_PIN_7, tabla[4]);

    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, tabla[4]);
    while(1){



    }

	return 0;
}
