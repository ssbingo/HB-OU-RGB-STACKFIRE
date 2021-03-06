//- -----------------------------------------------------------------------------------------------------------------------
// AskSin++
// 2018-08-03 jp112sdl Creative Commons - http://creativecommons.org/licenses/by-nc-sa/3.0/de/
//- -----------------------------------------------------------------------------------------------------------------------

// define this to read the device id, serial and device type from bootloader section
// #define USE_OTA_BOOTLOADER

#define EI_NOTEXTERNAL
#include <EnableInterrupt.h>
#include <SPI.h>
#include <AskSinPP.h>
#include <LowPower.h>
#include <Register.h>


// - ---------------------------------------------------------------------------- -
// Bei der Belegung der LED-Anschlüsse 11-20                                      -
// - ---------------------------------------------------------------------------- -
#define doubleLED

// - ---------------------------------------------------------------------------- -
// Anzahl der LED's pro Augang - Arduino Mega 2560                                -
// Bei einer Belegung von 144px/m:  max. gesamt 720px                             -
//    -  max  5 x 144px (76% des dynamischen Speichers                            -
//    -  max 10 x  72px (76% des dynamischen Speichers                            -
//    -  max 20 x  36px (76% des dynamischen Speichers                            -
//  nicht belegte Ausgänge auf 1 setzen                                           -
// - ---------------------------------------------------------------------------- -
  #define WSNUM_LEDS10    30         //Anzahl angeschlossener LEDs
  #define WSNUM_LEDS11    30         //Anzahl angeschlossener LEDs
  #define WSNUM_LEDS12    30         //Anzahl angeschlossener LEDs
  #define WSNUM_LEDS13    30         //Anzahl angeschlossener LEDs
  #define WSNUM_LEDS14    30         //Anzahl angeschlossener LEDs
  #define WSNUM_LEDS15    30         //Anzahl angeschlossener LEDs
  #define WSNUM_LEDS16    30         //Anzahl angeschlossener LEDs
  #define WSNUM_LEDS17    30         //Anzahl angeschlossener LEDs        
  #define WSNUM_LEDS18    30         //Anzahl angeschlossener LEDs        
  #define WSNUM_LEDS19    30         //Anzahl angeschlossener LEDs  

#ifdef doubleLED
  #define WSNUM_LEDS20    30         //Anzahl angeschlossener LEDs 
  #define WSNUM_LEDS21    30         //Anzahl angeschlossener LEDs
  #define WSNUM_LEDS22    30         //Anzahl angeschlossener LEDs
  #define WSNUM_LEDS23    30         //Anzahl angeschlossener LEDs
  #define WSNUM_LEDS24    30         //Anzahl angeschlossener LEDs
  #define WSNUM_LEDS25    30         //Anzahl angeschlossener LEDs
  #define WSNUM_LEDS26    30         //Anzahl angeschlossener LEDs
  #define WSNUM_LEDS27    30         //Anzahl angeschlossener LEDs        
  #define WSNUM_LEDS28    30         //Anzahl angeschlossener LEDs
  #define WSNUM_LEDS29    30         //Anzahl angeschlossener LEDs  
#endif
                    
  #define WSLED_PIN_10   3           //GPIO Pin LED Anschluss - Stripe 1 
  #define WSLED_PIN_11   5           //GPIO Pin LED Anschluss - Stripe 2
  #define WSLED_PIN_12   7           //GPIO Pin LED Anschluss - Stripe 3
  #define WSLED_PIN_13   9           //GPIO Pin LED Anschluss - Stripe 4
  #define WSLED_PIN_14   11          //GPIO Pin LED Anschluss - Stripe 5
  #define WSLED_PIN_15   15          //GPIO Pin LED Anschluss - Stripe 6
  #define WSLED_PIN_16   17          //GPIO Pin LED Anschluss - Stripe 7
  #define WSLED_PIN_17   19          //GPIO Pin LED Anschluss - Stripe 8        
  #define WSLED_PIN_18   20          //GPIO Pin LED Anschluss - Stripe 9        
  #define WSLED_PIN_19   21          //GPIO Pin LED Anschluss - Stripe 10   

