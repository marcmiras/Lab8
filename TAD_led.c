/*
 * File:   TAD_led.c
 * Author: Marc Miras Fortuny
 *
 * Created on February 20, 2026, 8:18 AM
 */


#include <xc.h>
#include "pic18f4321.h"
#include "TAD_led.h"

void LED_Off() {
    LATAbits.LATA3 = 0;
    LATAbits.LATA4 = 0;
}

void LED_Init() {
    TRISAbits.TRISA3 = 0;
    TRISAbits.TRISA4 = 0;
    
    LED_Off();
}

void LED_False() {
    LATAbits.LATA3 = 1;
    LATAbits.LATA4 = 0;
}

void LED_True() {
    LATAbits.LATA3 = 0;
    LATAbits.LATA4 = 1;
}
