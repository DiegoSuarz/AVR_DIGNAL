/*
 * ds1624.c
 *
 * Created: 29/07/2019 01:53:09 p. m.
 *  Author: Dignal
 */ 
#ifndef  F_CPU
	#define F_CPU 16000000UL
#endif

#include <avr/delay.h>
#include <avr/io.h>
#include "i2c_master.h"
#include "ds1624.h"

const uint8_t decimal_values[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
const uint8_t rounded_values[16] =  {0,1,1,2,3,3,4,4,5,6,6,7,8,8,9,9};

void init_DS1624(void)
{
	i2c_start(ADDRESS | I2C_WRITE);
	i2c_write(COMANDO_ACCESS_CONFIG);
	i2c_write(COMANDO_ONESHOT);
	i2c_stop();	
}
void init_conversion(void)
{
	i2c_start(ADDRESS | I2C_WRITE);
	i2c_write(COMANDO_INICIAR_CONVERSION);
	i2c_stop();
}
uint16_t read_temp_i2c(void)
{
	uint8_t tempMSB;
	uint8_t tempLSB;
	uint16_t temp;
	
	i2c_start(ADDRESS | I2C_WRITE);
	i2c_write(COMANDO_LEERTEMP);
	i2c_start(ADDRESS | I2C_READ);
	tempMSB = i2c_read_ack();
	tempLSB = i2c_read_nack();
	i2c_stop();
	
	temp = (tempMSB<<8) | tempLSB;
	return temp;
	
}
uint16_t read_temp(void)
{
	uint8_t  temp_int;
	uint8_t  temp_decimal;
	uint16_t temp;
	uint16_t result;
	int16_t  raw_temp;
	
	init_conversion();

	raw_temp = read_temp_i2c();

	temp = (raw_temp < 0) ? ((~raw_temp) + 1) : raw_temp; //si el valor de temperatura es negativo, se aplica complementa A2
	temp_int     = getMSB_Value(temp);
	temp_decimal = getLSB_Value(temp);
	temp_decimal = roundingDecimalPart(temp_decimal);
	
	result = (temp_int<<8) + temp_decimal;
	return result;
	
}
uint8_t roundingDecimalPart(uint8_t decimal_byte)
{
	uint8_t temp_decimal;

	temp_decimal = (decimal_byte&0b11110000)>>4;
	int i;
	for(i = 0;i<=15;i++)
	{
		if(temp_decimal != decimal_values[i]) continue;
		temp_decimal = rounded_values[i];
		break;
	}
	return temp_decimal;
}