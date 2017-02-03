/*
* File Name          : drv_pwm.h
* Author             : ck
* Date               : 2016/12/11
* Description        : 
*                       
* HISTORY:
* Date               
* 2016/12/11          : 
*/

#ifndef DRV_PWM__H
#define DRV_PWM__H

/* Includes ------------------------------------------------------------------*/
#include "fr_sys.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

void Tim1_Pwm_INIT(u16 pwm_period, u16 pwm_prescaler);

#endif
