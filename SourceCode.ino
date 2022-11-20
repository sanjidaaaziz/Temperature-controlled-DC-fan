#include <LiquidCrystal.h>  
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#define DHTTYPE    DHT11   
#define DHTPIN A0

DHT_Unified dht(DHTPIN, DHTTYPE);
int Contrast = 150; 

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
lcd.begin(16, 2);
analogWrite(6, Contrast);
pinMode(9,OUTPUT);
Serial.begin(9600);
delay(500);
Serial.println("DHT11 Humidity & temperature Sensor\n\n");
delay(1000);
Serial.begin(9600);
dht.begin();
sensor_t sensor;
} 

void loop()
{
  sensors_event_t event;
  dht.temperature().getEvent(&event);

  Serial.print(F("Temp: "));
  Serial.print(event.temperature);
  delay(500);
  
if(event.temperature>=30)
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
