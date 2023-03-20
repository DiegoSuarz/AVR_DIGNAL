#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

void timer1_freq()
{
    TCCR1B |= (1<<WGM12) | (1<<CS12); //modo CTC activado y clk interno con preescaler de 256
    TIMSK1 |= (1<<OCIE1A); //interrupcion por comparacion habilitada

/*
OCRnA = fclk/ (fOCnA * 2 * pree) - 1
 
 si quieron que la comparacion se de cada 15hz, con un presecaler de 256
 * 
 * OCRnA = 16x10^6 /(15 x 2 x 256)- 1
 * OCRnA = 2082
 */
    OCR1A = 2082; //PARA UNA FRECUENCIA DE 15HZ

}

void timer1_freq_param(unsigned char freq)
{
    TCCR1B |= (1<<WGM12) | (1<<CS12); //modo CTC activado y clk interno con preescaler de 256
    TIMSK1 |= (1<<OCIE1A); //interrupcion por comparacion habilitada
    OCR1A = (F_CPU/(freq*2*256))-1;
}
int main(void)
{
    
    DDRB |= (1<<PORTB5);
    sei();
//    timer1_freq();
    timer1_freq_param(15); //que la comparacion se de cada 15Hz
    while(1);
    return 0;
}

ISR(TIMER1_COMPA_vect)
{
    PORTB ^= (1<<PORTB5);
}