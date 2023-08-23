#include <FastLED.h>

#define LED_PIN_OUTER_RING 0
#define LED_PIN_MIDDLE_RING 1
#define LED_PIN_CENTER_RING 2
#define LED_PIN_BROW_L 3
#define LED_PIN_BROW_S 4
#define LED_PIN_BEAK 5
#define LED_PIN_TOP_CHEST 6
#define LED_PIN_MIDDLE_CHEST 7
#define LED_PIN_BOTTOM_CHEST 8


#define NUM_LEDS_OUTER_RING 81
#define NUM_LEDS_MIDDLE_RING 55
#define NUM_LEDS_CENTER_RING 14
#define NUM_LEDS_BROW_L 58
#define NUM_LEDS_BROW_S 55
#define NUM_LEDS_BEAK 10
#define NUM_LEDS_TOP_CHEST 49
#define NUM_LEDS_MIDDLE_CHEST 44
#define NUM_LEDS_BOTTOM_CHEST 41

#define LED_TYPE    WS2811
#define COLOR_ORDER BRG
#define BRIGHTNESS  150

#define RATE 50

CRGB ring_1[NUM_LEDS_OUTER_RING];
CRGB ring_2[NUM_LEDS_MIDDLE_RING];
CRGB ring_3[LED_PIN_CENTER_RING];
CRGB brow_1[NUM_LEDS_BROW_L];
CRGB brow_2[NUM_LEDS_BROW_S];
CRGB beak[NUM_LEDS_BEAK];
CRGB top_chest[NUM_LEDS_TOP_CHEST];
CRGB middle_chest[NUM_LEDS_MIDDLE_CHEST];
CRGB bottom_chest[NUM_LEDS_BOTTOM_CHEST];


void setup() {
  // put your setup code here, to run once:
  delay( 1000 ); // power-up safety delay

  
  FastLED.addLeds<LED_TYPE, LED_PIN_OUTER_RING, COLOR_ORDER>(ring_1, NUM_LEDS_OUTER_RING).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN_MIDDLE_RING, COLOR_ORDER>(ring_2, NUM_LEDS_MIDDLE_RING).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN_CENTER_RING, COLOR_ORDER>(ring_3, NUM_LEDS_CENTER_RING).setCorrection( TypicalLEDStrip );
  
  FastLED.addLeds<LED_TYPE, LED_PIN_BROW_L, COLOR_ORDER>(brow_1, NUM_LEDS_BROW_L).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN_BROW_S, COLOR_ORDER>(brow_2, NUM_LEDS_BROW_S).setCorrection( TypicalLEDStrip );
  
  FastLED.addLeds<LED_TYPE, LED_PIN_BEAK, COLOR_ORDER>(beak, NUM_LEDS_BEAK).setCorrection( TypicalLEDStrip );

  FastLED.addLeds<LED_TYPE, LED_PIN_TOP_CHEST, COLOR_ORDER>(beak, NUM_LEDS_TOP_CHEST).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN_MIDDLE_CHEST, COLOR_ORDER>(beak, NUM_LEDS_MIDDLE_CHEST).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN_BOTTOM_CHEST, COLOR_ORDER>(beak, NUM_LEDS_BOTTOM_CHEST).setCorrection( TypicalLEDStrip );
//   startupLEDsTest();
  //  test();
}




