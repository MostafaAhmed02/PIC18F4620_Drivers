/* 
 * File:   Appllication.c
 * Author:  Mostafa Ahmed Allam
 * Email : maag7503@gmail.com
 */

#include"Application.h"



LED_Config_t led_RC0 = {.LED_pin = GPIO_PIN0,.LED_port = GPIO_PORTC,.LED_status = GPIO_HIGH};
LED_Config_t led_RC1 = {.LED_pin = GPIO_PIN1,.LED_port = GPIO_PORTC,.LED_status = GPIO_HIGH};
LED_Config_t led_RC2 = {.LED_pin = GPIO_PIN2,.LED_port = GPIO_PORTC,.LED_status = GPIO_HIGH};
LED_Config_t led_RC3 = {.LED_pin = GPIO_PIN3,.LED_port = GPIO_PORTC,.LED_status = GPIO_HIGH};


//Pin_Config_t pin = {
//    .direction = , 
//    .logic = ,
//    .pin = ,
//    .
//    
//};
    Std_ReturnType ret = E_NOT_OK;
int main() {
    
    application_initialize(); 
    while (1)
    {
        
        LED_turn_on(&led_RC0);
        LED_turn_off(&led_RC1);
        LED_turn_off(&led_RC2);
        LED_turn_off(&led_RC3);
        __delay_ms(1000);
        LED_toggle(&led_RC0);
        LED_toggle(&led_RC1);
        LED_toggle(&led_RC2);
        LED_toggle(&led_RC3);
        __delay_ms(1000);
        LED_turn_off(&led_RC0);
        LED_turn_on(&led_RC1);
        LED_toggle(&led_RC2);
        LED_turn_on(&led_RC3);
        __delay_ms(1000);
    }
    return 0;
}
void application_initialize(void)
{
    Std_ReturnType ret = E_NOT_OK;
    ret = LED_initialize(&led_RC0);
    ret = LED_initialize(&led_RC1);
    ret = LED_initialize(&led_RC2);
    ret = LED_initialize(&led_RC3);
        
}
