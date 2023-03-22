#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "usart.h"
#include <stdio.h>

/*
 Para poder imprimir valores flotantes con la libreria sprint se debe realizar los siguientes pasos
 * 1: ir a la configuracion del proyecto
 * 2; ir a XC8 Global options
 * 3: ir a xC8 linker
 * 4: escribir en additional options: -Wl,-u,vfprintf -lprintf_flt 
 */

#define VREF 5.0
#define RES 1024.0

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

int main(void) {
    
    
    unsigned char str_adc[10];
    ADC_init();
//    init_uart();
    
    while(1)
    {
        sprintf((char*)str_adc,"ADC: %1.2f\n\r",convert_volt());
//        send_string(str_adc);
        _delay_ms(500);
    
    }   
    
    return 0;
}



