#include <dht.h>
#include <LiquidCrystal.h>  
#define dht_apin A0 // Analog Pin sensor is connected to
int Contrast = 150; 
dht DHT;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup(){
lcd.begin(16, 2);
analogWrite(6, Contrast);
pinMode(9,OUTPUT);
Serial.begin(9600);
delay(500);//Delay to let system boot
Serial.println("DHT11 Humidity & temperature Sensor\n\n");
delay(1000);//Wait before accessing Sensor 
}
  
void loop(){
 
int t=DHT.temperature;
int h=DHT.humidity;
DHT.read11(dht_apin);
     
Serial.print("Current humidity = ");
Serial.print(h);
Serial.print("%  ");
Serial.print("temperature = ");
Serial.print(t); 
Serial.println("C  ");
 
lcd.setCursor(0,0); 
lcd.print("Temp: ");
lcd.print(t);
delay(500);//Wait 500 milliseconds before accessing sensor again.
 
if(t>=30)
{
   digitalWrite(9, HIGH);
   lcd.setCursor(0,1); 
   lcd.print("Fan ON ");
}
else{
   digitalWrite(9, LOW);
   lcd.setCursor(0,1); 
   lcd.print("Fan OFF");
 }
}
