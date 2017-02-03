/*
* File Name          : fr_delay.h
* Author             : ck
* Date               : 2016/12/5
* Description        : 
*                       
* HISTORY:
* Date               
* 2016/12/5          : 
*/

#ifndef FR_DELAY__H
#define FR_DELAY__H

/* Includes ------------------------------------------------------------------*/
#include "fr_sys.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

void SYStem_Init(void);
void delay_us(u32 nus); 
void delay_ms(u16 nus); 

#endif
