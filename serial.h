#include "ser.h"

#ifndef _SERIAL_H
#define _SERIAL_H

/* Initialize serial I/O */
void serial_init(void);

/* Transmits a character */
void tx_byte(unsigned char byte);

/* Transmits a character string */
void tx_data(const char *data);

#endif