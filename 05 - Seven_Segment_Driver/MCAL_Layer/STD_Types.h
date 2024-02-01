
/* 
 * File:   STD_Types.c
 * Author:  Mostafa Ahmed Allam
 * Email : maag7503@gmail.com
 */

#ifndef STD_TYPES_H
#define	STD_TYPES_H
/* ************** Include Section ************** */

#include "STD_Libraries.h"
/* ************** Macro Section ************** */

typedef unsigned char       uint8;  //unsigned char = uint8 (1 bytes) now
typedef unsigned short      uint16; //unsigned short = uint16 (2 bytes) now
typedef unsigned int        uint32; //unsigned int = uint32 (4 bytes) now
typedef unsigned long long  uint64; //unsigned long long = uint64 (8 bytes) now

typedef signed char         sint8;  //signed char = sint8 (1 bytes) now
typedef signed short        sint16; //signed short = sint16 (2 bytes) now
typedef signed int          sint32; //signed int = sint32 (4 bytes) now
typedef signed long long    sint64; //signed long long = sint64 (8 bytes) now

typedef float               float32; //float = float32 (4 bytes) now
typedef double              float64; //float = float64 (8 bytes) now


/* ************** Datatype Definition Section ************** */
typedef uint8               Std_ReturnType; //uint8 = Std_ReturnType now


/* This is the standard return, Illustrates functions executed well or not*/
#define E_NOT_OK            (Std_ReturnType)0X00
#define E_OK                (Std_ReturnType)0X01

#endif	/* STD_TYPES_H */

