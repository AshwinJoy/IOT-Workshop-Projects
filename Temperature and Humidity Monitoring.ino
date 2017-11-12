#include <CayenneMQTTESP8266.h>
#include <DHT.h>
#include <ESP8266WiFi.h>


char ssid[] = "*****";
char password[] = "*********";

char username[] = "*****************";
char mqtt_password[] = "*************";
char client_id[] = "*****************";

DHT dht(7,DHT11);

void setup()
{
      Cayenne.begin(username,mqtt_password,client_id,ssid,password);
  
}


void loop()
{
  Cayenne.loop();
  
  float temp = dht.readTemperature(true);
  float hum = dht.readHumidity();

  Cayenne.virtualWrite(1, temp, TYPE_TEMPERATURE , UNIT_FAHRENHEIT);
  Cayenne.virtualWrite(2, hum,  TYPE_RELATIVE_HUMIDITY , UNIT_PERCENT);
   
}
