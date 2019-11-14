#include "stm32f10x.h"                  // Device header
#define delay for(int i=0;i<5000000;i++)
#define GPIO_ODR_ODR13                       ((uint16_t)0x2000)
void GPIO_Init();
int main ()
{
	GPIO_Init();
	while(1)
	{
		GPIOC->ODR^=GPIO_ODR_ODR13;
		delay;
	}
}

void GPIO_Init()
{
	RCC->APB2ENR|=RCC_APB2ENR_IOPCEN;
  GPIOC->CRH|=(GPIO_CRH_MODE13);	
	//GPIOA->CRH&=~(GPIO_CRH_CNF13);
}

