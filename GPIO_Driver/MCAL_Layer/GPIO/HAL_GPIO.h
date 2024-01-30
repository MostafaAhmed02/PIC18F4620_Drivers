/* 
 * File:   HAL_GPIO.h
 * Author:  Mostafa Ahmed Allam
 * Email : maag7503@gmail.com
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/* ************** Include Section ************** */

#include"../STD_Types.h"
#include"../xc.h"
#include"../STD_Libraries.h"
#include"pic18f4620.h"

/* ************** Macro Section ************** */

#define BIT_MASK                        (uint8)1
#define MAX_PORT_NUMBER                 (uint8)5
#define MAX_PIN_SIZE                    (uint8)8

/* ************** Macro Function Section ************** */

#define SET_BIT(PORT_REG,BIT_POS)       (PORT_REG |= (BIT_MASK<<BIT_POS))
#define CLEAR_BIT(PORT_REG,BIT_POS)     (PORT_REG &= ~(BIT_MASK<<BIT_POS))
#define TOGGLE_BIT(PORT_REG,BIT_POS)    (PORT_REG ^= (BIT_MASK<<BIT_POS))
#define READ_BIT(PORT_REG,BIT_POS)       ((PORT_REG>>BIT_POS) & 1)

/* ************** Datatype Declaration Section ************** */
typedef enum
{
    GPIO_LOW =0,
    GPIO_HIGH
}Logic_t;
typedef enum
{
    GPIO_OUTPUT = 0,
    GPIO_INPUT
}Direction_t;
typedef enum
{
    GPIO_PIN0 = 0,
    GPIO_PIN1 ,
    GPIO_PIN2 ,
    GPIO_PIN3 ,
    GPIO_PIN4 ,
    GPIO_PIN5 ,
    GPIO_PIN6 ,
    GPIO_PIN7 

}Pin_Pos_t;
typedef enum
{
    GPIO_PORTA =0,
    GPIO_PORTB,
    GPIO_PORTC,
    GPIO_PORTD,
    GPIO_PORTE
}Port_t;

typedef struct 
{
    uint8 port : 3;
    uint8 pin : 3;
    uint8 logic : 1;
    uint8 direction : 1;
}Pin_Config_t;

/* ************** Function Declaration Section ************** */

/* *********** gpio_pin_initialize() ***********
 * @brief       ->This function used to initialize the direction of any pin to be Output and clear it in the same time. 
 * @param Pin   ->This is a pointer to struct that compine all date about the pin will be configured.
 * @return      ->  STD_RETURN_TYPE , the return type that indicates if
 *                  [E_OK] : The function done successfully.
 *                  [E_NOT_OK] : There issue in the function!!
 */
Std_ReturnType gpio_pin_initialize              (const Pin_Config_t *pin);
/* *********** gpio_pin_direction_initialize() ***********
 * @brief       ->This function used to initialize the direction of any pin Input/Output.
 * @param Pin   ->This is a pointer to struct that compine all date about the pin will be configured.
 * @return      ->  Std_ReturnType , the return type that indicates if
 *                  [E_OK] : The function done successfully.
 *                  [E_NOT_OK] : There issue in the function!!
 */
Std_ReturnType gpio_pin_directoin_initialize    (const Pin_Config_t *pin);

/* *********** gpio_pin_read_direction() ***********
 * @brief       ->This function used to initialize the direction of any pin Input/Output.
 * @param Pin   ->This is a pointer to struct that compine all date about the pin will be configured.
 * @param dir
 * @return      ->  Std_ReturnType , the return type that indicates if
 *                  [E_OK] : The function done successfully.
 *                  [E_NOT_OK] : There issue in the function!! 
 */
Std_ReturnType gpio_pin_read_direction          (const Pin_Config_t *pin, Direction_t *dir);
/* *********** gpio_pin_write_logic() ***********
 * @brief       ->This function used to read the direction of any pin Input/Output.
 * @param Pin   ->This is a pointer to struct that compine all date about the pin will be configured.
 * @param logic
 * @return      ->  Std_ReturnType , the return type that indicates if
 *                  [E_OK] : The function done successfully.
 *                  [E_NOT_OK] : There issue in the function!!  
 */
Std_ReturnType gpio_pin_write_logic             (const Pin_Config_t *pin, Logic_t logic);
/* *********** gpio_pin_read_logic() ***********
 * @brief       ->This function used to write High/Low on any pin.
 * @param Pin   ->This is a pointer to struct that compine all date about the pin will be configured.
 * @param logic_status
 * @return      ->  Std_ReturnType , the return type that indicates if
 *                  [E_OK] : The function done successfully.
 *                  [E_NOT_OK] : There issue in the function!!  
 */
Std_ReturnType gpio_pin_read_logic              (const Pin_Config_t *pin, Logic_t *logic);
/* *********** gpio_pin_toggle() ***********
 * @brief       ->This function used to toggle the status of any pin. 
 * @param Pin   ->This is a pointer to struct that compine all date about the pin will be configured.
 * @return      ->  Std_ReturnType , the return type that indicates if
 *                  [E_OK] : The function done successfully.
 *                  [E_NOT_OK] : There issue in the function!!
 */
Std_ReturnType gpio_pin_toggle                  (const Pin_Config_t *pin);


/* *********** gpio_port_directoin_initialize() ***********
 * @brief       ->This function used to initialize the direction of any port Input/Output.
 * @param Port  ->This is the index of any port.
 * @param dir_status ->This is the status of the port pins Output/Input.
 */
Std_ReturnType gpio_port_directoin_initialize   (Port_t port, uint8 dir);
/* *********** gpio_port_read_direction() ***********
 * @brief       ->This function used to initialize the direction of any port Input/Output.
 * @param Port  ->This is the index of any port.
 * @param ret_dir ->This is the status of the port pins Output/Input.
 */
Std_ReturnType gpio_port_read_direction         (Port_t port, uint8 *ret_dir);
/* *********** gpio_port_read_logic() ***********
 * @brief       ->This function used to read the status of any port High/Low.
 * @param Port  ->This is the index of any port.
 * @param logic_status->This is stores the status of the port pins High/Low.
 */
Std_ReturnType gpio_port_read_logic             (Port_t port, uint8 *logic);
/* *********** gpio_port_write_logic() ***********
 * @brief       ->This function used to write High/Low on any port.
 * @param Port  ->This is the index of any port.
 * @param logic ->This is the status of the port pins High/Low.
 */
Std_ReturnType gpio_port_write_logic            (Port_t port, uint8 logic);
/* *********** gpio_port_toglle_logic() ***********
 * @brief       ->This function used to toggle the status of any port pins.
 * @param Port  ->This is the index of any port.
 */
Std_ReturnType gpio_port_toggle                 (Port_t port);

#endif	/* HAL_GPIO_H */

