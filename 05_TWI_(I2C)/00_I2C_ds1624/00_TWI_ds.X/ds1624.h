/*
 * ds1624.h
 *
 * Created: 29/07/2019 02:01:31 p. m.
 *  Author: Dignal
 */ 


#ifndef DS1624_H_
#define DS1624_H_

#include <stdint.h>

#define ADDRESS 0b10010000
#define COMANDO_ONESHOT       0b01001011
#define COMANDO_CON_CONTINUA  0b01001010
#define COMANDO_LEERTEMP           0xAA
#define COMANDO_INICIAR_CONVERSION 0xEE
#define COMANDO_ACCESS_CONFIG      0xAC

#define getMSB_Value(v)   (unsigned char)((v & 0b1111111100000000)>>8);
#define getLSB_Value(v)   (unsigned char)( v & 0b0000000011111111);

void init_DS1624(void);
void init_conversion(void);
uint16_t read_temp_i2c(void);
uint16_t read_temp(void);
uint8_t roundingDecimalPart(uint8_t decimal_byte);




#endif /* DS1624_H_ */