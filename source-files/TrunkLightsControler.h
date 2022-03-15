#pragma once
#include "Light.h"

class TrunkLightsControler
{
private:
	Light left;
	Light right;
	bool isOn_left_right = false;
public:
	TrunkLightsControler();

	/// @brief Turns on left and right trunk light
	void TurnOn();
	/// @brief Turns off left and right trunk light
	void TurnOff();
	/// @brief Turns up the brightness of the left and right trunk lights
	void TurnUpBrightness();
	/// @brief Turns down the brightness of the left and right trunk lights
	void TurnDownBrightness();
	/// @brief Displays information about the remaining working hours of the light
	void DisplayInfo_left();
	/// @brief Displays information about the remaining working hours of the light
	void DisplayInfo_right();
	/// @brief Replace the light with a new one.
	void Replace_left();
	/// @brief Replace the light with a new one.
	void Replace_right();
};