#include <FastLED.h>

#define LED_PIN_OUTER_RING 0
#define LED_PIN_MIDDLE_RING 1
#define LED_PIN_CENTER_RING 2


#define NUM_LEDS_OUTER_RING 81
#define NUM_LEDS_MIDDLE_RING 55
#define NUM_LEDS_CENTER_RING 14

#define LED_TYPE    WS2811
#define COLOR_ORDER BRG
#define BRIGHTNESS  150

#define RATE 50

CRGB ring_1[NUM_LEDS_OUTER_RING];
CRGB ring_2[NUM_LEDS_MIDDLE_RING];
CRGB ring_3[NUM_LEDS_MIDDLE_RING];


void setup() {
  // put your setup code here, to run once:
  delay( 1000 ); // power-up safety delay
  
  // Outer Ring: Pin 1, 81 LEDs
  FastLED.addLeds<LED_TYPE, LED_PIN_OUTER_RING, COLOR_ORDER>(ring_1, NUM_LEDS_OUTER_RING).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN_MIDDLE_RING, COLOR_ORDER>(ring_2, NUM_LEDS_MIDDLE_RING).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN_CENTER_RING, COLOR_ORDER>(ring_3, NUM_LEDS_CENTER_RING).setCorrection( TypicalLEDStrip );
  

  // startupLEDsTest();
}




void loop() {
  uint8_t phase_1 = millis() / 500;
  
  if (phase_1 < 255 / 3) {
    sweep();
  } else if (phase_1 < 255 * 2 / 3) {
    pulse();
  } else {
    chase();
  }
  FastLED.show();
}








void sweep() {
  uint8_t rate_1 = 30;
  uint8_t rate_2 = 20;
  uint8_t rate_3 = 15;


  uint8_t phase_1 = - millis() / rate_1;
  uint8_t phase_2 = - millis() / rate_2;
  uint8_t phase_3 = - millis() / rate_3;


  for( uint8_t i = 0; i < NUM_LEDS_OUTER_RING; i++) {
    ring_1[i] = CHSV(i * 255 / NUM_LEDS_OUTER_RING + phase_1, 255, 255);
  }
  for( uint8_t i = 0; i < NUM_LEDS_MIDDLE_RING; i++) {
    ring_2[i] = CHSV(i * 255 / NUM_LEDS_MIDDLE_RING + phase_2, 255, 255);
  }
  for( uint8_t i = 0; i < NUM_LEDS_CENTER_RING; i++) {
    ring_3[i] = CHSV(i * 255 / NUM_LEDS_CENTER_RING + phase_3, 255, 255);
  }
}



void pulse() {
  uint8_t rate_1 = 17;
  uint8_t rate_2 = 25;

  uint8_t phase_1 = - millis() / rate_1;
  uint8_t phase_2 = - millis() / rate_2;

  uint8_t amplitude_1 = 245;
  uint8_t amplitude_2 = 200;
  uint8_t amplitude_3 = 180;

  uint8_t floor_1 = 10;
  uint8_t floor_2 = 55;
  uint8_t floor_3 = 75;

  for( uint8_t i = 0; i < NUM_LEDS_OUTER_RING; i++) {
    ring_1[i] = CHSV(phase_2, 255, cubicwave8(- phase_1) * amplitude_1 / 255 + floor_1);
  }
  for( uint8_t i = 0; i < NUM_LEDS_MIDDLE_RING; i++) {
    ring_2[i] = CHSV(phase_2, 255, cubicwave8(- phase_1) * amplitude_2 / 255 + floor_2);
  }
  for( uint8_t i = 0; i < NUM_LEDS_CENTER_RING; i++) {
    ring_3[i] = CHSV(phase_2, 255, cubicwave8(- phase_1) * amplitude_3 / 255 + floor_3);
  }
}

void chase() {
  uint8_t rate_1 = 4;
  uint8_t rate_2 = 25;

  uint8_t phase_1 = millis() / rate_1;
  uint8_t phase_2 = - millis() / rate_2;
  uint8_t phase_3 = phase_2 + 30;
  uint8_t phase_4 = phase_2 + 60;

  uint8_t width_1 = 2;

  for( uint8_t i = 0; i < NUM_LEDS_OUTER_RING; i++) {
    if (abs(i - NUM_LEDS_OUTER_RING * phase_1 / 255 ) < width_1) {
      ring_1[i] = CHSV(phase_2, 255, 255);
    } else {
      ring_1[i] = CHSV(phase_2, 255, 0);
    }
  }
  for( uint8_t i = 0; i < NUM_LEDS_MIDDLE_RING; i++) {
    if (abs(i - NUM_LEDS_MIDDLE_RING * phase_1 / 255 ) < width_1) {
      ring_2[i] = CHSV(phase_3, 255, 255);
    } else {
      ring_2[i] = CHSV(phase_3, 255, 0);
    }
  }
  for( uint8_t i = 0; i < NUM_LEDS_CENTER_RING; i++) {
    if (abs(i - NUM_LEDS_CENTER_RING * phase_1 / 255 ) < width_1) {
      ring_3[i] = CHSV(phase_4, 255, 255);
    } else {
      ring_3[i] = CHSV(phase_4, 255, 0);
    }
  }
  // for( uint8_t i = 0; i < NUM_LEDS_MIDDLE_RING; i++) {
  //   ring_2[i] = CHSV(phase_2, 255, cubicwave8(- phase_1) * amplitude_2 / 255 + floor_2);
  // }
  // for( uint8_t i = 0; i < NUM_LEDS_CENTER_RING; i++) {
  //   ring_3[i] = CHSV(phase_2, 255, cubicwave8(- phase_1) * amplitude_3 / 255 + floor_3);
  // }

}



void startupLEDsTest() {
  // startup blink test to confirm LEDs are working.
  FastLED.setBrightness(32);
  fill_solid(ring_1, NUM_LEDS_OUTER_RING, CRGB(255,0,0));  // fill red
  fill_solid(ring_2, NUM_LEDS_MIDDLE_RING, CRGB(255,0,0));  // fill red
  fill_solid(ring_3, NUM_LEDS_CENTER_RING, CRGB(255,0,0));  // fill red
  FastLED.show();
  delay(1000);
  fill_solid(ring_1, NUM_LEDS_OUTER_RING, CRGB(0,255,0));  // fill blue
  fill_solid(ring_2, NUM_LEDS_MIDDLE_RING, CRGB(0,255,0));  // fill blue
  fill_solid(ring_3, NUM_LEDS_CENTER_RING, CRGB(0,255,0));  // fill blue
  FastLED.show();
  delay(1000);
  fill_solid(ring_1, NUM_LEDS_OUTER_RING, CRGB(0,0,255));  // fill green
  fill_solid(ring_2, NUM_LEDS_MIDDLE_RING, CRGB(0,0,255));  // fill green
  fill_solid(ring_3, NUM_LEDS_CENTER_RING, CRGB(0,0,255));  // fill green
  FastLED.show();
  delay(1000);
  
  FastLED.clear(); // Off?
  FastLED.show();
  delay(1000);
  FastLED.setBrightness(BRIGHTNESS);

}

void test() {
  ring_3[13] = CHSV(255, 255, 255);
}
