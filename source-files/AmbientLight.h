#pragma once
#include "Light.h"

#define minColour 380
#define maxColour 780

class AmbientLight
{
private:
	uint16_t currentColour;
	Light red;
	Light green;
	Light blue;
	uint8_t redValue;
	uint8_t greenValue;
	uint8_t blueValue;
	uint8_t brightness;

public:
	AmbientLight() :
		currentColour(minColour),
		red(Light("Ambient Light Red")), 
		green(Light("Ambient Light Green")), 
		blue(Light("Ambient Light Blue")),
		brightness(0) {
		waveLengthToRGBConverter(currentColour, &redValue, &greenValue, &blueValue);
	}
private:
	static void waveLengthToRGBConverter(uint16_t waveLength, uint8_t* outRed, uint8_t* outGreen, uint8_t* outBlue);
public:
	void NextColour();
	void On();
	void Off();
	void TurnUpBrightness();
	void TurnDownBrightness();
};