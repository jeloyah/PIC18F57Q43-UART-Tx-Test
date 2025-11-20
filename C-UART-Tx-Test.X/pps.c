#include <xc.h>
#include "pps.h"

void PPS_Initialize(void)
{
    /* sequence for unlock PPS */
    PPS_unlock();
      
    /* UART1_TX is connected to RF7 pin */
    RC4PPS = 0x20;
    
    /* sequence for lock PPS */
    PPS_lock();
}

void PPS_lock(void) {
    /* Disable interrupts */
    di();
    
    /* Required sequence */
    PPSLOCK = 0x55;
    
    /* Required sequence */
    PPSLOCK = 0xAA;
    
    /* Set PPS locked bit*/
    PPSLOCK |= 0x01;
    
    /* Enable interrupts */
    ei();  
}

void PPS_unlock(void) {
    /* Disable interrupts */
    di();
    
    /* Required sequence */
    PPSLOCK = 0x55;
    
    /* Required sequence */
    PPSLOCK = 0xAA;
    
    /* Clear PPS locked bit*/
    PPSLOCK &= 0xFE;
    
    /* Enable interrupts */
    ei();  
}