#include <Servo.h>     

#include <CayenneMQTTESP8266.h>
#include <ESP8266WiFi.h>

int ldr = A0; //global decl.
int ldr_data;
char ssid[] = "Ohyeah";
char password[] = "amIsafe?";

char username[] = "f7b9e220-ab2a-11e7-a1da-536ee79fd847";
char mqtt_password[] = "65772ca6f34a31873c8bc251f8fb608407f035bc";
char client_id[] = "a30ed5f0-ab3e-11e7-b177-579293954599";
Servo myservo; //object


void setup()
{
    pinMode(ldr,INPUT);
  myservo.attach(D2); //servo connected at d2 pin  digital

  Cayenne.begin(username,mqtt_password,client_id,ssid,password);
}

void loop()
{
  Cayenne.loop();
  
    ldr_data = analogRead(ldr);

    Cayenne.virtualWrite(0, ldr_data);
 }

CAYENNE_IN(2) //channel1
{

  myservo.write(getValue.asInt()); //gets value and coverts it to int
}
  

