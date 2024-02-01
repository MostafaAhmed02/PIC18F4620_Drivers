/* 
 * File:   Motor_Driver.h
 * Author: Mostafa Ahmed
 * Email : maag7503@gmail.com
 */

#ifndef ECU_MOTOR_H
#define	ECU_MOTOR_H


/* ************** Include Section ************** */
#include "../../MCAL_Layer/GPIO/HAL_GPIO.h" 

/* ************** Macro Declarations ************** */

#define  DC_MOTOR_ON_STATUS       0X01U       
#define  DC_MOTOR_OFF_STATUS      0X00U 

#define  DC_MOTOR_PIN_1          0X00U 
#define  DC_MOTOR_PIN_2          0X01U 

/* ********* Datatype Declarations ********* */

/* You can remove this struct and treat with 
    pin config only as shown in vid06 in the lectures */

/*We have two pins in DC motor so we used this struct. */
typedef struct 
{
    Pin_Config_t   dc_motor_pin[2];
    
}dc_motor_t;


/* ********* Function Declarations ********* */


/* ********* Software interfaces ********* */

Std_ReturnType      DC_Motor_Initialize(const dc_motor_t *_dc_motor);
Std_ReturnType      DC_Motor_Move_Right(const dc_motor_t *_dc_motor);
Std_ReturnType      DC_Motor_Move_Left (const dc_motor_t *_dc_motor);
Std_ReturnType      DC_Motor_Stop(const dc_motor_t *_dc_motor);
#endif	/* ECU_MOTOR_H */

