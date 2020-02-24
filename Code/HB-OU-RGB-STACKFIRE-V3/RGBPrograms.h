void RGBProgramRainbow(uint8_t speed, uint8_t brightness) {
  static uint8_t startIndex = 0;
  static unsigned long lastmillis = millis();
  if (millis() - lastmillis > speed) {
    startIndex = startIndex + 1;
    for ( int i = 0; i < WSNUM_LEDS10; i++) {
      leds10[i] = ColorFromPalette( RainbowColors_p, startIndex, brightness, LINEARBLEND);
    }
    for ( int i = 0; i < WSNUM_LEDS11; i++) {
      leds11[i] = ColorFromPalette( RainbowColors_p, startIndex, brightness, LINEARBLEND);
    }  
    for ( int i = 0; i < WSNUM_LEDS12; i++) {
      leds12[i] = ColorFromPalette( RainbowColors_p, startIndex, brightness, LINEARBLEND);
    } 
    for ( int i = 0; i < WSNUM_LEDS13; i++) {
      leds13[i] = ColorFromPalette( RainbowColors_p, startIndex, brightness, LINEARBLEND);
    } 
    for ( int i = 0; i < WSNUM_LEDS14; i++) {
      leds14[i] = ColorFromPalette( RainbowColors_p, startIndex, brightness, LINEARBLEND);
    } 
    for ( int i = 0; i < WSNUM_LEDS15; i++) {
      leds15[i] = ColorFromPalette( RainbowColors_p, startIndex, brightness, LINEARBLEND);
    } 
    for ( int i = 0; i < WSNUM_LEDS16; i++) {
      leds16[i] = ColorFromPalette( RainbowColors_p, startIndex, brightness, LINEARBLEND);
    } 
    for ( int i = 0; i < WSNUM_LEDS17; i++) {
      leds17[i] = ColorFromPalette( RainbowColors_p, startIndex, brightness, LINEARBLEND);
    } 
    for ( int i = 0; i < WSNUM_LEDS18; i++) {
      leds18[i] = ColorFromPalette( RainbowColors_p, startIndex, brightness, LINEARBLEND);
    } 
    for ( int i = 0; i < WSNUM_LEDS19; i++) {
      leds19[i] = ColorFromPalette( RainbowColors_p, startIndex, brightness, LINEARBLEND);
    }     
    
#ifdef doubleLED
    for ( int i = 0; i < WSNUM_LEDS20; i++) {
      leds20[i] = ColorFromPalette( RainbowColors_p, startIndex, brightness, LINEARBLEND);
    }
    for ( int i = 0; i < WSNUM_LEDS21; i++) {
      leds21[i] = ColorFromPalette( RainbowColors_p, startIndex, brightness, LINEARBLEND);
    }  
    for ( int i = 0; i < WSNUM_LEDS22; i++) {
      leds22[i] = ColorFromPalette( RainbowColors_p, startIndex, brightness, LINEARBLEND);
    } 
    for ( int i = 0; i < WSNUM_LEDS23; i++) {
      leds23[i] = ColorFromPalette( RainbowColors_p, startIndex, brightness, LINEARBLEND);
    } 
    for ( int i = 0; i < WSNUM_LEDS24; i++) {
      leds24[i] = ColorFromPalette( RainbowColors_p, startIndex, brightness, LINEARBLEND);
    } 
    for ( int i = 0; i < WSNUM_LEDS25; i++) {
      leds25[i] = ColorFromPalette( RainbowColors_p, startIndex, brightness, LINEARBLEND);
    } 
    for ( int i = 0; i < WSNUM_LEDS26; i++) {
      leds26[i] = ColorFromPalette( RainbowColors_p, startIndex, brightness, LINEARBLEND);
    } 
    for ( int i = 0; i < WSNUM_LEDS27; i++) {
      leds27[i] = ColorFromPalette( RainbowColors_p, startIndex, brightness, LINEARBLEND);
    } 
    for ( int i = 0; i < WSNUM_LEDS28; i++) {
      leds28[i] = ColorFromPalette( RainbowColors_p, startIndex, brightness, LINEARBLEND);
    } 
    for ( int i = 0; i < WSNUM_LEDS29; i++) {
      leds29[i] = ColorFromPalette( RainbowColors_p, startIndex, brightness, LINEARBLEND);
    }  
#endif
                          
    lastmillis = millis();
  }
}

