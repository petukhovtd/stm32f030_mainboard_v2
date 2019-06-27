#include <stm32_lcd_wh1602b.h>

static void LCDSendBite( uint8_t Out );

static void LCDSendBite8( uint8_t Out );

static void LCDSendDate( uint8_t Date );

static void LCDSendInstr( uint8_t Instr );

static void LCDSendInstrShort( uint8_t Instr );

void LCDInit( void )
{
     Delay_ms( 20000 );
     LCDSendInstrShort( 0x3 );
     Delay_us( 5000 );
     LCDSendInstrShort( 0x3 );
     Delay_us( 200 );
     LCDSendInstrShort( 0x3 );
     Delay_us( 200 );
     LCDSendInstrShort( 0x2 );
     Delay_us( 200 );
     LCDSendInstr( 0x28 );          //4-line 2-str, 5*8
     Delay_us( 50 );
     LCDSendInstr( 0x08 );               //Display OFF
     Delay_us( 50 );
     LCDClear();
     Delay_us( 50 );
     LCDSendInstr( 0x06 );
     Delay_us( 50 );
     LCDSendInstr( 0x0C );               //Disply ON
     Delay_us( 50 );
}

void LCDInit8bit( void )
{
     Delay_us( 20000 );
     LCDSendInstr( 0x30 );
     Delay_us( 5000 );
     LCDSendInstr( 0x30 );
     Delay_us( 200 );
     LCDSendInstr( 0x30 );
     Delay_us( 200 );
     LCDSendInstr( 0x38 ); //Confing 8-bit, 2-line, 5*8
     Delay_us( 50 );
     LCDSendInstr( 0x08 );               //Display OFF
     Delay_us( 50 );
     LCDClear();
     Delay_us( 50 );
     LCDSendInstr( 0x06 );
     Delay_us( 50 );
     LCDSendInstr( 0x0C );               //Disply ON
     Delay_us( 50 );
}

static void LCDSendBite( uint8_t Out )
{
     EN_H;
     if ( Out & 0x80 )D7_H; else D7_L;
     if ( Out & 0x40 )D6_H; else D6_L;
     if ( Out & 0x20 )D5_H; else D5_L;
     if ( Out & 0x10 )D4_H; else D4_L;
     Delay_us( 10 );
     EN_L;
     Delay_us( 10 );
     EN_H;
     if ( Out & 0x08 )D7_H; else D7_L;
     if ( Out & 0x04 )D6_H; else D6_L;
     if ( Out & 0x02 )D5_H; else D5_L;
     if ( Out & 0x01 )D4_H; else D4_L;
     Delay_us( 10 );
     EN_L;
     Delay_us( 10 );
}

static void LCDSendBite8( uint8_t Out )
{
     EN_H;
     if ( Out & 0x80 )D7_H; else D7_L;
     if ( Out & 0x40 )D6_H; else D6_L;
     if ( Out & 0x20 )D5_H; else D5_L;
     if ( Out & 0x10 )D4_H; else D4_L;
     if ( Out & 0x08 )D3_H; else D3_L;
     if ( Out & 0x04 )D2_H; else D2_L;
     if ( Out & 0x02 )D1_H; else D1_L;
     if ( Out & 0x01 )D0_H; else D0_L;
     Delay_us( 1 );
     EN_L;
     Delay_us( 40 );
}

static void LCDSendDate( uint8_t Date )
{
     RS_H;
//  LCD_SendBite(Date);
     LCDSendBite8( Date );
}

static void LCDSendInstr( uint8_t Instr )
{
     RS_L;
//  LCD_SendBite(Instr);
     LCDSendBite8( Instr );
}

static void LCDSendInstrShort( uint8_t Instr )
{
     RS_L;
     EN_H;
     if ( Instr & 0x08 )D7_H; else D7_L;
     if ( Instr & 0x04 )D6_H; else D6_L;
     if ( Instr & 0x02 )D5_H; else D5_L;
     if ( Instr & 0x01 )D4_H; else D4_L;
     Delay_us( 1 );
     EN_L;
     Delay_us( 30 );
}

void LCDClear( void )
{
     LCDSendInstr( 0x01 );
     Delay_us( 1600 );
}

void LCDClearManualDelay( uint32_t delay)
{
     LCDSendInstr( 0x01 );
     Delay_us( delay );
}

void LCDCursorBlink( uint8_t State )
{
     if ( State == 'E' )
     { LCDSendInstr( 0x0D ); }
     else
     { LCDSendInstr( 0x0C ); }

     Delay_us( 50 );
}

void LCDCursorPositionYX( uint8_t Y, uint8_t X )
{
     LCDSendInstr( 0x80 + Y * 0x40 + X );
     Delay_us( 50 );
}

void LCDPrint( uint8_t *str )
{
     char data;
     while ( *str )
     {
          data = *str++;
          LCDSendDate( data );
     }
}

void LCDPrint2Str( uint8_t* str1, uint8_t* str2 )
{
     LCDCursorBlink( 'D' );
     LCDClear();
     LCDCursorPositionYX( 0, 0 );
     LCDPrint( &str1 );
     LCDCursorPositionYX( 1, 0 );
     LCDPrint( &str2 );
}