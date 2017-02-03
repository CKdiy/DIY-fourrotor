
#include "fr_sys.h"
#include "include.h"
#include "drv_led.h"

void SYS_INIT(void)
{
    SYStem_Init();
    Rf_NVIC_Configuration();
    Led_Gpio_Init();   
}

int main(void)
{    
    SYS_INIT();
    while(1)
    {        
        LED2_B = 0;
        delay_ms(500);
        LED2_B = 1;
    } 
    return 1;
}
