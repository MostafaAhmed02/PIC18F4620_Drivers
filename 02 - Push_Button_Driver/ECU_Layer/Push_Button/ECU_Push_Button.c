/* 
 * File:   ECU_Push_Button.c
 * Author: Mostafa Ahmed Allam
 *Email : maag7504@gmail.com
 */

/* ************** Include Section ************** */
#include "ECU_Push_Button.h"

/* ************** Function Definition Section ************** */
Std_ReturnType button_initialize (const Button_t *Button)
{
    
   Std_ReturnType ret = E_OK;
    if(NULL == Button){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_directoin_initialize(&(Button->button_pin));
    }
    return ret;
}

Std_ReturnType button_read_state (const Button_t *Button ,Button_state_t *btn_state)
{
    Std_ReturnType ret = E_NOT_OK;
    Logic_t Pin_Logic_Status = GPIO_LOW;
    if((NULL == Button) || (NULL == btn_state)){
        ret = E_NOT_OK;
    }
    else{
        gpio_pin_read_logic(&(Button->button_pin), &Pin_Logic_Status);
        if(BUTTON_ACTIVE_HIGH == Button->button_logic){
            if(GPIO_HIGH == Pin_Logic_Status){
                *btn_state = BUTTON_PRESSED;
            }
            else{
                *btn_state = BUTTON_RELEASED;
            }
        }
        else if(BUTTON_ACTIVE_LOW == Button->button_logic){
            if(GPIO_HIGH == Pin_Logic_Status){
                *btn_state = BUTTON_RELEASED;
            }
            else{
                *btn_state = BUTTON_PRESSED;
            }
        }
        else { /* Nothing */ }
        ret = E_OK;
    }
    return ret;
}