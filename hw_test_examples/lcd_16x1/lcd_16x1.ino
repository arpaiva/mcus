#include <LiquidCrystal.h> 

int contrast_val = 64;  // higher values mean lower contrast {0,...,255} 

// LCD display pins (using 5 through 12 as data pins)
const byte contrast_pin = 10; // must be a PWM pin
const byte rs_pin = 11;
const byte enable_pin = 12;

// Describes the LCD configuration
// See https://docs.arduino.cc/libraries/liquidcrystal/ for docs
LiquidCrystal lcd(rs_pin, enable_pin, 6, 7, 8, 9);  // 4-bit mode
// LiquidCrystal lcd(rs_pin, enable_pin, 2, 3, 4, 5, 6, 7, 8, 9);  // 8-bit mode

void setup() {
  analogWrite(contrast_pin, contrast_val);

  // initialize the LCD interface
  // note that 16x1 displays are addressed as 8x2!
  lcd.begin(8, 2);
} 

// Handle the two 8-char segments to print one line.
// Once it fills a full 16-char line, it prints each additional character
// one at a time, with the delay in between, while scrolling

void write_line(String text, int ms_wait=150);

void write_line(String text, int ms_wait) {
  int str_len = text.length();

//  lcd.setCursor(0, 1);  // init right hand side
  lcd.home();  // back to start
  lcd.clear();

  lcd.print(text);
  if (str_len <= 8)
    return;

  // otherwise continue printing
  lcd.setCursor(0, 1);  // move to the right segment
  lcd.print(text.substring(8));
  if (str_len <= 16)
    return;

  // print the rest one char at a time with scrolling
  for (int i=16; i<str_len; i++) {
    delay(ms_wait);
    lcd.scrollDisplayLeft();
    lcd.write(text[i]);
  }
}

void loop() {
  write_line("Hello World!");
  delay(1000);

  write_line("I'm just a dude.");
  delay(1000);

  lcd.clear();
  delay(300);
}
