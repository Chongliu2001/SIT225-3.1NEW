#include "thingProperties.h"
#include <DHT.h>

#define DHTPIN 2  // Pin where the DHT22 is connected
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Initialize serial and cloud properties
  Serial.begin(9600);
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  
  // Initialize DHT sensor
  dht.begin();
}

void loop() {
  ArduinoCloud.update();
  
  // Read temperature as Celsius
  float t = dht.readTemperature();
  
  // Update cloud variable
  temp = t;
  
  // Optional: Output temperature data to serial monitor
  Serial.print("Temperature: ");
  Serial.println(temp);
}