void loop() {
  uint8_t phase_1 = millis() / 1000;
//  test();
//  sweep();
//  pulse();
//  chase();
  
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
  uint8_t rate_4 = 40;
  uint8_t rate_5 = 15;
  


  uint8_t phase_1 = - millis() / rate_1;
  uint8_t phase_2 = - millis() / rate_2;
  uint8_t phase_3 = - millis() / rate_3;
  uint8_t phase_4 = - millis() / rate_4;
  uint8_t phase_5 = - millis() / rate_5;


  for( uint8_t i = 0; i < NUM_LEDS_OUTER_RING; i++) {
    ring_1[i] = CHSV(i * 255 / NUM_LEDS_OUTER_RING + phase_1, 255, 255);
  }
  for( uint8_t i = 0; i < NUM_LEDS_MIDDLE_RING; i++) {
    ring_2[i] = CHSV(i * 255 / NUM_LEDS_MIDDLE_RING + phase_2, 255, 255);
  }
  for( uint8_t i = 0; i < NUM_LEDS_CENTER_RING; i++) {
    ring_3[i] = CHSV(i * 255 / NUM_LEDS_CENTER_RING + phase_3, 255, 255);
  }
  for( uint8_t i = 0; i < NUM_LEDS_BROW_L; i++) {
    brow_1[i] = CHSV(i * 255 / NUM_LEDS_BROW_L + phase_4, 255, 255);
  }
  for( uint8_t i = 0; i < NUM_LEDS_BROW_S; i++) {
    brow_2[i] = CHSV(i * 255 / NUM_LEDS_BROW_S + phase_4 - 255 / 3, 255, 255);
  }
  for( uint8_t i = 0; i < NUM_LEDS_BEAK; i++) {
    beak[i] = CHSV(i * 255 / NUM_LEDS_BEAK + phase_4, 255, 255);
  }
  for( uint8_t i = 0; i < NUM_LEDS_TOP_CHEST; i++) {
    top_chest[i] = CHSV(i * 255 / NUM_LEDS_TOP_CHEST + phase_5, 255, 255);
  }
  for( uint8_t i = 0; i < NUM_LEDS_MIDDLE_CHEST; i++) {
    middle_chest[i] = CHSV(i * 255 / NUM_LEDS_MIDDLE_CHEST + phase_5 + 30, 255, 255);
  }
  for( uint8_t i = 0; i < NUM_LEDS_BOTTOM_CHEST; i++) {
    bottom_chest[i] = CHSV(i * 255 / NUM_LEDS_BOTTOM_CHEST + phase_5 + 60, 255, 255);
  }
}




void pulse() {
  uint8_t rate_1 = 17; // pulsation
  uint8_t rate_2 = 15; // hue

  uint8_t phase_1 = - millis() / rate_1; // pulsation
  uint8_t phase_2 = - millis() / rate_2; // hue

  uint8_t amplitude_1 = 245;
  uint8_t amplitude_2 = 200;
  uint8_t amplitude_3 = 180;
  uint8_t amplitude_4a = 60;
  uint8_t amplitude_4b = 60;
  uint8_t amplitude_5a = 60;
  uint8_t amplitude_5b = 60;
  
  uint8_t floor_1 = 10;
  uint8_t floor_2 = 55;
  uint8_t floor_3 = 75;
  uint8_t floor_4 = 10;
  uint8_t floor_5 = 10;
  

  for( uint8_t i = 0; i < NUM_LEDS_OUTER_RING; i++) {
    ring_1[i] = CHSV(phase_2, 255, cubicwave8(- phase_1) * amplitude_1 / 255 + floor_1);
  }
  for( uint8_t i = 0; i < NUM_LEDS_MIDDLE_RING; i++) {
    ring_2[i] = CHSV(phase_2 + 15, 255, cubicwave8(- phase_1) * amplitude_2 / 255 + floor_2);
  }
  for( uint8_t i = 0; i < NUM_LEDS_CENTER_RING; i++) {
    ring_3[i] = CHSV(phase_2 + 30, 255, cubicwave8(- phase_1) * amplitude_3 / 255 + floor_3);
  }
  for( uint8_t i = 0; i < NUM_LEDS_BROW_L; i++) {
    brow_1[i] = CHSV(phase_2 - 15, 255, cubicwave8(- phase_1) * amplitude_4a / 255 + floor_4 - amplitude_4b * i / NUM_LEDS_BROW_L);
  }
  for( uint8_t i = 0; i < NUM_LEDS_BROW_S; i++) {
    brow_2[i] = CHSV(phase_2 - 15, 255, cubicwave8(- phase_1) * amplitude_4a / 255 + floor_4 - amplitude_4b * i / NUM_LEDS_BROW_S);
  }
  for( uint8_t i = 0; i < NUM_LEDS_BEAK; i++) {
    beak[i] = CHSV(phase_2 - 15, 255, cubicwave8(- phase_1) * amplitude_4a / 255 + floor_4 - amplitude_4b * i / NUM_LEDS_BEAK);
  }
  for( uint8_t i = 0; i < NUM_LEDS_TOP_CHEST; i++) {
    top_chest[i] = CHSV(phase_2 - 20, 255, cubicwave8(- phase_1) * amplitude_5a / 255 + floor_5 - amplitude_5b * i / NUM_LEDS_TOP_CHEST);
  }
  for( uint8_t i = 0; i < NUM_LEDS_MIDDLE_CHEST; i++) {
    middle_chest[i] = CHSV(phase_2 - 20, 255, cubicwave8(- phase_1) * amplitude_5a / 255 + floor_5 - amplitude_5b * i / NUM_LEDS_MIDDLE_CHEST);
  }
  for( uint8_t i = 0; i < NUM_LEDS_BOTTOM_CHEST; i++) {
    bottom_chest[i] = CHSV(phase_2 - 20, 255, cubicwave8(- phase_1) * amplitude_5a / 255 + floor_5 - amplitude_5b * i / NUM_LEDS_BOTTOM_CHEST);
  }
}

