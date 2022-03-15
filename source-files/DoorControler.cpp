#include "DoorControler.h"

DoorControler::DoorControler()
	: frontLeft("Front left door light"), frontRight("Front right door light"),
	backLeft("Back left door light"), backRight("Back right door light") {}

void DoorControler::TurnOnFrontLeft()
{
	//If the front left door light is off then it can be turned on
	if (!isOn_frontLeft)
	{
		//Front left door light is marked as on
		isOn_frontLeft = true;
		//Turns on the front left door light
		frontLeft.On();
	}
}
void DoorControler::TurnOnFrontRight()
{
	//If the front right door light is off then it can be turned on
	if (!isOn_frontRight)
	{
		//Front right door light is marked as on
		isOn_frontRight = true;
		//Turns on the front right door light
		frontRight.On();
	}
}
void DoorControler::TurnOnBackLeft()
{
	//If the back left door light is off then it can be turned on
	if (!isOn_backLeft) 
	{
		//Back left door light is marked as on
		isOn_backLeft = true;
		//Turns on the back left door light
		backLeft.On();
	}
}
void DoorControler::TurnOnBackRight()
{
	//If the back right door light is off then it can be turned on
	if(!isOn_backRight) 
	{
		//Back right door light is marked as on
		isOn_backRight = true;
		//Turns on the back right door light
		backRight.On();
	}
}
void DoorControler::TurnOffFrontLeft()
{
	//If the front left door light is on then it can be turned off
	if (isOn_frontLeft)
	{
		//Front left door light is marked as off
		isOn_frontLeft = false;
		//Turns off the front left door light
		frontLeft.Off();
	}
}
void DoorControler::TurnOffFrontRight()
{
	//If the front right door light is on then it can be turned off
	if(isOn_frontRight) 
	{
		//Front right door light is marked as off
		isOn_frontRight = false;
		//Turns off the front right door light
		frontRight.Off();
	}
}
void DoorControler::TurnOffBackLeft()
{
	//If the back left door light is on then it can be turned off
	if (isOn_backLeft) 
	{
		//Back left door light is marked as off
		isOn_backLeft = false;
		//Turns off the back left door light
		backLeft.Off();
	}
}
void DoorControler::TurnOffBackRight()
{
	//If the back right door light is on then it can be turned off
	if (isOn_backRight) 
	{
		//Back right door light is marked as off
		isOn_backRight = false;
		//Turns off the back right door light
		backRight.Off();
	}
}

void DoorControler::TurnOnAll()
{
	TurnOnFrontLeft();
	TurnOnFrontRight();
	TurnOnBackLeft();
	TurnOnBackRight();
}
void DoorControler::TurnOffAll()
{
	TurnOffFrontLeft();
	TurnOffFrontRight();
	TurnOffBackLeft();
	TurnOffBackRight();
}

void DoorControler::DisplayInfo_frontLeft()
{
	frontLeft.Diagnose();
}
void DoorControler::DisplayInfo_frontRight()
{
	frontRight.Diagnose();
}
void DoorControler::DisplayInfo_backLeft()
{
	backLeft.Diagnose();
}
void DoorControler::DisplayInfo_backRight()
{
	backRight.Diagnose();
}

void DoorControler::Replace_frontLeft()
{
	frontLeft.Replace();
}
void DoorControler::Replace_frontRight()
{
	frontRight.Replace();
}
void DoorControler::Replace_backLeft()
{
	backLeft.Replace();
}
void DoorControler::Replace_backRight()
{
	backRight.Replace();
}