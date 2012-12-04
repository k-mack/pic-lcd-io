#include <htc.h>
#include "serial.h"

void serial_init(void)
{
    SPEN = 1;       /* Enable serial port */
    SYNC = 0;       /* Asynchronous communication */
    TXEN = 1;       /* Enable transmissions */
    CREN = 1;       /* Enable reception */
    BRGH = 1;       /* High baud rate selected */
    SPBRG = 51;    /* Set baud rate to 9600 (see ser.c) */
    TRISC |= 0x80;  /* Set receive pin to input */
    PORTC = 0;      /* Clear PORTC */
}

void tx_byte(unsigned char byte)
{
    while(!TXIF);
	TXREG = byte;
}

void tx_data(const char *data)
{
    while(*data)
	{
		while(!TXIF);
		TXREG = *data++;
	}
}