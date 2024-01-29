/* 
 * File:   Hal_GPIO.h
 * Author: Mostafa Ahmed (maag7503@gmail.com)
 */



#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/* ************* Includes Section ************* */

#include "../STD_Libraries.h"
#include "../STD_Types.h"
#include "pic18f4620.h"

/* ************* Macro definition section ************* */

#define MAX_PORT_NUMBER                     5

#define SET_BIT(REG,BIT_POS)                (REG |= (1<<BIT_POS))
#define CLEAR_BIT(REG,BIT_POS)              (REG &=~(1<<BIT_POS))
#define TOGGLE_BIT(REG,BIT_POS)             (REG ^= (1<<BIT_POS))

#define READ_BIT(REG,BIT_POS)               ((REG >> BIT_POS ) & 1)


/* ************* Data type definition section ************* */

volatile uint8 *tris_register[MAX_PORT_NUMBER] = {&TRISA ,&TRISB ,&TRISC ,&TRISD ,&TRISE};
volatile uint8 *port_register[MAX_PORT_NUMBER] = {&PORTA ,&PORTB ,&PORTC ,&PORTD ,&PORTE};
volatile uint8 *lat_register[MAX_PORT_NUMBER] =  {&LATA ,&LATB ,&LATC ,&LATD ,&LATE};


typedef enum 
{
    GPIO_PIN_OUTPUT = 0,
    GPIO_PIN_INPUT
}Direction_Pin;

typedef enum 
{
    GPIO_LOW = 0,
    GPIO_HIGH
}Logic_Pin;

typedef enum 
{
    GPIO_PIN0 = 0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7
}GPIO_PIN;

typedef enum 
{
    GPIO_PORTA = 0,
    GPIO_PORTB ,
    GPIO_PORTC ,
    GPIO_PORTD ,
    GPIO_PORTE 
}GPIO_PORT;

typedef struct 
{
    /* port is 3 because number of ports is 5 so, I can implement them in 3 bits at least*/
    uint8 port      : 3;
    /* port is 3 because number of ports is 8 so, I can implement them in 3 bits at least*/
    uint8 pin       : 3;
    /* port is 3 because number of ports is 2 so, I can implement them in 1 bits at least*/
    uint8 direction : 1;
    /* port is 3 because number of ports is 2 so, I can implement them in 1 bits at least*/
    uint8 logic     : 1;
}Pin_Config;

/* ************* Function declaration section ************* */

/* *********** gpio_pin_direction_initialize() ***********
 * @brief       ->This function used to initialize the direction of any pin Input/Output.
 * @param Pin   ->This is a pointer to struct that compine all date about the pin will be configured.
 * @return      ->  STD_RETURN_TYPE , the return type that indicates if
 *                  [E_OK] : The function done successfully.
 *                  [E_NOT_OK] : There issue in the function!!
 */
STD_RETURN_TYPE    gpio_pin_direction_initialize(const Pin_Config *Pin);

/* *********** gpio_pin_read_direction() ***********
 * @brief       ->This function used to initialize the direction of any pin Input/Output.
 * @param Pin   ->This is a pointer to struct that compine all date about the pin will be configured.
 * @param dir_status
 * @return      ->  STD_RETURN_TYPE , the return type that indicates if
 *                  [E_OK] : The function done successfully.
 *                  [E_NOT_OK] : There issue in the function!! 
 */
STD_RETURN_TYPE    gpio_pin_read_direction(const Pin_Config *Pin ,Direction_Pin *dir_status);

/* *********** gpio_pin_write_logic() ***********
 * @brief       ->This function used to read the direction of any pin Input/Output.
 * @param Pin   ->This is a pointer to struct that compine all date about the pin will be configured.
 * @param logic_status
 * @return      ->  STD_RETURN_TYPE , the return type that indicates if
 *                  [E_OK] : The function done successfully.
 *                  [E_NOT_OK] : There issue in the function!!  
 */
STD_RETURN_TYPE    gpio_pin_write_logic(const Pin_Config *Pin ,Logic_Pin logic_status);
/* *********** gpio_pin_read_logic() ***********
 * @brief       ->This function used to write High/Low on any pin.
 * @param Pin   ->This is a pointer to struct that compine all date about the pin will be configured.
 * @param logic_status
 * @return      ->  STD_RETURN_TYPE , the return type that indicates if
 *                  [E_OK] : The function done successfully.
 *                  [E_NOT_OK] : There issue in the function!!  
 */

STD_RETURN_TYPE    gpio_pin_read_logic(const Pin_Config *Pin , Logic_Pin *logic_status);

/* *********** gpio_pin_toglle_logic() ***********
 * @brief       ->This function used to toggle the status of any pin. 
 * @param Pin   ->This is a pointer to struct that compine all date about the pin will be configured.
 * @return      ->  STD_RETURN_TYPE , the return type that indicates if
 *                  [E_OK] : The function done successfully.
 *                  [E_NOT_OK] : There issue in the function!!
 */
STD_RETURN_TYPE    gpio_pin_toglle_logic(const Pin_Config *Pin);

/* *********** gpio_pin_initialize() ***********
 * @brief       ->This function used to initialize the direction of any pin to be Output and clear it in the same time. 
 * @param Pin   ->This is a pointer to struct that compine all date about the pin will be configured.
 * @return      ->  STD_RETURN_TYPE , the return type that indicates if
 *                  [E_OK] : The function done successfully.
 *                  [E_NOT_OK] : There issue in the function!!
 */
STD_RETURN_TYPE    gpio_pin_initialize(const Pin_Config *Pin);



/* *********** gpio_port_initialize() ***********
 * @brief       ->This function used to initialize the direction of any port to Output and clear it.
 * @param Port  ->This is the index of any port.
 */
void    gpio_port_initialize(GPIO_PORT Port);

/* *********** gpio_port_direction_initialize() ***********
 * @brief       ->This function used to initialize the direction of any port Input/Output.
 * @param Port  ->This is the index of any port.
 * @param dir_status ->This is the status of the port pins Output/Input.
 */
void    gpio_port_direction_initialize(GPIO_PORT Port ,uint8 dir_status);

/* *********** gpio_port_write_logic() ***********
 * @brief       ->This function used to write High/Low on any port.
 * @param Port  ->This is the index of any port.
 * @param logic_status->This is the status of the port pins High/Low.
 */
void    gpio_port_write_logic(GPIO_PORT Port ,uint8 logic_status);

/* *********** gpio_port_read_logic() ***********
 * @brief       ->This function used to read the status of any port High/Low.
 * @param Port  ->This is the index of any port.
 * @param logic_status->This is stores the status of the port pins High/Low.
 */
void    gpio_port_read_logic(GPIO_PORT Port , uint8 *logic_status);

/* *********** gpio_port_toglle_logic() ***********
 * @brief       ->This function used to toggle the status of any port pins.
 * @param Port  ->This is the index of any port.
 */
void    gpio_port_toglle_logic(GPIO_PORT Port);
#endif	/* HAL_GPIO_H */

