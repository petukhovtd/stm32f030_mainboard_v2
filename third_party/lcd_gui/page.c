#include <page.h>

static PARAMETER_MOVE_ANS PageMove( struct Page *p, PARAMETER_MOVE m )
{
     switch (m)
     {
          case NEXT:
               if ( p->currentParameter == (p->pageParameterMax - 1))
               {
                    return PARAMETER_MOVE_NEXT_PAGE;
               }
               p->currentParameter++;
               return PARAMETER_MOVE_OK;
               break;

          case PREVIOS:
               if ( p->currentParameter == 0 )
               {
                    return PARAMETER_MOVE_PREVIOS_PAGE;
               }
               p->currentParameter--;
               return PARAMETER_MOVE_OK;
               break;

          case ACTION:
               p->massParameter[p->currentParameter]->action();
               return PARAMETER_MOVE_OK;
               break;

          default:
               return PARAMETER_MOVE_ERROR;
               break;
     }
}

void PageInitStuct( Page *p )
{
     p->currentParameter = 0;
     p->pageParameterMax = 0;
     p->move = &PageMove;
}

