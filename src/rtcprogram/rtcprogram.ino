#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;
void setup() {
   if (! rtc.begin()) {
   Serial.println("RTC not initialized");
 }
 rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
 delay(3000);

}

void loop() {

}
