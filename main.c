#include <htc.h>
#include "init.h"
#include "lcd.h"
#include "ser.h"
#include "util.h"

__CONFIG(FOSC_INTOSCIO & MCLRE_OFF & WDTE_OFF & PWRTE_OFF & CP_OFF & CPD_OFF &
        BOREN_OFF & DEBUG_OFF);

void interrupt ISR(void)
{
    if (INTF) /* RB0 interrupt (on falling edge) detected */
    {
        INTF = 0;
        lcd_clear();
        INTE = 1;
    }
    
    ser_int(); /* macro in ser.h */
}

void main(void)
{
	/* Initialization */
	clk_init();
	io_init();
	lcd_init();
	ser_init();
	
	lcd_puts("Welcome!\nStart typing @$%");
	ser_puts("Welcome to the LCD module serial interface!\n\r");
	
	unsigned char rx_data = 0;      /* Received data byte */
	
	rx_data = ser_getch();
    lcd_clear();
    lcd_putch(rx_data);
    ser_putch(rx_data);
	
	while (1)
	{
    	rx_data = ser_getch();  /* Block on serial line */
    	ser_putch(rx_data);     /* Echo input back to transmitter */
    	lcd_putch(rx_data);     /* Write received data to LCD */
	}
}