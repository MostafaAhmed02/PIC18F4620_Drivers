/* 
 * File:   Appllication.c
 * Author:  Mostafa Ahmed Allam
 * Email : maag7503@gmail.com
 */

#include"Application.h"


Relay_t relay1 ={
    .relay_port = GPIO_PORTC,
    .relay_pin = GPIO_PIN0,
    .relay_status = RELAY_OFF_STATUS
};

int main() {

    Std_ReturnType ret = E_NOT_OK;
    ret = relay_initialize(&relay1);
    
    while (1) {
        ret = relay_turn_on(&relay1);
        __delay_ms(5000);
        ret = relay_turn_off(&relay1);
        __delay_ms(5000);
    }
    return 0;
}

