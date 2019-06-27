#ifndef PARAMETER_H
#define PARAMETER_H

#include <stdlib.h>
#include <stdint.h>
#include <define_config.h>

typedef struct Parameter
{
     enum
     {
          TYPE_NULL,
          TYPE_INTEGER,
          TYPE_STRING
     } type;

     uint32_t iValue;
     uint8_t sValue[ SVALUE_NUM_MAX ][ SVALUE_LEN_MAX ];
     uint32_t min;
     uint32_t max;
     uint16_t step;
     uint8_t mul1;
     uint8_t mul1Level;
     uint8_t mul2;
     uint8_t mul2Level;
     uint8_t adr;
     uint8_t index;
     void ( *change )( struct Parameter *p, signed char n );
     void ( *action )( void );
} Parameter;

void ParameterInitFullStruct( Parameter *p );
void ParameterInitStruct( Parameter *p );

#endif
