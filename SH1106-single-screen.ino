// SINGLE SCREEN ANIMATION

//
// ThingPulse SSD1306 library
// 
// wiring for small screens, wemos to OLED
//
// GND -> GND -> BLACK
// 3.3V -> VDD -> RED
// D5 -> CLK (SCK) -> PURPLE
// D7 -> MOSI (DOUT) (SDA) -> ORANGE
// D0 -> RES -> BLUE
// D2 -> DC -> YELLOW
// D8 -> CS -> WHITE

// The colour of the wires is arbitrary,
// something I have concocted to help in the construction
// of multi-screen boards


//
// ------------------variables you need to change------------------------------------
//


//        only change things inside dotted lines
        
        // Sketch -> add file (this is the file of images, see the second tab at top)
        #include "taxi.h"
        
        // number of frames
        uint8_t frames = 135;
        
        // frame rate in milloseconds (100 = 10 frames a second)
        uint8_t frameRate = 100;

//
// ------------------now change name of array below------------------------------------
//


#include "SH1106Spi.h"

// ------------------begin ESP8266'centric----------------------------------
#define FREQUENCY    160                  // valid 80, 160
//
#include "ESP8266WiFi.h"


SH1106Spi       display(D0, D2, D8);
uint8_t i = 0;


void setup() {

  /* Initializations,  turns wifi off and saves battery */
  WiFi.forceSleepBegin();                  // turn off ESP8266 RF

  // initialises the small screens
  display.init();

}

void loop() {

  //
  // ------------------change array name (current name is 'taxi' ------------------------------------
  //

  display.drawXbm( 0, 0, 128, 64, taxi[i]);

  //
  // ------------------end stuff to change------------------------------------
  //
  display.display();

  if (i == frames) {
    i = 0;
  } else {
    i++;
  }
  display.clear();
  delay(frameRate);


}
