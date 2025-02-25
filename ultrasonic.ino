#define trig D5
#define echo D6
#define led D2

 void setup () 
{
  Serial.begin(9600);
  pinMode (trig, OUTPUT);     //Trig
  pinMode (echo, INPUT);      //Echo
}

void loop (){

  long duration;
  float distance;

  //clear the trig pin
  digitalWrite(trig,LOW);
  delayMicroseconds(2);

  //set the trigger pin high fot 10 microseconds
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  //measure the echo pulse width
  duration = pulseIn(echo,HIGH);

  //speed of sound or ultrasonic wave = 343 meters per seconds
  //speed of sound or ultrasonic wave = 0.0343 cm per microseconds
  distance = (duration * 0.034)/2;

  int threshold = 5;
  if (distance < threshold){
	  digitalWrite(led,HIGH);
  }else{
	  digitalWrite(led,LOW);
  }

  //print the distance on serial monitor
  Serial.print("Distance....");
  Serial.print(distance);
  Serial.println("CM");

  delay(2000);
}

