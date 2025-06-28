#include "Variable.h"

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  pinMode(analogLX, INPUT);
  pinMode(analogLY, INPUT);
  pinMode(selL, INPUT);
  pinMode(analogRX, INPUT);
  pinMode(analogRY, INPUT);

  // Inisialisasi ESP-NOW -> cek ESP-NOW udah berjalan atau belum
  if (esp_now_init() != 0) {
    Serial.println("Gagal menginisialisasi ESP-NOW");
    return;
  }

  // callback pengiriman
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);

  // peer (ESP32)
  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
}

void loop() {
  SendData(); // Panggil fungsi untuk mengirim data
  analog.LX = analogRead(analogLX);
  analog.LY = analogRead(analogLY);
  analog.RX = analogRead(analogRX);
  analog.RY = analogRead(analogRY);
  control.boost = digitalRead(selL);
}