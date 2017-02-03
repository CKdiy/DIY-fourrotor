/*
* 文件名             : drv_led.c
* Author             : ck
* Date               : 2016/12/10
* Description        : LED IO口驱动
*                       
* HISTORY:
* Date               
* 2017/01/26         : 完善led驱动
*/


/* Includes ------------------------------------------------------------------*/
#include "drv_led.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

void Led_Gpio_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct; 
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    
    /* LED1~LED3 */    
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;   //推挽输出
    GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
    GPIO_InitStruct.GPIO_Speed= GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStruct); 
    GPIO_SetBits(GPIOC, GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15); //输出高
      
    /* LED4~LED8 */
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_11|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
    GPIO_InitStruct.GPIO_Speed= GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStruct); 
    GPIO_SetBits(GPIOB, GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_11|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);    
}
