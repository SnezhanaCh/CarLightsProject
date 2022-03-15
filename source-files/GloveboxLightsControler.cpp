#include "GloveboxLightsControler.h"

GloveboxLightsControler::GloveboxLightsControler()
	:top("Glovebox light") {}

void GloveboxLightsControler::TurnOn()
{
	//If the glovebox light is off then it can be turned on
	if (!isOn)
	{
		//Glovebox light is marked as on
		isOn = true;
		/// Turns on the glovebox light
		top.On();
	}
}
void GloveboxLightsControler::TurnOff()
{
	//If the glovebox light is on then it can be turned off
	if (isOn)
	{
		//Glovebox light is marked as off
		isOn = false;
		/// Turns off the glovebox light
		top.Off();
	}
}
void GloveboxLightsControler::TurnUpBrightness()
{
	/// Turns up the brightness of the glovebox light
	top.TurnUpBrightness();
}
void GloveboxLightsControler::TurnDownBrightness()
{
	/// Turns down the brightness of the glovebox light
	top.TurnDownBrightness();
}
void GloveboxLightsControler::DisplayInfo_top()
{
	top.Diagnose();
}
void GloveboxLightsControler::Replace_top()
{
	top.Replace();
}