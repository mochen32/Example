#include "Shift.h"

void Shift_GPIO_Config(void)
{		
		
		GPIO_InitTypeDef GPIO_InitStructure;

		// ¿ªÆôGPIOBµÄÊ±ÖÓ
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE); 
	
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		GPIO_Init(GPIOA, &GPIO_InitStructure);	

	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		GPIO_Init(GPIOA, &GPIO_InitStructure);	

		GPIO_ResetBits(GPIOA, GPIO_Pin_0); 
	  GPIO_ResetBits(GPIOA, GPIO_Pin_1);
}


void Send_164(uint8_t Data)
{
   uint8_t  i,num;
	 num = Data;
	 PAout(4)=0;
	 for(i=0;i<8;i++)
	  {
			 PAout(4)= 0;
	     if((num & 0x80)==0x80)
				 PAout(5)=1;	
			 else   
         PAout(5)=0;			 
			 PAout(4)=1;			 
       num = num<<1;	
 		 
	  }	
}


void Delay_us(uint32_t us)
{
	uint32_t i;
	SysTick_Config(72);
	
	for(i=0; i<us; i++)
	{
		while( !((SysTick->CTRL) & (1<<16)) );
	}
	
	SysTick->CTRL &= ~ SysTick_CTRL_ENABLE_Msk;
}


void Delay_ms(uint32_t ms)
{
	uint32_t i;
	SysTick_Config(72000);
	
	for(i=0; i<ms; i++)
	{
		while( !((SysTick->CTRL) & (1<<16)) );
	}	
	SysTick->CTRL &= ~ SysTick_CTRL_ENABLE_Msk;
}


