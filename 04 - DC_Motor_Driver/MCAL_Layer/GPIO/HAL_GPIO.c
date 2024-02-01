/* 
 * File:   HAL_GPIO.c
 * Author:  Mostafa Ahmed Allam
 * Email : maag7503@gmail.com
 */

#include "HAL_GPIO.h"



volatile uint8 *Tris_Register [MAX_PORT_NUMBER] = {&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};
volatile uint8 *Lat_Register  [MAX_PORT_NUMBER] = {&LATA,&LATB,&LATC,&LATD,&LATE};
volatile uint8 *Port_Register [MAX_PORT_NUMBER] = {&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};


Std_ReturnType gpio_pin_initialize              (const Pin_Config_t *pin)
{
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL == pin)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_directoin_initialize(pin);
        ret = gpio_pin_write_logic(pin,pin->logic);
        ret = E_OK;
    }
    return ret;
}
Std_ReturnType gpio_pin_directoin_initialize    (const Pin_Config_t *pin)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == pin)
    {
        ret = E_NOT_OK;
    }
    
    switch(pin->direction)
    {
        case GPIO_OUTPUT: 
            CLEAR_BIT(*Tris_Register[pin->port],pin->pin);
            ret = E_OK;
            break;
            
        case GPIO_INPUT: 
            SET_BIT(*Tris_Register[pin->port],pin->pin);
            ret = E_OK;
            break;
            
        default:    ret = E_NOT_OK;
    }
    return ret;
}
Std_ReturnType gpio_pin_read_direction          (const Pin_Config_t *pin, Direction_t *dir)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == pin || NULL == dir)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *dir = READ_BIT(*Tris_Register[pin->port],pin->pin);
        ret = E_OK;
    }
    return ret;
}
Std_ReturnType gpio_pin_write_logic             (const Pin_Config_t *pin, Logic_t logic)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == pin)
    {
        ret = E_NOT_OK;
    }
    switch(logic)
    {
        case GPIO_LOW:
            CLEAR_BIT(*Lat_Register[pin->port],pin->pin);
            ret = E_OK;
            break;
        case GPIO_HIGH:
            SET_BIT(*Lat_Register[pin->port],pin->pin);
            ret = E_OK;
            break;
        default: ret = E_NOT_OK;
    }
    return ret;
}
Std_ReturnType gpio_pin_read_logic              (const Pin_Config_t *pin, Logic_t *logic)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == pin || NULL == logic)
    {
        ret = E_NOT_OK;
    }
    else
    {
        * logic = READ_BIT(*Port_Register[pin->port],pin->pin);    
        ret = E_OK;
    }
    return ret;
}
Std_ReturnType gpio_pin_toggle                  (const Pin_Config_t *pin)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == pin)
    {
        ret = E_NOT_OK;
    }
    else
    {
        TOGGLE_BIT(*Lat_Register[pin->port],pin->pin);
        ret = E_OK;
    }
    return ret;
    
}


Std_ReturnType gpio_port_directoin_initialize   (Port_t port, uint8 dir)
{
    Std_ReturnType ret = E_NOT_OK;
    
    if(port > (MAX_PORT_NUMBER - 1))
    {
     ret = E_NOT_OK;   
    }
    else
    {
        *Tris_Register[port] = dir;
        ret = E_OK; 
    }
    return ret;            
}
Std_ReturnType gpio_port_read_direction         (Port_t port, uint8 *ret_dir)
{
    Std_ReturnType ret = E_NOT_OK;
    if(port > (MAX_PORT_NUMBER - 1))
    {
        ret = E_NOT_OK;
    }
    else
    {
        *ret_dir = *Tris_Register[port];
        ret = E_OK; 
    }
    return ret;
}
Std_ReturnType gpio_port_read_logic             (Port_t port, uint8 *logic)
{
    Std_ReturnType ret = E_NOT_OK;
    
    if(port > (MAX_PORT_NUMBER-1))
    {
        ret = E_NOT_OK;
    }
    else
    {
        *logic = *Lat_Register[port];
        ret = E_OK;
    }
    return ret;
}
Std_ReturnType gpio_port_write_logic            (Port_t port, uint8 logic)
{
    Std_ReturnType ret = E_NOT_OK;
    
    if(port > (MAX_PORT_NUMBER-1))
    {
        ret = E_NOT_OK;
    }
    else
    {
        *Lat_Register[port] = logic;
        ret = E_OK;
    }
    return ret;
}
Std_ReturnType gpio_port_toggle                 (Port_t port)
{
    Std_ReturnType ret = E_NOT_OK;
    if(port > (MAX_PORT_NUMBER-1))
    {
        ret = E_NOT_OK;
    }
    else
    {
        (*Lat_Register[port]) ^= 0XFF;
        ret = E_OK;
    }
    return ret;
}
