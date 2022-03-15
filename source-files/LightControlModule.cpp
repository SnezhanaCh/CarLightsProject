#include "LightControlModule.h"

void LightControlModule::StopAllLights()
{
	TLC.TurnOff();
	DC.TurnOffAll();
	GLC.TurnOff();
	CLC.TurnOffAll();
	FLC.TurnOff();
	DLC.TurnOff();
	ALC.TurnOff();
}
void LightControlModule::TrunkOpen()
{
	TLC.TurnOn();
}
void LightControlModule::TrunkClosed()
{
	TLC.TurnOff();
}
void LightControlModule::BrakePressed()
{
	SLC.TurnOn();
}
void LightControlModule::BrakeReleased()
{
	SLC.TurnOff();
}
void LightControlModule::FrontLeftDoorOpened()
{
	//If the front left door is closed then it can be opened
	if (!isFrontLDoorOpened)
	{
		//Front left door marked open
		isFrontLDoorOpened = true;
		//Start front left door light
		DC.TurnOnFrontLeft();
		//Start ceiling lights
		CLC.TurnOnAll();
		//Start floor lights
		FLC.TurnOn();
	}
}
void LightControlModule::FrontRightDoorOpened()
{
	//If the front right door is closed then it can be opened
	if (!isFrontRDoorOpened)
	{
		//Front right door marked open
		isFrontRDoorOpened = true;
		//Start front right door light
		DC.TurnOnFrontRight();
		//Start ceiling lights
		CLC.TurnOnAll();
		//Start floor lights
		FLC.TurnOn();
	}
}
void LightControlModule::BackLeftDoorOpened()
{
	//If the back left door is closed then it can be opened
	if (!isBackLDoorOpened)
	{
		//Back left door marked open
		isBackLDoorOpened = true;
		//Start back left door light
		DC.TurnOnBackLeft();
		//Start ceiling lights
		CLC.TurnOnAll();
		//Start floor lights
		FLC.TurnOn();
	}
}
void LightControlModule::BackRightDoorOpened()
{
	//If the back right door is closed then it can be opened
	if (!isBackRDoorOpened)
	{
		//Back right door marked open
		isBackRDoorOpened = true;
		//Start back right door light
		DC.TurnOnBackRight();
		//Start ceiling lights
		CLC.TurnOnAll();
		//Start floor lights
		FLC.TurnOn();
	}
}
void LightControlModule::FrontLeftDoorClosed()
{
	//If the front left door is opened then it can be closed
	if (isFrontLDoorOpened)
	{
		//Front left door marked closed
		isFrontLDoorOpened = false;
		//Stop front left door light
		DC.TurnOffFrontLeft();
		//If all doors are closed then ceiling lights and floor lights are turned off
		if ((!isFrontRDoorOpened) && (!isBackLDoorOpened) && (!isBackRDoorOpened))
		{
			//Stop ceiling lights
			CLC.TurnOffAll();
			//Stop floor lights
			FLC.TurnOff();
		}
	}
}
void LightControlModule::FrontRightDoorClosed()
{
	//If the front right door is opened then it can be closed
	if (isFrontRDoorOpened)
	{
		//Front right door marked closed
		isFrontRDoorOpened = false;
		//Stop front right door light
		DC.TurnOffFrontRight();
		//If all doors are closed then ceiling lights and floor lights are turned off
		if ((!isFrontLDoorOpened) && (!isBackLDoorOpened) && (!isBackRDoorOpened))
		{
			//Stop ceiling lights
			CLC.TurnOffAll();
			//Stop floor lights
			FLC.TurnOff();
		}
	}
}
void LightControlModule::BackLeftDoorClosed()
{
	//If the back left door is opened then it can be closed
	if (isBackLDoorOpened)
	{
		//Back left door marked closed
		isBackLDoorOpened = false;
		//Stop back left door light
		DC.TurnOffBackLeft();
		//If all doors are closed then ceiling lights and floor lights are turned off
		if ((!isFrontLDoorOpened) && (!isFrontRDoorOpened) && (!isBackRDoorOpened))
		{
			//Stop ceiling lights
			CLC.TurnOffAll();
			//Stop floor lights
			FLC.TurnOff();
		}
	}
}
void LightControlModule::BackRightDoorClosed()
{
	//If the back right door is opened then it can be closed
	if (isBackRDoorOpened)
	{
		//Back right door marked closed
		isBackRDoorOpened = false;
		//Stop back right door light
		DC.TurnOffBackRight();
		//If all doors are closed then ceiling lights and floor lights are turned off
		if ((!isFrontLDoorOpened) && (!isFrontRDoorOpened) && (!isBackLDoorOpened))
		{
			//Stop ceiling lights
			CLC.TurnOffAll();
			//Stop floor lights
			FLC.TurnOff();
		}
	}
}
void LightControlModule::AllDoorsOpened()
{
	FrontLeftDoorOpened();
	FrontRightDoorOpened();
	BackLeftDoorOpened();
	BackRightDoorOpened();
}
void LightControlModule::AllDoorsClosed()
{
	FrontLeftDoorClosed();
	FrontRightDoorClosed();
	BackLeftDoorClosed();
	BackRightDoorClosed();
}
void LightControlModule::GloveboxOpened()
{
	GLC.TurnOn();
}
void LightControlModule::GloveboxClosed()
{
	GLC.TurnOff();
}
void LightControlModule::CarUnlocked()
{
	BC.BlinkOnceAll();
	DLC.TurnOn();
}
void LightControlModule::CarLocked()
{
	BC.BlinkOnceAll();
	StopAllLights();
}
void LightControlModule::OpenTrunk()
{
	TLC.TurnOn();
}
void LightControlModule::CloseTrunk()
{
	TLC.TurnOff();
}
void LightControlModule::DayLightsOn()
{
	DLC.TurnOn();
}
void LightControlModule::DayLightsOff()
{
	DLC.TurnOff();
}
void LightControlModule::LowBeamOn()
{
	LBC.TurnOn();
	BLC.TurnOn();
	NPC.TurnOn();
}
void LightControlModule::LowBeamOff()
{
	LBC.TurnOff();
	BLC.TurnOff();
	NPC.TurnOff();
}
void LightControlModule::HighBeamOn()
{
	if (LBC.IsOn())
	{
		HBC.TurnOn();
	}
	else
	{
		std::cout << "[INFO] The low beams must be turned on in order to turn on the high beams!\n";
	}
}
void LightControlModule::HighBeamOff()
{
	HBC.TurnOff();
}
void LightControlModule::BlinkersLeftOn()
{
	BC.TurnOnBlinkingAllLeft();
}
void LightControlModule::BlinkersLeftOff()
{
	BC.TurnOffBlinkingAllLeft();
}
void LightControlModule::BlinkersRightOn()
{
	BC.TurnOnBlinkingAllRight();
}
void LightControlModule::BlinkersRightOff()
{
	BC.TurnOffBlinkingAllRight();
}
void LightControlModule::BlinkersLeftFiveBlinks()
{
	BC.TurnOnFiveBlinksAllLeft();
}
void LightControlModule::BlinkersRightFiveBlinks()
{
	BC.TurnOnFiveBlinksAllRight();
}
void LightControlModule::FogLightsOn()
{
	FogLC.TurnOn();
}
void LightControlModule::FogLightsOff()
{
	FogLC.TurnOff();
}
void LightControlModule::LightsTestOn()
{
	//TrunkLights
	TLC.TurnOn();
	//StopLights
	SLC.TurnOn();
	//DoorLights
	DC.TurnOnAll();
	//GloveboxLights
	GLC.TurnOn();
	//CeilingLights
	CLC.TurnOnAll();
	//FloorLights
	FLC.TurnOn();
	//BlinkerLights
	BC.TurnOn_ConstantLightMode_All();
	//LowBeamLights
	LBC.TurnOn();
	//DayLights
	DLC.TurnOn();
	//HighBeamLights
	HBC.TurnOn();
	//FogLights
	FogLC.TurnOn();
	//BackLights
	BLC.TurnOn();
	//NumberPlateLights
	NPC.TurnOn();
	//AmbientLight
	ALC.TurnOn();
}
void LightControlModule::LightsTestOff()
{
	//TrunkLights
	TLC.TurnOff();
	//StopLights
	SLC.TurnOff();
	//DoorLights
	DC.TurnOffAll();
	//GloveboxLights
	GLC.TurnOff();
	//CeilingLights
	CLC.TurnOffAll();
	//FloorLights
	FLC.TurnOff();
	//BlinkerLights
	BC.TurnOff_ConstantLightMode_All();
	//LowBeamLights
	LBC.TurnOff();
	//DayLights
	DLC.TurnOff();
	//HighBeamLights
	HBC.TurnOff();
	//FogLights
	FogLC.TurnOff();
	//BackLights
	BLC.TurnOff();
	//NumberPlateLights
	NPC.TurnOff();
	//AmbientLight
	ALC.TurnOff();
}

