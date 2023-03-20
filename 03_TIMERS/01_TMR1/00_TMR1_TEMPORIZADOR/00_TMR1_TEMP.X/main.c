
/*
 TCNT1 = 65536 - ((tiempo x FCLK)/prescaler)
 * ejm:
 * TCNT1 = 65536 - ((200x10-3 x 16x10^6)/256)
 * TCNT1 = 53036
 */

#include <avr/io.h>
#include <avr/interrupt.h>


int main(void) {
    
    DDRB = (1<<DDRB5);   
    TCCR1B |= (1<<CS12); //configurar clk internoc pre= 256
    TIMSK1 |= (1<<TOIE1); //habilitamos interrupion TMR1
    sei(); //habilitar interrupciones globales
    
    while(1);
    return 0;
}

ISR(TIMER1_OVF_vect)
{
    PORTB ^= (1<<PORTB5); //toggle LED
}