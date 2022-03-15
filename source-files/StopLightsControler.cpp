#include "StopLightsControler.h"

StopLightsControler::StopLightsControler()
	: left("Left stop light"), right("Right stop light") {}

void StopLightsControler::TurnOn()
{
	// If the left and right stop lights are off then they can be turned on
	if (!isOn_left_right)
	{
		//Left and right stop lights marked as on
		isOn_left_right = true;
		// Turns on the left stop light
		left.On();
		/// Turns on the right stop light
		right.On();
	}
}
void StopLightsControler::TurnOff()
{
	//If the left and right stop lights are on then they can be turned off
	if (isOn_left_right)
	{
		//Left and right stop lights marked as off
		isOn_left_right = false;
		/// Turns off the left stop light
		left.Off();
		/// Turns off the right stop light
		right.Off();
	}
}
void StopLightsControler::DisplayInfo_left()
{
	left.Diagnose();
}
void StopLightsControler::DisplayInfo_right()
{
	right.Diagnose();
}
void StopLightsControler::Replace_left()
{
	left.Replace();
}
void StopLightsControler::Replace_right()
{
	right.Replace();
}