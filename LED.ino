
#include <FastLED.h>

#define NUM_LEDS 18
#define NUM_LEDS2 60


#define DATA_PIN 3
#define DATA_PIN2 4


CRGB leds[NUM_LEDS];
CRGB leds2[NUM_LEDS2];
CRGB aktfarbe;
int durchlauf = 0;
int fortschritt = 0;
int p = 0;

void setup() {

   	delay(500);

    FastLED.addLeds<WS2811, DATA_PIN,  GRB>(leds, NUM_LEDS); 
    FastLED.addLeds<WS2811, DATA_PIN2,  GRB>(leds2, NUM_LEDS2);     


}



void loop() {

   for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) {
     leds2[p] = CRGB(abs((255*sin((p/7.0)))),abs(255*sin(p/13.0)),abs(255*sin(p/10.0)));

      for (int i=0;i< whiteLed;i++){
        if (i < fortschritt) {leds[i]=CRGB(255,192*i/NUM_LEDS,0);}

      }

      leds[whiteLed] = CRGB::White;


      FastLED.show();


      delay(20);


      leds[whiteLed] = CRGB::Black;
      leds2[p] = CRGB::Black;
      p++;
      if (p>=NUM_LEDS2) {p=0;}
   }
   fortschritt++;
   if (fortschritt == NUM_LEDS ) {
     fortschritt =0;
     durchlauf = 1- durchlauf;
   }
}
