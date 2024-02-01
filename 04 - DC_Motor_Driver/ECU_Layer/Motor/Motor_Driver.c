/* 
 * File:   Motor_Driver.c
 * Author: Mostafa Ahmed
 * Email : maag7503@gmail.com
 */


#include "Motor_Driver.h"

Std_ReturnType      DC_Motor_Initialize(const dc_motor_t *_dc_motor)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _dc_motor)
    {
        ret = E_NOT_OK;
    }
    else
    {

        
//        Pin_Config_t dc_motor_pin2 = {
//            .direction = GPIO_OUTPUT,
//            .logic = _dc_motor->dc_motor[1].dc_motor_status,
//            .pin = _dc_motor->dc_motor[1].dc_motor_pin,
//            .port = _dc_motor->dc_motor[1].dc_motor_port
//        };
        
        gpio_pin_initialize(&(_dc_motor->dc_motor_pin[DC_MOTOR_PIN_1]));
        gpio_pin_initialize(&(_dc_motor->dc_motor_pin[DC_MOTOR_PIN_2]));
        ret = E_OK;
    }
    return ret;
}
Std_ReturnType      DC_Motor_Move_Right(const dc_motor_t *_dc_motor)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _dc_motor)
    {
        ret = E_NOT_OK;
    }
    else
    {

        
        gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[DC_MOTOR_PIN_1]),GPIO_HIGH);
        gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[DC_MOTOR_PIN_2]),GPIO_LOW);
        ret = E_OK;
    }
    return ret;
}
Std_ReturnType      DC_Motor_Move_Left (const dc_motor_t *_dc_motor)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _dc_motor)
    {
        ret = E_NOT_OK;
    }
    else
    {

        gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[DC_MOTOR_PIN_1]),GPIO_LOW);
        gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[DC_MOTOR_PIN_2]),GPIO_HIGH);
        ret = E_OK;
    }
    return ret;
}
Std_ReturnType      DC_Motor_Stop(const dc_motor_t *_dc_motor)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _dc_motor)
    {
        ret = E_NOT_OK;
    }
    else
    {
        gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[DC_MOTOR_PIN_1]),GPIO_LOW);
        gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[DC_MOTOR_PIN_2]),GPIO_LOW);
        ret = E_OK;
    }
    return ret;
}