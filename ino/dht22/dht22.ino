// Includes //
#include "DHT.h"
// End Includes //

// Defines //
#define aPin A0
#define DHTTYPE DHT22       // DHT 11
DHT dht(aPin, DHTTYPE);
// End defines //

///////////////////////////////////////////////////////
// Setup //
void setup() {
  Serial.begin(57600);
  Serial.println(F("DHT22 test!"));
  dht.begin();

}
// End setup //
///////////////////////////////////////////////////////
// Loop //
void loop(){
ldr();
temp(); 
}
// End loop //
///////////////////////////////////////////////////////
// Temperature //
void temp() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);
  
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F(" Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("C "));
  Serial.print(f);
  Serial.print(F("F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("C "));
  Serial.print(hif);
  Serial.println(F("F"));
}
// End Temperature
///////////////////////////////////////////////////////
// LDR //
void ldr()
{
delay(2000);
int aPin = analogRead(A0);
float voltage = aPin * (3.0 / 1023.0);
Serial.println(voltage);
}
