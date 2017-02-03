/*
* File Name          : drv_led.h
* Author             : ck
* Date               : 2016/12/10
* Description        : 
*                       
* HISTORY:
* Date               
* 2017/01/26         : ÕÍ…∆led∫Í∂®“Â
*/

#ifndef DRV_LED__H
#define DRV_LED__H

/* Includes ------------------------------------------------------------------*/
#include "fr_sys.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

#define LED1_R PCout(13) 
#define LED2_B PCout(14) 
#define LED3_R PCout(15) 

#define LED4_B PBout(15) 
#define LED5_R PBout(14)
#define LED6_B PBout(13) 
#define LED7_R PBout(9)
#define LED8_B PBout(8) 
#define LED_USER PBout(12) 

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

void Led_Gpio_Init(void);

#endif
