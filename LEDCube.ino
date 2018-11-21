#include <LedCube.h>

LedCube cube;

void setup() 
{
  
}

void loop() 
{
  for(int i = 0; i < 10; i++)
  {
    cube.rotatingPlane();
  }
  for(int i = 0; i < 3; i++)
  {
    cube.randomLights();
  }
  for(int i = 0; i < 5; i++)
  {
    cube.fallingLevel();
  }
}
