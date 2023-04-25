#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;

void setup() {
  Serial.begin(9600);
  while (!Serial); // Wait for Serial to initialize

  if (!rtc.begin()) {
    Serial.println("RTC initialization failed!");
    while (1); // Wait indefinitely
  }

  // If the RTC has lost power, set the time to the compile time
  if (rtc.lostPower()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  Serial.println("RTC initialized successfully.");
}

void loop() {
  // Wait for input from the serial monitor
  while (!Serial.available()) {
    // Do nothing
  }

  // Read the input from the serial monitor
  String input = Serial.readStringUntil('\n');
  input.trim();

  // Check if the input is a valid time in the format HH:MM:SS
  if (input.length() != 8 || input.charAt(2) != ':' || input.charAt(5) != ':') {
    Serial.println("Invalid time format. Please enter a time in the format HH:MM:SS");
    return;
  }

  int hours = input.substring(0, 2).toInt();
  int minutes = input.substring(3, 5).toInt();
  int seconds = input.substring(6, 8).toInt();

  // Set the alarm time on the RTC
  rtc.setAlarm(ALM1_MATCH_HOURS, hours);
  rtc.setAlarm(ALM1_MATCH_MINUTES, minutes);
  rtc.setAlarm(ALM1_MATCH_SECONDS, seconds);
  rtc.enableAlarm(ALARM_1);

  // Print a message to the serial monitor to confirm that the alarm was set
  Serial.print("Alarm set for ");
  Serial.print(hours);
  Serial.print(":");
  Serial.print(minutes);
  Serial.print(":");
  Serial.println(seconds);
}
