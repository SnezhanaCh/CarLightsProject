#include "AmbientLightControler.h"

void AmbientLightControler::TurnOn()
{
	/// Turns on ambient light
	centralWire.On();
}
void AmbientLightControler::TurnOff()
{
	/// Turns off ambient light
	centralWire.Off();
}
void AmbientLightControler::TurnUpBrightness()
{
	/// Turns up the brightness of the ambient light
	centralWire.TurnUpBrightness();
}
void AmbientLightControler::TurnDownBrightness()
{
	/// Turns down the brightness of the ambient light
	centralWire.TurnDownBrightness();
}
void AmbientLightControler::NextColour()
{
	/// Changes the current ambient light color
	centralWire.NextColour();
}