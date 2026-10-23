#include "DHT.h"

#define DHTPIN 2
#define LEDPIN 8
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

float limit = 30.0;   // alert temperature in °C

void setup() {
  Serial.begin(9600);
  pinMode(LEDPIN, OUTPUT);
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();

  if (isnan(temp)) {
    Serial.println("Sensor error");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" C");

  if (temp > limit) {
    digitalWrite(LEDPIN, HIGH);   // too hot: LED on
  } else {
    digitalWrite(LEDPIN, LOW);    // normal: LED off
  }

  delay(2000);
}
