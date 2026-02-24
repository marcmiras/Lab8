/*
 * File:   main.c
 * Author: Marc Miras Fortuny
 *
 * Created on February 20, 2026, 8:04 AM
 */


#include <xc.h>
#include "pic18f4321.h"
#include "TAD_ASIO.h"
#include "TAD_led.h"
#include "TAD_Pols.h"

#pragma config OSC = HSPLL
#pragma config PBADEN = DIG
#pragma config WDT = OFF

/*
#define _XTAL_FREQ 1000000
#define T0CON_CONFIG '11001000'
#define INTCON_CONFIG 0xE0
#define RECARREGA_TMR0 156
*/

void main(void);


void main(void) {
    
    LED_Init();
    ASIO_Init();
    POL_Init();
    
    while(1) {
        ASIO_Motor();
        POL_Motor();
    }
        
    return;
}
