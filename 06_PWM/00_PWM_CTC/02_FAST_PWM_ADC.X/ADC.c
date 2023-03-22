#include <avr/io.h>
#include "ADC.h"

void ADC_init(void)
{
    ADMUX |= (1<<MUX0) |(1<<MUX1) |(1<<REFS0); //ADC3 como canal analogico, voltaje de referencia AVcc
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