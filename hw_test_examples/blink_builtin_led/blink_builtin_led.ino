/*
 * Makes the built-in LED blink.
 *
 * This is a useful, basic test that we are able to upload code
 * to the arduino and that it is working.
 *
 * This code implements several different patterns, selectable by setting `PATTERN`.
 */

#define PATTERN 1

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void blink(int on_time, int off_time) {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(on_time);
  digitalWrite(LED_BUILTIN, LOW);
  delay(off_time);
}

void loop() {
#if PATTERN == 1    // 1Hz blinking
  blink(500, 500);
#elif PATTERN == 2    // fast blinking (2.5Hz)
  blink(200, 200);
#elif PATTERN == 3  // SOS pattern
  int i;
  for (i=0; i<3; i++)
    blink(300, 200);
  for (i=0; i<3; i++)
    blink(600, 200);
  for (i=0; i<3; i++)
    blink(300, 200);
#else   // slow blinking
  blink(1000, 1000);
#endif
}
