#ifndef EX7_CONST_H
#define EX7_CONST_H

enum TEMPERATURE_TYPES {
    KELVIN = 0,     
    CELSIUS = 1,    
    FAHRENHEIT = 2  
};

// Array limits
#define SAMPLE_LIMIT    10
#define TEMP_TYPES      3

// Temperature conversion
#define ZERO_C          273.15 // 0K = -273.15  
#define ZERO_F          32     // Add + 32 for fahrenheit  
#define MUL_F           1.8    // Multiply for fahrenheit

// States
#define GAS             100
#define SOLID           0

#endif