/* 
 * File:   Hal_GPIO.c
 * Author: Mostafa Ahmed
 */

#include "Hal_GPIO.h"

/*
 Pin_Config is pointer to avoid calling and copying the struct into Memory every 
 * ... time when calling the function and const to avoid changing the values of it.
 */

STD_RETURN_TYPE    gpio_pin_direction_initialize(const Pin_Config *Pin)
{
  STD_RETURN_TYPE ret = E_NOT_OK;
  if(NULL == Pin)
    {
      ret = E_NOT_OK ;
    }
  else
    {
      if(Pin->direction == GPIO_PIN_OUTPUT)
        {
          CLEAR_BIT(*tris_register[Pin->port],Pin->pin);
        }
      else if (Pin->direction == GPIO_PIN_INPUT)
        {
          SET_BIT(*tris_register[Pin->port],Pin->pin);
        }
      else
        {
          ret = E_NOT_OK ;
        }
      ret = E_OK ;
    }
  return ret;  
}
STD_RETURN_TYPE    gpio_pin_read_direction(const Pin_Config *Pin ,Direction_Pin *dir_status)
{
  STD_RETURN_TYPE ret = E_NOT_OK ;
  if((NULL == Pin) || (NULL == dir_status))
    {
      ret = E_NOT_OK ;
    }
  else
    {
      *dir_status = READ_BIT(*tris_register[Pin->port],Pin->pin);
      ret = E_OK ;
    }
  return ret;  
}
STD_RETURN_TYPE    gpio_pin_write_logic(const Pin_Config *Pin ,Logic_Pin logic_status)
{
  STD_RETURN_TYPE ret = E_NOT_OK ;
  if(NULL == Pin)
    {
      ret = E_NOT_OK ;
    }
  else
    {
      if(logic_status == GPIO_HIGH)
        {
          SET_BIT(*lat_register[Pin->port],Pin->pin);
        }
      else if (logic_status == GPIO_LOW)
        {
          CLEAR_BIT(*lat_register[Pin->port],Pin->pin);
        }
      else
        {
          ret = E_NOT_OK ;
        }
      ret = E_OK ;
    }
  return ret;  
}
STD_RETURN_TYPE    gpio_pin_read_logic(const Pin_Config *Pin , Logic_Pin *logic_status)
{
  STD_RETURN_TYPE ret = E_NOT_OK ;
  if((NULL == Pin) || (NULL == logic_status))
    {
      ret = E_NOT_OK ;
    }
  else
    {
        *logic_status = READ_BIT(*port_register[Pin->port],Pin->pin);
        ret = E_OK ;
    }
  return ret;  
}
STD_RETURN_TYPE    gpio_pin_toglle_logic(const Pin_Config *Pin)
{
  STD_RETURN_TYPE ret = E_NOT_OK ;
  if(NULL == Pin)
    {
      ret = E_NOT_OK ;
    }
  else
    {
      TOGGLE_BIT(*lat_register[Pin->port],Pin->pin);
      ret = E_OK ;
    }
  return ret;
}
STD_RETURN_TYPE    gpio_pin_initialize(const Pin_Config *Pin)
{
  STD_RETURN_TYPE ret = E_NOT_OK ;
  if(NULL == Pin)
    {
      ret = E_NOT_OK ;
    }
  else
    {
      CLEAR_BIT(*tris_register[Pin->port],Pin->pin);
      CLEAR_BIT(*port_register[Pin->port],Pin->pin);
      ret = E_OK ;
    }
  return ret;
}



void    gpio_port_initialize(GPIO_PORT Port)
{
  *tris_register[Port] = 0x00;
  *lat_register[Port] = 0x00;
}
void    gpio_port_direction_initialize(GPIO_PORT Port ,uint8 dir_status)
{
  *tris_register[Port] = dir_status;
}
void    gpio_port_write_logic(GPIO_PORT Port ,uint8 logic_status)
{
  *lat_register[Port] = logic_status;
}
void    gpio_port_read_logic(GPIO_PORT Port , uint8 *logic_status)
{
  *logic_status = *lat_register[Port];
}
void    gpio_port_toglle_logic(GPIO_PORT Port)
{
  *lat_register[Port] ^= 0XFF ; //*lat_register[Port] = *lat_register[Port] ^ 0XFF ;
}
