#ifndef PAGE_H
#define PAGE_H

#include <define_config.h>
#include <parameter.h>
#include <stdint.h>

typedef enum
{
     PARAMETER_MOVE_ERROR,
     PARAMETER_MOVE_OK,
     PARAMETER_MOVE_NEXT_PAGE,
     PARAMETER_MOVE_PREVIOS_PAGE
} PARAMETER_MOVE_ANS;

typedef enum
{
     SHOW,
     NEXT,
     PREVIOS,
     ACTION
} PARAMETER_MOVE;

typedef struct Page
{
     uint8_t currentParameter;
     uint8_t pageParameterMax;
     Parameter *massParameter[PAGE_PARAMETER_MAX];
     uint8_t cusorYX[LCD_LINE][PAGE_PARAMETER_MAX];
     PARAMETER_MOVE_ANS ( *move )( struct Page *p, PARAMETER_MOVE m );

     void ( *show )( void );
     void ( *cursorShow )( struct Page *p );
} Page;

void PageInitStuct( Page *p );

#endif
