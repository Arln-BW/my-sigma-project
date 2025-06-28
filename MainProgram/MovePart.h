#include"Motor.h"

class LowerPart{
  private:
    Motor roda_1;
    Motor roda_2;
  public:
    LowerPart();
    LowerPart(byte sel_1, byte pwm_1, byte sel_2, byte pwm_24);
    void Movement(float V1, float V2);
};