#include "CeilingLightsControler.h"

CeilingLightsControler::CeilingLightsControler()
	: front("Front ceiling light"), backLeft("Back left ceiling light"),
	backRight("Back right ceiling light") {}

void CeilingLightsControler::TurnOnFront()
{
	//If the front ceiling light is off then it can be turned on
	if (!isOn_front) 
	{
		//Front ceiling light is marked as on
		isOn_front = true;
		//Turns on the front ceiling light
		front.On();
	}
}
void CeilingLightsControler::TurnOnBackLeft()
{
	//If the back left ceiling light is off then it can be turned on
	if (!isOn_backLeft) 
	{
		//Back left ceiling light is marked as on
		isOn_backLeft = true;
		//Turns on the back left ceiling light
		backLeft.On();
	}
}
void CeilingLightsControler::TurnOnBackRight()
{
	//If the back right ceiling light is off then it can be turned on
	if (!isOn_backRight) 
	{
		//Back right ceiling light is marked as on
		isOn_backRight = true;
		//Turns on the back right ceiling light
		backRight.On();
	}
}
void CeilingLightsControler::TurnOffFront()
{
	//If the front ceiling light is on then it can be turned off
	if (isOn_front) 
	{
		//Front ceiling light is marked as off
		isOn_front = false;
		//Turns off the front ceiling light
		front.Off();
	}
}
void CeilingLightsControler::TurnOffBackLeft()
{
	//If the back left ceiling light is on then it can be turned off
	if (isOn_backLeft) 
	{
		//Back left ceiling light is marked as off
		isOn_backLeft = false;
		//Turns off the back left ceiling light
		backLeft.Off();
	}
}
void CeilingLightsControler::TurnOffBackRight()
{
	//If the back right ceiling light is on then it can be turned off
	if (isOn_backRight) 
	{
		//Back right ceiling light is marked as off
		isOn_backRight = false;
		//Turns off the back right ceiling light
		backRight.Off();
	}
}

void CeilingLightsControler::TurnUpBrightness_front()
{
	front.TurnUpBrightness();
}
void CeilingLightsControler::TurnUpBrightness_backLeft()
{
	backLeft.TurnUpBrightness();
}
void CeilingLightsControler::TurnUpBrightness_backRight()
{
	backRight.TurnUpBrightness();
}
void CeilingLightsControler::TurnDownBrightness_front()
{
	front.TurnDownBrightness();
}
void CeilingLightsControler::TurnDownBrightness_backLeft()
{
	backLeft.TurnDownBrightness();
}
void CeilingLightsControler::TurnDownBrightness_backRight()
{
	backRight.TurnDownBrightness();
}

void CeilingLightsControler::TurnOnAll()
{
	TurnOnFront();
	TurnOnBackLeft();
	TurnOnBackRight();
}
void CeilingLightsControler::TurnOffAll()
{
	TurnOffFront();
	TurnOffBackLeft();
	TurnOffBackRight();
}

void CeilingLightsControler::DisplayInfo_front()
{
	front.Diagnose();
}
void CeilingLightsControler::DisplayInfo_backLeft()
{
	backLeft.Diagnose();
}
void CeilingLightsControler::DisplayInfo_backRight()
{
	backRight.Diagnose();
}

void CeilingLightsControler::Replace_front()
{
	front.Replace();
}
void CeilingLightsControler::Replace_backLeft()
{
	backLeft.Replace();
}
void CeilingLightsControler::Replace_backRight()
{
	backRight.Replace();
}