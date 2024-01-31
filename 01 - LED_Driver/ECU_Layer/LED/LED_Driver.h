/* 
 * File:   LED_Driver.h
 * Author: Mostafa Ahmed Allam
 *Email : maag7504@gmail.com
 */

#ifndef LED_DRIVER_H
#define	LED_DRIVER_H


/* ************** Include Section ************** */
#include "LED_Driver_CFG.h"
#include "../LED/../../MCAL_Layer/GPIO/HAL_GPIO.h"

/* ************** Macro Section ************** */
/* ************** Datatype Declaration Section ************** */
typedef enum
{
    LED_OFF = 0,
    LED_ON
}LED_Status_t;

typedef struct
{
    uint8 LED_port :3;
    uint8 LED_pin : 3;
    uint8 LED_status:1;
}LED_Config_t;

/* ************** Function Declaration Section ************** */
Std_ReturnType LED_initialize       (const LED_Config_t *led);
Std_ReturnType LED_turn_on          (const LED_Config_t *led);
Std_ReturnType LED_turn_off         (const LED_Config_t *led);
Std_ReturnType LED_toggle           (const LED_Config_t *led);
#endif	/* LED_DRIVER_H */

