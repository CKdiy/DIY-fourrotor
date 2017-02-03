/*
* �ļ���             : fr_delay.c
* Author             : ck
* Date               : 2016/12/10
* Description        : ϵͳ��ʱ
*                       
* HISTORY:
* Date               
* 2016/12/5          : 
*/

/* Includes ------------------------------------------------------------------*/
#include "fr_delay.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

static u8  fac_us=0;//us��ʱ������
static u16 fac_ms=0;//ms��ʱ������

/* Private function prototypes -----------------------------------------------*/

/* SYSTICK��ʱ�ӹ̶�ΪHCLKʱ�ӵ�1/8 */   
void SYStem_Init(void)
{
    /* ϵͳʱ�ӵ�1/8  72M/8=9M  ÿ����һ�ξ���1/9us */
    SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
    fac_us=SystemCoreClock/8000000;  
    fac_ms=fac_us*1000;   
}

void delay_us(u32 nus)
{		
	u32 temp;	    	 
	SysTick->LOAD=nus*fac_us; //ʱ�����	  		 
	SysTick->VAL=0x00;        //��ռ�����
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;          //��ʼ����	 
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));//�ȴ�ʱ�䵽��   
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;       //�رռ�����
	SysTick->VAL =0X00;       //��ռ�����	 
}

void delay_ms(u16 nms)
{	 		  	  
	u32 temp;		   
	SysTick->LOAD=(u32)nms*fac_ms;//ʱ�����(SysTick->LOADΪ24bit)
	SysTick->VAL =0x00;           //��ռ�����
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;          //��ʼ����  
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));//�ȴ�ʱ�䵽��   
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;       //�رռ�����
	SysTick->VAL =0X00;       //��ռ�����	  	    
} 
