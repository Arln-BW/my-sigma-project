#include <ESP8266WiFi.h>
#include <espnow.h>
#include <FastTrig.h>

// --------------- pin analog
#define analogLX 14 // D5
#define analogLY 12 // D6
#define selL 13 // D7

#define analogRX 16 // D0
#define analogRY 5 // D1

#define pinStart 

// --------------- mac address esp32
// alamat MAC ESP32 -> 88:13:BF:C8:6D:C8
uint8_t broadcastAddress[] = {0x88, 0x13, 0xBF, 0xC8, 0x6D, 0xC8};