#ifdef doubleLED
  #define WSLED_PIN_20   23          //GPIO Pin LED Anschluss - Stripe 11 
  #define WSLED_PIN_21   25          //GPIO Pin LED Anschluss - Stripe 12
  #define WSLED_PIN_22   27          //GPIO Pin LED Anschluss - Stripe 13
  #define WSLED_PIN_23   29          //GPIO Pin LED Anschluss - Stripe 14
  #define WSLED_PIN_24   31          //GPIO Pin LED Anschluss - Stripe 15   
  #define WSLED_PIN_25   22          //GPIO Pin LED Anschluss - Stripe 16
  #define WSLED_PIN_26   24          //GPIO Pin LED Anschluss - Stripe 17
  #define WSLED_PIN_27   26          //GPIO Pin LED Anschluss - Stripe 18       
  #define WSLED_PIN_28   28          //GPIO Pin LED Anschluss - Stripe 19      
  #define WSLED_PIN_29   30          //GPIO Pin LED Anschluss - Stripe 19 
#endif

  #define WSLED_TYPE    WS2812B    //LED Typ
  #define WSCOLOR_ORDER GRB        //Farbreihenfolge

  #define SLOW_PROGRAM_TIMER     30     //ms Wartezeit für den Übergang
  #define NORMAL_PROGRAM_TIMER   15     //ms Wartezeit für den Übergang
  #define FAST_PROGRAM_TIMER     0      //ms Wartezeit für den Übergang
  #define FIRE_PROGRAM_COOLING   55
  #define FIRE_PROGRAM_SPARKLING 120


//  -------------------------------------------------------------------------------------
//  - Auswahl der Flammendarstellung (siehe Fire2012/Fire2012WithPalette                -
//  -------------------------------------------------------------------------------------
// COOLING:   20 hohe Flamme ..... 100 kurze Flamme
// SPARKING:  50  mehr Flackern ..... 200 mehr Lodern
// RGBCtrl.h Zeile 748-772 RGBProgramFire1(brightness,"1-6");
//
//  Programm: Langsamer Durchlauf (1)
  #define FIRE_PRG_1_1_COOLING   60
  #define FIRE_PRG_1_1_SPARKING 180
//
//  Programm: Normaler Durchlauf (2)
  #define FIRE_PRG_1_2_COOLING  80
  #define FIRE_PRG_1_2_SPARKING 200
//
//  Programm: Schneller Durchlauf (3)
  #define FIRE_PRG_1_3_COOLING  60
  #define FIRE_PRG_1_3_SPARKING 130
//
//  Programm: Lagerfeuer (4)
  #define FIRE_PRG_2_1_COOLING  100 //60  
  #define FIRE_PRG_2_1_SPARKING 50  //180
//
//  Programm: Wasserfall (5)
  #define FIRE_PRG_2_2_COOLING  80
  #define FIRE_PRG_2_2_SPARKING 75 //200
//
//  Programm: TV-Simulation (6)
  #define FIRE_PRG_2_3_COOLING  60
  #define FIRE_PRG_2_3_SPARKING 130
//  -------------------------------------------------------------------------------------




