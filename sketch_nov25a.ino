#define BLYNK_TEMPLATE_ID "TMPL3y6RVk0yP"
#define BLYNK_TEMPLATE_NAME "krish"
#define BLYNK_AUTH_TOKEN "vDhYmEiD0AyxnVtyF8jqX8xI8w2ah9VZ"
#include <gpio.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
 
char auth[] = BLYNK_AUTH_TOKEN;
 
char ssid[] = "Krishna"; // Your Wifi Name
char pass[] = "123456789"; // Your Wifi Password
 
//in the below code, we have set all values reverse
//For value==1, digitalWrite is "LOW" as the realy module is active "LOW" to turn device ON.
//For value==0, digitalWrite is "HIGH" as Optocoupler based relay is turned OFF when HIGH Input is given
BLYNK_WRITE(V1)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D0, LOW); 
    Serial.println("LED ON"); //Setting Digital PIN as LOW to turn ON Device if relay module is "active low"
  }
  if(value == 0)
  {
     digitalWrite(D0, HIGH);
     Serial.println("LED OFF");//Setting Digital PIN as HIGH to turn OFF Device if relay module is "active low"
  }
}
 
BLYNK_WRITE(V2)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D1, LOW);
    Serial.println("LED ON");
  }
  if(value == 0)
  {
     digitalWrite(D1, HIGH);  
     Serial.println("LED OFF");
  }
}
 
BLYNK_WRITE(V3)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D2, LOW);
    Serial.println("LED ON");
  }
  if(value == 0)
  {
     digitalWrite(D2, HIGH);
     Serial.println("LED OFF");
  }
}
 
BLYNK_WRITE(V0)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D3, LOW);
    Serial.println("LED ON");
  }
  if(value == 0)
  {
     digitalWrite(D3, HIGH);
     Serial.println("LED OFF");
  }
}
 
 
void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(D0,OUTPUT); //GPIO 16 (equivalent to PIN 16 of Arduino)
  pinMode(D1,OUTPUT); //GPIO 05 (equivalent to PIN 05 of Arduino)
  pinMode(D2,OUTPUT);//GPIO 04 (equivalent to PIN 16 of Arduino)
  pinMode(D3,OUTPUT);//GPIO 00 (equivalent to PIN 00 of Arduino)
}
 
void loop()
{
  Blynk.run();
}