/* Header Directives Definitions */
#include "DISPLAY.h"

/* Structure Object Definitions */
DISPLAY_TypeDef_t DISPLAY;

/**
 * @brief  Initializes the 4-digit 7-segment display and starts the timer interrupt.
 * @param hTIMx   Pointer to the timer handle used for display multiplexing.
 * @param D1_GPIO GPIO port for Digit 1 control pin.
 * @param D1_PIN  GPIO pin number for Digit 1 control.
 * @param D2_GPIO GPIO port for Digit 2 control pin.
 * @param D2_PIN  GPIO pin number for Digit 2 control.
 * @param D3_GPIO GPIO port for Digit 3 control pin.
 * @param D3_PIN  GPIO pin number for Digit 3 control.
 * @param D4_GPIO GPIO port for Digit 4 control pin.
 * @param D4_PIN  GPIO pin number for Digit 4 control.
 * @param A_GPIO  GPIO port for Segment A.
 * @param A_PIN   GPIO pin number for Segment A.
 * @param B_GPIO  GPIO port for Segment B.
 * @param B_PIN   GPIO pin number for Segment B.
 * @param C_GPIO  GPIO port for Segment C.
 * @param C_PIN   GPIO pin number for Segment C.
 * @param D_GPIO  GPIO port for Segment D.
 * @param D_PIN   GPIO pin number for Segment D.
 * @param E_GPIO  GPIO port for Segment E.
 * @param E_PIN   GPIO pin number for Segment E.
 * @param F_GPIO  GPIO port for Segment F.
 * @param F_PIN   GPIO pin number for Segment F.
 * @param G_GPIO  GPIO port for Segment G.
 * @param G_PIN   GPIO pin number for Segment G.
 * @param DOT_GPIO GPIO port for Dot (decimal point).
 * @param DOT_PIN  GPIO pin number for Dot (decimal point).
 * @retval None
 */
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
																			 GPIO_TypeDef* DOT_GPIO, uint16_t  DOT_PIN){

	DISPLAY.htim = hTIMx;
	HAL_TIM_Base_Start_IT(DISPLAY.htim);

	DISPLAY.D1_GPIOx = D1_GPIO;
	DISPLAY.D1_PINx = D1_PIN;

	DISPLAY.D2_GPIOx = D2_GPIO;
	DISPLAY.D2_PINx = D2_PIN;

	DISPLAY.D3_GPIOx = D3_GPIO;
	DISPLAY.D3_PINx = D3_PIN;

	DISPLAY.D4_GPIOx = D4_GPIO;
	DISPLAY.D4_PINx = D4_PIN;

	DISPLAY.A_GPIOx = A_GPIO;
	DISPLAY.A_PINx = A_PIN;

	DISPLAY.B_GPIOx = B_GPIO;
	DISPLAY.B_PINx = B_PIN;

	DISPLAY.C_GPIOx = C_GPIO;
	DISPLAY.C_PINx = C_PIN;

	DISPLAY.D_GPIOx = D_GPIO;
	DISPLAY.D_PINx = D_PIN;

	DISPLAY.E_GPIOx = E_GPIO;
	DISPLAY.E_PINx = E_PIN;

	DISPLAY.F_GPIOx = F_GPIO;
	DISPLAY.F_PINx = F_PIN;

	DISPLAY.G_GPIOx = G_GPIO;
	DISPLAY.G_PINx = G_PIN;

	DISPLAY.DOT_GPIOx = DOT_GPIO;
	DISPLAY.DOT_PINx = DOT_PIN;

	GPIO_WRITE_PIN(DISPLAY.D1_GPIOx, DISPLAY.D1_PINx, display_LOW);
	GPIO_WRITE_PIN(DISPLAY.D2_GPIOx, DISPLAY.D2_PINx, display_LOW);
	GPIO_WRITE_PIN(DISPLAY.D3_GPIOx, DISPLAY.D3_PINx, display_LOW);
	GPIO_WRITE_PIN(DISPLAY.D4_GPIOx, DISPLAY.D4_PINx, display_LOW);
	GPIO_WRITE_PIN(DISPLAY.A_GPIOx, DISPLAY.A_PINx, display_HIGH);
	GPIO_WRITE_PIN(DISPLAY.B_GPIOx, DISPLAY.B_PINx, display_HIGH);
	GPIO_WRITE_PIN(DISPLAY.C_GPIOx, DISPLAY.C_PINx, display_HIGH);
	GPIO_WRITE_PIN(DISPLAY.D_GPIOx, DISPLAY.D_PINx, display_HIGH);
	GPIO_WRITE_PIN(DISPLAY.E_GPIOx, DISPLAY.E_PINx, display_HIGH);
	GPIO_WRITE_PIN(DISPLAY.F_GPIOx, DISPLAY.F_PINx, display_HIGH);
	GPIO_WRITE_PIN(DISPLAY.G_GPIOx, DISPLAY.G_PINx, display_HIGH);
	GPIO_WRITE_PIN(DISPLAY.DOT_GPIOx, DISPLAY.DOT_PINx, display_HIGH);
}