void chase() {
  uint8_t rate_1 = 4;
  uint8_t rate_2 = 50;

  uint8_t phase_1 = millis() / rate_1;
  uint8_t phase_2 = - millis() / rate_2;
  uint8_t phase_3 = phase_2 + 30;
  uint8_t phase_4 = phase_2 + 60;
  uint8_t phase_5 = phase_1 - 180;
  uint8_t phase_6 = phase_1 - 15;
  uint8_t phase_7 = - phase_1 - 30;

  uint8_t width_1 = 4;

  for( uint8_t i = 0; i < NUM_LEDS_OUTER_RING; i++) {
    if ((abs(i - NUM_LEDS_OUTER_RING * phase_1 / 255 ) < width_1) ||
        (abs(i - NUM_LEDS_OUTER_RING * phase_1 / 255 ) > NUM_LEDS_OUTER_RING - width_1)) {
      ring_1[i] = CHSV(phase_2, 255, 255);
    } else {
      ring_1[i] = CHSV(phase_2, 255, 0);
    }
  }
  for( uint8_t i = 0; i < NUM_LEDS_MIDDLE_RING; i++) {
    if ((abs(i - NUM_LEDS_MIDDLE_RING * phase_1 / 255 ) < width_1) || 
        (abs(i - NUM_LEDS_MIDDLE_RING * phase_1 / 255 ) > NUM_LEDS_MIDDLE_RING - width_1) ) {
      ring_2[i] = CHSV(phase_3, 255, 255);
    } else {
      ring_2[i] = CHSV(phase_3, 255, 0);
    }
  }
  for( uint8_t i = 0; i < NUM_LEDS_CENTER_RING; i++) {
    if ((abs(i - NUM_LEDS_CENTER_RING * phase_1 / 255 ) < width_1) || 
        (abs(i - NUM_LEDS_CENTER_RING * phase_1 / 255 ) > NUM_LEDS_CENTER_RING - width_1) ) {
      ring_3[i] = CHSV(phase_4, 255, 255);
    } else {
      ring_3[i] = CHSV(phase_4, 255, 0);
    }
  }
  for( uint8_t i = 0; i < NUM_LEDS_BROW_L; i++) {
    if ((abs(i - NUM_LEDS_BROW_L * phase_5 / 255 ) < width_1) || 
        (abs(i - NUM_LEDS_BROW_L * phase_5 / 255 ) > NUM_LEDS_BROW_L - width_1) ) {
      brow_1[i] = CHSV(phase_4, 255, 255);
    } else {
      brow_1[i] = CHSV(phase_4, 255, 0);
    }
  }
  for( uint8_t i = 0; i < NUM_LEDS_BROW_S; i++) {
    if ((abs(i - NUM_LEDS_BROW_S * 1.5 * phase_6 / 255 ) < width_1) || 
        (abs(i - NUM_LEDS_BROW_S * 1.5 * phase_6 / 255 ) > NUM_LEDS_BROW_S * 1.5 - width_1) ) {
      brow_2[i] = CHSV(phase_4, 255, 255);
    } else {
      brow_2[i] = CHSV(phase_4, 255, 0);
    }
  }
  for( uint8_t i = 0; i < NUM_LEDS_BEAK; i++) {
    if ((abs(i - NUM_LEDS_BEAK * 3 * phase_7 / 255 ) < width_1/2) || 
        (abs(i - NUM_LEDS_BEAK * 3 * phase_7 / 255 ) > NUM_LEDS_BEAK*3 - width_1/2) ) {
      beak[i] = CHSV(phase_4, 255, 255);
    } else {
      beak[i] = CHSV(phase_4, 255, 0);
    }
  }
  for( uint8_t i = 0; i < NUM_LEDS_TOP_CHEST; i++) {
    if ((abs(i - NUM_LEDS_TOP_CHEST * phase_5 / 255 ) < width_1) || 
        (abs(i - NUM_LEDS_TOP_CHEST * phase_5 / 255 ) > NUM_LEDS_TOP_CHEST - width_1) ) {
      top_chest[i] = CHSV(phase_4, 255, 255);
    } else {
      top_chest[i] = CHSV(phase_4, 255, 0);
    }
  }
  for( uint8_t i = 0; i < NUM_LEDS_MIDDLE_CHEST; i++) {
    if ((abs(i - NUM_LEDS_MIDDLE_CHEST * phase_5 / 255 ) < width_1) || 
        (abs(i - NUM_LEDS_MIDDLE_CHEST * phase_5 / 255 ) > NUM_LEDS_MIDDLE_CHEST - width_1) ) {
      middle_chest[i] = CHSV(phase_4, 255, 255);
    } else {
      middle_chest[i] = CHSV(phase_4, 255, 0);
    }
  }
  for( uint8_t i = 0; i < NUM_LEDS_BOTTOM_CHEST; i++) {
    if ((abs(i - NUM_LEDS_BOTTOM_CHEST * phase_5 / 255 ) < width_1) || 
        (abs(i - NUM_LEDS_BOTTOM_CHEST * phase_5 / 255 ) > NUM_LEDS_BOTTOM_CHEST - width_1) ) {
      bottom_chest[i] = CHSV(phase_4, 255, 255);
    } else {
      bottom_chest[i] = CHSV(phase_4, 255, 0);
    }
  }
}



