
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "GPIO.h"

int main(void) 
{   
    DDRBbits.pinb5 = 1;  //PB5 como salida (led)
    DDRBbits.pinb7 = 0;  //PB7 como entrada (switch)
    while(1)
    {
        PORTBbits.portb5 = 1;   //LED ON
        _delay_ms(1000);
        PORTBbits.portb5 = 0;   //LED OFF
        _delay_ms(1000);
    }
    return 0;
}
