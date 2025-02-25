#define sound_sensor A0
#define led D2

float soundlevel;
int threshold = 330;

void setup() {
 Serial.begin(9600);
 pinMode(led,OUTPUT);
 digitalWrite(led,LOW);
}

void loop() {
  soundlevel = analogRead(sound_sensor);
  Serial.print("Sound level: ");
  Serial.println(soundlevel);
  if (soundlevel > threshold){
    digitalWrite(led,HIGH);
  }else{
    digitalWrite(led,LOW);
  }
  delay(500);
}
