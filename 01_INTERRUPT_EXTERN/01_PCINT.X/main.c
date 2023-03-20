#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void) {
    DDRB |= (1<<DDRB5); //PB5 como salida
    DDRD |= (1<<DDRD0); //PD0 como salida que genera la interrupc
    
    PCICR = (1<< PCIE1); //habilitar agraupacion de PCINT1 
    PCMSK1 = (1<<PCINT12); //habilitar PCINT12 como fuente de interrupcion
    sei();
        
    while(1){
        PORTD ^= (1<<PORTD0);
    }
    
    return 0;
}

ISR(PCINT1_vect)
{
    PORTB^=(1<<PORTB5);
}

