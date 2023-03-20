#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void) {
    
    DDRD |= (1<<DDRD0); //PD0 como salida que genera la interrupcion
    
    DDRB |= (1<<DDRB5); //PB5 como salida
    
    EICRA |= (1<<ISC01);    //INT0 -> PD2 como flanco de bajada
    EICRA &= ~(1<<ISC00);
    
    EIMSK |= (1<<INT0); //habilitar interrupcion INT0
    
    sei(); //habilitar interrupciones globales
    
    while(1)
    {
      //generar los eventos de interrupcion
        PORTD ^= (1<<PORTD0);
    }
    
    return 0;
}

ISR(INT0_vect)
{
    PORTB ^= (1<<PORTB5);
    _delay_ms(2000);
}
