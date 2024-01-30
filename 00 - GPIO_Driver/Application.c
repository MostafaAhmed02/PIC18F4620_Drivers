/* 
 * File:   Appllication.c
 * Author:  Mostafa Ahmed Allam
 * Email : maag7503@gmail.com
 */

#include"Application.h"



Pin_Config_t test0 = {
   .direction = GPIO_OUTPUT,
   .logic = GPIO_LOW,
   .pin = GPIO_PIN0,
   .port = GPIO_PORTC
};

Std_ReturnType ret = E_NOT_OK;
int main() {
    ret = gpio_pin_initialize(&test0);
    while(1)
    {
        ret = gpio_pin_write_logic(&test0,GPIO_HIGH);
        __delay_ms(1000);
        ret = gpio_pin_write_logic(&test0,GPIO_LOW);
        __delay_ms(1000);
    }
    return 0;
}

