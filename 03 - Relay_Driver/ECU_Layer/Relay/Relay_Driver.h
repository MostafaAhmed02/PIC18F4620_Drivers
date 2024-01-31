/* 
 * File:   Relay_Driver.h
 * Author: Mostafa Ahmed Allam
 *Email : maag7504@gmail.com
 */
#ifndef RELAY_DRIVER_H
#define	RELAY_DRIVER_H

/* ************** Include Section ************** */
#include "../../MCAL_Layer/GPIO/HAL_GPIO.h"

/* ************** Datatype Declaration Section ************** */

typedef enum
{
    RELAY_OFF_STATUS = 0,
    RELAY_ON_STATUS
}Relay_Status_t;
typedef struct
{
    uint8 relay_port : 3;
    uint8 relay_pin : 3;
    uint8 relay_status : 1;
}Relay_t;
/* ************** Function Declaration Section ************** */
Std_ReturnType relay_initialize (Relay_t *relay);
Std_ReturnType relay_turn_on (Relay_t *relay);
Std_ReturnType relay_turn_off (Relay_t *relay);
#endif	/* RELAY_DRIVER_H */

