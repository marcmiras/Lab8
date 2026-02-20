/*
 * File:   TAD_ASIO.c
 * Author: marcmiras
 *
 * Created on February 20, 2026, 8:22 AM
 */


#include <xc.h>
#include "pic18f4321.h"
#include "TAD_ASIO.h"
#include "TAD_led.h"

#define TXSTA_CONFIG 0x20 
#define RCSTA_CONFIG 0x90
#define BAUDCON_CONFIG 0x00 // EX1: n = 64 // EX2: n = 89
#define SPBRG_CONFIG 0x59 // EX1: o 40 en hex // EX2: o 59 en hex

unsigned static char state;
unsigned static char i = 0;

void ASIO_Init() {
    TXSTA = TXSTA_CONFIG;
    RCSTA = RCSTA_CONFIG;
    BAUDCON = BAUDCON_CONFIG;
    SPBRG = SPBRG_CONFIG;
    
    TRISCbits.TRISC6 = 1; // Tx
    TRISCbits.TRISC7 = 1; // Rx
    
    return; 
}

void ASIO_Motor() {
    switch (state) {
        case 0:
            if (PIR1bits.TXIF == 1) { // Si el TXREG està buit 
                i++;
                
                if (i >= 255) i = 0;
                
                TXREG = i;
                state = 1;   
            }   
                
            break;
            
        case 1:
            if (PIR1bits.RCIF == 1) { // Ha rebut algo
                (RCREG == i) ? LED_True() : LED_False(); // És el mateix?
                state = 0;
            } 
            
            break;
    }
    
    return;
};
