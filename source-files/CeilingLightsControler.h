#pragma once
#include "Light.h"

class CeilingLightsControler
{
private:
	Light front;
	Light backLeft;
	Light backRight;
	bool isOn_front = false;
	bool isOn_backLeft = false;
	bool isOn_backRight = false;
public:
	CeilingLightsControler();

	/// @brief Turns on the front ceiling light
	void TurnOnFront();
	/// @brief Turns on the back left ceiling light
	void TurnOnBackLeft();
	/// @brief Turns on the back right ceiling light
	void TurnOnBackRight();
	/// @brief Turns off the front ceiling light
	void TurnOffFront();
	/// @brief Turns off the back left ceiling light
	void TurnOffBackLeft();
	/// @brief Turns off the back right ceiling light
	void TurnOffBackRight();

	void TurnUpBrightness_front();
	void TurnUpBrightness_backLeft();
	void TurnUpBrightness_backRight();
	void TurnDownBrightness_front();
	void TurnDownBrightness_backLeft();
	void TurnDownBrightness_backRight();

	/// @brief Turns on front, back left, back right ceiling lights
	void TurnOnAll();
	/// @brief Turns off front, back left, back right ceiling lights
	void TurnOffAll();

	/// @brief Displays information about the remaining working hours of the light
	void DisplayInfo_front();
	/// @brief Displays information about the remaining working hours of the light
	void DisplayInfo_backLeft();
	/// @brief Displays information about the remaining working hours of the light
	void DisplayInfo_backRight();

	/// @brief Replace the light with a new one.
	void Replace_front();
	/// @brief Replace the light with a new one.
	void Replace_backLeft();
	/// @brief Replace the light with a new one.
	void Replace_backRight();
};