/**
 * @brief  Activates all digit control lines of the display.
 * @retval None
 */
void DISPLAY_allSegmentON(void){
		GPIO_WRITE_PIN(DISPLAY.D1_GPIOx, DISPLAY.D1_PINx, display_HIGH);
		GPIO_WRITE_PIN(DISPLAY.D2_GPIOx, DISPLAY.D2_PINx, display_HIGH);
		GPIO_WRITE_PIN(DISPLAY.D3_GPIOx, DISPLAY.D3_PINx, display_HIGH);
		GPIO_WRITE_PIN(DISPLAY.D4_GPIOx, DISPLAY.D4_PINx, display_HIGH);
}

/**
 * @brief  Deactivates all digit control lines of the display.
 * @retval None
 */
void DISPLAY_allSegmentOFF(void){
	GPIO_WRITE_PIN(DISPLAY.D1_GPIOx, DISPLAY.D1_PINx, display_LOW);
	GPIO_WRITE_PIN(DISPLAY.D2_GPIOx, DISPLAY.D2_PINx, display_LOW);
	GPIO_WRITE_PIN(DISPLAY.D3_GPIOx, DISPLAY.D3_PINx, display_LOW);
	GPIO_WRITE_PIN(DISPLAY.D4_GPIOx, DISPLAY.D4_PINx, display_LOW);
}

/**
 * @brief  Turns off all digits on the display.
 * @retval None
 */
void DISPLAY_allDigitsOFF(void){
	GPIO_WRITE_PIN(DISPLAY.D1_GPIOx, DISPLAY.D1_PINx, display_LOW);
	GPIO_WRITE_PIN(DISPLAY.D2_GPIOx, DISPLAY.D2_PINx, display_LOW);
	GPIO_WRITE_PIN(DISPLAY.D3_GPIOx, DISPLAY.D3_PINx, display_LOW);
	GPIO_WRITE_PIN(DISPLAY.D4_GPIOx, DISPLAY.D4_PINx, display_LOW);
}

/**
 * @brief  Toggles all digit control lines and forces all segments ON.
 * @retval None
 */
void DISPLAY_allSegmentBlink(void){

	GPIO_TOGGLE_PIN(DISPLAY.D1_GPIOx, DISPLAY.D1_PINx);
	GPIO_TOGGLE_PIN(DISPLAY.D2_GPIOx, DISPLAY.D2_PINx);
	GPIO_TOGGLE_PIN(DISPLAY.D3_GPIOx, DISPLAY.D3_PINx);
	GPIO_TOGGLE_PIN(DISPLAY.D4_GPIOx, DISPLAY.D4_PINx);

	GPIO_WRITE_PIN(GPIOB, GPIO_PIN_13, display_LOW);
	GPIO_WRITE_PIN(GPIOB, GPIO_PIN_2, display_LOW);
	GPIO_WRITE_PIN(GPIOC, GPIO_PIN_5, display_LOW);
	GPIO_WRITE_PIN(GPIOA, GPIO_PIN_11, display_LOW);
	GPIO_WRITE_PIN(GPIOB, GPIO_PIN_12, display_LOW);
	GPIO_WRITE_PIN(GPIOB, GPIO_PIN_14, display_LOW);
	GPIO_WRITE_PIN(GPIOC, GPIO_PIN_6, display_LOW);
	GPIO_WRITE_PIN(GPIOA, GPIO_PIN_12, display_LOW);
}

/**
 * @brief  Selects a specific digit to be active on the 7-segment display.
 * @param digit  Digit index to activate (1–4).
 * @retval None
 */
