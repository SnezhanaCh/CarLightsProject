#pragma once
#include "Light.h"

class LowBeamControler
{
private:
	Light left;
	Light right;
	bool isOn_left_right = false;
public:
	LowBeamControler();

	/// @brief Turns on left and right low beam light
	void TurnOn();
	/// @brief Turns off left and right low beam light
	void TurnOff();
	
	/// @brief Gives info whether low beam lights are turned on.
	/// @return True if low beam lights are on
	bool IsOn();
	/// @brief Displays information about the remaining working hours of the light
	void DisplayInfo_left();
	/// @brief Displays information about the remaining working hours of the light
	void DisplayInfo_right();
	/// @brief Replace the light with a new one.
	void Replace_left();
	/// @brief Replace the light with a new one.
	void Replace_right();
};