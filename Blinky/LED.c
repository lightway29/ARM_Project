/*----------------------------------------------------------------------------
 * Name:    LED.c
 * Purpose: low level LED functions
 * Note(s):
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2009-2011 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

#include "LPC17xx.H"                         /* LPC17xx definitions           */
#include "LED.h"

const unsigned long led_mask[] = { 1UL<<28, 1UL<<29, 1UL<<31, 1UL<< 2,
                                   1UL<< 3, 1UL<< 4, 1UL<< 5, 1UL<< 6 };


/*----------------------------------------------------------------------------
  initialize LED Pins
 *----------------------------------------------------------------------------*/
void LED_Init (void) {

  LPC_SC->PCONP     |= (1 << 15);            /* enable power to GPIO & IOCON  */

  LPC_GPIO1->FIODIR |= 0xB0000000;           /* LEDs on PORT1 are output      */
  LPC_GPIO2->FIODIR |= 0x0000007C;           /* LEDs on PORT2 are output      */
}


//long int c =10000000;

//void delay(long int a)
//{	long int i=0;
//	for(i=0;i<a;i++);
//}

/*----------------------------------------------------------------------------
  Function that turns on requested LED
 *----------------------------------------------------------------------------*/
void LED_On (unsigned int num) {

  if (num < 3) LPC_GPIO1->FIOPIN |=  led_mask[num];
  else         LPC_GPIO2->FIOPIN |=  led_mask[num];
}

/*----------------------------------------------------------------------------
  Function that turns off requested LED
 *----------------------------------------------------------------------------*/
void LED_Off (unsigned int num) {

  if (num < 3) LPC_GPIO1->FIOPIN &= ~led_mask[num];
  else         LPC_GPIO2->FIOPIN &= ~led_mask[num];
}

/*----------------------------------------------------------------------------
  Function that outputs value to LEDs
 *----------------------------------------------------------------------------*/
void LED_Out(unsigned int value) {
  int i;

  for (i = 0; i < LED_NUM; i++) {
//    if (value & (1<<i)) {
//      LED_On (i);
		//	for(i=0;i<10000000;i++);
//    } else {
//      LED_Off(i);
//    }
		
		 LED_On (3);
     LED_Off(2);
     LED_Off(1);
     LED_On (0);
		
		for(i=0;i<50000;i++);
		
		LED_On(3);
    LED_Off(2);
    LED_Off(1);
    LED_On (0);
		
		for(i=0;i<50000;i++);
		
		LED_On(3);
    LED_On(2);
    LED_Off(1);
    LED_Off (0);
		
		for(i=0;i<50000;i++);
		
		LED_Off(3);
    LED_On(2);
    LED_On(1);
    LED_Off (0);
		
		for(i=0;i<50000;i++);
		
		LED_Off(3);
    LED_Off(2);
    LED_On(1);
    LED_On(0);
		
		for(i=0;i<50000;i++);
		
  }
}