void DISPLAY_selectDigit(uint8_t digit){

	DISPLAY.digitCount = digit;

	if(DISPLAY.digitCount == 1){
		GPIO_WRITE_PIN(DISPLAY.D1_GPIOx, DISPLAY.D1_PINx, display_HIGH);
		GPIO_WRITE_PIN(DISPLAY.D2_GPIOx, DISPLAY.D2_PINx, display_LOW);
		GPIO_WRITE_PIN(DISPLAY.D3_GPIOx, DISPLAY.D3_PINx, display_LOW);
		GPIO_WRITE_PIN(DISPLAY.D4_GPIOx, DISPLAY.D4_PINx, display_LOW);
	}
	else if(DISPLAY.digitCount == 2){
		GPIO_WRITE_PIN(DISPLAY.D1_GPIOx, DISPLAY.D1_PINx, display_LOW);
		GPIO_WRITE_PIN(DISPLAY.D2_GPIOx, DISPLAY.D2_PINx, display_HIGH);
		GPIO_WRITE_PIN(DISPLAY.D3_GPIOx, DISPLAY.D3_PINx, display_LOW);
		GPIO_WRITE_PIN(DISPLAY.D4_GPIOx, DISPLAY.D4_PINx, display_LOW);
	}
	else if(DISPLAY.digitCount == 3){
		GPIO_WRITE_PIN(DISPLAY.D1_GPIOx, DISPLAY.D1_PINx, display_LOW);
		GPIO_WRITE_PIN(DISPLAY.D2_GPIOx, DISPLAY.D2_PINx, display_LOW);
		GPIO_WRITE_PIN(DISPLAY.D3_GPIOx, DISPLAY.D3_PINx, display_HIGH);
		GPIO_WRITE_PIN(DISPLAY.D4_GPIOx, DISPLAY.D4_PINx, display_LOW);
	}
	else if(DISPLAY.digitCount == 4){
		GPIO_WRITE_PIN(DISPLAY.D1_GPIOx, DISPLAY.D1_PINx, display_LOW);
		GPIO_WRITE_PIN(DISPLAY.D2_GPIOx, DISPLAY.D2_PINx, display_LOW);
		GPIO_WRITE_PIN(DISPLAY.D3_GPIOx, DISPLAY.D3_PINx, display_LOW);
		GPIO_WRITE_PIN(DISPLAY.D4_GPIOx, DISPLAY.D4_PINx, display_HIGH);
	}
	else{
		GPIO_WRITE_PIN(DISPLAY.D1_GPIOx, DISPLAY.D1_PINx, display_LOW);
		GPIO_WRITE_PIN(DISPLAY.D2_GPIOx, DISPLAY.D2_PINx, display_LOW);
		GPIO_WRITE_PIN(DISPLAY.D3_GPIOx, DISPLAY.D3_PINx, display_LOW);
		GPIO_WRITE_PIN(DISPLAY.D4_GPIOx, DISPLAY.D4_PINx, display_LOW);
	}
}

/**
 * @brief  Displays a single digit (0–9) on the 7-segment display.
 * @param number  The digit to display (0–9).
 * @retval None
 */
