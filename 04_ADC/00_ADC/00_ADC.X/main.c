#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include "usart.h"

void ADC_init(void)
{
    ADMUX |= (1<<MUX0) |(1<<MUX1) |(1<<REFS0); //ADC3 como canal analogico, voltaje de referencia AVcc
    ADCSRA |= (1<<ADPS0) | (1<<ADPS1); //divisor clock /8
    DIDR0 |= (1<<ADC3D); //deshabilita el comportamiento digital del pin PC3/AD3
}


int main(void) {
    
    unsigned int adc_result;  //resultado de 10 bits del ADC
    unsigned char str_adc[10];
    ADC_init();
    init_uart();
    
    while(1)
    {
        ADCSRA |= (1<<ADSC) | (1<<ADEN);    //habilitar el modulo ADC e iniciar la conversion
        while(ADCSRA & (1<<ADSC));          //Espera a que finalice la conversion
        ADCSRA &= ~(1<<ADEN);               //Deshabilita el modulo ADC
        adc_result = ADC;                   //lectura del resultado de la conversion
    
        sprintf(str_adc,"ADC: %u\n\r",adc_result);
        send_string(str_adc);
        _delay_ms(500);
    
    }   
    
    return 0;
}


