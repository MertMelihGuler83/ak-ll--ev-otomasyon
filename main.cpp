#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

char auth[] = "YourBlynkAuthToken";
char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
}

void loop() {
  Blynk.run();
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  Blynk.virtualWrite(V5, humidity);     // Nem verisi gönderiliyor
  Blynk.virtualWrite(V6, temperature);  // Sıcaklık verisi gönderiliyor
  delay(2000);
}
