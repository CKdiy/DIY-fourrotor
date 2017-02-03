/*
* 文件名             : fr_sys.c
* Author             : ck
* Date               : 2016/12/5
* Description        : 系统中断分组设置
*                       
* HISTORY:
* Date               
* 2016/12/5          : 
*/


/* Includes ------------------------------------------------------------------*/
#include "fr_sys.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

void Rf_NVIC_Configuration(void)
{
    NVIC_PriorityGroupConfig( NVIC_PriorityGroup_2 );
}
