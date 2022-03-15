#include "DayLightsControler.h"

DayLightsControler::DayLightsControler()
	: left("Left day light"), right("Right day light") {}

void DayLightsControler::TurnOn()
{
	//If the left and right day lights are off then they can be turned on
	if (!isOn_left_right)
	{
		//Left and right day lights marked as on
		isOn_left_right = true;
		/// Turns on the left day light
		left.On();
		/// Turns on the right day light
		right.On();
	}
}
void DayLightsControler::TurnOff()
{
	//If the left and right day lights are on then they can be turned off
	if (isOn_left_right)
	{
		//Left and right day lights marked as off
		isOn_left_right = false;
		/// Turns off the left day light
		left.Off();
		/// Turns off the right day light
		right.Off();
	}
}
void DayLightsControler::DisplayInfo_left()
{
	left.Diagnose();
}
void DayLightsControler::DisplayInfo_right()
{
	right.Diagnose();
}
void DayLightsControler::Replace_left()
{
	left.Replace();
}
void DayLightsControler::Replace_right()
{
	right.Replace();
}