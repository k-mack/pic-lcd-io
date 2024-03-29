#ifndef _UTIL_H
#define _UTIL_H

/* This is must be updated if the system clock's frequency changes */
#define _XTAL_FREQ 8000000

/* Useful macros */
#define SETBIT(ADDR,BIT) (ADDR |= (1<<BIT))
#define CLEARBIT(ADDR,BIT) (ADDR &= ~(1<<BIT))

/* Generic bit markers */
#define BIT0 0
#define BIT1 1
#define BIT2 2
#define BIT3 3
#define BIT4 4
#define BIT5 5
#define BIT6 6
#define BIT7 7

#endif