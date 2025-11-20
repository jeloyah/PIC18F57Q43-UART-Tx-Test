
#include <xc.h>
#include <stdio.h>
#include "main.h"
#include "clock.h"
#include "gpio.h"
#include "uart1.h"
#include "timer0.h"
#include "ioc.h"
#include "pps.h"
#include "lcd.h"


void main(void) {
    
    /* System Clock Initialization */
	CLOCK_Initialize();
          
    /* Config PortA */
    PortA_Initialize();
    
    /* Config PortB */
    PortB_Initialize();

    /* Config PortC */
    PortC_Initialize();
    
    /* Config PortD */
    PortD_Initialize();
    
    /* Config PortE */
    PortE_Initialize();
    
    /* Config PortF */
    PortF_Initialize();  
    
    /* UART1 configuration */
    UART1_Initialize();
    
    /* Config Timer0 */
    TIMER0_Initialize();
     
    /* Config PPS */
    PPS_Initialize();
    
    /* Config IOC */
    IOC_Initialize();
   
    /* Config LCD */
    LCD_Initialize();
    
    LCD_CLEAR_DISPLAY();
    
    /* Enable interrupts */
    ei();
    
    /* infinite loop */
    while(1)
    {
        
        LCD_printstring("Hello MCU world!\n");
        
        /* Transmit a string */
        UART1_send_string("Hello MCU PIC world! \n");
        
        TIMER0_Delay_ms(500);
        
        LCD_CLEAR_DISPLAY();
        
    } /* while*/
    
    return;
} /* main */
