#include <parameter.h>

static void ParameterChange( Parameter *p, signed char n )
{
     signed long int in = n;

     if ( abs( in ) >= p->mul2Level )
     {
          in *= p->mul2;
     }
     else if ( abs( in ) >= p->mul1Level )
     {
          in *= p->mul1;
     }

     in *= p->step;

     if (( in < 0 ) && ( p->iValue < abs( in )))
     {
          p->iValue = 0;
     }
     else if (( p->iValue + in ) > p->max )
     {
          p->iValue = p->max;
     }
     else
     {
          p->iValue += in;
     }

     if( p->iValue < p->min )
     {
          p->iValue = p->min;
     }
}

void ParameterInitFullStruct( Parameter *p )
{
     p->type = TYPE_INTEGER;
     p->iValue = 0;
     for( uint8_t i = 0; i < SVALUE_NUM_MAX; i++ )
     {
          for( uint8_t j = 0; j < SVALUE_LEN_MAX; j++ )
          {
               p->sValue[ i ][ j ] = 0;
          }
     }
     p->min = 0;
     p->max = 1;
     p->step = 1;
     p->mul1 = 1;
     p->mul1Level = 1;
     p->mul2 = 1;
     p->mul2Level = 1;
     p->adr = 0;
     p->index = 0;
     p->change = & ParameterChange;
};

void ParameterInitStruct( Parameter *p )
{
     p->change = & ParameterChange;
};