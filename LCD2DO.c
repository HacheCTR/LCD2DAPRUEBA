#include "LCD.h"


uint32_t uWriteConstant = 10;
uint8_t uBitMode = 1;
uint8_t uDisplayControl = 0x0F;
uint8_t uFunctionSet = 0x38;

void vEnablePulse(void)
{
	HAL_GPIO_WritePin(RS_GPIO_PORT, RS_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(E_GPIO_PORT, E_PIN, GPIO_PIN_SET);
	TimeDelay(uWriteConstant);
	HAL_GPIO_WritePin(RS_GPIO_PORT, RS_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(E_GPIO_PORT, E_PIN, GPIO_PIN_RESET);
	TimeDelay(60);
}
void vRSandE(bool state)
{
	if(state)
	{
		HAL_GPIO_WritePin(RS_GPIO_PORT, RS_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(E_GPIO_PORT, E_PIN, GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(RS_GPIO_PORT, RS_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(E_GPIO_PORT, E_PIN, GPIO_PIN_RESET);
	}
}
void vWriteBits(uint8_t byte)
{
	uint8_t uPines0_3 = byte&0xF, uPines4_7 = (byte>>4)&0xF;

	if(uBitMode == 1)
	{
		HAL_GPIO_WritePin(D0_GPIO_PORT, D0_PIN, (GPIO_PinState)(uPines0_3&0x1));
		HAL_GPIO_WritePin(D1_GPIO_PORT, D1_PIN, (GPIO_PinState)(uPines0_3&0x2));
		HAL_GPIO_WritePin(D2_GPIO_PORT, D2_PIN, (GPIO_PinState)(uPines0_3&0x4));
		HAL_GPIO_WritePin(D3_GPIO_PORT, D3_PIN, (GPIO_PinState)(uPines0_3&0x8));
		HAL_GPIO_WritePin(D4_GPIO_PORT, D4_PIN, (GPIO_PinState)(uPines4_7&0x1));
		HAL_GPIO_WritePin(D5_GPIO_PORT, D5_PIN, (GPIO_PinState)(uPines4_7&0x2));
		HAL_GPIO_WritePin(D6_GPIO_PORT, D6_PIN, (GPIO_PinState)(uPines4_7&0x4));
		HAL_GPIO_WritePin(D7_GPIO_PORT, D7_PIN, (GPIO_PinState)(uPines4_7&0x8));

		vEnablePulse();
	}
}
void uWriteCommand(uint8_t command)
{
	//Set RS to 0
	vRSandE(false);
	//Call low level write parallel function
	vWriteBits(command);
}
//6) Write 8 bits data
void uWriteData(uint8_t data)
{
	//Set RS to 1
	vRSandE(true);
	//Call low level write parallel function
	vWriteBits(data);
}
