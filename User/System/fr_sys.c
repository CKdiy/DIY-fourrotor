/*
* �ļ���             : fr_sys.c
* Author             : ck
* Date               : 2016/12/5
* Description        : ϵͳ�жϷ�������
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
