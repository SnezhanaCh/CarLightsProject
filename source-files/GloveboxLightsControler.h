#pragma once
#include "Light.h"

class GloveboxLightsControler
{
private:
	Light top;
	bool isOn = false;
public:
	GloveboxLightsControler();

	/// @brief Turns on the glovebox light
	void TurnOn();
	/// @brief Turns off the glovebox light
	void TurnOff();
	/// @brief Turns up the brightness of the glovebox light
	void TurnUpBrightness();
	/// @brief Turns down the brightness of the glovebox light
	void TurnDownBrightness();
	/// @brief Displays information about the remaining working hours of the light
	void DisplayInfo_top();
	/// @brief Replace the light with a new one.
	void Replace_top();
};

