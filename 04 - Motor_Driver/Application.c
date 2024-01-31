/* 
 * File:   Appllication.c
 * Author:  Mostafa Ahmed Allam
 * Email : maag7503@gmail.com
 */

#include"Application.h" 


dc_motor_t dc_motor1 = {
    .dc_motor_pin[0].pin = GPIO_PIN0,
    .dc_motor_pin[0].port = GPIO_PORTA,
    .dc_motor_pin[0].logic = DC_MOTOR_OFF_STATUS,
    .dc_motor_pin[0].direction = GPIO_OUTPUT,
    .dc_motor_pin[1].pin = GPIO_PIN1,
    .dc_motor_pin[1].port = GPIO_PORTA,
    .dc_motor_pin[1].logic = DC_MOTOR_OFF_STATUS,
    .dc_motor_pin[1].direction = GPIO_OUTPUT
    
};
dc_motor_t dc_motor2 = {
    .dc_motor_pin[0].pin = GPIO_PIN2,
    .dc_motor_pin[0].port = GPIO_PORTA,
    .dc_motor_pin[0].logic = DC_MOTOR_OFF_STATUS,
    .dc_motor_pin[0].direction = GPIO_OUTPUT,
    .dc_motor_pin[1].pin = GPIO_PIN3,
    .dc_motor_pin[1].port = GPIO_PORTA,
    .dc_motor_pin[1].logic = DC_MOTOR_OFF_STATUS,
    .dc_motor_pin[1].direction = GPIO_OUTPUT
    
};
Std_ReturnType ret = E_NOT_OK;
int main() {

    Std_ReturnType ret = E_NOT_OK;
    application_initialize();
    while (1)
    {
        ret = DC_Motor_Move_Left(&dc_motor1);
        ret = DC_Motor_Move_Left(&dc_motor2);
        __delay_ms(3000);
        ret = DC_Motor_Move_Right(&dc_motor1);
        ret = DC_Motor_Move_Right(&dc_motor2);
        __delay_ms(3000);
        
        ret = DC_Motor_Stop(&dc_motor1);
        ret = DC_Motor_Stop(&dc_motor2);
        __delay_ms(3000);
        ret = DC_Motor_Move_Right(&dc_motor1);
        ret = DC_Motor_Move_Left(&dc_motor2);
        __delay_ms(3000);
        ret = DC_Motor_Move_Right(&dc_motor2);
        ret = DC_Motor_Move_Left(&dc_motor1);
        __delay_ms(3000);
        
    }
    return 0;
}

void application_initialize(void)
{
    Std_ReturnType ret = E_NOT_OK;
    ret = DC_Motor_Initialize(&dc_motor1);
    ret = DC_Motor_Initialize(&dc_motor2);
}

