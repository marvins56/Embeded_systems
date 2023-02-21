/*
  L298N H-Bridge Demo
  l298-demo.ino
  Demonstrates operation of L298N Dual H-Bridge Motor Driver
  
  DroneBot Workshop 2022
  https://dronebotworkshop.com
*/

// Motor Connections (ENA & ENB must use PWM pins)
#define IN1 9
#define IN2 8
#define IN3 7
#define IN4 6
#define ENA 10
#define ENB 5
const int irsensor=13;

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
 // Set motors forward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW); 
  analogWrite(ENA, 150);
  analogWrite(ENB, 150); 
}
void reverse(){
 // Set motors forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);  
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
}

void left(){
   digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
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
 
  // digitalWrite(IN1, LOW);
  // digitalWrite(IN2, HIGH);
  
  // digitalWrite(IN3, LOW);
  // digitalWrite(IN4, HIGH);


   digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
  
}
void setup() {

  // Set motor connections as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  Serial.begin(9600);
  // Start with motors off
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void loop() {


if (digitalRead(irsensor)==HIGH){

  forward();

} else if (digitalRead(irsensor)==LOW){
 
 rotate(); 
}else{
   analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
 
// forward();
// delay(3000);
// reverse();
// delay(3000);
//left();
// delay(1000);
// Right();
// delay(1000);
  // Accelerate & decelerate both motors forward
  // motorAccel();
  // motorDecel();

  // delay(500);

  // // Set motors reverse
  // digitalWrite(IN1, LOW);
  // digitalWrite(IN2, HIGH);
  // digitalWrite(IN3, LOW);
  // digitalWrite(IN4, HIGH);

  // // Accelerate & decelerate both motors backward
  // motorAccel();
  // motorDecel();

  // delay(500);

  // // Set motors in opposite directions (full speed)


  

  // delay(500);

  // analogWrite(ENA, 0);
  // analogWrite(ENB, 0);

  // delay(500);
}
