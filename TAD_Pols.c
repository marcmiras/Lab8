/*
 * File:   TAD_Pols.c
 * Author: marcmiras
 *
 * Created on February 24, 2026, 11:28 AM
 */


#include <xc.h>
#include "pic18f4321.h"
#include "TAD_Pols.h"

#define POL0 PORTBbits.RB0
#define POL1 PORTBbits.RB1

static unsigned char state = 0;
static unsigned char pressed0 = 0;
static unsigned char pressed1 = 0;

void POL_Init() {
    TRISBbits.TRISB0 = 1;
    TRISBbits.TRISB1 = 1;
    INTCON2bits.RBPU = 0; // enable internal pull-ups (buttons are active-low)
}

void POL_Motor() {
    switch (state) {
        case 0: // IDLE: waiting for any press
            if (POL0 == 0) {
                pressed0 = 1;
                state = 1;
            } else if (POL1 == 0) {
                pressed1 = 1;
                state = 2;
            }
            break;

        case 1: // waiting for RB0 release
            if (POL0 == 1) state = 0;
            break;

        case 2: // waiting for RB1 release
            if (POL1 == 1) state = 0;
            break;
    }
}

unsigned char POL_IsPressed0() {
    if (pressed0) {
        pressed0 = 0;
        return 1;
    }
    return 0;
}

unsigned char POL_IsPressed1() {
    if (pressed1) {
        pressed1 = 0;
        return 1;
    }
    return 0;
}
