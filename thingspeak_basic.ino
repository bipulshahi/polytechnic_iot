#include <dht.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>

const char* ssid = "mywifi";                 //your hotspot name
const char* password = "abcdexyz";        //your hotspot password
WiFiClient client;

long myChannelNumber = 2855162;
const char* myWriteApiKey = "8S20QE4T0AHUGRVE";

void setup() {
 Serial.begin(9600);
 Serial.print("Connecting to...");
 Serial.println(ssid);
 WiFi.begin(ssid,password);             //to connect with your hotspot

 while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
 }
  Serial.print(" ");
  Serial.print("WiFi Connected.");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
}

void loop() {
  float temperature = 25;
  float humidity = 35;

  ThingSpeak.writeField(myChannelNumber, 1, temperature, myWriteApiKey);
  ThingSpeak.writeField(myChannelNumber, 2, humidity, myWriteApiKey);

 delay(13000);
}
