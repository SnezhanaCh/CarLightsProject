#pragma once
#include "Light.h"

class FloorLightsControler
{
private:
	Light left;
	Light right;
	bool isOn_left = false;
	bool isOn_right = false;
public:
	FloorLightsControler();

	/// @brief Turns on left and right floor light
	void TurnOn();
	/// @brief Turns off left and right floor light
	void TurnOff();
	/// @brief Turns up the brightness of the left and right floor lights
	void TurnUpBrightness();
	/// @brief Turns down the brightness of the left and right floor lights
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