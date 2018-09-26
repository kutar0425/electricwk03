#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"`
int freq = 5000;
int ledchannel = 0;
int resolution = 8;
SSD1306Wire  display(0x3c, 21, 22);

void setup() {
  Serial.begin(115200);
  pinMode(36,INPUT);
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
}

void loop() {
  // put your main code here, to run repeatedly:
int read=analogRead(36);
Serial.println(read);
    delay(10);
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_16);
    display.drawString(0, 0, "Read Value is");
    display.drawString(0,20, String(read));
    display.display();
}
