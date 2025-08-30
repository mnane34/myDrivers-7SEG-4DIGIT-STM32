/**
 * @file    DISPLAY.h
 * @brief   7 Segment - 4 Digit Display Driver for STM32
 * @author  Mertcan NANE
 * @date    2025-08-027
 * @version 1.0
 *
 * @contact
 *  https://github.com/mnane34
 *  https://www.youtube.com/@mnane34
 *  https://www.linkedin.com/in/mertcan-nane/
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

/* Additional Header Definitions */
#include "main.h"
#include "stdint.h"
#include "TIME.h"
#include "GPIO.h"

#pragma once

/* Display logic states definitions according to commond type of displays */
#define COMMON_CATHODE

#if (defined(COMMON_ANODE) && !defined(COMMON_CATHODE))
	#define DISPLAY_POLARITY 0
#elif (defined(COMMON_CATHODE) && !defined(COMMON_ANODE))
	#define DISPLAY_POLARITY 1
#endif

#define display_HIGH 		( DISPLAY_POLARITY )
#define display_LOW		( 1 - DISPLAY_POLARITY )

typedef struct{

	TIM_HandleTypeDef *htim;

	GPIO_TypeDef* D1_GPIOx;
	uint16_t D1_PINx;

	GPIO_TypeDef* D2_GPIOx;
	uint16_t D2_PINx;

	GPIO_TypeDef* D3_GPIOx;
	uint16_t D3_PINx;

	GPIO_TypeDef* D4_GPIOx;
	uint16_t D4_PINx;

	GPIO_TypeDef* A_GPIOx;
	uint16_t A_PINx;

	GPIO_TypeDef* B_GPIOx;
	uint16_t B_PINx;

	GPIO_TypeDef* C_GPIOx;
	uint16_t C_PINx;

	GPIO_TypeDef* D_GPIOx;
	uint16_t D_PINx;

	GPIO_TypeDef* E_GPIOx;
	uint16_t E_PINx;

	GPIO_TypeDef* F_GPIOx;
	uint16_t F_PINx;

	GPIO_TypeDef* G_GPIOx;
	uint16_t G_PINx;

	GPIO_TypeDef* DOT_GPIOx;
	uint16_t DOT_PINx;

	uint8_t digitCount;
	volatile uint8_t tempCounter;
	volatile uint8_t digitBuffer[4];
	volatile uint8_t scanTime;

}DISPLAY_TypeDef_t;

void DISPLAY_init(TIM_HandleTypeDef * hTIMx, GPIO_TypeDef* D1_GPIO, uint16_t  D1_PIN,
							 	 	 	 	 	 	 	 	 	 	 	 	 GPIO_TypeDef* D2_GPIO, uint16_t  D2_PIN,
																			 GPIO_TypeDef* D3_GPIO, uint16_t  D3_PIN,
																			 GPIO_TypeDef* D4_GPIO, uint16_t  D4_PIN,
																			 GPIO_TypeDef* A_GPIO, uint16_t  A_PIN,
																			 GPIO_TypeDef* B_GPIO, uint16_t  B_PIN,
																			 GPIO_TypeDef* C_GPIO, uint16_t  C_PIN,
																			 GPIO_TypeDef* D_GPIO, uint16_t  D_PIN,
																			 GPIO_TypeDef* E_GPIO, uint16_t  E_PIN,
																			 GPIO_TypeDef* F_GPIO, uint16_t  F_PIN,
																			 GPIO_TypeDef* G_GPIO, uint16_t  G_PIN,
																			 GPIO_TypeDef* DOT_GPIO, uint16_t  DOT_PIN);
void DISPLAY_allSegmentON(void);
void DISPLAY_allSegmentOFF(void);
void DISPLAY_allDigitsOFF(void);
void DISPLAY_allSegmentBlink(void);
void DISPLAY_selectDigit(uint8_t digit);
void DISPLAY_writeDigit(uint8_t number);
void DISPLAY_write(volatile uint16_t number);

#endif