void LightControlModule::DisplayStatus_TrunkLight_left()
{
	TLC.DisplayInfo_left();
}
void LightControlModule::DisplayStatus_TrunkLight_right()
{
	TLC.DisplayInfo_right();
}
void LightControlModule::DisplayStatus_StopLight_left()
{
	SLC.DisplayInfo_left();
}
void LightControlModule::DisplayStatus_StopLight_right()
{
	SLC.DisplayInfo_right();
}
void LightControlModule::DisplayStatus_DoorLight_frontLeft()
{
	DC.DisplayInfo_frontLeft();
}
void LightControlModule::DisplayStatus_DoorLight_frontRight()
{
	DC.DisplayInfo_frontRight();
}
void LightControlModule::DisplayStatus_DoorLight_backLeft()
{
	DC.DisplayInfo_backLeft();
}
void LightControlModule::DisplayStatus_DoorLight_backRight()
{
	DC.DisplayInfo_backRight();
}
void LightControlModule::DisplayStatus_GloveboxLight_top()
{
	GLC.DisplayInfo_top();
}
void LightControlModule::DisplayStatus_CeilingLight_front()
{
	CLC.DisplayInfo_front();
}
void LightControlModule::DisplayStatus_CeilingLight_backLeft()
{
	CLC.DisplayInfo_backLeft();
}
void LightControlModule::DisplayStatus_CeilingLight_backRight()
{
	CLC.DisplayInfo_backRight();
}
void LightControlModule::DisplayStatus_FloorLight_left()
{
	FLC.DisplayInfo_left();
}
void LightControlModule::DisplayStatus_FloorLight_right()
{
	FLC.DisplayInfo_right();
}
void LightControlModule::DisplayStatus_BlinkerLight_frontLeft()
{
	BC.DisplayInfo_frontLeft();
}
void LightControlModule::DisplayStatus_BlinkerLight_frontRight()
{
	BC.DisplayInfo_frontRight();
}
void LightControlModule::DisplayStatus_BlinkerLight_sideLeft()
{
	BC.DisplayInfo_sideLeft();
}
void LightControlModule::DisplayStatus_BlinkerLight_sideRight()
{
	BC.DisplayInfo_sideRight();
}
void LightControlModule::DisplayStatus_BlinkerLight_backLeft()
{
	BC.DisplayInfo_backLeft();
}
void LightControlModule::DisplayStatus_BlinkerLight_backRight()
{
	BC.DisplayInfo_backRight();
}
void LightControlModule::DisplayStatus_LowBeamLight_left()
{
	LBC.DisplayInfo_left();
}
void LightControlModule::DisplayStatus_LowBeamLight_right()
{
	LBC.DisplayInfo_right();
}
void LightControlModule::DisplayStatus_DayLight_left()
{
	DLC.DisplayInfo_left();
}
void LightControlModule::DisplayStatus_DayLight_right()
{
	DLC.DisplayInfo_right();
}
void LightControlModule::DisplayStatus_HighBeamLight_left()
{
	HBC.DisplayInfo_left();
}
void LightControlModule::DisplayStatus_HighBeamLight_right()
{
	HBC.DisplayInfo_right();
}
void LightControlModule::DisplayStatus_FogLight_left()
{
	FogLC.DisplayInfo_left();
}
void LightControlModule::DisplayStatus_FogLight_right()
{
	FogLC.DisplayInfo_right();
}
void LightControlModule::DisplayStatus_BackLight_left()
{
	BLC.DisplayInfo_left();
}
void LightControlModule::DisplayStatus_BackLight_right()
{
	BLC.DisplayInfo_right();
}
void LightControlModule::DisplayStatus_NumberPlateLight_left()
{
	NPC.DisplayInfo_left();
}
void LightControlModule::DisplayStatus_NumberPlateLight_right()
{
	NPC.DisplayInfo_right();
}
void LightControlModule::DisplayStatus_All()
{
	DisplayStatus_TrunkLight_left();
	DisplayStatus_TrunkLight_right();
	DisplayStatus_StopLight_left();
	DisplayStatus_StopLight_right();
	DisplayStatus_DoorLight_frontLeft();
	DisplayStatus_DoorLight_frontRight();
	DisplayStatus_DoorLight_backLeft();
	DisplayStatus_DoorLight_backRight();
	DisplayStatus_GloveboxLight_top();
	DisplayStatus_CeilingLight_front();
	DisplayStatus_CeilingLight_backLeft();
	DisplayStatus_CeilingLight_backRight();
	DisplayStatus_FloorLight_left();
	DisplayStatus_FloorLight_right();
	DisplayStatus_BlinkerLight_frontLeft();
	DisplayStatus_BlinkerLight_frontRight();
	DisplayStatus_BlinkerLight_sideLeft();
	DisplayStatus_BlinkerLight_sideRight();
	DisplayStatus_BlinkerLight_backLeft();
	DisplayStatus_BlinkerLight_backRight();
	DisplayStatus_LowBeamLight_left();
	DisplayStatus_LowBeamLight_right();
	DisplayStatus_DayLight_left();
	DisplayStatus_DayLight_right();
	DisplayStatus_HighBeamLight_left();
	DisplayStatus_HighBeamLight_right();
	DisplayStatus_FogLight_left();
	DisplayStatus_FogLight_right();
	DisplayStatus_BackLight_left();
	DisplayStatus_BackLight_right();
	DisplayStatus_NumberPlateLight_left();
	DisplayStatus_NumberPlateLight_right();
}

