const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor


void setup() {
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
   Serial.begin(9600); // Starting Serial Terminal
}

void loop() {
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   
   cm = microsecondsToCentimeters(duration);
if(cm <= 10) {
  
digitalWrite(13,HIGH);
digitalWrite(11,LOW);
digitalWrite(12,LOW);
}
else if(cm >= 11 && cm <= 50 ) {

digitalWrite(13,LOW);
digitalWrite(11,HIGH);
digitalWrite(12,LOW);
}
else{
  
digitalWrite(13,LOW);
digitalWrite(11,LOW);
digitalWrite(12,HIGH);
}

   Serial.print(inches);
   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(100);
}
long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}