//  -------------------------------------------------------------------------------------
//  - Auswahl der Farbpalette für FirePrg2 (siehe Fire2012WithPalette                   -
//  - Standard: HeatColors_p                                                            -
//  -------------------------------------------------------------------------------------
#define GPALNR 9
//    
//  1:  static uint8_t hue = 0;
//      hue++;
//      CRGB darkcolor  = CHSV(hue,255,192); // pure hue, three-quarters brightness
//      CRGB lightcolor = CHSV(hue,128,255); // half 'whitened', full brightness
//      gPal = CRGBPalette16( CRGB::Black, darkcolor, lightcolor, CRGB::White);
//  2:  gPal = CRGBPalette256( CRGB::Black, CRGB::OrangeRed, CRGB::Red, CRGB::Yellow );
//  3:  gPal = CRGBPalette16( CRGB::Black, CRGB::Blue, CRGB::Aqua,  CRGB::White);
//  4:  gPal = CRGBPalette16( CRGB::Black, CRGB::Red, CRGB::White);    
//  5:  gPal = RainbowColors_p;
//  6:  gPal = CloudColors_p;
//  7:  gPal = PartyColors_p;
//  8:  gPal = OceanColors_p;
//  9:  gPal = CRGBPalette16( CRGB::Black, CRGB::Red, CRGB::Orange, CRGB::Yellow); //gPal = ForestColors_p;
//  10: gPal = HeatColors_p;
//  11: gPal = LavaColors_p;
//  -------------------------------------------------------------------------------------


//
//  -------------------------------------------------------------------------------------
//  - Auswahl der Darstellungsgeschwindigkeit                                           -
//    I recommend running this simulation at anywhere from 30-100 frames per second,    -
//    meaning an interframe delay of about 10-35 milliseconds.                          -
//  -------------------------------------------------------------------------------------
//
#define FRAMES_PER_SECOND 30
//

#if defined __AVR_ATmega2560__
#define CONFIG_BUTTON_PIN 13
#else
#define CONFIG_BUTTON_PIN 8
#endif
#define ONBOARD_LED_PIN   4

#include "RGBCtrl.h"

#define PEERS_PER_CHANNEL 4

using namespace as;

// define all device properties
const struct DeviceInfo PROGMEM devinfo = {
  {0xFA, 0xB5, 0x01},     // Device ID
  "HB_KAMIN01",           // Device Serial
  {0xFA, 0xB5},           // Device Model
  0x25,                   // Firmware Version
  as::DeviceType::Dimmer, // Device Type
  {0x01, 0x00}            // Info Bytes
};

/**
   Configure the used hardware
*/
#if defined __AVR_ATmega2560__
typedef AskSin<StatusLed<ONBOARD_LED_PIN>, NoBattery, Radio<LibSPI<53>, 2>> HalType;
#else
typedef AskSin<StatusLed<ONBOARD_LED_PIN>, NoBattery, Radio<LibSPI<10>, 2>> HalType;
#endif

DEFREGISTER(Reg0, MASTERID_REGS, 0x20, 0x21)
class Ws28xxList0 : public RegList0<Reg0> {
  public:
    Ws28xxList0(uint16_t addr) : RegList0<Reg0>(addr) {}

    void defaults () {
      clear();
    }
};

typedef RGBLEDChannel<HalType, PEERS_PER_CHANNEL, Ws28xxList0> ChannelType;
typedef RGBLEDDevice<HalType, ChannelType, 3, Ws28xxList0> RGBLEDType;

HalType hal;
RGBLEDType sdev(devinfo, 0x20);
ConfigButton<RGBLEDType> cfgBtn(sdev);

void setup () {
  DINIT(57600, ASKSIN_PLUS_PLUS_IDENTIFIER);
  sdev.init(hal);
  buttonISR(cfgBtn, CONFIG_BUTTON_PIN);
  
  /*
  // Set frequency for CC1101
  hal.radio.initReg(CC1101_FREQ2, 0x21);
  hal.radio.initReg(CC1101_FREQ1, 0x66);
  hal.radio.initReg(CC1101_FREQ0, 0x72);
*/
  
  sdev.initDone();
}

void loop() {
  bool worked = hal.runready();
  bool poll = sdev.pollRadio();
  if ( worked == false && poll == false ) {
    hal.activity.savePower<Idle<true>>(hal);
  }
  
  sdev.handleLED();
}
