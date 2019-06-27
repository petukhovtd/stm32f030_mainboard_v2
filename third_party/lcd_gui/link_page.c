#include <link_page.h>

static void LinkPageMove( LinkPage *lp, PARAMETER_MOVE m )
{
     Page* page = lp->massPage[lp->currentPage];

     switch ( page->move( page, m ))
     {
          case PARAMETER_MOVE_OK:
               page->cursorShow( page );
               break;

          case PARAMETER_MOVE_NEXT_PAGE:
               lp->currentPage++;
               if( lp->currentPage == lp->linkPageMax )
               {
                    lp->currentPage = 0;
               }
               Page* nextPage = lp->massPage[ lp->currentPage ];
               nextPage->currentParameter = 0;
               nextPage->show();
               nextPage->cursorShow( nextPage );
               break;

          case PARAMETER_MOVE_PREVIOS_PAGE:
               if( lp->currentPage == 0 )
               {
                    lp->currentPage = lp->linkPageMax - 1;
               }
               else
               {
                    lp->currentPage--;
               }
               Page* prevPage = lp->massPage[ lp->currentPage ];
               prevPage->currentParameter = page->pageParameterMax - 1;
               prevPage->show();
               prevPage->cursorShow( prevPage );
               break;

          default:
               page->show();
               page->cursorShow( page );
               break;
     }
}

static void LinkPageChangeParameter( LinkPage *lp, signed char n )
{
     Page* page = lp->massPage[lp->currentPage];
     Parameter* parameter = page->massParameter[page->currentParameter];
     parameter->change( parameter, n );
     page->show();
     page->cursorShow( page );
}

static void LinkPageActionParameter( LinkPage *lp)
{
     Page* page = lp->massPage[lp->currentPage];
     Parameter* parameter = page->massParameter[page->currentParameter];
     parameter->action();
}

void LinkPageInitStruct( LinkPage *lp )
{
     lp->currentPage = 0;
     lp->linkPageMax = 0;
     lp->move = &LinkPageMove;
     lp->changeParameter = &LinkPageChangeParameter;
     lp->actionParameter = &LinkPageActionParameter;
}

