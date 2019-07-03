#include "control_button.h"

static bool GetButtonClicked( Button *b )
{
     if ( b->buttonClicked )
     {
          b->buttonClicked = false;
          return true;
     }
     return false;
}

static void NewState( Button *b, bool state )
{
     if ( !b->buttonLastState && state )
     {
          b->buttonClicked = true;
     }
     b->buttonLastState = state;
}

void ButtonInitStruct( Button *b )
{
     b->buttonLastState = false;
     b->buttonClicked = false;
     b->GetButtonClicked = &GetButtonClicked;
     b->NewState = &NewState;
}