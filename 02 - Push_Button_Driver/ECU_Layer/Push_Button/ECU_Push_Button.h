/* 
 * File:   ECU_Push_Button.h
 * Author: Mostafa Ahmed Allam
 *Email : maag7504@gmail.com
 */

#ifndef ECU_PUSH_BUTTON_H
#define	ECU_PUSH_BUTTON_H

/* ************** Include Section ************** */
#include "../../MCAL_Layer/GPIO/HAL_GPIO.h"
/* ************** Function Definition Section ************** */
/* ************** Macro Section ************** */
/* ************** Macro Function Section ************** */
/* ************** Datatype Declaration Section ************** */
typedef enum
{
  BUTTON_PRESSED = 0,
  BUTTON_RELEASED  
}Button_state_t;

typedef enum
{
    BUTTON_ACTIVE_LOW = 0,
    BUTTON_ACTIVE_HIGH
}Button_logic_t;

typedef struct 
{
    Pin_Config_t button_pin ;
    Button_state_t button_status;
    Button_logic_t button_logic;
    
}Button_t;
/* ************** Function Declaration Section ************** */
Std_ReturnType button_initialize (const Button_t *Button);
Std_ReturnType button_read_state (const Button_t *Button ,Button_state_t *btn_state);

#endif	/* ECU_PUSH_BUTTON_H */

