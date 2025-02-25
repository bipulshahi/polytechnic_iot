//sound sensor as digital sensor
#define sound_sensor D5
#define led D2

int soundstatus;

void setup() {
 pinMode(sound_sensor,INPUT);
 pinMode(led,OUTPUT);
 Serial.begin(9600);
 digitalWrite(led,LOW);
}

void loop() {
  soundstatus = digitalRead(sound_sensor);
  Serial.print("Sound Status: ");
  Serial.println(soundstatus);
  if (soundstatus == 1){
    digitalWrite(led,HIGH);
  }else{
    digitalWrite(led,LOW);
  }
  delay(500);
}
