#define BLYNK_TEMPLATE_ID "TMPL6NXSyvXZF"
#define BLYNK_TEMPLATE_NAME "Latihan Kendali Lampu LED"
#define BLYNK_AUTH_TOKEN "n5WbqtaQeRMMn4v5yeZuWyPfGGf8vec3"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

const int LED2 = 18;
const int LED1 = 19;

BLYNK_WRITE(V0) {
  int value = param.asInt();
  digitalWrite(LED1, value);
  Serial.print("LED 1 Menyala");
  Serial.println(value == HIGH ? "Nyala" : "Mati");
}

BLYNK_WRITE(V1) {
  int value = param.asInt();
  digitalWrite(LED2, value);
  Serial.print("LED 2 Menyala");
  Serial.println(value == HIGH ? "Nyala" : "Mati");
}

void setup() {
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  Serial.println("Menghubungkan BLYNK ...");
  Blynk.begin(auth, ssid, pass);
  Serial.println("TERSAMBUNG");
}

void loop() {
  Blynk.run();
}