void DISPLAY_writeDigit(uint8_t number){
		if(number == 0){
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_13, display_LOW);
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_2, display_LOW);
			GPIO_WRITE_PIN(GPIOC, GPIO_PIN_5, display_LOW);
			GPIO_WRITE_PIN(GPIOA, GPIO_PIN_11, display_LOW);
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_12, display_LOW);
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_14, display_LOW);
			GPIO_WRITE_PIN(GPIOC, GPIO_PIN_6, display_HIGH);
		}
		else if(number == 1){
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_13, display_HIGH);
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_2, display_LOW);
			GPIO_WRITE_PIN(GPIOC, GPIO_PIN_5, display_LOW);
			GPIO_WRITE_PIN(GPIOA, GPIO_PIN_11, display_HIGH);
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_12, display_HIGH);
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_14, display_HIGH);
			GPIO_WRITE_PIN(GPIOC, GPIO_PIN_6, display_HIGH);
		}
		else if(number == 2){
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_13, display_LOW);
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_2, display_LOW);
			GPIO_WRITE_PIN(GPIOC, GPIO_PIN_5, display_HIGH);
			GPIO_WRITE_PIN(GPIOA, GPIO_PIN_11, display_LOW);
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_12, display_LOW);
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_14, display_HIGH);
			GPIO_WRITE_PIN(GPIOC, GPIO_PIN_6, display_LOW);
		}
		else if(number == 3){
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_13, display_LOW);
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_2, display_LOW);
			GPIO_WRITE_PIN(GPIOC, GPIO_PIN_5, display_LOW);
			GPIO_WRITE_PIN(GPIOA, GPIO_PIN_11, display_LOW);
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_12, display_HIGH);
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_14, display_HIGH);
			GPIO_WRITE_PIN(GPIOC, GPIO_PIN_6, display_LOW);
		}
		else if(number == 4){
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_13, display_HIGH);
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_2, display_LOW);
			GPIO_WRITE_PIN(GPIOC, GPIO_PIN_5, display_LOW);
			GPIO_WRITE_PIN(GPIOA, GPIO_PIN_11, display_HIGH);
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_12, display_HIGH);
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_14, display_LOW);
			GPIO_WRITE_PIN(GPIOC, GPIO_PIN_6, display_LOW);
		}
		else if(number == 5){
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_13, display_LOW);
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_2, display_HIGH);
			GPIO_WRITE_PIN(GPIOC, GPIO_PIN_5, display_LOW);
			GPIO_WRITE_PIN(GPIOA, GPIO_PIN_11, display_LOW);
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_12, display_HIGH);
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_14, display_LOW);
			GPIO_WRITE_PIN(GPIOC, GPIO_PIN_6, display_LOW);
		}
		else if(number == 6){
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_13, display_LOW);
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_2, display_HIGH);
			GPIO_WRITE_PIN(GPIOC, GPIO_PIN_5, display_LOW);
			GPIO_WRITE_PIN(GPIOA, GPIO_PIN_11, display_LOW);
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_12, display_LOW);
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_14, display_LOW);
			GPIO_WRITE_PIN(GPIOC, GPIO_PIN_6, display_LOW);
		}
		else if(number == 7){
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_13, display_LOW);
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_2, display_LOW);
			GPIO_WRITE_PIN(GPIOC, GPIO_PIN_5, display_LOW);
			GPIO_WRITE_PIN(GPIOA, GPIO_PIN_11, display_HIGH);
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_12, display_HIGH);
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_14, display_HIGH);
			GPIO_WRITE_PIN(GPIOC, GPIO_PIN_6, display_HIGH);
		}
		else if(number == 8){
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_13, display_LOW);
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_2, display_LOW);
			GPIO_WRITE_PIN(GPIOC, GPIO_PIN_5, display_LOW);
			GPIO_WRITE_PIN(GPIOA, GPIO_PIN_11, display_LOW);
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_12, display_LOW);
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_14, display_LOW);
			GPIO_WRITE_PIN(GPIOC, GPIO_PIN_6, display_LOW);
		}
		else if(number == 9){
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_13, display_LOW);
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_2, display_LOW);
			GPIO_WRITE_PIN(GPIOC, GPIO_PIN_5, display_LOW);
			GPIO_WRITE_PIN(GPIOA, GPIO_PIN_11, display_LOW);
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_12, display_HIGH);
			GPIO_WRITE_PIN(GPIOB, GPIO_PIN_14, display_LOW);
			GPIO_WRITE_PIN(GPIOC, GPIO_PIN_6, display_LOW);
		}
}

/**
 * @brief  Writes a decimal number into the display buffer.
 * @param number  The decimal number to display (0–9999).
 * @retval None
 */
void DISPLAY_write(volatile uint16_t number){

	uint8_t partsOfNum[4] = {0};
	uint8_t scanTime = 3;

	partsOfNum[0] = number % 10; // divide parts of number
	partsOfNum[1] = (number / 10) % 10;
	partsOfNum[2] = (number / 100) % 10;
	partsOfNum[3] = (number / 1000) % 10;

	for(int i=3; i>0; i--){ // find digit number
		if(partsOfNum[i] == 0){
			scanTime--;
		}
		else{
			break;
		}
	}

	for(int i=0; i<4; i++){ // copy to buffer
		DISPLAY.digitBuffer[i] = partsOfNum[i];
	}
	DISPLAY.scanTime = scanTime;
}
