#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10,11);
LiquidCrystal_I2C lcd(0x27,16,2);
const int TRIGGER_PIN1=2;
const int ECHO_PIN1=3;
const int TRIGGER_PIN2=4;
const int ECHO_PIN2=5;
const int TRIGGER_PIN3=6;
const int ECHO_PIN3=7;
//distance in cm
float distance_1=0, result_1=0;
float distance_2=0, result_2=0;
float distance_3=0, result_3=0;
long Time_1,Time_2,Time_3;
float car_1,car_2;
float d_1=6.0,d_2=6.0,d_3=6.0;
int total = 0 ,time=0 ;
void setup()
{
  mySerial.begin(115200);
  pinMode(TRIGGER_PIN1,OUTPUT);
  pinMode(TRIGGER_PIN2,OUTPUT);  
  pinMode(TRIGGER_PIN3,OUTPUT);
  pinMode(ECHO_PIN1,INPUT);
  pinMode(ECHO_PIN2,INPUT);
  pinMode(ECHO_PIN3,INPUT);
  digitalWrite(TRIGGER_PIN1,LOW);
  digitalWrite(TRIGGER_PIN2,LOW);
  digitalWrite(TRIGGER_PIN3,LOW);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("SMART");
  lcd.setCursor(0,1);
  lcd.print("PARKING");
  delay(2000);
  lcd.clear();
}

void loop() 
{
  total=0;
  car_1=sensor_1();
  car_2=sensor_2();
  lcd.setCursor(0,0);
  lcd.print("CAR1:");
  if(car_1<=d_1)
  {
    lcd.print("PARKED");
  }
  else
  {
    total+=1;
  }
  if(car_1>d_1)
  {
    lcd.print("FREE");
  }
  if(car_2<=d_1)
  {
    lcd.print("PARKED");
  }
  else
  {
    total+=1;
  }
  if(car_2>d_1)
  {
    lcd.print("FREE");
  }
  lcd.print("FREE: ");
  lcd.print(total);
  if(time>=50)
  {
   mySerial.print('*');
   mySerial.print(total);
   mySerial.println('#');
   time=0;
  }
 time+=1;
 delay(200);
}
float sensor_1(void)
{
digitalWrite(TRIGGER_PIN1,HIGH);
delayMicroseconds(10);
digitalWrite(TRIGGER_PIN1,LOW);
Time_1=pulseIn(ECHO_PIN1,HIGH);
d_1=Time_1*0.034;
return result_1=d_1/2;
}
float sensor_2(void)
{
digitalWrite(TRIGGER_PIN2,HIGH);
delayMicroseconds(10);
digitalWrite(TRIGGER_PIN2,LOW);
Time_1=pulseIn(ECHO_PIN2,HIGH);
d_2=Time_2*0.034;
return result_2=d_2/2;
}






