/*
 * The circuit:
 * LCD RS pin to digital pin 26
 * LCD Enable pin to digital pin 27
 * LCD D4 pin to digital pin 30
 * LCD D5 pin to digital pin 31
 * LCD D6 pin to digital pin 32
 * LCD D7 pin to digital pin 33
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground

 */

#include <LiquidCrystal.h>
LiquidCrystal lcd(26, 27, 30, 31, 32, 33);
int trigPin1=50;
int echoPin1=51;

int trigPin2=41;
int echoPin2=40;

unsigned long time1,time2;
long timewa;
double speedwa;
long duration1, distance1;
long duration2, distance2;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  
  lcd.begin(16, 2);
  lcd.print("Measuring!!!");
  
  
}

void loop() {

  for(long i =0;i<999999;i++){
      digitalWrite(trigPin1, LOW);  // Added this line
      delayMicroseconds(2); // Added this line
      digitalWrite(trigPin1, HIGH);
      delayMicroseconds(10); // Added this line
      digitalWrite(trigPin1, LOW);
      duration1 = pulseIn(echoPin1, HIGH);
      distance1 = (duration1/2) / 29.1;
    
       if (distance1 <= 30 and distance1 >= 1){
        time1 = millis();
        break;
      }
      else {
       // Serial.print ( "Sensor1  ");
       // Serial.print ( distance1);
       // Serial.println("cm");
      }

  }


 // delay(1);
  
  for(long j=0;j<999999;j++){
      digitalWrite(trigPin2, LOW);  // Added this line
      delayMicroseconds(2); // Added this line
      digitalWrite(trigPin2, HIGH);
      delayMicroseconds(10); // Added this line
      digitalWrite(trigPin2, LOW);
      duration2 = pulseIn(echoPin2, HIGH);
      distance2= (duration2/2) / 29.1;
    
       if (distance2 <= 30 and distance2 >= 1){
        time2 = millis();
        break;
    
       // Serial.print("Speed  ");
       // Serial.print(speedwa);
       // Serial.println("cm/s");
      }
      else {
        
       // Serial.print("Sensor2  ");
       // Serial.print(distance2);
       // Serial.println("cm");
      }
    
  }


  lcd.clear();
  timewa = time2 - time1;

  speedwa = 15000.00/timewa;

  Serial.print("Speed  ");
  Serial.print(speedwa);
  Serial.println("cm/s");

  
  lcd.setCursor(0,0);
  lcd.print("Speed in cm/s");
  lcd.setCursor(0,1);
  lcd.print(speedwa);
  
  
 /* Serial.print("time difference  ");
  Serial.print(time2-time1);
  Serial.println("ms");
  */

  if(speedwa >= 100){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("ALERT!!!!!");
      lcd.setCursor(0,1);
      lcd.print("OVERSPEEDING ");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Speed in cm/s");
      lcd.setCursor(0,1);
      lcd.print(speedwa);      
  }

  else{
    delay(1000);
    lcd.clear();
  }
  
  //delay(1000);
  //lcd.clear();
  
}
