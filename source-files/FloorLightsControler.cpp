#include "FloorLightsControler.h"

FloorLightsControler::FloorLightsControler()
	: left("Left floor light"), right("Right floor light") {}

void FloorLightsControler::TurnOn()
{
	//If the left floor light is off then it can be turned on
	if (!isOn_left)
	{
		//Left floor light is marked as on
		isOn_left = true;
		//Turns on the left floor light
		left.On();
	}
	//If the right floor light is off then it can be turned on
	if (!isOn_right)
	{
		//Right floor light is marked as on
		isOn_right = true;
		//Turns on the right floor light
		right.On();
	}
}
void FloorLightsControler::TurnOff()
{
	//If the left floor light is on then it can be turned off
	if (isOn_left)
	{
		//Left floor light is marked as off
		isOn_left = false;
		//Turns off the left floor light
		left.Off();
	}
	//If the right floor light is on then it can be turned off
	if (isOn_right) 
	{
		//Right floor light is marked as off
		isOn_right = false;
		//Turns off the right floor light
		right.Off();
	}
}
void FloorLightsControler::TurnUpBrightness()
{
	/// Turns up the brightness of the left floor light
	left.TurnUpBrightness();
	/// Turns up the brightness of the right floor light
	right.TurnUpBrightness();
}
void FloorLightsControler::TurnDownBrightness()
{
	/// Turns down the brightness of the left floor light
	left.TurnDownBrightness();
	/// Turns down the brightness of the right floor light
	right.TurnDownBrightness();
}
void FloorLightsControler::DisplayInfo_left()
{
	left.Diagnose();
}
void FloorLightsControler::DisplayInfo_right()
{
	right.Diagnose();
}
void FloorLightsControler::Replace_left()
{
	left.Replace();
}
void FloorLightsControler::Replace_right()
{
	right.Replace();
}