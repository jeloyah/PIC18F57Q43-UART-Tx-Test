
#include <xc.h>
#include "uart1.h"

/* UART1 configuration */
void UART1_Initialize(void) {
    
    /* Baud rate = 9600 bps with Fosc=64MHz */
    U1BRG = 0x019F;
    
    /* Serial port enable */
    U1CON1 = 0x80;
    
    /* Baud rate normal, auto-baud disable, transmit enable, receiver disable, 8-bit uart no parity */
    U1CON0 = 0x20;
        
    return;
}

/* Send a string through UART1 */
void UART1_send_string(char *string)
{
    while(*string)
    {
        while(!PIR4bits.U1TXIF);          // wait until the transmitter is ready
        U1TXB = *string;                     // send one character
        string++;
    }
}

/* Send a charthrough UART1 */
void UART1_send_char(char data)
{
    while(!PIR4bits.U1TXIF);          // wait until the transmitter is ready
    U1TXB = data;                     // send one character        
}

