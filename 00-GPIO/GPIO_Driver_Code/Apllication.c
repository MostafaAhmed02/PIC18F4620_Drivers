/* 
 * File:   main.c
 * Author: Mostafa Ahmed
 */

#include "Apllication.h"

 Pin_Config PC0 = {.port = GPIO_PORTC, .pin=GPIO_LOW, .direction = GPIO_PIN_OUTPUT , .logic = GPIO_HIGH};

STD_RETURN_TYPE ret = E_NOT_OK;


int main ()
{
   ret = gpio_pin_direction_initialize(&PC0);
  
  gpio_port_initialize (GPIO_PORTD);
  
  while(1)
    {
      ret = gpio_pin_write_logic (&PC0 , GPIO_HIGH);
      __delay_ms(500);
      ret = gpio_pin_write_logic (&PC0, GPIO_LOW);
      __delay_ms(500);
      ret = gpio_pin_toglle_logic (&PC0);
      __delay_ms(1000);
      
      gpio_port_write_logic (GPIO_PORTD , 0xff);
      __delay_ms(1000);
      gpio_port_write_logic (GPIO_PORTD , 0x00);
      __delay_ms(1000);
      
    }
    
  
  /*Done!!*/
   
  return (EXIT_SUCCESS);
}

