#include <LiquidCrystal.h> 

// LCD Pin Definitions 
#define rs 7
#define e 8
#define d4 9
#define d5 10
#define d6 11
#define d7 12

// HC SR04 Pin Definitions
#define TRIG_PIN 2
#define ECHO_PIN 3

// Passive Buzzer Pin Definitions 
#define BUZZ_PIN 4

// LED Pin Definitions
#define GREEN_PIN 5
#define YELLOW_PIN 6
#define RED_PIN 13

int pingTravelTime; 
int distance;
int delayTime;
int led;

LiquidCrystal lcd(rs,e,d4,d5,d6,d7);

void setup() {
  pinMode(TRIG_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);

  pinMode(BUZZ_PIN, OUTPUT);

  pinMode(GREEN_PIN,OUTPUT);
  pinMode(YELLOW_PIN,OUTPUT);
  pinMode(RED_PIN,OUTPUT);

  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop() {

  //Emit Ultrasonic Pulse
  digitalWrite(TRIG_PIN,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN,LOW);

  // Measures how long ECHO_PIN stays high for
  pingTravelTime = pulseIn(ECHO_PIN,HIGH); 
  
  // Convert travel time to distance in cm
  distance = (pingTravelTime * 0.0343) / 2;

  // Handling cases where no object is detected 
  if (pingTravelTime == 0){
    lcd.setCursor(0,0);
    lcd.print("No object detected");
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(YELLOW_PIN, LOW);
    digitalWrite(RED_PIN,LOW);
    noTone(BUZZ_PIN);
    return; 
  }

  // Displays distance on LCD
  lcd.setCursor(0,0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm      ");  // Extra spaces to clear display
  

  // Determines the delayTime and which led to light based on distance
  if (distance <= 5)
  {
    delayTime = 1;
    led = RED_PIN;
  }
  else if(distance <= 10)
  {
    delayTime = 150;
    led = YELLOW_PIN;
  }
  else if (distance <= 15)
  {
    delayTime = 700;
    led = GREEN_PIN;
  }
  else
  {
    // No alerts for objects further than 15cm
    delayTime = 0;
    noTone(BUZZ_PIN);
    digitalWrite(RED_PIN, LOW);
    digitalWrite(YELLOW_PIN,LOW);
    digitalWrite(GREEN_PIN, LOW);
    return;
  }
  
  // Turn all LEDs off
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN,LOW);
  digitalWrite(GREEN_PIN, LOW);
  
  // Create a sound and delay based on the distance of the object
  tone(BUZZ_PIN,2000);
  digitalWrite(led,HIGH);
  delay(100);
  noTone(BUZZ_PIN);
  digitalWrite(led,LOW);
  delay(delayTime);

  
}
