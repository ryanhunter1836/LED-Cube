#define LOWER 10
#define MIDDLE 11
#define UPPER 12
#define L1 1
#define L2 2
#define L3 3
#define M1 4
#define M2 5
#define M3 6
#define R1 7
#define R2 8
#define R3 9

#include "LedCube.h"


//initialize LED cube
LedCube::LedCube()
{
  //set all the pins to outputs
  for(int i = 0; i <= 12; i++)
  {
    pinMode(i, OUTPUT);
  }
  //turn all the lights off
  allLayersOff();
  allOff();
}

void LedCube::allOff()
{
  for(int i = 1; i <= 9; i++)
  {
    digitalWrite(i, LOW);
  }
}

void LedCube::allOn()
{
  for(int i = 0; i <= 9; i++)
  {
    digitalWrite(i, HIGH);
  }
}

void LedCube::allLayersOn()
{
  digitalWrite(LOWER, HIGH);
  digitalWrite(MIDDLE, HIGH);
  digitalWrite(UPPER, HIGH);
}

void LedCube::allLayersOff()
{
  digitalWrite(LOWER, LOW);
  digitalWrite(MIDDLE, LOW);
  digitalWrite(UPPER, LOW);
}

void LedCube::blinkAll()
{
  LedCube::allLayersOn();
  LedCube::allOn();
  delay(1000);
  LedCube::allOff();
  LedCube::allLayersOff();
  delay(3000);
}

void LedCube::fallingLevel()
{
	allOn();
	digitalWrite(UPPER, HIGH);
	delay(500);
	digitalWrite(UPPER, LOW);
	digitalWrite(MIDDLE, HIGH);
	delay(500);
	digitalWrite(MIDDLE, LOW);
	digitalWrite(LOWER, HIGH);
	delay(500);
	digitalWrite(LOWER, LOW);
	allLayersOff();
	allOff();
	delay(3000);
}

void LedCube::randomLights()
{
	allOff();
	allLayersOff();
	for(int i = 0; i < 27; i++)
	{
		long light = random(1, 10);
		long layer = random(10, 13);
		digitalWrite(light, HIGH);
		digitalWrite(layer, HIGH);
		delay(125);
		digitalWrite(light, LOW);
		digitalWrite(layer, LOW);
	}
}

void LedCube::rotatingPlane()
{
	allOn();
	digitalWrite(MIDDLE, HIGH);
	delay(150);
	//we have to use multiplexing in order to get this pattern to display correctly
	for(int i = 0; i < 10; i++)
	{
		allOff();
		allLayersOff();
		digitalWrite(L1, HIGH);
		digitalWrite(L2, HIGH);
		digitalWrite(L3, HIGH);
		digitalWrite(LOWER, HIGH);
		delay(5);
		allOff();
		allLayersOff();
		digitalWrite(M1, HIGH);
		digitalWrite(M2, HIGH);
		digitalWrite(M3, HIGH);
		digitalWrite(MIDDLE, HIGH);
		delay(5);
		allOff();
		allLayersOff();
		digitalWrite(R1, HIGH);
		digitalWrite(R2, HIGH);
		digitalWrite(R3, HIGH);
		digitalWrite(UPPER, HIGH);
		delay(5);
	}
	allOff();
	allLayersOn();
	digitalWrite(M1, HIGH);
	digitalWrite(M2, HIGH);
	digitalWrite(M3, HIGH);
	delay(150);
	//we have to use multiplexing in order to get this pattern to display correctly
	for(int i = 0; i < 10; i++)
	{
		allOff();
		allLayersOff();
		digitalWrite(L1, HIGH);
		digitalWrite(L2, HIGH);
		digitalWrite(L3, HIGH);
		digitalWrite(UPPER, HIGH);
		delay(5);
		allOff();
		allLayersOff();
		digitalWrite(M1, HIGH);
		digitalWrite(M2, HIGH);
		digitalWrite(M3, HIGH);
		digitalWrite(MIDDLE, HIGH);
		delay(5);
		allOff();
		allLayersOff();
		digitalWrite(R1, HIGH);
		digitalWrite(R2, HIGH);
		digitalWrite(R3, HIGH);
		digitalWrite(LOWER, HIGH);
		delay(5);
	}
}