void startupLEDsTest() {
  // startup blink test to confirm LEDs are working.
  FastLED.setBrightness(32);
  fill_solid(ring_1, NUM_LEDS_OUTER_RING, CRGB(255,0,0));  // fill red
  fill_solid(ring_2, NUM_LEDS_MIDDLE_RING, CRGB(255,0,0));  // fill red
  fill_solid(ring_3, NUM_LEDS_CENTER_RING, CRGB(255,0,0));  // fill red
  fill_solid(brow_1, NUM_LEDS_BROW_L, CRGB(255,0,0));  // fill red
  fill_solid(brow_2, NUM_LEDS_BROW_S, CRGB(255,0,0));  // fill red
  fill_solid(beak, NUM_LEDS_BEAK, CRGB(255,0,0));  // fill red
  FastLED.show();
  delay(2000);
  fill_solid(ring_1, NUM_LEDS_OUTER_RING, CRGB(0,255,0));  // fill blue
  fill_solid(ring_2, NUM_LEDS_MIDDLE_RING, CRGB(0,255,0));  // fill blue
  fill_solid(ring_3, NUM_LEDS_CENTER_RING, CRGB(0,255,0));  // fill blue
  fill_solid(brow_1, NUM_LEDS_BROW_L, CRGB(0,255,0));  // fill blue
  fill_solid(brow_2, NUM_LEDS_BROW_S, CRGB(0,255,0));  // fill blue
  fill_solid(beak, NUM_LEDS_BEAK, CRGB(0,255,0));  // fill blue
  FastLED.show();
  delay(2000);
  fill_solid(ring_1, NUM_LEDS_OUTER_RING, CRGB(0,0,255));  // fill green
  fill_solid(ring_2, NUM_LEDS_MIDDLE_RING, CRGB(0,0,255));  // fill green
  fill_solid(ring_3, NUM_LEDS_CENTER_RING, CRGB(0,0,255));  // fill green
  fill_solid(brow_1, NUM_LEDS_BROW_L, CRGB(0,0,255));  // fill green
  fill_solid(brow_2, NUM_LEDS_BROW_S, CRGB(0,0,255));  // fill green
  fill_solid(beak, NUM_LEDS_BEAK, CRGB(0,0,255));  // fill green
  FastLED.show();
  delay(2000);
  
  FastLED.clear(); // Off?
  FastLED.show();
//  delay(1000);
  FastLED.setBrightness(BRIGHTNESS);

}

void test() {
  brow_1[57] = CHSV(255, 255, 255);
  brow_2[31] = CHSV(255, 255, 255);
  beak[9] = CHSV(255, 255, 255);
}
