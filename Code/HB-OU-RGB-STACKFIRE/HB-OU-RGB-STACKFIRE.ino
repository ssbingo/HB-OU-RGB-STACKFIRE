//- -----------------------------------------------------------------------------------------------------------------------
// AskSin++
// 2018-08-03 jp112sdl Creative Commons - http://creativecommons.org/licenses/by-nc-sa/3.0/de/
//- -----------------------------------------------------------------------------------------------------------------------

// define this to read the device id, serial and device type from bootloader section
// #define USE_OTA_BOOTLOADER

//#define USE_BATTERY

#define USE MEGA


//#ifdef USE_BATTERY
//  #define USE_WOR
//  #define BAT_CRITICAL 15
//  #define BATTSENS BattSensor<AsyncMeter<InternalVCC>>
//  #define MODEL_1 0xFA
//  #define MODEL_2 0xB6
//#else
  #define BATTSENS NoBattery
  #define MODEL_1 0xFA
  #define MODEL_2 0xB5
//#endif


#define EI_NOTEXTERNAL
#include <EnableInterrupt.h>
#include <SPI.h>
#include <AskSinPP.h>
#include <LowPower.h>
#include <Register.h>

#ifdef USE MEGA
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
#else
// - ---------------------------------------------------------------------------- -
// Anzahl der LED's pro Augang - Arduino Pro/Pro mini                             -
// Bei einer Belegung von 144px/m:  max. gesamt 100px                             -
//    -  max 1 x 100px [69cm] (81% des dynamischen Speichers)                     -
//    -  max 2 x  50px [35cm] (81% des dynamischen Speichers)                     -
//    -  max 3 x  36px [25cm] (83% des dynamischen Speichers)                     -
//  nicht belegte Ausgänge auf 1 setzen                                           -
// - ---------------------------------------------------------------------------- - 
  #define WSNUM_LEDS1    30        //Anzahl angeschlossener LEDs
  #define WSNUM_LEDS2    30        //Anzahl angeschlossener LEDs
  #define WSNUM_LEDS3    1         //Anzahl angeschlossener LEDs
#endif

#ifdef USE MEGA
  #define WSLED_PIN_10   3           //GPIO Pin LED Anschluss - Stripe 1 
  #define WSLED_PIN_11   5           //GPIO Pin LED Anschluss - Stripe 2
  #define WSLED_PIN_12   7           //GPIO Pin LED Anschluss - Stripe 3
  #define WSLED_PIN_13   9           //GPIO Pin LED Anschluss - Stripe 4
  #define WSLED_PIN_14   11          //GPIO Pin LED Anschluss - Stripe 5
  #define WSLED_PIN_15   13          //GPIO Pin LED Anschluss - Stripe 6
  #define WSLED_PIN_16   15          //GPIO Pin LED Anschluss - Stripe 7
  #define WSLED_PIN_17   17          //GPIO Pin LED Anschluss - Stripe 8        
  #define WSLED_PIN_18   19          //GPIO Pin LED Anschluss - Stripe 9        
  #define WSLED_PIN_19   21          //GPIO Pin LED Anschluss - Stripe 10    

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
#else
  #define WSLED_PIN_1   5          //GPIO Pin LED Anschluss - Stripe 1 
  #define WSLED_PIN_2   6          //GPIO Pin LED Anschluss - Stripe 2
  #define WSLED_PIN_3   9          //GPIO Pin LED Anschluss - Stripe 3
#endif

#define WSLED_TYPE     WS2812B    //LED Typ

#define WSCOLOR_ORDER GRB        //Farbreihenfolge

#ifdef USE MEGA
  #define WSLED_ENPIN   40          //Enable Pin StepUp
#else
  #define WSLED_ENPIN   7           //Enable Pin StepUp
