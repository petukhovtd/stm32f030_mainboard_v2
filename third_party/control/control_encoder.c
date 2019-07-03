#include "control_encoder.h"

static void NewState( Encoder *e, uint8_t state )
{
     if (((e->LastState == 3) && (state == 2)) ||
         ((e->LastState == 0) && (state == 1)))
     {
          e->Count++;
     }
     else if (((e->LastState == 3) && (state == 1)) ||
              ((e->LastState == 0) && (state == 2)))
     {
          e->Count--;
     }
     e->LastState = state;
}

static signed int GetCount( Encoder *e )
{
     signed int res = e->Count;
     e->Count = 0;
     return res;
}


static bool CheckCount( Encoder *e )
{
     return e->Count != 0;
}

void EncoderInitStruct( Encoder *e )
{
     e->LastState = 0;
     e->Count = 0;
     e->NewState = &NewState;
     e->GetCount = &GetCount;
     e->CheckCount = &CheckCount;
}