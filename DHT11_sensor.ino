#include <DHT.h>
#include <DHT_U.h>

float tem;
float hum;
float temf;

#define dhtpin 8   //defining dht pinno.
#define dhttype DHT11 //defining dht type

DHT dht(dhtpin, dhttype);
void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  dht.begin();
}

void loop() {
  tem = dht.readTemperature();        //reading temperature in celsius
  temf = dht.readTemperature(true);   //reading temperature in fahrenheit
  hum = dht.readHumidity();   

  if(isnan(tem) || isnan(temf) || isnan(hum)){
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  //heat index in fahreheit
  float hif = dht.computeHeatIndex(temf, hum);
  //heat index in celsius
  float hic = dht.computeHeatIndex(tem, hum, false);

  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print("%  Temperature: ");
  Serial.print(tem);
  Serial.print("°C ");
  Serial.print(temf);
  Serial.print("°F  ");
  Serial.print("Heat Index: ");
  Serial.print(hic);
  Serial.print("°C ");
  Serial.print(hif);
  Serial.println("°F ");
  delay(2000);
}
