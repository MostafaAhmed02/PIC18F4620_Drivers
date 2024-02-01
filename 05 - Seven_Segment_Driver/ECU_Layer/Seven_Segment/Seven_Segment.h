/* 
 * File:   Seven_Segment.h
 * Author: Mostafa Ahmed Allam
 *Email : maag7504@gmail.com
 */

#ifndef SEVEN_SEGMENT_H
#define	SEVEN_SEGMENT_H

/* ************** Include Section ************** */
#include"../../MCAL_Layer/GPIO/HAL_GPIO.h"


#define     SEGMENT_PIN0        0
#define     SEGMENT_PIN1        1
#define     SEGMENT_PIN2        2
#define     SEGMENT_PIN3        3
/* ********* Macro Function Declarations ********* */

/* ********* Datatype Declarations ********* */
typedef enum 
{
    COMMON_CATHODE_7_SEG = 0,
    COMMON_ANODE_7_SEG
}seg_tyepe_t;

typedef struct 
{
    Pin_Config_t Seven_Pins[4];
    seg_tyepe_t segment_type;
}Segment_t;
/* ********* Function Declarations ********* */
Std_ReturnType seven_segment_initialize (const Segment_t *_7_seg);
Std_ReturnType seven_segment_out_number (const Segment_t *_7_seg , uint8 number);

/* ************** Function Declaration Section ************** */
/* ************** Function Definition Section ************** */
/* ************** Macro Section ************** */
/* ************** Macro Function Section ************** */
/* ************** Datatype Declaration Section ************** */

#endif	/* SEVEN_SEGMENT_H */

