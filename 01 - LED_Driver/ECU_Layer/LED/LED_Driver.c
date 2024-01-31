/* 
 * File:   LED_Driver.h
 * Author: Mostafa Ahmed Allam
 *Email : maag7504@gmail.com
 */


/* ************** Include Section ************** */
#include "LED_Driver.h"

/* ************** Function Definition Section ************** */
Std_ReturnType LED_initialize       (const LED_Config_t *led)
{
    Std_ReturnType ret = E_OK;
    
    
    if(NULL == led)
    {
        ret = E_NOT_OK;
    }
    else
    {
        Pin_Config_t pin_config = {
        .direction = GPIO_OUTPUT, .logic = led->LED_status,
        .pin = led->LED_pin,      .port = led->LED_port
    };        ret = gpio_pin_initialize(&pin_config);

    }
    return ret;
}
Std_ReturnType LED_turn_on          (const LED_Config_t *led)
{
    Std_ReturnType ret = E_OK;
    if(NULL == led)
    {
        ret = E_NOT_OK;
    }
    else
    {
        Pin_Config_t pin_config = {
        .direction = GPIO_OUTPUT, .logic = led->LED_status,
        .pin = led->LED_pin, .port = led->LED_port
    };
        ret = gpio_pin_write_logic(&pin_config,GPIO_HIGH);
    }
    return ret;
}

Std_ReturnType LED_turn_off         (const LED_Config_t *led)
{
    Std_ReturnType ret = E_OK;;
    if(NULL == led)
    {
        ret = E_NOT_OK;
    }
    else
    {
        Pin_Config_t pin_config = {
        .direction = GPIO_OUTPUT, .logic = led->LED_status,
        .pin = led->LED_pin, .port = led->LED_port
    };
        ret = gpio_pin_write_logic(&pin_config,GPIO_LOW);
    }
    return ret;
}

Std_ReturnType LED_toggle           (const LED_Config_t *led)
{
    Std_ReturnType ret = E_OK;
    if(NULL == led)
    {
        ret = E_NOT_OK;
    }
    else
    {
        Pin_Config_t pin_config = {
        .direction = GPIO_OUTPUT, .logic = led->LED_status,
        .pin = led->LED_pin, .port = led->LED_port
    };
        ret = gpio_pin_toggle(&pin_config);

    }
    return ret;
}

/* ************** Macro Section ************** */
/* ************** Macro Function Section ************** */
/* ************** Datatype Declaration Section ************** */