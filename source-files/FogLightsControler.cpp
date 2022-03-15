#include "FogLightsControler.h"

FogLightsControler::FogLightsControler()
	: left("Left fog light"), right("Right fog light") {}

void FogLightsControler::TurnOn()
{
	//If the left and right fog lights are off then they can be turned on
	if (!isOn_left_right)
	{
		//Left and right fog lights marked as on
		isOn_left_right = true;
		/// Turns on the left fog light
		left.On();
		/// Turns on the right fog light
		right.On();
	}
}
void FogLightsControler::TurnOff()
{
	//If the left and right fog lights are on then they can be turned off
	if (isOn_left_right)
	{
		//Left and right fog lights marked as off
		isOn_left_right = false;
		/// Turns off the left fog light
		left.Off();
		/// Turns off the right fog light
		right.Off();
	}
}
void FogLightsControler::DisplayInfo_left()
{
	left.Diagnose();
}
void FogLightsControler::DisplayInfo_right()
{
	right.Diagnose();
}
void FogLightsControler::Replace_left()
{
	left.Replace();
}
void FogLightsControler::Replace_right()
{
	right.Replace();
}