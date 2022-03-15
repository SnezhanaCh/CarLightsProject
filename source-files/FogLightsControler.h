#pragma once
#include "Light.h"

class FogLightsControler
{
private:
	Light left;
	Light right;
	bool isOn_left_right = false;
public:
	FogLightsControler();

	// @brief Turns on left and right fog light
	void TurnOn();
	/// @brief Turns off left and right fog light
	void TurnOff();
	/// @brief Displays information about the remaining working hours of the light
	void DisplayInfo_left();
	/// @brief Displays information about the remaining working hours of the light
	void DisplayInfo_right();
	/// @brief Replace the light with a new one.
	void Replace_left();
	/// @brief Replace the light with a new one.
	void Replace_right();
};