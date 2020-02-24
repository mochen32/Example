 
#include "stm32f10x.h"
#include "bsp_usart.h"
#include "Shift.h"

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{	
	uint8_t Num;
	uint8_t i;
  USART_Config();
	Shift_GPIO_Config();
  while(1)
	{	
    Num=0x1;		
		for(i=0;i<255;i++)
		{
		  Send_164(Num);
			Delay_ms(500);
			Num=Num+1;
		}
	}	
}


