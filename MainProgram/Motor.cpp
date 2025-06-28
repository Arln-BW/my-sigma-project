#include "wiring_constants.h"
#include "Motor.h"

Motor::Motor(){
  return;
}

Motor::Motor(byte pin_selector, byte pin_pwm){
  this->pin_selector = pin_selector;
  this->pin_pwm = pin_pwm;

  pinMode(pin_selector, OUTPUT);
  pinMode(pin_pwm, OUTPUT);
}

void Motor::cw(byte speed){
  digitalWrite(pin_selector, LOW); // awal low
  analogWrite(pin_pwm, speed);
}

void Motor::ccw(byte speed){
  digitalWrite(pin_selector, HIGH); // awal high
  analogWrite(pin_pwm, speed);
}

void Motor::stop(){
  analogWrite(pin_pwm, 0);
}