#endif
//  -------------------------------------------------------------------------------------
//  - Auswahl der Flammendarstellung (siehe Fire2012/Fire2012WithPalette                -
//  -------------------------------------------------------------------------------------
// COOLING:   20 hohe Flamme ..... 100 kurze Flamme
// SPARKING:  50  mehr Flackern ..... 200 mehr Lodern
//
//
//  Programm: Langsamer Durchlauf
#define FIRE_PRG_1_1_COOLING   60
#define FIRE_PRG_1_1_SPARKING 180
//
//  Programm: Normaler Durchlauf
#define FIRE_PRG_1_2_COOLING  80
#define FIRE_PRG_1_2_SPARKING 200
//
//  Programm: Schneller Durchlauf
#define FIRE_PRG_1_3_COOLING  60
#define FIRE_PRG_1_3_SPARKING 130
//
//  Programm: Lagerfeuer
#define FIRE_PRG_2_1_COOLING  60  
#define FIRE_PRG_2_1_SPARKING 180
//
//  Programm: Wasserfall
#define FIRE_PRG_2_2_COOLING  80
#define FIRE_PRG_2_2_SPARKING 200
//
//  Programm: TV-Simulation
#define FIRE_PRG_2_3_COOLING  60
#define FIRE_PRG_2_3_SPARKING 130
//  -------------------------------------------------------------------------------------
//
//  -------------------------------------------------------------------------------------
//  - Auswahl der Farbpalette für FirePrg2 (siehe Fire2012WithPalette                   -
//  - Standard: HeatColors_p                                                            -
//  -------------------------------------------------------------------------------------
#define GPALNR 10
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
//
//
//  -------------------------------------------------------------------------------------
//  - Auswahl der Darstellungsgeschwindigkeit                                           -
//    I recommend running this simulation at anywhere from 30-100 frames per second,    -
//    meaning an interframe delay of about 10-35 milliseconds.                          -
//  -------------------------------------------------------------------------------------
//
#define FRAMES_PER_SECOND 100
//
//
#define CONFIG_BUTTON_PIN 8
#define ONBOARD_LED_PIN   4

#include "RGBCtrl.h"

#define PEERS_PER_CHANNEL 4

using namespace as;

// define all device properties
const struct DeviceInfo PROGMEM devinfo = {
  {MODEL_1, MODEL_2, 0x01},   // Device ID
  "HB_KAMIN01",               // Device Serial  
  {MODEL_1, MODEL_2},         // Device Model
  0x10,                       // Firmware Version
  as::DeviceType::Dimmer,     // Device Type
  {0x01, 0x00}                // Info Bytes
};

typedef AskSin<StatusLed<ONBOARD_LED_PIN>, BATTSENS, Radio<LibSPI<10>, 2>> HalType;

DEFREGISTER(Reg0, MASTERID_REGS, DREG_LOWBATLIMIT)
class Ws28xxList0 : public RegList0<Reg0> {
  public:
    Ws28xxList0(uint16_t addr) : RegList0<Reg0>(addr) {}

    void defaults () {
      clear();
      lowBatLimit(22);
    }
};

typedef RGBLEDChannel<HalType, PEERS_PER_CHANNEL, Ws28xxList0> ChannelType;

class RGBLEDType : public RGBLEDDevice<HalType, ChannelType, 3, Ws28xxList0> {
private:
    uint8_t wsledpin;
  public:
    typedef RGBLEDDevice<HalType, ChannelType, 3, Ws28xxList0> DevType;
    RGBLEDType (const DeviceInfo& i, uint16_t addr) : DevType(i, addr), wsledpin(0) {}
    virtual ~RGBLEDType () {}

    void initWSLED(uint8_t p) {
      wsledpin = p;
      pinMode(wsledpin, OUTPUT); //LED-Kerze - 5V_Enable
    }

    void enableWSLED(bool b) {
      digitalWrite(wsledpin, b);
    }

    virtual void configChanged () {
      DevType::configChanged();
#ifdef USE_BATTERY
      uint8_t lowbat = getList0().lowBatLimit();
      DDECLN(lowbat);
      if ( lowbat > 0 ) {
        battery().low(lowbat);
      }
#endif
    }
};

HalType hal;
RGBLEDType sdev(devinfo, 0x20);
ConfigButton<RGBLEDType> cfgBtn(sdev);

void setup () {
  DINIT(57600, ASKSIN_PLUS_PLUS_IDENTIFIER);
  sdev.init(hal);
  buttonISR(cfgBtn, CONFIG_BUTTON_PIN);
#ifdef USE_BATTERY
  hal.activity.stayAwake(seconds2ticks(5));
  // measure battery every 4 hours
  hal.battery.init(seconds2ticks(60UL * 60 * 4), sysclock);
  hal.battery.critical(BAT_CRITICAL);
#endif
  sdev.initWSLED(WSLED_ENPIN);
  sdev.enableWSLED(true);
  sdev.initDone();
}

void loop() {
  bool worked = hal.runready();
  bool poll = sdev.pollRadio();
  bool on = (sdev.getCurrentLevel() > 0);

  if (sdev.channel(1).lowBat() == false && hal.battery.low() == true) {
    sdev.channel(1).lowBat(true);
    sdev.channel(1).changed(true);
  }

  if (hal.battery.critical())
    hal.activity.sleepForever(hal);

#ifdef USE_BATTERY
  sdev.enableWSLED(on);
  if ( worked == false && poll == false && (sdev.getCurrentProgram() == 0 || on == false)) {
    hal.sleep();
  }
#endif

  sdev.handleLED();
}
