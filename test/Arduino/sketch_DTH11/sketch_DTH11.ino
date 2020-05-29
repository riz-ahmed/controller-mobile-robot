#include <dht11.h>

#define dht_apin A0

dht11 DHT11;

void setup() {
  
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
}

void loop() {
  
  DHT11.read(dht_apin);

  Serial.print("Current humidity = ");
  Serial.print(DHT11.humidity);
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(DHT11.temperature); 
  Serial.println("C  ");
  
  delay(1000);//Wait 5 seconds before accessing sensor again.
}
