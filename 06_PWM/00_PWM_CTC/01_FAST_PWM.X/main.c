#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
/* Frecuencia de la señal PWM:
 * 
 * fOCnX_PWM = Fclk / ( Nx(1 + TOP))
 * ejm: fosk = 16Mhz, N(prescaler) = 1, TOP
 * fOCnX_PWM = 16x10^6 / ( 1x(1 + 1023))
 * fOCnX_PWM = 15.63 Khz
 
 */
void PWM_init()
{
    TCCR1A |= (1<<COM1A1)|(1<<WGM11) | (1<< WGM10); //PWM modo invertido, timer modo fast PWM
    TCCR1B |= (1<<WGM12) | (1<< CS10);
    OCR1A = 512;  //50% de duty cycle

}

int main(void) {
    
    DDRB |= (1<<DDRB1); //PB1 como salida digital para utilizarse como PWM
    PWM_init();
    while(1)
    {
        
    }
    return 0;
}


