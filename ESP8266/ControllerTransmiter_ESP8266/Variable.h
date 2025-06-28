#include "header.h"

// Struktur data yang akan dikirim

struct analogModule {
  int LX;
  int LY;
  int RX;
  int RY;
} analog;

struct __attribute__((packed)) DataRobot {
  // bool start;
  bool boost;
  float vx;
  float vy;  
  int Wr;
} control;