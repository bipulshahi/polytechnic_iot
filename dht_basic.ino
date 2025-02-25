#include <dht.h>
dht DHT;
#define DHT11_PIN D5
void setup() {
  Serial.begin(9600);
}
void loop() {
  // DISPLAY DATA
  DHT.read11(DHT11_PIN);
  Serial.print("Humidity: ");
  Serial.print(DHT.humidity, 1);
  Serial.print(",\t");
  Serial.print("Temperature: ");
  Serial.println(DHT.temperature, 1);
  delay(2000);
}
