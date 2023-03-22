#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


/*
 OCRnA define el periodo total de la señal PWM 
 OCRnB define el ciclo de trabajo 
 * 
 OCRnA = (Fclk / (fOCnA * 2 * N) ) - 1
 * 
 para frecuencia deseada de 10khz fOCnA, fosc = 16mhz, pree=1
  OCRnA = (16x10^6 / ( 10x10^3 * 2 * 1) ) - 1
  OCRnA = 799 
*/
int main(void) {
    
    DDRB |= (1<<DDRB5);
    
    TCCR1B |= (1<<CS10)| (WGM12); //prescaler = 1, modo de temporizador CTC
    TIMSK1 |= (1<<OCIE1A) | (1<<OCIE1B); //habllitamos las interrupciones de los 2 canales de comparacion  
    
  /*   OCRnA = (Fclk / (fOCnA * 2 * N) ) - 1
 * 
    para frecuencia deseada de 10khz fOCnA, fosc = 16mhz, pree=1
  OCRnA = (16x10^6 / ( 10x10^3 * 2 * 1) ) - 1
  OCRnA = 799 
    */
    OCR1A = 799; //define el periodo de la señal con una frecuencia de 10Khz
    
    OCR1A = 399; //50 porciento del duty cycle
    sei();
    while(1)
    {
        
    }
    return 0;
}

ISR(TIMER1_COMPA_vect)
{
    PORTB  |= (1<<PORTB5); //pone el alto la señal del PWM
}

ISR(TIMER1_COMPB_vect)
{
    PORTB  &= ~(1<<PORTB5); //pone el bajo la señal del PWM
}
