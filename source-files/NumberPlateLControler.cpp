#include "NumberPlateLControler.h"

NumberPlateLControler::NumberPlateLControler()
	: left("Left number plate light"), right("Right number plate light") {}

void NumberPlateLControler::TurnOn()
{
	//If the left and right number plate lights are off then they can be turned on
	if (!isOn_left_right)
	{
		//Left and right number plate lights marked as on
		isOn_left_right = true;
		/// Turns on the left number plate light
		left.On();
		/// Turns on the right number plate light
		right.On();
	}
}
void NumberPlateLControler::TurnOff()
{
	//If the left and right number plate lights are on then they can be turned off
	if (isOn_left_right)
	{
		//Left and right number plate lights marked as off
		isOn_left_right = false;
		/// Turns off the left number plate light
		left.Off();
		/// Turns off the right number plate light
		right.Off();
	}
}
void NumberPlateLControler::DisplayInfo_left()
{
	left.Diagnose();
}
void NumberPlateLControler::DisplayInfo_right()
{
	right.Diagnose();
}
void NumberPlateLControler::Replace_left()
{
	left.Replace();
}
void NumberPlateLControler::Replace_right()
{
	right.Replace();
}
