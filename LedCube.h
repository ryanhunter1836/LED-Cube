/*
 * Library for driving LED cube
 */

#include "Arduino.h"

class LedCube
{
  public:
    LedCube();
    void rotatingPlane(); //display rotating plane
    void fallingLevel();
    void blinkAll();
	void randomLights();
  private:
    void allOff(); //turn all lights off
    void allOn();
    void allLayersOn();
    void allLayersOff();
};
