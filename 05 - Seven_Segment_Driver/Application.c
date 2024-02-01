/* 
 * File:   Appllication.c
 * Author:  Mostafa Ahmed Allam
 * Email : maag7503@gmail.com
 */

#include"Application.h"

uint8 _7_seg_com_anode_values [10] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
uint8 _7_seg_com_cathode_values [10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};


uint8 seconds = 50;
uint8 minutes = 59;
uint8 hours = 11;
uint32 delay_val = 3333;
uint8 counter = 0;
uint8 counter2 = 0;


uint8 ones = 0;
uint8 tens = 0;
Segment_t Segment_1 = {
  .Seven_Pins[SEGMENT_PIN0].direction = GPIO_OUTPUT,
  .Seven_Pins[SEGMENT_PIN1].direction = GPIO_OUTPUT,
  .Seven_Pins[SEGMENT_PIN2].direction = GPIO_OUTPUT,
  .Seven_Pins[SEGMENT_PIN3].direction = GPIO_OUTPUT,

  .Seven_Pins[SEGMENT_PIN0].logic = GPIO_LOW,
  .Seven_Pins[SEGMENT_PIN1].logic = GPIO_LOW,
  .Seven_Pins[SEGMENT_PIN2].logic = GPIO_LOW,
  .Seven_Pins[SEGMENT_PIN3].logic = GPIO_LOW,

  .Seven_Pins[SEGMENT_PIN0].pin = GPIO_PIN0,
  .Seven_Pins[SEGMENT_PIN1].pin = GPIO_PIN1,
  .Seven_Pins[SEGMENT_PIN2].pin = GPIO_PIN2,
  .Seven_Pins[SEGMENT_PIN3].pin = GPIO_PIN3,

  .Seven_Pins[SEGMENT_PIN0].port = GPIO_PORTC,
  .Seven_Pins[SEGMENT_PIN1].port = GPIO_PORTC,
  .Seven_Pins[SEGMENT_PIN2].port = GPIO_PORTC,
  .Seven_Pins[SEGMENT_PIN3].port = GPIO_PORTC,

  .segment_type = COMMON_ANODE_7_SEG

};

