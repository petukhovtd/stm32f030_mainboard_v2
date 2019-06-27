#ifndef LINK_PAGE_H
#define LINK_PAGE_H

#include <define_config.h>
#include <page.h>

typedef struct LinkPage
{
     uint8_t currentPage;
     uint8_t linkPageMax;
     Page *massPage[PAGE_MAX];
     void ( *move )( struct LinkPage *lp, PARAMETER_MOVE m );
     void ( *changeParameter )( struct LinkPage *lp, signed char n );
     void ( *actionParameter )( struct LinkPage *lp );
} LinkPage;

void LinkPageInitStruct( LinkPage *lp );

#endif
