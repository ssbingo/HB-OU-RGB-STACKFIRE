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

void RGBProgramWaterfall (uint8_t brightness) {}

void RGBProgramTVSimulation (uint8_t brightness) {}
