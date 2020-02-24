#ifndef __RGBPROGRAMSFIRE_H__
#define __RGBPROGRAMSFIRE_H__

CRGBPalette16 gPal;

void RGBProgramFire1(uint8_t brightness, uint8_t PrgNr) {
  
  static unsigned long lastmillis = millis();

  uint8_t COOLING = 0;
  uint8_t SPARKING = 0; 

 switch (PrgNr) {
  case 1:
    COOLING = FIRE_PRG_1_1_COOLING;
    SPARKING = FIRE_PRG_1_1_SPARKING;
    break;    
  case 2:
    COOLING = FIRE_PRG_1_2_COOLING;
    SPARKING = FIRE_PRG_1_2_SPARKING;
    break;    
  case 3:
    COOLING = FIRE_PRG_1_3_COOLING;
    SPARKING = FIRE_PRG_1_3_SPARKING;
    break;    
  case 4:
    COOLING = FIRE_PRG_2_1_COOLING;
    SPARKING = FIRE_PRG_2_1_SPARKING;
    break;    
  case 5:
    COOLING = FIRE_PRG_2_2_COOLING;
    SPARKING = FIRE_PRG_2_2_SPARKING;
    break;    
  case 6:
    COOLING = FIRE_PRG_2_3_COOLING;
    SPARKING = FIRE_PRG_2_3_SPARKING;
    break;        
}

if (GPALNR == 1) {
    static uint8_t hue = 0;
    hue++;
    CRGB darkcolor  = CHSV(hue,255,192); // pure hue, three-quarters brightness
    CRGB lightcolor = CHSV(hue,128,255); // half 'whitened', full brightness
    gPal = CRGBPalette16( CRGB::Black, darkcolor, lightcolor, CRGB::White);
}else if (GPALNR == 2) {
    gPal = CRGBPalette256( CRGB::Black, CRGB::Red, CRGB::OrangeRed, CRGB::Yellow );
}else if (GPALNR == 3) {
    gPal = CRGBPalette16( CRGB::Black, CRGB::Blue, CRGB::Aqua,  CRGB::White);
}else if (GPALNR == 4) {    
    gPal = CRGBPalette16( CRGB::Black, CRGB::Red, CRGB::White);    
}else if (GPALNR == 5) {    
    gPal = RainbowColors_p;
}else if (GPALNR == 6) {    
    gPal = CloudColors_p;
}else if (GPALNR == 7) {    
    gPal = PartyColors_p;
}else if (GPALNR == 8) {    
    gPal = OceanColors_p;
}else if (GPALNR == 9) {    
    gPal = CRGBPalette16( CRGB::Black, CRGB::Red, CRGB::Orange, CRGB::Yellow);  //gPal = ForestColors_p;
}else if (GPALNR == 10) {    
    gPal = HeatColors_p;
}else if (GPALNR == 11) {    
    gPal = LavaColors_p;
}


  if (millis() - lastmillis > 15) {

    static byte heat10[WSNUM_LEDS10];
    static byte heat11[WSNUM_LEDS11];
    static byte heat12[WSNUM_LEDS12];
    static byte heat13[WSNUM_LEDS13];
    static byte heat14[WSNUM_LEDS14];
    static byte heat15[WSNUM_LEDS15];
    static byte heat16[WSNUM_LEDS16];
    static byte heat17[WSNUM_LEDS17];    
    static byte heat18[WSNUM_LEDS18];    
    static byte heat19[WSNUM_LEDS19];    

#ifdef doubleLED
    static byte heat20[WSNUM_LEDS20];  
    static byte heat21[WSNUM_LEDS21];  
    static byte heat22[WSNUM_LEDS22];
    static byte heat23[WSNUM_LEDS23];
    static byte heat24[WSNUM_LEDS24];
    static byte heat25[WSNUM_LEDS25];
    static byte heat26[WSNUM_LEDS26];
    static byte heat27[WSNUM_LEDS27];    
    static byte heat28[WSNUM_LEDS28];      
    static byte heat29[WSNUM_LEDS29];                         
#endif

    for ( int i = 0; i < WSNUM_LEDS10; i++) {
      heat10[i] = qsub8( heat10[i],  random8(0, ((COOLING * 10) / WSNUM_LEDS10) + 2));
    }
    for ( int i = 0; i < WSNUM_LEDS11; i++) {
      heat11[i] = qsub8( heat11[i],  random8(0, ((COOLING * 10) / WSNUM_LEDS11) + 2));
    }
    for ( int i = 0; i < WSNUM_LEDS12; i++) {
      heat12[i] = qsub8( heat12[i],  random8(0, ((COOLING * 10) / WSNUM_LEDS12) + 2));
    }
    for ( int i = 0; i < WSNUM_LEDS13; i++) {
      heat13[i] = qsub8( heat13[i],  random8(0, ((COOLING * 10) / WSNUM_LEDS13) + 2));
    }
    for ( int i = 0; i < WSNUM_LEDS14; i++) {
      heat14[i] = qsub8( heat14[i],  random8(0, ((COOLING * 10) / WSNUM_LEDS14) + 2));
    }
    for ( int i = 0; i < WSNUM_LEDS15; i++) {
      heat15[i] = qsub8( heat15[i],  random8(0, ((COOLING * 10) / WSNUM_LEDS15) + 2));
    }
    for ( int i = 0; i < WSNUM_LEDS16; i++) {
      heat16[i] = qsub8( heat16[i],  random8(0, ((COOLING * 10) / WSNUM_LEDS16) + 2));
    }
    for ( int i = 0; i < WSNUM_LEDS17; i++) {
      heat17[i] = qsub8( heat17[i],  random8(0, ((COOLING * 10) / WSNUM_LEDS17) + 2));
    }                    
    for ( int i = 0; i < WSNUM_LEDS18; i++) {
      heat18[i] = qsub8( heat18[i],  random8(0, ((COOLING * 10) / WSNUM_LEDS18) + 2));
    }                    
    for ( int i = 0; i < WSNUM_LEDS19; i++) {
      heat19[i] = qsub8( heat18[i],  random8(0, ((COOLING * 10) / WSNUM_LEDS19) + 2));
    }                    


#ifdef doubleLED
    for ( int i = 0; i < WSNUM_LEDS20; i++) {
      heat20[i] = qsub8( heat20[i],  random8(0, ((COOLING * 10) / WSNUM_LEDS20) + 2));
    }
    for ( int i = 0; i < WSNUM_LEDS21; i++) {
      heat21[i] = qsub8( heat21[i],  random8(0, ((COOLING * 10) / WSNUM_LEDS21) + 2));
    }
    for ( int i = 0; i < WSNUM_LEDS22; i++) {
      heat22[i] = qsub8( heat22[i],  random8(0, ((COOLING * 10) / WSNUM_LEDS22) + 2));
    }
    for ( int i = 0; i < WSNUM_LEDS23; i++) {
      heat23[i] = qsub8( heat22[i],  random8(0, ((COOLING * 10) / WSNUM_LEDS23) + 2));
    }
    for ( int i = 0; i < WSNUM_LEDS24; i++) {
      heat24[i] = qsub8( heat24[i],  random8(0, ((COOLING * 10) / WSNUM_LEDS24) + 2));
    }
    for ( int i = 0; i < WSNUM_LEDS25; i++) {
      heat25[i] = qsub8( heat25[i],  random8(0, ((COOLING * 10) / WSNUM_LEDS25) + 2));
    }
    for ( int i = 0; i < WSNUM_LEDS26; i++) {
      heat26[i] = qsub8( heat26[i],  random8(0, ((COOLING * 10) / WSNUM_LEDS26) + 2));
    }
    for ( int i = 0; i < WSNUM_LEDS27; i++) {
      heat27[i] = qsub8( heat27[i],  random8(0, ((COOLING * 10) / WSNUM_LEDS27) + 2));
    }
    for ( int i = 0; i < WSNUM_LEDS28; i++) {
      heat28[i] = qsub8( heat28[i],  random8(0, ((COOLING * 10) / WSNUM_LEDS28) + 2));
    }    
    for ( int i = 0; i < WSNUM_LEDS29; i++) {
      heat29[i] = qsub8( heat29[i],  random8(0, ((COOLING * 10) / WSNUM_LEDS29) + 2));
    }                    
#endif

    for ( int k = WSNUM_LEDS10 - 1; k >= 2; k--) {
      heat10[k] = (heat10[k - 1] + heat10[k - 2] + heat10[k - 2] ) / 3;
    }
    for ( int k = WSNUM_LEDS11 - 1; k >= 2; k--) {
      heat11[k] = (heat11[k - 1] + heat11[k - 2] + heat11[k - 2] ) / 3;
    }
    for ( int k = WSNUM_LEDS12 - 1; k >= 2; k--) {
      heat12[k] = (heat12[k - 1] + heat12[k - 2] + heat12[k - 2] ) / 3;
    }
    for ( int k = WSNUM_LEDS13 - 1; k >= 2; k--) {
      heat13[k] = (heat13[k - 1] + heat13[k - 2] + heat13[k - 2] ) / 3;
    }
    for ( int k = WSNUM_LEDS14 - 1; k >= 2; k--) {
      heat14[k] = (heat14[k - 1] + heat14[k - 2] + heat14[k - 2] ) / 3;
    }
    for ( int k = WSNUM_LEDS15 - 1; k >= 2; k--) {
      heat15[k] = (heat15[k - 1] + heat15[k - 2] + heat15[k - 2] ) / 3;
    }
    for ( int k = WSNUM_LEDS16 - 1; k >= 2; k--) {
      heat16[k] = (heat16[k - 1] + heat16[k - 2] + heat16[k - 2] ) / 3;
    }
    for ( int k = WSNUM_LEDS17 - 1; k >= 2; k--) {
      heat17[k] = (heat17[k - 1] + heat17[k - 2] + heat17[k - 2] ) / 3;
    }                
    for ( int k = WSNUM_LEDS18 - 1; k >= 2; k--) {
      heat18[k] = (heat18[k - 1] + heat18[k - 2] + heat18[k - 2] ) / 3;
    }                
    for ( int k = WSNUM_LEDS19 - 1; k >= 2; k--) {
      heat19[k] = (heat19[k - 1] + heat19[k - 2] + heat19[k - 2] ) / 3;
    }                


#ifdef doubleLED
    for ( int k = WSNUM_LEDS20 - 1; k >= 2; k--) {
      heat20[k] = (heat20[k - 1] + heat20[k - 2] + heat20[k - 2] ) / 3;
    }
    for ( int k = WSNUM_LEDS21 - 1; k >= 2; k--) {
      heat21[k] = (heat21[k - 1] + heat21[k - 2] + heat21[k - 2] ) / 3;
    }
    for ( int k = WSNUM_LEDS22 - 1; k >= 2; k--) {
      heat22[k] = (heat22[k - 1] + heat22[k - 2] + heat22[k - 2] ) / 3;
    }
    for ( int k = WSNUM_LEDS23 - 1; k >= 2; k--) {
      heat23[k] = (heat23[k - 1] + heat23[k - 2] + heat23[k - 2] ) / 3;
    }
    for ( int k = WSNUM_LEDS24 - 1; k >= 2; k--) {
      heat24[k] = (heat24[k - 1] + heat24[k - 2] + heat24[k - 2] ) / 3;
    }
    for ( int k = WSNUM_LEDS25 - 1; k >= 2; k--) {
      heat25[k] = (heat25[k - 1] + heat25[k - 2] + heat25[k - 2] ) / 3;
    }
    for ( int k = WSNUM_LEDS26 - 1; k >= 2; k--) {
      heat26[k] = (heat26[k - 1] + heat26[k - 2] + heat26[k - 2] ) / 3;
    }
    for ( int k = WSNUM_LEDS27 - 1; k >= 2; k--) {
      heat27[k] = (heat27[k - 1] + heat27[k - 2] + heat27[k - 2] ) / 3;
    }
    for ( int k = WSNUM_LEDS28 - 1; k >= 2; k--) {
      heat28[k] = (heat28[k - 1] + heat28[k - 2] + heat28[k - 2] ) / 3;
    }
    for ( int k = WSNUM_LEDS29 - 1; k >= 2; k--) {
      heat29[k] = (heat29[k - 1] + heat29[k - 2] + heat29[k - 2] ) / 3;
    }
#endif    
       
    if ( random8() < SPARKING ) {
      int y = random8(7);
      heat10[y] = qadd8( heat10[y], random8(160, 255) );
      heat11[y] = qadd8( heat11[y], random8(160, 255) );
      heat12[y] = qadd8( heat12[y], random8(160, 255) );
      heat13[y] = qadd8( heat13[y], random8(160, 255) );
      heat14[y] = qadd8( heat14[y], random8(160, 255) );
      heat15[y] = qadd8( heat15[y], random8(160, 255) );
      heat16[y] = qadd8( heat16[y], random8(160, 255) );
      heat17[y] = qadd8( heat17[y], random8(160, 255) );
      heat18[y] = qadd8( heat18[y], random8(160, 255) );
      heat19[y] = qadd8( heat19[y], random8(160, 255) ); 

#ifdef doubleLED
      heat20[y] = qadd8( heat20[y], random8(160, 255) );
      heat21[y] = qadd8( heat21[y], random8(160, 255) );
      heat22[y] = qadd8( heat22[y], random8(160, 255) );
      heat23[y] = qadd8( heat23[y], random8(160, 255) );
      heat24[y] = qadd8( heat24[y], random8(160, 255) );
      heat25[y] = qadd8( heat25[y], random8(160, 255) );
      heat26[y] = qadd8( heat26[y], random8(160, 255) );
      heat27[y] = qadd8( heat27[y], random8(160, 255) );
      heat28[y] = qadd8( heat28[y], random8(160, 255) );
      heat29[y] = qadd8( heat29[y], random8(160, 255) );     
#endif
    }

    for ( int j = 0; j < WSNUM_LEDS10; j++) {
      //CRGB color = HeatColor( heat[j]);
      byte colorindex = scale8( heat10[j], 240);
      CRGB color = ColorFromPalette( gPal, colorindex);
      int pixelnumber;

    pixelnumber = j;

      leds10[pixelnumber] = color;
    }
    
    for ( int j = 0; j < WSNUM_LEDS11; j++) {
      //CRGB color = HeatColor( heat[j]);
      byte colorindex = scale8( heat11[j], 240);
      CRGB color = ColorFromPalette( gPal, colorindex);
      int pixelnumber;

    pixelnumber = j;

      leds11[pixelnumber] = color;
    }
    
    for ( int j = 0; j < WSNUM_LEDS12; j++) {
      //CRGB color = HeatColor( heat[j]);
      byte colorindex = scale8( heat12[j], 240);
      CRGB color = ColorFromPalette( gPal, colorindex);
      int pixelnumber;

    pixelnumber = j;

      leds12[pixelnumber] = color;
    }

    for ( int j = 0; j < WSNUM_LEDS13; j++) {
      //CRGB color = HeatColor( heat[j]);
      byte colorindex = scale8( heat13[j], 240);
      CRGB color = ColorFromPalette( gPal, colorindex);
      int pixelnumber;

    pixelnumber = j;

      leds13[pixelnumber] = color;
    }

    for ( int j = 0; j < WSNUM_LEDS14; j++) {
      //CRGB color = HeatColor( heat[j]);
      byte colorindex = scale8( heat14[j], 240);
      CRGB color = ColorFromPalette( gPal, colorindex);
      int pixelnumber;

    pixelnumber = j;

      leds14[pixelnumber] = color;
    }

    for ( int j = 0; j < WSNUM_LEDS15; j++) {
      //CRGB color = HeatColor( heat[j]);
      byte colorindex = scale8( heat15[j], 240);
      CRGB color = ColorFromPalette( gPal, colorindex);
      int pixelnumber;

    pixelnumber = j;

      leds15[pixelnumber] = color;
    }

    for ( int j = 0; j < WSNUM_LEDS16; j++) {
      //CRGB color = HeatColor( heat[j]);
      byte colorindex = scale8( heat16[j], 240);
      CRGB color = ColorFromPalette( gPal, colorindex);
      int pixelnumber;

    pixelnumber = j;

      leds16[pixelnumber] = color;
    }

    for ( int j = 0; j < WSNUM_LEDS17; j++) {
      //CRGB color = HeatColor( heat[j]);
      byte colorindex = scale8( heat17[j], 240);
      CRGB color = ColorFromPalette( gPal, colorindex);
      int pixelnumber;

    pixelnumber = j;

      leds17[pixelnumber] = color;
    }
    for ( int j = 0; j < WSNUM_LEDS18; j++) {
      //CRGB color = HeatColor( heat[j]);
      byte colorindex = scale8( heat18[j], 240);
      CRGB color = ColorFromPalette( gPal, colorindex);
      int pixelnumber;

    pixelnumber = j;

      leds18[pixelnumber] = color;
    }
    for ( int j = 0; j < WSNUM_LEDS19; j++) {
      //CRGB color = HeatColor( heat[j]);
      byte colorindex = scale8( heat19[j], 240);
      CRGB color = ColorFromPalette( gPal, colorindex);
      int pixelnumber;

    pixelnumber = j;

      leds19[pixelnumber] = color;
    }  



#ifdef doubleLED
    for ( int j = 0; j < WSNUM_LEDS20; j++) {
      //CRGB color = HeatColor( heat[j]);
      byte colorindex = scale8( heat20[j], 240);
      CRGB color = ColorFromPalette( gPal, colorindex);
      int pixelnumber;

    pixelnumber = j;

      leds20[pixelnumber] = color;
    }
    
    for ( int j = 0; j < WSNUM_LEDS21; j++) {
      //CRGB color = HeatColor( heat[j]);
      byte colorindex = scale8( heat21[j], 240);
      CRGB color = ColorFromPalette( gPal, colorindex);
      int pixelnumber;

    pixelnumber = j;

      leds21[pixelnumber] = color;
    }

    for ( int j = 0; j < WSNUM_LEDS21; j++) {
      //CRGB color = HeatColor( heat[j]);
      byte colorindex = scale8( heat21[j], 240);
      CRGB color = ColorFromPalette( gPal, colorindex);
      int pixelnumber;

    pixelnumber = j;

      leds22[pixelnumber] = color;
    }

    for ( int j = 0; j < WSNUM_LEDS23; j++) {
      //CRGB color = HeatColor( heat[j]);
      byte colorindex = scale8( heat23[j], 240);
      CRGB color = ColorFromPalette( gPal, colorindex);
      int pixelnumber;

    pixelnumber = j;

      leds23[pixelnumber] = color;
    }
    
    for ( int j = 0; j < WSNUM_LEDS24; j++) {
      //CRGB color = HeatColor( heat[j]);
      byte colorindex = scale8( heat24[j], 240);
      CRGB color = ColorFromPalette( gPal, colorindex);
      int pixelnumber;

    pixelnumber = j;

      leds24[pixelnumber] = color;
    }
    
    for ( int j = 0; j < WSNUM_LEDS25; j++) {
      //CRGB color = HeatColor( heat[j]);
      byte colorindex = scale8( heat25[j], 240);
      CRGB color = ColorFromPalette( gPal, colorindex);
      int pixelnumber;

    pixelnumber = j;

      leds25[pixelnumber] = color;
    }
    
    for ( int j = 0; j < WSNUM_LEDS26; j++) {
      //CRGB color = HeatColor( heat[j]);
      byte colorindex = scale8( heat26[j], 240);
      CRGB color = ColorFromPalette( gPal, colorindex);
      int pixelnumber;

    pixelnumber = j;

      leds26[pixelnumber] = color;
    }
    
    for ( int j = 0; j < WSNUM_LEDS27; j++) {
      //CRGB color = HeatColor( heat[j]);
      byte colorindex = scale8( heat27[j], 240);
      CRGB color = ColorFromPalette( gPal, colorindex);
      int pixelnumber;

    pixelnumber = j;

      leds27[pixelnumber] = color;
    }
    
    for ( int j = 0; j < WSNUM_LEDS28; j++) {
      //CRGB color = HeatColor( heat[j]);
      byte colorindex = scale8( heat28[j], 240);
      CRGB color = ColorFromPalette( gPal, colorindex);
      int pixelnumber;

    pixelnumber = j;

      leds28[pixelnumber] = color;
    }
    
    for ( int j = 0; j < WSNUM_LEDS29; j++) {
      //CRGB color = HeatColor( heat[j]);
      byte colorindex = scale8( heat29[j], 240);
      CRGB color = ColorFromPalette( gPal, colorindex);
      int pixelnumber;

    pixelnumber = j;

      leds29[pixelnumber] = color;
    }
#endif
    lastmillis = millis();
  }
}

#endif
