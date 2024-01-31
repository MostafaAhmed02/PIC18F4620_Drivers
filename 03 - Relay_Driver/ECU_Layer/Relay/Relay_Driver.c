/* 
 * File:   Relay_Driver.c
 * Author: Mostafa Ahmed Allam
 *Email : maag7504@gmail.com
 */
/* ************** Include Section ************** */
#include "Relay_Driver.h"

/* ************** Function Definition Section ************** */
Std_ReturnType relay_initialize(Relay_t *relay) {

    Std_ReturnType ret = E_NOT_OK;
    
    if (NULL == relay) {
        ret = E_NOT_OK;
    } else {
        Pin_Config_t relay_pin = {
        .direction = GPIO_OUTPUT,
        .logic = relay->relay_status,
        .pin = relay->relay_pin,
        .port = relay->relay_port
    };
        ret = gpio_pin_initialize(&relay_pin);
        ret = E_OK;
    }
    return ret;
}

Std_ReturnType relay_turn_on(Relay_t *relay) {
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == relay) {
        ret = E_NOT_OK;
    } else {
        Pin_Config_t relay_pin = {
            .direction = GPIO_OUTPUT,
            .logic = relay->relay_status,
            .pin = relay->relay_pin,
            .port = relay->relay_port
        };
        
        ret = gpio_pin_write_logic(&relay_pin,GPIO_HIGH);
        ret = E_OK;
    }
    return ret;
}

Std_ReturnType relay_turn_off(Relay_t *relay) {
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == relay) {
        ret = E_NOT_OK;
    } else {
        Pin_Config_t relay_pin = {
            .direction = GPIO_OUTPUT,
            .logic = relay->relay_status,
            .pin = relay->relay_pin,
            .port = relay->relay_port
        };
        
        ret = gpio_pin_write_logic(&relay_pin,GPIO_LOW);
        ret = E_OK;
    }
    return ret;
}
