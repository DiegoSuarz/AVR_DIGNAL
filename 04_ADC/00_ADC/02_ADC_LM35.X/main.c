#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "usart.h"
#include <stdio.h>

#define VREF 1.1
#define RES 1024.0

void ADC_init(void)
{
    ADMUX |= (1<<MUX0) |(1<<MUX1) |(1<<REFS0)|(1<<REFS1); //ADC3 como canal analogico, voltaje de referencia interno 1.1v
    ADCSRA |= (1<<ADPS0) | (1<<ADPS1); //divisor clock /8
    DIDR0 |= (1<<ADC3D); //deshabilita el comportamiento digital del pin PC3/AD3
}

unsigned int ADC_convert()
{
    
    ADCSRA |= (1<<ADSC) | (1<<ADEN);    //habilitar el modulo ADC e iniciar la conversion
    while(ADCSRA & (1<<ADSC));          //Espera a que finalice la conversion
    ADCSRA &= ~(1<<ADEN);               //Deshabilita el modulo ADC
    return ADC;                        //lectura del resultado de la conversion
}

float convert_volt()
{
    float volt;
    volt = (float)(VREF / RES) * ADC_convert();
    return volt;
}

int main(void) {
    
    float temperatura;
    unsigned char str_adc[10];
    ADC_init();
    init_uart();
    
    while(1)
    {
        temperatura = (convert_volt() - 0.5) / 0.01; //mcp9700a
        temperatura = convert_volt() / 0.01; //LM35
        sprintf((char*)str_adc,"ADC: %1.2f\n\r",temperatura);
        send_string(str_adc);
        _delay_ms(500);
    
    }   
    
    return 0;
}

