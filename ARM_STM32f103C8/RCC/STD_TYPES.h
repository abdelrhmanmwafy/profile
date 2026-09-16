
#ifndef STD_TYPES_H
#define STD_TYPES_H
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned int u32;
typedef unsigned long long int u64;
typedef signed char s8;
typedef signed short int s16;
typedef signed int s32;
typedef signed long long int s64;
typedef float f32;
typedef double f64;

#define NULL ((void*)0x00)

typedef u8 Set_ReeturnType;
#define E_OK   (Set_ReeturnType)1
#define E_NOT_OK    (Set_ReeturnType)0

#endif