void LightControlModule::Replace_TrunkLight_left()
{
	TLC.Replace_left();
}
void LightControlModule::Replace_TrunkLight_right()
{
	TLC.Replace_right();
}
void LightControlModule::Replace_StopLight_left()
{
	SLC.Replace_left();
}
void LightControlModule::Replace_StopLight_right()
{
	SLC.Replace_right();
}
void LightControlModule::Replace_DoorLight_frontLeft()
{
	DC.Replace_frontLeft();
}
void LightControlModule::Replace_DoorLight_frontRight()
{
	DC.Replace_frontRight();
}
void LightControlModule::Replace_DoorLight_backLeft()
{
	DC.Replace_backLeft();
}
void LightControlModule::Replace_DoorLight_backRight()
{
	DC.Replace_backRight();
}
void LightControlModule::Replace_GloveboxLight_top()
{
	GLC.Replace_top();
}
void LightControlModule::Replace_CeilingLight_front()
{
	CLC.Replace_front();
}
void LightControlModule::Replace_CeilingLight_backLeft()
{
	CLC.Replace_backLeft();
}
void LightControlModule::Replace_CeilingLight_backRight()
{
	CLC.Replace_backRight();
}
void LightControlModule::Replace_FloorLight_left()
{
	FLC.Replace_left();
}
void LightControlModule::Replace_FloorLight_right()
{
	FLC.Replace_right();
}
void LightControlModule::Replace_BlinkerLight_frontLeft()
{
	BC.Replace_frontLeft();
}
void LightControlModule::Replace_BlinkerLight_frontRight()
{
	BC.Replace_frontRight();
}
void LightControlModule::Replace_BlinkerLight_sideLeft()
{
	BC.Replace_sideLeft();
}
void LightControlModule::Replace_BlinkerLight_sideRight()
{
	BC.Replace_sideRight();
}
void LightControlModule::Replace_BlinkerLight_backLeft()
{
	BC.Replace_backLeft();
}
void LightControlModule::Replace_BlinkerLight_backRight()
{
	BC.Replace_backRight();
}
void LightControlModule::Replace_LowBeamLight_left()
{
	LBC.Replace_left();
}
void LightControlModule::Replace_LowBeamLight_right()
{
	LBC.Replace_right();
}
void LightControlModule::Replace_DayLight_left()
{
	DLC.Replace_left();
}
void LightControlModule::Replace_DayLight_right()
{
	DLC.Replace_right();
}
void LightControlModule::Replace_HighBeamLight_left()
{
	HBC.Replace_left();
}
void LightControlModule::Replace_HighBeamLight_right()
{
	HBC.Replace_right();
}
void LightControlModule::Replace_FogLight_left()
{
	FogLC.Replace_left();
}
void LightControlModule::Replace_FogLight_right()
{
	FogLC.Replace_right();
}
void LightControlModule::Replace_BackLight_left()
{
	BLC.Replace_left();
}
void LightControlModule::Replace_BackLight_right()
{
	BLC.Replace_right();
}
void LightControlModule::Replace_NumberPlateLight_left()
{
	NPC.Replace_left();
}
void LightControlModule::Replace_NumberPlateLight_right()
{
	NPC.Replace_right();
}
void LightControlModule::Replace_All()
{
	Replace_TrunkLight_left();
	Replace_TrunkLight_right();
	Replace_StopLight_left();
	Replace_StopLight_right();
	Replace_DoorLight_frontLeft();
	Replace_DoorLight_frontRight();
	Replace_DoorLight_backLeft();
	Replace_DoorLight_backRight();
	Replace_GloveboxLight_top();
	Replace_CeilingLight_front();
	Replace_CeilingLight_backLeft();
	Replace_CeilingLight_backRight();
	Replace_FloorLight_left();
	Replace_FloorLight_right();
	Replace_BlinkerLight_frontLeft();
	Replace_BlinkerLight_frontRight();
	Replace_BlinkerLight_sideLeft();
	Replace_BlinkerLight_sideRight();
	Replace_BlinkerLight_backLeft();
	Replace_BlinkerLight_backRight();
	Replace_LowBeamLight_left();
	Replace_LowBeamLight_right();
	Replace_DayLight_left();
	Replace_DayLight_right();
	Replace_HighBeamLight_left();
	Replace_HighBeamLight_right();
	Replace_FogLight_left();
	Replace_FogLight_right();
	Replace_BackLight_left();
	Replace_BackLight_right();
	Replace_NumberPlateLight_left();
	Replace_NumberPlateLight_right();
}

