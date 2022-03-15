#include "TrunkLightsControler.h"

TrunkLightsControler::TrunkLightsControler()
	: left("Left trunk light"), right("Right trunk light") {}

void TrunkLightsControler::TurnOn()
{
	//If the left and right trunk lights are off then they can be turned on
	if (!isOn_left_right)
	{
		//Left and right trunk lights marked as on
		isOn_left_right = true;
		/// Turns on the left trunk light
		left.On();
		/// Turns on the right trunk light
		right.On();
	}
}
void TrunkLightsControler::TurnOff()
{
	//If the left and right trunk lights are on then they can be turned off
	if (isOn_left_right) 
	{
		//Left and right trunk lights marked as off
		isOn_left_right = false;
		/// Turns off the left trunk light
		left.Off();
		/// Turns off the right trunk light
		right.Off();
	}
}
void TrunkLightsControler::TurnUpBrightness() 
{
	/// Turns up the brightness of the left trunk light
	left.TurnUpBrightness();
	/// Turns up the brightness of the right trunk light
	right.TurnUpBrightness();
}
void TrunkLightsControler::TurnDownBrightness() 
{
	/// Turns down the brightness of the left trunk light
	left.TurnDownBrightness();
	/// Turns down the brightness of the right trunk light
	right.TurnDownBrightness();
}
void TrunkLightsControler::DisplayInfo_left()
{
	left.Diagnose();
}
void TrunkLightsControler::DisplayInfo_right()
{
	right.Diagnose();
}
void TrunkLightsControler::Replace_left()
{
	left.Replace();
}
void TrunkLightsControler::Replace_right()
{
	right.Replace();
}