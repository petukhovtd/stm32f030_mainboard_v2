#ifndef CONTROL_ENCODER_H
#define CONTROL_ENCODER_H

#include <stdint.h>
#include <stdbool.h>

typedef struct Encoder_
{
     uint8_t LastState;
     signed int Count;
     void ( *NewState )( struct Encoder_ *e, uint8_t state );
     signed int ( *GetCount )( struct Encoder_ *e );
     bool ( *CheckCount )( struct Encoder_ *e );
} Encoder;

void EncoderInitStruct( Encoder *e );

#endif
