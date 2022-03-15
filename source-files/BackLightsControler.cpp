#include "BackLightsControler.h"

BackLightsControler::BackLightsControler()
	: left("Left back light"), right("Right back light") {}

void BackLightsControler::TurnOn()
{
	//If the left and right back lights are off then they can be turned on
	if (!isOn_left_right)
	{
		//Left and right back lights marked as on
		isOn_left_right = true;
		// Turns on the left back light
		left.On();
		// Turns on the right back light
		right.On();
	}
}
void BackLightsControler::TurnOff()
{
	//If the left and right back lights are on then they can be turned off
	if (isOn_left_right)
	{
		//Left and right back lights marked as off
		isOn_left_right = false;
		// Turns off the left back light
		left.Off();
		// Turns off the right back light
		right.Off();
	}
}
void BackLightsControler::DisplayInfo_left()
{
	left.Diagnose();
}
void BackLightsControler::DisplayInfo_right()
{
	right.Diagnose();
}
void BackLightsControler::Replace_left()
{
	left.Replace();
}
void BackLightsControler::Replace_right()
{
	right.Replace();
}