#include "LowBeamControler.h"

LowBeamControler::LowBeamControler()
	: left("Left low beam light"), right("Right low beam light") {}

void LowBeamControler::TurnOn()
{
	//If the left and right low beam lights are off then they can be turned on
	if (!isOn_left_right)
	{
		//Left and right low beam lights marked as on
		isOn_left_right = true;
		/// Turns on the left low beam light
		left.On();
		/// Turns on the right low beam light
		right.On();
	}
}
void LowBeamControler::TurnOff()
{
	//If the left and right low beam lights are on then they can be turned off
	if (isOn_left_right)
	{
		//Left and right low beam lights marked as off
		isOn_left_right = false;
		/// Turns off the left low beam light
		left.Off();
		/// Turns off the right low beam light
		right.Off();
	}
}
bool LowBeamControler::IsOn()
{
	return isOn_left_right;
}
void LowBeamControler::DisplayInfo_left()
{
	left.Diagnose();
}
void LowBeamControler::DisplayInfo_right()
{
	right.Diagnose();
}
void LowBeamControler::Replace_left()
{
	left.Replace();
}
void LowBeamControler::Replace_right()
{
	right.Replace();
}