#ifndef PAGES_H
#define PAGES_H

void cursorShow( Page *p )
{
     LCDCursorBlink( 'D' );
     LCDCursorPositionYX( p->cusorYX[0][p->currentParameter], p->cusorYX[1][p->currentParameter] );
     LCDCursorBlink( 'E' );
}


void InSourcePrint( void )
{
     uint8_t s1[16] = {0,};
     uint8_t s2[16] = {0,};

     sprintf( &s1, "In->%s", inSource.sValue[inSource.iValue] );

     if( inSourceFreq.iValue >= 1000 )
     {
          uint16_t d1 = inSourceFreq.iValue / 1000;
          uint16_t d2 = inSourceFreq.iValue - d1*1000;
          sprintf( &s2, "Fin=%d.%03dkHz", d1, d2 );
     }
     else
     {
          sprintf( &s2, "Fin=%dHz", inSourceFreq.iValue );
     }

     LCDPrint2Str( &s1, &s2 );
}

void GenFreqPrint( void )
{
     uint8_t s1[16] = {0};
     uint8_t s2[16] = {0};

     if( genFreq.iValue >= 1000 )
     {
          uint16_t d1 = genFreq.iValue / 1000;
          uint16_t d2 = genFreq.iValue - d1*1000;
          sprintf( &s2, "Fgen=%d.%03dkHz", d1, d2 );
     }
     else
     {
          sprintf( &s1, "Fgen=%dHz", genFreq.iValue );
     }

     if( inSourceFreq.iValue >= 1000 )
     {
          uint16_t d1 = inSourceFreq.iValue / 1000;
          uint16_t d2 = inSourceFreq.iValue - d1*1000;
          sprintf( &s2, "Fin=%d.%03dkHz", d1, d2 );
     }
     else
     {
          sprintf( &s2, "Fin=%dHz", inSourceFreq.iValue );
     }


     LCDPrint2Str( &s1, &s2 );
}

void Channal1DivPrint( void )
{
     uint8_t s1[16] = {0};
     uint8_t s2[16] = {0};

     sprintf( &s1, "CH1 /div=%d", channal1Devider.iValue );

     uint32_t f = inSourceFreq.iValue/channal1Devider.iValue;
     if( f >= 1000 )
     {
          uint16_t d1 = f / 1000;
          uint16_t d2 = f - d1*1000;
          sprintf( &s2, "Fout=%d.%03dkHz", d1, d2 );
     }
     else
     {
          sprintf( &s2, "Fout=%dHz", f );
     }


     LCDPrint2Str( &s1, &s2 );
}

void Channal1ImpDelPrint( void )
{
     uint8_t s1[16] = {0};
     uint8_t s2[16] = {0};

     if( channal1Impulse.iValue >= 1000 )
     {
          uint16_t d1 = channal1Impulse.iValue / 1000;
          uint16_t d2 = channal1Impulse.iValue - d1*1000;
          sprintf( &s1, "Imp1=%d.%03dus", d1, d2 );
     }
     else
     {
          sprintf( &s1, "Imp1=%dns", channal1Impulse.iValue );
     }


     if( channal1Delay.iValue >= 1000 )
     {
          uint16_t d1 = channal1Delay.iValue / 1000;
          uint16_t d2 = channal1Delay.iValue - d1*1000;
          sprintf( &s2, "Del1=%d.%03dus", d1, d2 );
     }
     else
     {
          sprintf( &s2, "Del1=%dns", channal1Delay.iValue);
     }


     LCDPrint2Str( &s1, &s2 );
}

void Channal2DivPrint( void )
{
     uint8_t s1[16] = {0};
     uint8_t s2[16] = {0};

     sprintf( &s1, "CH2 /div=%d", channal2Devider.iValue );

     uint32_t f = inSourceFreq.iValue/channal2Devider.iValue;
     if( f >= 1000 )
     {
          uint16_t d1 = f / 1000;
          uint16_t d2 = f - d1*1000;
          sprintf( &s2, "Fout=%d.%03dkHz", d1, d2 );
     }
     else
     {
          sprintf( &s2, "Fout=%dHz", f );
     }


     LCDPrint2Str( &s1, &s2 );
}

void Channal2ImpDelPrint( void )
{
     uint8_t s1[16] = {0};
     uint8_t s2[16] = {0};

     if( channal2Impulse.iValue >= 1000 )
     {
          uint16_t d1 = channal2Impulse.iValue / 1000;
          uint16_t d2 = channal2Impulse.iValue - d1*1000;
          sprintf( &s1, "Imp2=%d.%03dus", d1, d2 );
     }
     else
     {
          sprintf( &s1, "Imp2=%dns", channal2Impulse.iValue );
     }


     if( channal2Delay.iValue >= 1000 )
     {
          uint16_t d1 = channal2Delay.iValue / 1000;
          uint16_t d2 = channal2Delay.iValue - d1*1000;
          sprintf( &s2, "Del2=%d.%03dus", d1, d2 );
     }
     else
     {
          sprintf( &s2, "Del2=%dns", channal2Delay.iValue);
     }


     LCDPrint2Str( &s1, &s2 );
}


#endif
