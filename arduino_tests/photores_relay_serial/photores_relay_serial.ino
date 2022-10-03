/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-light-sensor
 */

 #define RELAY_IN 4

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(RELAY_IN,OUTPUT);
}

void loop() {
  // reads the input on analog pin A0 (value between 0 and 1023)
  int analogValue = analogRead(A0),
      relay=0;

  Serial.print("Analog reading: ");
  Serial.print(analogValue);   // the raw analog reading
  // We'll have a few threshholds, qualitatively determined
  if (analogValue < 10) {
    Serial.println(" - Dark");
    relay=1;
  } else if (analogValue < 200) {
    Serial.println(" - Dim");
    relay=1;
  } else if (analogValue < 500) {
    Serial.println(" - Light");
  } else if (analogValue < 800) {
    Serial.println(" - Bright");
  } else {
    Serial.println(" - Very bright");
  }

  digitalWrite(RELAY_IN,relay);

  delay(500);
}
