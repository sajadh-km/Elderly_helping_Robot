#include <DS1302.h>

const int RTC_CE_PIN = 22;
const int RTC_IO_PIN = 24;
const int RTC_SCLK_PIN = 26;

DS1302 rtc(RTC_CE_PIN, RTC_IO_PIN, RTC_SCLK_PIN);

void setup() {
  Serial.begin(9600);
  rtc.halt(false);
  rtc.writeProtect(false);
}

void loop() {
  if (Serial.available() >= 8) {
    String input = Serial.readStringUntil('\n');
    int hour = input.substring(0, 2).toInt();
    int minute = input.substring(3, 5).toInt();
    int second = input.substring(6, 8).toInt();
    rtc.writeTime(hour, minute, second);
    Serial.println("Time set successfully!");
  }
}
