#define mq A0
#define led D2

float gaslevel;
int threshold = 700;

void setup() {
 Serial.begin(9600);
 pinMode(D2,OUTPUT);
}

void loop() {
 gaslevel = analogRead(mq);
 Serial.print("Gas level: ");
 Serial.println(gaslevel);
 if (gaslevel > 700){
  digitalWrite(D2,HIGH);
 }else{
  digitalWrite(D2,LOW);
 }
 delay(1000);
}
