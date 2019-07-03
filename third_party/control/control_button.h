#ifndef CONTROL_BUTTON_H
#define CONTROL_BUTTON_H

#include <stdbool.h>

typedef struct Button_
{
     bool buttonLastState;
     bool buttonClicked;

     void ( *NewState )( struct Button_ *b, bool state );

     bool ( *GetButtonClicked )( struct Button_ *b );
} Button;

void ButtonInitStruct( Button *b );

#endif
