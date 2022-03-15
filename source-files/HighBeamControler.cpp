#include "HighBeamControler.h"

HighBeamControler::HighBeamControler()
	: left("Left high beam light"), right("Right high beam light") {}

void HighBeamControler::TurnOn()
{
	//If the left and right high beam lights are off then they can be turned on
	if (!isOn_left_right)
	{
		//Left and right high beam lights marked as on
		isOn_left_right = true;
		/// Turns on the left high beam light
		left.On();
		/// Turns on the right high beam light
		right.On();
	}
}
void HighBeamControler::TurnOff()
{
	//If the left and right high beam lights are on then they can be turned off
	if (isOn_left_right)
	{
		//Left and right high beam lights marked as off
		isOn_left_right = false;
		/// Turns off the left high beam light
		left.Off();
		/// Turns off the right high beam light
		right.Off();
	}
}
void HighBeamControler::DisplayInfo_left()
{
	left.Diagnose();
}
void HighBeamControler::DisplayInfo_right()
{
	right.Diagnose();
}
void HighBeamControler::Replace_left()
{
	left.Replace();
}
void HighBeamControler::Replace_right()
{
	right.Replace();
}