int
main ()
{

  Std_ReturnType ret = E_NOT_OK;
  /* ************* Testing the 7-Segment in proteus , Done successfully!! ************* */
  ret = seven_segment_initialize (&Segment_1);
  ret = gpio_port_directoin_initialize (GPIO_PORTD, 0x00);

  /* ************* From 1->99 double seven segment ************* */
#if 0
  while (1)
    {
      ret = gpio_port_write_logic (GPIO_PORTC, 0xc0);
      ret = gpio_port_write_logic (GPIO_PORTC, 0xc0);
      __delay_ms (1000);
      ret = gpio_port_write_logic (GPIO_PORTC, 0xf9);
      ret = gpio_port_write_logic (GPIO_PORTC, 0xf9);
      __delay_ms (1000);
      ret = gpio_port_write_logic (GPIO_PORTC, 0xa4);
      ret = gpio_port_write_logic (GPIO_PORTC, 0xa4);
      __delay_ms (1000);
      ret = gpio_port_write_logic (GPIO_PORTC, 0xb0);
      ret = gpio_port_write_logic (GPIO_PORTC, 0xb0);
      __delay_ms (1000);
      ret = gpio_port_write_logic (GPIO_PORTC, 0x92);
      ret = gpio_port_write_logic (GPIO_PORTC, 0x92);
      __delay_ms (1000);
      ret = gpio_port_write_logic (GPIO_PORTC, 0x82);
      ret = gpio_port_write_logic (GPIO_PORTC, 0x82);
      __delay_ms (1000);
      ret = gpio_port_write_logic (GPIO_PORTC, 0xf8);
      ret = gpio_port_write_logic (GPIO_PORTC, 0xf8);
      __delay_ms (1000);
      ret = gpio_port_write_logic (GPIO_PORTC, 0x80);
      ret = gpio_port_write_logic (GPIO_PORTC, 0x80);
      __delay_ms (1000);
      ret = gpio_port_write_logic (GPIO_PORTC, 0x90);
      ret = gpio_port_write_logic (GPIO_PORTC, 0x90);
      __delay_ms (1000);

    }
#endif 
#if 0


  /*initializing the process with zeros*/

  while (1)
    {
      ret = gpio_port_write_logic (PORTC_INDEX, _7_seg_com_anode_values[0]);
      ret = gpio_port_write_logic (PORTD_INDEX, _7_seg_com_anode_values[0]);
      __delay_ms (100);
      for (tens = 0; tens < 10; tens++)
        {
          ret = gpio_port_write_logic (PORTC_INDEX, _7_seg_com_anode_values[tens]);
          for (ones = 0; ones < 10; ones++)
            {
              ret = gpio_port_write_logic (PORTD_INDEX, _7_seg_com_anode_values[ones]);
              __delay_ms (150);
            }
        }
    }
#endif
  /*Small project to illustrate the decoder work */
#if 0
  while (1)
    {
      ret = gpio_port_write_logic (PORTC_INDEX, 0x09);
      __delay_ms (500);
      ret = gpio_port_write_logic (PORTC_INDEX, 0x90);
      __delay_ms (500);


    }
#endif
  /* ************* From 1->99 double seven segment by decoder ************* */
#if 0
  while (1)
    {
      for (tens = 0; tens < 10; tens++)
        {
          ret = gpio_port_write_logic (PORTC_INDEX, tens);
          for (ones = 0; ones < 10; ones++)
            {
              ret = gpio_port_write_logic (PORTD_INDEX, ones);
              __delay_ms (150);
            }
        }
    }
#endif
  /* ************* Clock using 6 7-segments and decoders ************* */
#if 0
  while (1)
    {
      Hours = 0;
      for (Hours = 0; Hours < 13; Hours++)
        {
          Hours_bcd = (((uint8) Hours % 10) | (((uint8) Hours / 10) << 4));
          ret = gpio_port_write_logic (PORTD_INDEX, Hours_bcd);
          for (Minutes = 0; Minutes < 10; Minutes++)
            {
              Minutes_bcd = (((uint8) Minutes % 10) | (((uint8) Minutes / 10) << 4));
              ret = gpio_port_write_logic (PORTB_INDEX, Minutes_bcd);
              for (Seconds = 0; Seconds < 10; Seconds++)
	{
	  Seconds_bcd = (((uint8) Seconds % 10) | (((uint8) Seconds / 10) << 4));
	  ret = gpio_port_write_logic (PORTC_INDEX, Seconds_bcd);
	  __delay_ms (120);
	}
              Seconds = 0;
            }
          Minutes = 0;
        }
    }
#endif
  /* ************* Advanced Clock using 8 7-segments and one decoder ************* */
#if 0
  while (1)
    {
      for (counter = 0; counter < 50; counter++)
        {
          ret = gpio_port_write_logic (PORTD_INDEX, 0x3E);
          ret = gpio_port_write_logic (PORTC_INDEX, ((uint8) Hours / 10));
          __delay_us (3333);

          ret = gpio_port_write_logic (PORTD_INDEX, 0x3D);
          ret = gpio_port_write_logic (PORTC_INDEX, ((uint8) Hours % 10));
          __delay_us (3333);

          ret = gpio_port_write_logic (PORTD_INDEX, 0x3B);
          ret = gpio_port_write_logic (PORTC_INDEX, ((uint8) Minutes / 10));
          __delay_us (3333);

          ret = gpio_port_write_logic (PORTD_INDEX, 0x37);
          ret = gpio_port_write_logic (PORTC_INDEX, ((uint8) Minutes % 10));
          __delay_us (3333);

          ret = gpio_port_write_logic (PORTD_INDEX, 0x2F);
          ret = gpio_port_write_logic (PORTC_INDEX, ((uint8) Seconds / 10));
          __delay_us (3333);

          ret = gpio_port_write_logic (PORTD_INDEX, 0x1F);
          ret = gpio_port_write_logic (PORTC_INDEX, ((uint8) Seconds % 10));
          __delay_us (3333);
        }
      Seconds++;
      if (Seconds == 60)
        {
          Seconds = 0;
          Minutes++;
        }
      if (Minutes == 60)
        {
          Minutes = 0;
          Hours++;
        }
      if (Hours == 24)
        {
          Hours = 0;
        }
    }
#endif  

#if 0
  while (1)
    {
      for (counter = 0; counter < 50; counter++)
        {
          ret = gpio_port_write_logic (GPIO_PORTD, 0X3E);
          ret = gpio_port_write_logic (GPIO_PORTC, ((uint8) (hours / 10)));
          __delay_us (3333);

          ret = gpio_port_write_logic (GPIO_PORTD, 0X3D);
          ret = gpio_port_write_logic (GPIO_PORTC, ((uint8) (hours % 10)));
          __delay_us (3333);

          ret = gpio_port_write_logic (GPIO_PORTD, 0X3B);
          ret = gpio_port_write_logic (GPIO_PORTC, ((uint8) (minutes / 10)));
          __delay_us (3333);
          ret = gpio_port_write_logic (GPIO_PORTD, 0X37);
          ret = gpio_port_write_logic (GPIO_PORTC, ((uint8) (minutes % 10)));
          __delay_us (3333);

          ret = gpio_port_write_logic (GPIO_PORTD, 0X2F);
          ret = gpio_port_write_logic (GPIO_PORTC, ((uint8) (seconds / 10)));
          __delay_us (3333);

          ret = gpio_port_write_logic (GPIO_PORTD, 0X1F);
          ret = gpio_port_write_logic (GPIO_PORTC, ((uint8) (seconds % 10)));
          __delay_us (3333);
        }
      seconds++;
      if (seconds == 60)
        {
          minutes++;
          seconds = 0;
          if (minutes == 60)
            {
              hours++;
              minutes = 0;
              if (hours == 12)
	{
	  hours = 0;
	}

            }
        }
    }
#endif

  while (1)
    {

      for (counter = 0; counter < 100; counter++)
        {
          for (counter2 = 0; counter2 < 100; counter2++)
            {
              gpio_port_write_logic (GPIO_PORTD, 0X01);
              ones = (counter / 10);
              ret = seven_segment_out_number (&Segment_1, (uint8) ones);
              __delay_ms (10);
              gpio_port_write_logic (GPIO_PORTD, 0X02);
              tens = (counter % 10);
              ret = seven_segment_out_number (&Segment_1, (uint8) tens);
              __delay_ms (10);
            }
        }
    }
  return 0;
}

