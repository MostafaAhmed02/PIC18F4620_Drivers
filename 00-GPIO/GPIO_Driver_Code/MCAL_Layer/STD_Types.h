/* 
 * File:   STD_Types.h
 * Author: Mostafa Ahmed
 */

#ifndef STD_TYPES_H
#define	STD_TYPES_H


/* ************* Includes section ************* */

#include "STD_Libraries.h"

/* ************* Data type declaration section ************* */

/*Main data types : */
typedef unsigned char                   uint8;
typedef unsigned short                  uint16;
typedef unsigned int                    uint32;
typedef unsigned long long              uint64;

typedef signed char                     sint8;
typedef signed short                    sint16;
typedef signed int                      sint32;
typedef signed long long                sint64;

typedef float                           float32;
typedef double                          float64;
/* ************* Macro definition section ************* */

typedef unsigned char                            STD_RETURN_TYPE;

#define E_OK                            (STD_RETURN_TYPE)0X01                   
#define E_NOT_OK                        (STD_RETURN_TYPE)0X00  
#define _XTAL_FREQ      8000000UL



/*Important data type used in driver's functions  : */
    



#endif	/* STD_TYPES_H */

