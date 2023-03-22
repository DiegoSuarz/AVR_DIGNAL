
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "ADC.h"

void PWM_init()
{
    TCCR1A |= (1<<COM1B1)|(1<<WGM11) | (1<< WGM10); //PWM modo invertido,  canal B PIN PB2, timer modo fast PWM 10b its
    TCCR1B |= (1<<WGM12) | (1<< CS10);
    

}

int main(void) {
    
    DDRB |= (1<<DDRB2); //pin de salida de la señal PWM
    ADC_init();
    PWM_init();
    while(1)
    {
        OCR1B = ADC_convert(); //regular el PWM con la salida del ADC
        _delay_ms(200);
    }
    return 0;
}

