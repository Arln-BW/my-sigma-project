#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(9600);        // Inisialisasi Serial Monitor
  WiFi.mode(WIFI_STA);        // Set ke mode Station
  delay(1000);                // Tunggu sebentar untuk stabil
  Serial.print("MAC Address: ");
  Serial.println(WiFi.macAddress()); // Cetak MAC Address
}

void loop() {
  // Tidak perlu loop untuk tujuan ini
}