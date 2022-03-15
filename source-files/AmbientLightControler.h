#pragma once
#include "AmbientLight.h"

class AmbientLightControler
{
private:
	AmbientLight centralWire;
public:
	/// @brief Turns on ambient light
	void TurnOn();
	/// @brief Turns off ambient light
	void TurnOff();
	/// @brief Turns up the brightness of the ambient light
	void TurnUpBrightness();
	/// @brief Turns down the brightness of the ambient light
	void TurnDownBrightness();
	/// @brief Changes the current ambient light color
	void NextColour();
};
