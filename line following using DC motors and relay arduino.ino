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
int s1 =12;  //left ir
int s2 = 11;  
int s3 = 13;  
int val_L,val_R,val_M;

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

Serial.begin(9600);

  pinMode(s1,INPUT); // make the L_pin as an input
  pinMode(s2,INPUT); // make the M_pin as an input
  pinMode(s3,INPUT); // make the R_pin as an input
  
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

 val_L = digitalRead(s1);//LEFT
   val_M = digitalRead(s2);//MIDDLE
   val_R = digitalRead(s3);//RIGHT
   
  // Serial.print("left:");
  // Serial.println(val_L);
  //  Serial.print(" RIGHT:");
  // Serial.print(val_R);
  // Serial.print(" MIDDLE:");
  // Serial.println(val_M);
  // delay(500);// delay in between reads for stability

  if(val_M == 1)//if the state of middle one is 1, which means detecting black line
  {
    forward();//car goes forward
    Serial.println("moving forward");
  }
  else
  {
    if((val_L == 1)&&(val_R == 0))//if only left line tracking sensor detects black trace
    {
      left();//car turns left
       Serial.println("moving left");
    }
else if((val_L == 0)&&(val_R == 1))//if only right line tracking sensor detects black trace
    {
      Right();//car turns right
       Serial.println("moving right");
    }
    else// if left and right line tracking sensors detect black trace or they don’t read
    {
      rotate();//car searchers 
       Serial.println("rotating ");
    }
  }








//   forward();

// } else if (digitalRead(irsensor)==LOW){
 
//  rotate(); 
// }else{
//    analogWrite(ENA, 0);
//   analogWrite(ENB, 0);
// }
 
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
