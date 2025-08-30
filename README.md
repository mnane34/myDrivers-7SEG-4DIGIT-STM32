# Driver Development of 7-Segment 4-Digit Display on STM32 

# ⚡ What is 7-Segment 4-Digit Display?

7-Segment 4-Digit Display is an electronic module composed of four seven-segment digits, each formed by LEDs arranged to display numbers 0–9 and some characters. It is commonly used in clocks, counters, and calculators for simple and clear numeric output. The digits are usually driven by multiplexing, which reduces power consumption while keeping the display readable.

# 🔥 How to Use an 7-Segment 4-Digit Display with Microcontrollers?

Using a 7-Segment 4-Digit Display, connect its segment and digit control pins to the microcontroller’s GPIOs. Use multiplexing to activate one digit at a time rapidly, creating the illusion that all digits are lit simultaneously. Finally, control the segments according to the number or character you want to display.

# 🛠️ Electrical Diagram

- **D1 (Digit 1 Control Pin)**<br>

Controls the first digit (leftmost). Setting HIGH or LOW (depending on common-anode/cathode) turns the digit ON or OFF.

- **D2 (Digit 2 Control Pin)**<br>

Controls the second digit. Used in multiplexing to select which digit is active.

- **D3 (Digit 3 Control Pin)**<br>

Controls the third digit. Activated during multiplexing to display its corresponding number.

- **D4 (Digit 4 Control Pin)**<br>

Controls the fourth digit. Only one digit is usually active at a time in multiplexing.

- **A (Segment A Pin)**<br>

Controls segment A of all digits, forming part of the displayed number.

- **B (Segment B Pin)**<br>

Controls segment B of all digits, forming part of the displayed number.

- **C (Segment C Pin)**<br>

Controls segment C of all digits, forming part of the displayed number.

- **D (Segment D Pin)**<br>

Controls segment D of all digits, forming part of the displayed number.

- **E (Segment E Pin)**<br>

Controls segment E of all digits, forming part of the displayed number.

- **F (Segment F Pin)**<br>

Controls segment F of all digits, forming part of the displayed number.

- **G (Segment G Pin)**<br>

Controls segment G of all digits, forming part of the displayed number.

- **DOT (Decimal Point Pin)**<br>

Controls the decimal point segment of all digits. Can be turned ON or OFF independently.

![Shematic](images/shematic.JPG)

In this application, the STM32 Nucleo F446RE development board was used. You can refer to the above wiring diagram.

# 🚀 Code Explanation

<pre><code class="language-c">void DISPLAY_init(TIM_HandleTypeDef * hTIMx, GPIO_TypeDef* D1_GPIO, uint16_t  D1_PIN,
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
</code></pre>

<pre><code class="language-c">void DISPLAY_allSegmentON(void);
</code></pre>

<pre><code class="language-c">void DISPLAY_allSegmentOFF(void);
</code></pre>

<pre><code class="language-c">void DISPLAY_allDigitsOFF(void);
</code></pre>

<pre><code class="language-c">void DISPLAY_allSegmentBlink(void);
</code></pre>

<pre><code class="language-c">void DISPLAY_selectDigit(uint8_t digit);
</code></pre>

<pre><code class="language-c">void DISPLAY_writeDigit(uint8_t number);
</code></pre>

<pre><code class="language-c">void DISPLAY_write(volatile uint16_t number);
</code></pre>

# 🖥️ Test Highlights

You can easily test the 7-Segment 4-Digit Display using the following code snippet

<pre><code class="language-c">#include "main.h"
</code></pre>

![test](images/test.jpg)

## 🎉 Thank You for Reviewing!

Thank you for taking the time to check out this project.

Feel free to follow me on these platforms for more updates and projects.

- YouTube: @mnane34

- LinkedIn: Mertcan Nane