#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 2, 3, 4, 5);
int tpin = A2;
int fpin = 11;
int fspeed=0;
int fLCD;
void setup()
{ 
Serial.begin(9600);
pinMode(fpin, OUTPUT);
pinMode(tpin, INPUT);
lcd.begin(16, 2);  
lcd.setCursor(3,0);  
lcd.print("TEMPERATURE");  
lcd.setCursor(2,1);  
lcd.print("CONTROL SYSTEM");
delay(2000);  
lcd.clear();
}
void loop()
{    
int val = analogRead(tpin);  
float v= val * (5.0/1023);  
float t = v * 100.0;
  Serial.println("voltage=");
  Serial.println(v);
  Serial.println("Temperature=");
  Serial.println(t);
  delay(1000);
if(t < 30)      
{            
fspeed = 0;              
analogWrite(fpin, fspeed);          
fLCD=0;              
}   
if((t >= 30) && (t <= 60))    
{         
fspeed = map(t, 30, 60, 0, 100);         
fLCD = map(t, 30, 60, 0, 100);     
analogWrite(fpin, fspeed);        
}  
if(t > 60)  
{           
analogWrite(fpin, 100);           
fLCD = 100; 
}
lcd.setCursor(1,0);   
lcd.print("TEMP: ");   
lcd.print(t);         
lcd.print("C");   
lcd.setCursor(1,1);      
lcd.print("FANSPEED: ");   
lcd.print(fLCD);       
lcd.print("%");   
 
}
