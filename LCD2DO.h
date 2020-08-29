#include <stdbool.h>
#include "stm32f4xx_hal.h"
#include <stdlib.h>

#define RS_PIN           GPIO_PIN_1
#define RS_GPIO_PORT     GPIOB

#define WR_PIN           GPIO_PIN_2
#define WR_GPIO_PORT     GPIOB

#define E_PIN            GPIO_PIN_3
#define E_GPIO_PORT      GPIOB

#define D0_PIN           GPIO_PIN_4
#define D0_GPIO_PORT     GPIOB

#define D1_PIN           GPIO_PIN_5
#define D1_GPIO_PORT     GPIOB

#define D2_PIN           GPIO_PIN_6
#define D2_GPIO_PORT     GPIOB

#define D3_PIN           GPIO_PIN_7
#define D3_GPIO_PORT     GPIOB

#define D4_PIN           GPIO_PIN_8
#define D4_GPIO_PORT     GPIOB

#define D5_PIN           GPIO_PIN_9
#define D5_GPIO_PORT     GPIOB

#define D6_PIN           GPIO_PIN_10
#define D6_GPIO_PORT     GPIOB

#define D7_PIN           GPIO_PIN_0
#define D7_GPIO_PORT     GPIOB
//PINS STATE OFF
#define  RS_OFF			 HAL_GPIO_WritePin(RS_GPIO_PORT, RS_PIN, 	GPIO_PIN_RESET)
#define  WR_OFF			 HAL_GPIO_WritePin(WR_GPIO_PORT, WR_PIN, 	GPIO_PIN_RESET)
#define  E_OFF           HAL_GPIO_WritePin(E_GPIO_PORT , E_PIN, 	GPIO_PIN_RESET)
#define  D0_OFF      	 HAL_GPIO_WritePin(D0_GPIO_PORT, D0_PIN,  	GPIO_PIN_RESET)
#define  D1_OFF      	 HAL_GPIO_WritePin(D1_GPIO_PORT, D1_PIN, 	GPIO_PIN_RESET)
#define  D2_OFF     	 HAL_GPIO_WritePin(D2_GPIO_PORT, D2_PIN,  	GPIO_PIN_RESET)
#define  D3_OFF      	 HAL_GPIO_WritePin(D3_GPIO_PORT, D3_PIN,  	GPIO_PIN_RESET)
#define  D4_OFF      	 HAL_GPIO_WritePin(D4_GPIO_PORT, D4_PIN,  	GPIO_PIN_RESET)
#define  D5_OFF      	 HAL_GPIO_WritePin(D5_GPIO_PORT, D5_PIN, 	GPIO_PIN_RESET)
#define  D6_OFF     	 HAL_GPIO_WritePin(D6_GPIO_PORT, D6_PIN,  	GPIO_PIN_RESET)
#define  D7_OFF      	 HAL_GPIO_WritePin(D7_GPIO_PORT, D7_PIN,  	GPIO_PIN_RESET)
//PINS STATE ON
#define  RS_ON			 HAL_GPIO_WritePin(RS_GPIO_PORT, RS_PIN, 	GPIO_PIN_SET)
#define  WR_ON			 HAL_GPIO_WritePin(WR_GPIO_PORT, WR_PIN, 	GPIO_PIN_SET)
#define  E_ON            HAL_GPIO_WritePin(E_GPIO_PORT , E_PIN, 	GPIO_PIN_SET)
#define  D0_ON      	 HAL_GPIO_WritePin(D0_GPIO_PORT, D0_PIN,  	GPIO_PIN_SET)
#define  D1_ON      	 HAL_GPIO_WritePin(D1_GPIO_PORT, D1_PIN, 	GPIO_PIN_SET)
#define  D2_ON     	     HAL_GPIO_WritePin(D2_GPIO_PORT, D2_PIN,  	GPIO_PIN_SET)
#define  D3_ON      	 HAL_GPIO_WritePin(D3_GPIO_PORT, D3_PIN,  	GPIO_PIN_SET)
#define  D4_ON      	 HAL_GPIO_WritePin(D4_GPIO_PORT, D4_PIN,  	GPIO_PIN_SET)
#define  D5_ON      	 HAL_GPIO_WritePin(D5_GPIO_PORT, D5_PIN, 	GPIO_PIN_SET)
#define  D6_ON     	     HAL_GPIO_WritePin(D6_GPIO_PORT, D6_PIN,  	GPIO_PIN_SET)
#define  D7_ON      	 HAL_GPIO_WritePin(D7_GPIO_PORT, D7_PIN,  	GPIO_PIN_SET)
//COMMANDS
#define CLEARDISPLAY 						0x01
#define RETURNHOME 							0x02
#define ENTRYMODESET 						0x04
#define DISPLAYCONTROL 						0x08
#define CURSORSHIFT 						0x10
#define FUNCTIONSET 						0x20
#define SETCGRAMADDR 						0x40
#define SETDDRAMADDR 						0x80
//INSTRUCTIONS MODES
#define ENTRY_SH		 					0x01
#define ENTRY_ID 							0x02
//Entry mode
#define ENTRY_SH		 					0x01
#define ENTRY_ID 							0x02
//Display control
#define DISPLAY_B							0x01
#define DISPLAY_C							0x02
#define DISPLAY_D							0x04
//Shift control
#define LCD_SHIFT_RL						0x04
#define LCD_SHIFT_SC						0x08
//Function set control
#define FUNCTION_F							0x04
#define FUNCTION_N							0x08
#define FUNCTION_DL							0x10
//FUNCTIONS
void vEnablePulse(void);
void vRSandE(bool state);
void vWriteBits(uint8_t byte);
void uWriteCommand(uint8_t command);
void uWriteData(uint8_t data);

