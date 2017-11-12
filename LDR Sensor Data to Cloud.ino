#include <CayenneMQTTESP8266.h>
#include <ESP8266WiFi.h> //to use espwifi

char ssid[] = "jinn"; //to tell the wifi & pw name to esp
char password[] = "jeenaksaju";

char username[] = "f7b9e220-ab2a-11e7-a1da-536ee79fd847";
char mqtt_password[] = "65772ca6f34a31873c8bc251f8fb608407f035bc";
char client_id[] = "7ef5c970-ab2b-11e7-bba6-6918eb39b85e"; //name of the device

int ldr = A0; //global decl.
int ldr_data;

void setup()
{

    Cayenne.begin(username,mqtt_password,client_id,ssid,password);  //to set connection bw cayenne and system & start Cayenne

    pinMode(ldr,INPUT);
  
}

void loop()
{
    Cayenne.loop();
  
    ldr_data = analogRead(ldr);

    Cayenne.virtualWrite(0, ldr_data);   //virtual print 
}

//mydevices.cayenne
