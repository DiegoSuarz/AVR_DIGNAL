/*
 * File:   main.c
 * Author: dg_su
 *
 * Created on 17 de marzo de 2023, 04:05 PM
 */


//#include "xc.h"

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/delay.h>

int main(void) {
    
    DDRB    = 0b00100000; //DDRB |= (1<<DDRB5);
    DDRD = 0b00000011; // DDRD = |(1<<0) | (1<<1); // DDRD |= (3<<DDRB0);
    
    while(1){
        PORTB   = 0b00100000; //PORTB |= (1<<PORTB5);
        _delay_ms(1000);
        PORTB &=~(1<<PORTB5);
        _delay_ms(1000);
    }
    
    
    while(1);
    return 0;
}
