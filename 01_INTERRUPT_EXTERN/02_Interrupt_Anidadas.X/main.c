#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void) {
    
    DDRB |= (1<<DDRB5);
    
    PCICR |= (1<<PCIE0); //habilitar PCINT0
    PCMSK0 |= (1<<PCINT7); //Elejimos PCINT7
    
    EICRA |= (1<<ISC01);    //INT0 flanco de bajada
    EIMSK |= (1<<INT0);     //habilitar INT0
    
    sei();  //habilitar interupciones globales
      
    while(1)
    {
        PORTD^= (1<<PORTD0);
        _delay_ms(1000);
    }
    return 0;
}

ISR(INT0_vect)
{
    sei(); //habilitamos las interrupciones globales ya que se deshabilitan automaticamente al entrar en  una ISR
    PORTB &= ~(1<<PORTD5);
}

ISR(PCINT0_vect)
{
    PORTB |= (1<<PORTB5);
}
