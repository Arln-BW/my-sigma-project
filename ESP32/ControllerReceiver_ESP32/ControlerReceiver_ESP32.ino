#include <esp_now.h>
#include <WiFi.h>

struct __attribute__((packed)) DataRobot {
  // bool start;
  bool boost;
  float vx;
  float vy;  
  int Wr;
} control;

// Fungsi untuk membaca dan memproses data yang diterima
void ReadInput(const esp_now_recv_info *recvInfo, const uint8_t *incomingData, int len) {
  memcpy(&control, incomingData, sizeof(control));
}

// Callback saat data diterima
void OnDataRecv(const esp_now_recv_info *recvInfo, const uint8_t *incomingData, int len) {
  ReadInput(recvInfo, incomingData, len); // Panggil fungsi ReadInput
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  // Inisialisasi ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Gagal menginisialisasi ESP-NOW");
    return;
  }

  // callback penerimaan atau panggil fungsinya
  // esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
  esp_now_register_recv_cb(OnDataRecv); // panggil fungsinya

  // ---------------------------------- debugging
  // Serial.print(control.boost);
  // Serial.print(" | ");
  // Serial.print(control.vx);
  // Serial.print(" | ");
  // Serial.print(control.vy);
  // Serial.print(" | ");
  // Serial.println(control.Wr);
}