/*
void RGBProgramFire(uint8_t brightness) {
  static unsigned long lastmillis = millis();
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


    for ( int i = 0; i < WSNUM_LEDS10; i++) {
      heat10[i] = qsub8( heat10[i],  random8(0, ((FIRE_PROGRAM_COOLING * 10) / WSNUM_LEDS10) + 2));
    }
    for ( int i = 0; i < WSNUM_LEDS11; i++) {
      heat11[i] = qsub8( heat11[i],  random8(0, ((FIRE_PROGRAM_COOLING * 10) / WSNUM_LEDS11) + 2));
    }        
    for ( int i = 0; i < WSNUM_LEDS12; i++) {
      heat12[i] = qsub8( heat12[i],  random8(0, ((FIRE_PROGRAM_COOLING * 10) / WSNUM_LEDS12) + 2));
    }
    for ( int i = 0; i < WSNUM_LEDS13; i++) {
      heat13[i] = qsub8( heat13[i],  random8(0, ((FIRE_PROGRAM_COOLING * 10) / WSNUM_LEDS13) + 2));
    }
    for ( int i = 0; i < WSNUM_LEDS14; i++) {
      heat14[i] = qsub8( heat14[i],  random8(0, ((FIRE_PROGRAM_COOLING * 10) / WSNUM_LEDS14) + 2));
    }
    for ( int i = 0; i < WSNUM_LEDS15; i++) {
      heat15[i] = qsub8( heat15[i],  random8(0, ((FIRE_PROGRAM_COOLING * 10) / WSNUM_LEDS15) + 2));
    }
    for ( int i = 0; i < WSNUM_LEDS16; i++) {
      heat16[i] = qsub8( heat16[i],  random8(0, ((FIRE_PROGRAM_COOLING * 10) / WSNUM_LEDS16) + 2));
    }
    for ( int i = 0; i < WSNUM_LEDS17; i++) {
      heat17[i] = qsub8( heat17[i],  random8(0, ((FIRE_PROGRAM_COOLING * 10) / WSNUM_LEDS17) + 2));
    }
    for ( int i = 0; i < WSNUM_LEDS18; i++) {
      heat18[i] = qsub8( heat18[i],  random8(0, ((FIRE_PROGRAM_COOLING * 10) / WSNUM_LEDS18) + 2));
    }
    for ( int i = 0; i < WSNUM_LEDS19; i++) {
      heat19[i] = qsub8( heat19[i],  random8(0, ((FIRE_PROGRAM_COOLING * 10) / WSNUM_LEDS19) + 2));
    } 

    for ( int i = 0; i < WSNUM_LEDS20; i++) {
      heat20[i] = qsub8( heat20[i],  random8(0, ((FIRE_PROGRAM_COOLING * 20) / WSNUM_LEDS20) + 2));
    }
    for ( int i = 0; i < WSNUM_LEDS21; i++) {
      heat21[i] = qsub8( heat21[i],  random8(0, ((FIRE_PROGRAM_COOLING * 20) / WSNUM_LEDS21) + 2));
    }        
    for ( int i = 0; i < WSNUM_LEDS22; i++) {
      heat22[i] = qsub8( heat22[i],  random8(0, ((FIRE_PROGRAM_COOLING * 20) / WSNUM_LEDS22) + 2));
    }
    for ( int i = 0; i < WSNUM_LEDS23; i++) {
      heat23[i] = qsub8( heat23[i],  random8(0, ((FIRE_PROGRAM_COOLING * 20) / WSNUM_LEDS23) + 2));
    }
    for ( int i = 0; i < WSNUM_LEDS24; i++) {
      heat24[i] = qsub8( heat24[i],  random8(0, ((FIRE_PROGRAM_COOLING * 20) / WSNUM_LEDS24) + 2));
    }


    for ( int i = 0; i < WSNUM_LEDS25; i++) {
      heat25[i] = qsub8( heat25[i],  random8(0, ((FIRE_PROGRAM_COOLING * 10) / WSNUM_LEDS25) + 2));
    }
    for ( int i = 0; i < WSNUM_LEDS26; i++) {
      heat26[i] = qsub8( heat26[i],  random8(0, ((FIRE_PROGRAM_COOLING * 10) / WSNUM_LEDS26) + 2));
    }
    for ( int i = 0; i < WSNUM_LEDS27; i++) {
      heat27[i] = qsub8( heat27[i],  random8(0, ((FIRE_PROGRAM_COOLING * 10) / WSNUM_LEDS27) + 2));
    }
    for ( int i = 0; i < WSNUM_LEDS28; i++) {
      heat28[i] = qsub8( heat28[i],  random8(0, ((FIRE_PROGRAM_COOLING * 10) / WSNUM_LEDS28) + 2));
    }
    for ( int i = 0; i < WSNUM_LEDS29; i++) {
      heat29[i] = qsub8( heat29[i],  random8(0, ((FIRE_PROGRAM_COOLING * 10) / WSNUM_LEDS29) + 2));
    } 

    
    
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



    
    if ( random8() < FIRE_PROGRAM_SPARKLING ) {
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

      heat20[y] = qadd8( heat20[y], random8(160, 255) );
      heat21[y] = qadd8( heat21[y], random8(160, 255) );
      heat22[y] = qadd8( heat22[y], random8(160, 255) ); 
      heat23[y] = qadd8( heat23[y], random8(160, 255) );
      heat24[y] = qadd8( heat24[y], random8(160, 255) );

      heat25[y] = qadd8( heat25[y], random8(260, 255) ); 
      heat26[y] = qadd8( heat26[y], random8(260, 255) );
      heat27[y] = qadd8( heat27[y], random8(260, 255) );
      heat28[y] = qadd8( heat28[y], random8(260, 255) ); 
      heat29[y] = qadd8( heat29[y], random8(260, 255) ); 
       
    }

    
    for ( int j = 0; j < WSNUM_LEDS10; j++) {
      CRGB color = HeatColor( heat10[j]);
      int pixelnumber;

      pixelnumber = j;

      leds10[pixelnumber] = color;
    }
    for ( int j = 0; j < WSNUM_LEDS11; j++) {
      CRGB color = HeatColor( heat11[j]);
      int pixelnumber;

      pixelnumber = j;

      leds11[pixelnumber] = color;
    }
    for ( int j = 0; j < WSNUM_LEDS12; j++) {
      CRGB color = HeatColor( heat12[j]);
      int pixelnumber;

      pixelnumber = j;

      leds12[pixelnumber] = color;
    }
    for ( int j = 0; j < WSNUM_LEDS13; j++) {
      CRGB color = HeatColor( heat13[j]);
      int pixelnumber;

      pixelnumber = j;

      leds13[pixelnumber] = color;
    }
    for ( int j = 0; j < WSNUM_LEDS14; j++) {
      CRGB color = HeatColor( heat14[j]);
      int pixelnumber;

      pixelnumber = j;

      leds14[pixelnumber] = color;
    }
    for ( int j = 0; j < WSNUM_LEDS15; j++) {
      CRGB color = HeatColor( heat15[j]);
      int pixelnumber;

      pixelnumber = j;

      leds15[pixelnumber] = color;
    }
    for ( int j = 0; j < WSNUM_LEDS16; j++) {
      CRGB color = HeatColor( heat16[j]);
      int pixelnumber;

      pixelnumber = j;

      leds16[pixelnumber] = color;
    }
    for ( int j = 0; j < WSNUM_LEDS17; j++) {
      CRGB color = HeatColor( heat17[j]);
      int pixelnumber;

      pixelnumber = j;

      leds17[pixelnumber] = color;
    }
    for ( int j = 0; j < WSNUM_LEDS18; j++) {
      CRGB color = HeatColor( heat18[j]);
      int pixelnumber;

      pixelnumber = j;

      leds18[pixelnumber] = color;
    }
    for ( int j = 0; j < WSNUM_LEDS19; j++) {
      CRGB color = HeatColor( heat19[j]);
      int pixelnumber;

      pixelnumber = j;

      leds19[pixelnumber] = color;
    }


    for ( int j = 0; j < WSNUM_LEDS20; j++) {
      CRGB color = HeatColor( heat20[j]);
      int pixelnumber;

      pixelnumber = j;

      leds20[pixelnumber] = color;
    }
    for ( int j = 0; j < WSNUM_LEDS21; j++) {
      CRGB color = HeatColor( heat21[j]);
      int pixelnumber;

      pixelnumber = j;

      leds21[pixelnumber] = color;
    }
    for ( int j = 0; j < WSNUM_LEDS22; j++) {
      CRGB color = HeatColor( heat22[j]);
      int pixelnumber;

      pixelnumber = j;

      leds22[pixelnumber] = color;
    }
    for ( int j = 0; j < WSNUM_LEDS23; j++) {
      CRGB color = HeatColor( heat23[j]);
      int pixelnumber;

      pixelnumber = j;

      leds23[pixelnumber] = color;
    }
    for ( int j = 0; j < WSNUM_LEDS24; j++) {
      CRGB color = HeatColor( heat24[j]);
      int pixelnumber;

      pixelnumber = j;

      leds24[pixelnumber] = color;
    }


    for ( int j = 0; j < WSNUM_LEDS25; j++) {
      CRGB color = HeatColor( heat25[j]);
      int pixelnumber;

      pixelnumber = j;

      leds25[pixelnumber] = color;
    }
    for ( int j = 0; j < WSNUM_LEDS26; j++) {
      CRGB color = HeatColor( heat26[j]);
      int pixelnumber;

      pixelnumber = j;

      leds26[pixelnumber] = color;
    }
    for ( int j = 0; j < WSNUM_LEDS27; j++) {
      CRGB color = HeatColor( heat27[j]);
      int pixelnumber;

      pixelnumber = j;

      leds27[pixelnumber] = color;
    }
    for ( int j = 0; j < WSNUM_LEDS28; j++) {
      CRGB color = HeatColor( heat28[j]);
      int pixelnumber;

      pixelnumber = j;

      leds28[pixelnumber] = color;
    }
    for ( int j = 0; j < WSNUM_LEDS29; j++) {
      CRGB color = HeatColor( heat29[j]);
      int pixelnumber;

      pixelnumber = j;

      leds29[pixelnumber] = color;
    }



    lastmillis = millis();
  }
}
*/ 

void RGBProgramWaterfall (uint8_t brightness) {}

void RGBProgramTVSimulation (uint8_t brightness) {}
