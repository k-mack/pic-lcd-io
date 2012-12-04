#include <htc.h>
#include "init.h"
#include "lcd.h"
#include "util.h"

/*****************************************************************************
 * Subroutine: io_init
 *
 * Description:
 * This subroutine sets up the input/output ports on the PIC.
 *
 * Modified Registers:
 * LCDCON
 * TRISB
 *
 * Input Parameters:
 * None
 *
 * Output Parameters:
 * None
 *
 * Subroutines:
 * None
 *****************************************************************************/
void io_init(void)
{
    LCDCON = 0;     /* Disable LCD control register */
    TRISB = 0x01;   /* PORTB is used for LCD control and external interrupt */
    TRISC = 0x80;   /* PORTC is all outputs expect UART RX pin */
    INTEDG = 0;     /* Detect falling edge on RB0 */
    INTE = 1;       /* Enable RB0 interrupt */
    GIE = 1;        /* Enable global interrupts */
}

/*****************************************************************************
 * Subroutine: clk_init
 *
 * Description:
 * This subroutine sets up the clock on the PIC.
 *
 * Modified Registers:
 * OSCCON
 *
 * Input Parameters:
 * None
 *
 * Output Parameters:
 * None
 *
 * Subroutines:
 * None
 *****************************************************************************/
void clk_init(void)
{
    OSCCON |= 0x71; /* 8 MHz sys clk; select internal oscillator*/
}
