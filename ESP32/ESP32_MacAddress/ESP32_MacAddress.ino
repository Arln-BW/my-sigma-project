#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA); // Mode station untuk mendapatkan MAC Address
  delay(1000);
  Serial.println("MAC Address: " + WiFi.macAddress());
}

void loop() {
  // Tidak perlu loop untuk tujuan ini
}