#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "GPIO.h"

int val;

int main(void) {
    
    pinMode(&DDRB,7,INPUT);
    pinMode(&DDRB,5,OUTPUT);
      
    while(1)
    {
        digitalWrite(&PORTB,5,HIGH);
        _delay_ms(200);
        digitalWrite(&PORTB,5,LOW);
        _delay_ms(200);
        
        val = digitalRead(&PINB, 7);
    }
    return 0;
}


