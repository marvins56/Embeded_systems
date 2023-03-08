/*
  L298N H-Bridge Demo
  l298-demo.ino
  Demonstrates operation of L298N Dual H-Bridge Motor Driver
  
  DroneBot Workshop 2022
  https://dronebotworkshop.com
*/

// Motor Connections (ENA & ENB must use PWM pins)
#include <RH_ASK.h>
#include <SPI.h>


#define IN1 9
#define IN2 8
#define IN3 7
#define IN4 6
#define ENA 10
#define ENB 5

RH_ASK rf_receiver;
int sensorPin = 2;

void motorAccel() {
  for (int i = 0; i < 256; i++) {
    analogWrite(ENA, i);
    analogWrite(ENB, i);
    delay(20);
  }
}

void motorDecel() {
  for (int i = 255; i >= 0; --i) {
    analogWrite(ENA, i);
    analogWrite(ENB, i);
    delay(20);
  }
}

void forward(){
   digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
}
void reverse(){
   digitalWrite(IN1, HIGH);
  digitalWrite(IN2,  LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
}

void left(){

  // Set motors forward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW); 
  analogWrite(ENA, 100);
  analogWrite(ENB, 100); 
}
void Right(){
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
    analogWrite(ENA, 100);
  analogWrite(ENB, 100);
}

void rotate(){
  // Set motors forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  analogWrite(ENA, 150);
  analogWrite(ENB, 150); 
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH); 
  analogWrite(ENA, 150);
  analogWrite(ENB, 150); 
  

}
void setup() {

Serial.begin(9600);
 
  if (!rf_receiver.init()) {
    Serial.println("RF receiver initialization failed!");
  }
  else {
    Serial.println("RF receiver initialized.");
  }
   
   pinMode(sensorPin, INPUT);

  // Set motor connections as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  // Start with motors off
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void loop() {

  uint8_t buffer[RH_ASK_MAX_MESSAGE_LEN];
  uint8_t buf_size = sizeof(buffer);

  if (rf_receiver.recv(buffer, &buf_size)) {
    Serial.print("Received message: ");
    for (int i = 0; i < buf_size; i++) {
      Serial.print((char)buffer[i]);
    }
    Serial.println();
  }  
  int sensorVal = digitalRead(sensorPin);
  if (sensorVal == HIGH) {
  forward();
  Serial.println("HIGH");    
  }
  else{
 if(sensorVal == LOW) {
rotate();


 Serial.println("LOW"); 
   }
       }

     
}
