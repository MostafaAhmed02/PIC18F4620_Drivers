/* 
 * File:   Appllication.c
 * Author:  Mostafa Ahmed Allam
 * Email : maag7503@gmail.com
 */

#include"Application.h"

Pin_Config_t pin_RC0 ={
    .direction = GPIO_OUTPUT,
    .logic = GPIO_LOW,
    .pin = GPIO_PIN0,
    .port = GPIO_PORTC,
};
Pin_Config_t pin_RC1 ={
    .direction = GPIO_OUTPUT,
    .logic = GPIO_LOW,
    .pin = GPIO_PIN1,
    .port = GPIO_PORTC,
};

Button_t btn0 = {
    .button_logic = BUTTON_ACTIVE_HIGH,
    .button_pin.direction = GPIO_INPUT,
    .button_pin.logic = GPIO_LOW,
    .button_pin.pin = GPIO_PIN0,
    .button_pin.port = GPIO_PORTD,
    .button_status = BUTTON_RELEASED
};
Button_t btn1 = {
    .button_logic = BUTTON_ACTIVE_LOW,
    .button_pin.direction = GPIO_INPUT,
    .button_pin.logic = GPIO_HIGH,
    .button_pin.pin = GPIO_PIN1,
    .button_pin.port = GPIO_PORTD,
    .button_status = BUTTON_RELEASED
};

Button_state_t btn0_status = BUTTON_RELEASED;
Button_state_t btn1_status = BUTTON_RELEASED;

Logic_t logic_status = GPIO_LOW;


uint8 btn_flag = 0;

uint32 valid = 0;
uint32 valid_status = BUTTON_RELEASED;
uint32 last_valid_status = BUTTON_RELEASED;
uint8 Program_Selected = 0;

int main() {
    application_initialization();
    Std_ReturnType ret = E_NOT_OK;
    ret = button_initialize(&btn0);
    while (1) {
        ret = button_read_state(&btn0, &btn0_status);
        if (BUTTON_PRESSED == btn0_status) {
            valid++;
            if (valid > 500) {
                valid_status = BUTTON_PRESSED;
            }

        } else {
            valid = 0;
            valid_status = BUTTON_RELEASED;
        }

        if (valid_status != last_valid_status) {
            last_valid_status = valid_status;
            if (BUTTON_PRESSED == valid_status) {
//                if (GPIO_LOW == logic_status) {
//                    gpio_pin_write_logic(&pin_RC0, GPIO_HIGH);
//                    logic_status = GPIO_HIGH;
//                } else {
//                    gpio_pin_write_logic(&pin_RC0, GPIO_LOW);
//                    logic_status = GPIO_LOW;
//                }
                Program_Selected++;
            }
        }
    }
    return 0;
}

void application_initialization(void) {
    Std_ReturnType ret = E_NOT_OK;
    ret = button_initialize(&btn0);
    ret = button_initialize(&btn1);
    ret = gpio_pin_initialize(&pin_RC0);
    ret = gpio_pin_initialize(&pin_RC1);
}
