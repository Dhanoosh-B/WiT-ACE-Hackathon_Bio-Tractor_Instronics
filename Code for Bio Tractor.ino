//Coding part for Bluetooth controling part

#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

char bt='S';
void setup()
{
  Serial.begin(38400);
 
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  Stop();
}


void loop() {
 
bt=Serial.read();

if(bt=='F')
{
 forward(); 
}

if(bt=='B')
{
 backward(); 
}

if(bt=='L')
{
 left(); 
}

if(bt=='R')
{
 right(); 
}

if(bt=='S')
{
 Stop(); 
}

}
void forward()
{
     motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void backward()
{
     motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void left()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void right()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
void Stop()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

// Coding part for coolent monitoring using IBM Cloud

const int trigP = 2;  
const int echoP = 0;  

long duration;
int distance;

void setup() {
pinMode(trigP, OUTPUT);  
pinMode(echoP, INPUT);  
Serial.begin(9600);      
}

void loop() {

digitalWrite(trigP, LOW);   
delayMicroseconds(2);       

digitalWrite(trigP, HIGH);  
delayMicroseconds(10);      
digitalWrite(trigP, LOW);   

duration = pulseIn(echoP, HIGH);   
distance= duration*0.034/2;        

Serial.print("Distance = ");        
Serial.println(distance);
delay(3000);                        
}

//Coding part for electricity monitoring in LCD Display 

#include<LiquidCrystal.h>
#define sensor A0
#define VOLT A1
#define LUX A3
LiquidCrystal lcd(2,3,4,5,6,7);
float Temperature, temp, volt, volts,lux,Temp;
int temp1, value;
byte degree[8] =
              {
                0b00011,
                0b00011,
                0b00000,
                0b00000,
                0b00000,
                0b00000,
                0b00000,
                0b00000
              };
void setup()
{
  lcd.begin(16,2);
  lcd.createChar(1, degree);
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print("  Soler Energy  ");
  lcd.setCursor(0,1);
  lcd.print("  Measurement   ");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" By Saddam Khan ");
  lcd.setCursor(0,1);
  lcd.print("ENGINEERS GARAGE");
  delay(2000);
  lcd.clear();
}
void loop()
{
     float reading=analogRead(sensor);
     Temperature=reading*(5.0/1023.0)*100;
     delay(10);

  temp1=analogRead(VOLT);
  volts= (temp1/511.5)*5;
  delay(10); 
   value=analogRead(LUX);
   volt=(value/1023.0)*5;
   lux=((2500/volt)-500)/3.3;
   delay(10);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("T:");
    lcd.print((int)analog_value);
    lcd.write(1);
    lcd.print("C");
  
    lcd.setCursor(8,0);
    lcd.print("V:");
    lcd.print(volts);
  
    lcd.setCursor(0,1);
    lcd.print("Intens: ");
    lcd.print((int)lux);
    lcd.print(" Lux");
 
 
   Serial.println((int)Temp);
   Serial.println(volts);
   Serial.println((int)lux);
   delay(500);
}

