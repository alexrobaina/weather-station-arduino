#include <DHT.h>

int DHT_PIN = 2;

DHT dht(DHT_PIN, DHT11);

void setup() {
  
  Serial.begin(9600);
  dht.begin();
  delay(5000);

}

void loop() {

  delay(2000);

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  float temperatureFahrenheit = dht.readTemperature(true);

  if (isnan(humidity) || isnan(temperature) || isnan(temperatureFahrenheit)) {
      Serial.println("Error when read data sensor");
      return; 
   }

   float hic = dht.computeHeatIndex(temperature, humidity, false);
   float hif = dht.computeHeatIndex(temperatureFahrenheit, humidity);

   Serial.print("Humidiry: ");
   Serial.print(humidity);
   Serial.print("% Temperature: ");
   Serial.print(temperature);
   Serial.print("ºC ");
   Serial.print(temperatureFahrenheit);
   Serial.print("ºFahrenheit Heat Index");
   Serial.print(hic);
   Serial.print("ºC ");
   Serial.print(hif);
   Serial.println("ºFahrenheit");

}
