/* Very basic 1-neopixel demo
 * By: Jeffrey Hundstad <we0a@arrl.net> 2015-04-20
 *
 * Circuit:
 * 5V    : NeoPixel VCC
 * GND   : NeoPixel GND
 * pin-6 : NeoPixel DataIn
 *         Uses LED_BUILTIN
 *
 * Cycle though: red, green, blue, white, 10 random colors, then black.
 * At every color switch change the built in LED (just to make sure it's working)
 *
 * You can find more here:
 *   https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library
*/

// built in LED
const byte led_pin = LED_BUILTIN;
// current status of the built in LED
boolean led_status = 0;

#include <Adafruit_NeoPixel.h>
const byte NEOPIXEL_PIN = 6;
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  randomSeed(analogRead(0));
  pinMode(led_pin, OUTPUT);
  digitalWrite(led_pin, led_status);
}

// Delay between each color change
const unsigned int color_delay = 500;

void loop() {

  digitalWrite(led_pin, led_status ^= 1); // Change built in LED

  // Red
  strip.setPixelColor(0, 255, 0, 0);
  strip.show();
  delay(color_delay);

  digitalWrite(led_pin, led_status ^= 1); // Change built in LED

  //Green
  strip.setPixelColor(0, 0, 255, 0);
  strip.show();
  delay(color_delay);

  digitalWrite(led_pin, led_status ^= 1); // Change built in LED

  //Blue
  strip.setPixelColor(0, 0, 0, 255);
  strip.show();
  delay(color_delay);

  digitalWrite(led_pin, led_status ^= 1); // Change built in LED

  //White
  strip.setPixelColor(0, 255, 255, 255);
  strip.show();
  delay(color_delay);

  digitalWrite(led_pin, led_status ^= 1); // Change built in LED

  // 10 random colors
  for (byte counter = 0; counter < 10; counter++) {
    strip.setPixelColor(0, random(255), random(255), random(255));
    strip.show();
    delay(color_delay);
    digitalWrite(led_pin, led_status ^= 1); // Change built in LED
  }

  digitalWrite(led_pin, led_status ^= 1); // Change built in LED

  //Black
  strip.setPixelColor(0, 0, 0, 0);
  strip.show();

  delay(color_delay);

}
