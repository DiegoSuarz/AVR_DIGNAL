#include <avr/io.h>
#include "usart.h"
void init_uart(void)
{
    DDRD |= (1<<DDRD1); //tx ccomo salida
    
    UCSR0B |= (1<<TXEN0); //habilitamos transmisor USART0
    UCSR0C |= (1<<UCSZ00) | (1<<UCSZ01); //configuramos el dato a 8 bits
    UBRR0 = 103; //USART a 9600 baudios a 16Mhz

}

void send_char(unsigned char c)
{
    while((UCSR0A & (1<<UDRE0)) == 0);  //while(!(UCSR0A & (1<<UDRE0)));
    UDR0 = c;  //enviar caracter por uart
    
}

void send_string(const unsigned char *pStr)
{
    while(*pStr != 0) // 0 = '\0'
    {
        send_char(*pStr);
        pStr++; //avanza a la siguiente direccion de la cadena
    }
}