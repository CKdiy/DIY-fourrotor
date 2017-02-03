/*
* 文件名             : drv_pwm.c
* Author             : ck
* Date               : 2016/12/11
* Description        : Tim1 4路PWM驱动
*                       
* HISTORY:
* Date               
* 2016/12/11         : 
*/

/* -----------------------Set the reference-------------------------------
   TIM3 Configuration: generate 4 PWM signals with 4 different duty cycles:
    The TIM3CLK frequency is set to SystemCoreClock (Hz), to get TIM3 counter
    clock at 24 MHz the Prescaler is computed as following:
	- Prescaler = (TIM3CLK / TIM3 counter clock) - 1
    SystemCoreClock is set to 72 MHz for Low-density, Medium-density, High-density
    and Connectivity line devices and to 24 MHz for Low-Density Value line and
    Medium-Density Value line devices
	
    The TIM3 is running at 36 KHz: TIM3 Frequency = TIM3 counter clock/(ARR + 1)
	= 24 MHz / 1000 = 24 KHz
    TIM3 Channel1 duty cycle = (TIM3_CCR1/ TIM3_ARR)* 100 = 50%
    TIM3 Channel2 duty cycle = (TIM3_CCR2/ TIM3_ARR)* 100 = 37.5%
    TIM3 Channel3 duty cycle = (TIM3_CCR3/ TIM3_ARR)* 100 = 25%
    TIM3 Channel4 duty cycle = (TIM3_CCR4/ TIM3_ARR)* 100 = 12.5%
----------------------------------------------------------------------------- */

/* Includes ------------------------------------------------------------------*/
#include "drv_pwm.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* 初始化Tim1 4路PWM输出脚*/
void Tim1_PwmPin_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 ; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}
/****************************************************  
   Description : pwm_period     自动重装载值 
                 pwm_prescaler  预分频 
   PWM frequence = 72M / pwm_prescaler  / pwm_period
*****************************************************/
void Tim1_Pwm_INIT(u16 pwm_period, u16 pwm_prescaler)
{
    TIM_TimeBaseInitTypeDef		    TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  				TIM_OCInitStructure;    
    
    Tim1_PwmPin_Init();
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
      
    /* 初始化Tim1 */    
	TIM_TimeBaseStructure.TIM_Period         = pwm_period;		
	TIM_TimeBaseStructure.TIM_Prescaler      = pwm_prescaler;	
	TIM_TimeBaseStructure.TIM_ClockDivision  = 0;	
	TIM_TimeBaseStructure.TIM_CounterMode    = TIM_CounterMode_Up;		
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
    
    /* 初始化通道为pwm模式 */
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    /* 比较输出使能 */
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    /* 初始占空比 */
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    
	TIM_OC1Init(TIM1, &TIM_OCInitStructure); 
    /* 启用预装载寄存器 */
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);
    
	TIM_OC2Init(TIM1, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);
    
    TIM_OC3Init(TIM1, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);
    
    TIM_OC4Init(TIM1, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable);   
  
  /* 启用输出 */
//  TIM_CtrlPWMOutputs(TIM1, ENABLE);
//	TIM_ARRPreloadConfig(TIM1, ENABLE);
    
	TIM_Cmd(TIM1, ENABLE);    
}

