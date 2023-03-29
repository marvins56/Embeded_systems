

// #define BLYNK_TEMPLATE_ID "TMPLQvvE9OAS"
// #define BLYNK_TEMPLATE_NAME "FLOOD DETECTION SYSTEM"
// #define BLYNK_AUTH_TOKEN "4PyO-gLfq85_AicEXWjgzUJF4m85GQOD"
#define BLYNK_TEMPLATE_ID "TMPL7z76kYdy"
#define BLYNK_TEMPLATE_NAME "FLOOD DETECTION SYSTEM"
#define BLYNK_AUTH_TOKEN "qmOdnnft8G3IfaL7LhjACTtEs1VK2SSM"

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define trig D5   // Trig pin
#define echo D6 
#define datapin D7

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "my own";
char pass[] = "marvin123456";
int depth =20;

BlynkTimer timer;
 
void waterlevel()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
long t = pulseIn(echo, HIGH);

long cm =  t /29/2;
// Serial.println(cm);
  long level = depth-cm;
  if (level<0)
  level=0;

  level = map(level,0,depth-3,0,100);
  Blynk.virtualWrite(V0, level);
  // Check distance and send notification
if (cm <= 50) {
Blynk.logEvent("midwaterlevel","Water level rising fast please take precaution");
}else if(cm >51 && cm < 80){
  Blynk.logEvent("midwaterlevel","Water level rising RAPIDLY, time to evacuate");

}else if(cm >81 && cm <=100){
  Blynk.logEvent("midwaterlevel","Floods INEVITABLE, PLEASE EVACUATE NOW");

}


}

void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(10L, waterlevel);
  
}

void loop()
{
  Blynk.run();
  timer.run();
  }