void LightControlModule::WarningLights_On()
{
	BC.TurnOnBlinkingAll();
}
void LightControlModule::WarningLights_Off()
{
	BC.TurnOffBlinkingAll();
}

void LightControlModule::SwitchAmbientLightColour()
{
	ALC.NextColour();
}
void LightControlModule::TurnUpAmbientBrightness()
{
	ALC.TurnUpBrightness();
}
void LightControlModule::TurnDownAmbientBrightness()
{
	ALC.TurnDownBrightness();
}
void LightControlModule::TurnOnAmbientLights()
{
	ALC.TurnOn();
}
void LightControlModule::TurnOffAmbientLights()
{
	ALC.TurnOff();
}
void LightControlModule::TurnUpCoupeLightsBrightness()
{
	CLC.TurnUpBrightness_front();
	CLC.TurnUpBrightness_backLeft();
	CLC.TurnUpBrightness_backRight();
}
void LightControlModule::TurnDownCoupeLightsBrightness()
{
	CLC.TurnDownBrightness_front();
	CLC.TurnDownBrightness_backLeft();
	CLC.TurnDownBrightness_backRight();
}
void LightControlModule::TurnUpGloveboxBrightness()
{
	GLC.TurnUpBrightness();
}
void LightControlModule::TurnDownGloveboxBrightness()
{
	GLC.TurnDownBrightness();
}
void LightControlModule::TurnOnCoupeLight_front()
{
	CLC.TurnOnFront();
}
void LightControlModule::TurnOnCoupeLight_backLeft()
{
	CLC.TurnOnBackLeft();
}
void LightControlModule::TurnOnCoupeLight_backRight()
{
	CLC.TurnOnBackRight();
}
void LightControlModule::TurnOffCoupeLight_front()
{
	CLC.TurnOffFront();
}
void LightControlModule::TurnOffCoupeLight_backLeft()
{
	CLC.TurnOffBackLeft();
}
void LightControlModule::TurnOffCoupeLight_backRight()
{
	CLC.TurnOffBackRight();
}
void LightControlModule::TurnOnTrunkLights()
{
	TLC.TurnOn();
}
void LightControlModule::TurnOffTrunkLights()
{
	TLC.TurnOff();
}