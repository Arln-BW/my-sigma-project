// mengirim data
void SendData() {
  esp_now_send(broadcastAddress, (uint8_t *) &control, sizeof(control));
}

// nilai gerak
void controlESP32(){
  float theta = atan2(-(analog.LY - 128), analog.LX - 128);

  if (analog.LX < 101 || analog.LX > 155) {
    control.vx = icos(theta);
  } else {
    control.vx = 0;
  }

  if (analog.LY < 101 || analog.LY > 155) {
    control.vy = isin(theta);
  } else {
    control.vy = 0;
  }

  if (analog.RX < 100) {
    control.Wr = -1;
  } else if (analog.RX > 155) {
    control.Wr = 1;
  } else {
    control.Wr = 0;
  }
}