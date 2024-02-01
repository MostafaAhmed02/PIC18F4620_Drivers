/* 
 * File:   Seven_Segment.c
 * Author: Mostafa Ahmed Allam
 *Email : maag7504@gmail.com
 */

/* ************** Include Section ************** */
#include "Seven_Segment.h"

/* ************** Function Definition Section ************** */
Std_ReturnType
seven_segment_initialize (const Segment_t *_7_seg)
{
  Std_ReturnType ret = E_NOT_OK;
  if (NULL == _7_seg)
    {
      ret = E_NOT_OK;
    }
  else
    {
      ret = gpio_pin_initialize (&(_7_seg->Seven_Pins[SEGMENT_PIN0]));
      ret = gpio_pin_initialize (&(_7_seg->Seven_Pins[SEGMENT_PIN1]));
      ret = gpio_pin_initialize (&(_7_seg->Seven_Pins[SEGMENT_PIN2]));
      ret = gpio_pin_initialize (&(_7_seg->Seven_Pins[SEGMENT_PIN3]));

      ret = E_OK;
    }
  return ret;

}

Std_ReturnType
seven_segment_out_number (const Segment_t *_7_seg, uint8 number)
{
  Std_ReturnType ret = E_NOT_OK;
  if ((NULL == _7_seg) && (number > 9))
    {
      ret = E_NOT_OK;
    }
  else
    {
      ret = gpio_pin_write_logic (&(_7_seg->Seven_Pins[SEGMENT_PIN0]), number & 0x01);
      ret = gpio_pin_write_logic (&(_7_seg->Seven_Pins[SEGMENT_PIN1]), (number >> 1) & 0x01);
      ret = gpio_pin_write_logic (&(_7_seg->Seven_Pins[SEGMENT_PIN2]), (number >> 2) & 0x01);
      ret = gpio_pin_write_logic (&(_7_seg->Seven_Pins[SEGMENT_PIN3]), (number >> 3) & 0x01);
      
      ret = E_OK;
    }
  return ret;

}

/* ************** Macro Section ************** */
/* ************** Macro Function Section ************** */
/* ************** Datatype Declaration Section ************** */