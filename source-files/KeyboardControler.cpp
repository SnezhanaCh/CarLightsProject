#include "KeyboardControler.h"

void KeyboardControler::Start()
{
	char userInput;
	while (1)
	{
		//Inform the use of initial options
		std::cout << std::endl <<

			"Press (number) for controls to:" << std::endl <<

			"(1)" << "Trunk" << std::endl <<
			"(2)" << "Doors" << std::endl <<
			"(3)" << "Brakes" << std::endl <<
			"(4)" << "GloveBox" << std::endl << 
			"(5)" << "Key" << std::endl <<
			"(6)" << "Steering wheel stick" << std::endl <<
			"(7)" << "Head unit" << std::endl <<
			"(8)" << "Diagnostics" << std::endl <<
			"(9)" << "End" << std::endl <<

		std::endl;
		// Get the input from the user
		userInput = getchar();
		getchar();

		// Operate the user command

		switch (userInput)
		{
		case '1':
		{
			// Trunk
			Trunk();
			break;
		}
		case '2':
		{
			// Doors
			Doors();
			break;
		}
		case '3':
		{
			// Brakes
			Brakes();
			break;
		}
		case '4':
		{
			// Glove Box
			GloveBox();
			break;
		}
		case '5':
		{
			// Key
			Key();
			break;
		}
		case '6':
		{
			// Steering wheel stick
			SteeringWheelStick();
			break;
		}
		case '7':
		{
			// Head unit
			HeadUnit();
			break;
		}
		case '8':
		{
			// Diagnostics
			Diagnostics();
			break;
		}
		case '9':
		{
			// End the program
			return;
		}
		default:
			break;
		}

		// Clear the screen
		//system("CLS");
	}
}


void KeyboardControler::Trunk()
{
	char userInput;
	std::cout <<

		"Press (number) to:" << std::endl <<

		"(1)" << "open the trunk" << std::endl <<
		"(2)" << "close the trunk" << std::endl <<
		"(3)" << "Go back" << std::endl <<

		std::endl;

	userInput = getchar();
	getchar();

	switch (userInput)
	{
	case '1':
		lightControlModule.TrunkOpen();
		break;
	case '2':
		lightControlModule.TrunkClosed();
		break;
	case '3':
		return;
	default:
		break;
	}
}
void KeyboardControler::Doors()
{
	uint16_t userInput;
	std::cout <<

		"Press (number) to:" << std::endl <<

		"(1)" << "open all doors" << std::endl <<
		"(2)" << "close all doors" << std::endl <<
		"(3)" << "open the front left door" << std::endl <<
		"(4)" << "close the front left door" << std::endl <<
		"(5)" << "open the front right door" << std::endl <<
		"(6)" << "close the front right door" << std::endl <<
		"(7)" << "open the back left door" << std::endl <<
		"(8)" << "close the back left door" << std::endl <<
		"(9)" << "open the back right door" << std::endl <<
		"(0)" << "close the back right door" << std::endl <<
		"(a)" << "Go back" << std::endl <<

	std::endl;

	userInput = getchar();
	getchar();

	switch (userInput)
	{
	case '1':
		lightControlModule.AllDoorsOpened();
		break;
	case '2':
		lightControlModule.AllDoorsClosed();
		break;
	case '3':
		lightControlModule.FrontLeftDoorOpened();
		break;
	case '4':
		lightControlModule.FrontLeftDoorClosed();
		break;
	case '5':
		lightControlModule.FrontRightDoorOpened();
		break;
	case '6':
		lightControlModule.FrontLeftDoorClosed();
		break;
	case '7':
		lightControlModule.BackLeftDoorOpened();
		break;
	case '8':
		lightControlModule.BackLeftDoorClosed();
		break;
	case '9':
		lightControlModule.BackRightDoorOpened();
		break;
	case '0':
		lightControlModule.BackRightDoorClosed();
		break;
	case 'a':
		return;
	default:
		break;
	}
}
void KeyboardControler::Brakes()
{
	char userInput;
	std::cout <<

		"Press (number) to:" << std::endl <<

		"(1)" << "press the brake" << std::endl <<
		"(2)" << "release the brake" << std::endl <<
		"(3)" << "Go back" << std::endl <<

		std::endl;

	userInput = getchar();
	getchar();

	switch (userInput)
	{
	case '1':
		lightControlModule.BrakePressed();
		break;
	case '2':
		lightControlModule.BrakeReleased();
		break;
	case '3':
		return;
	default:
		break;
	}
}
void KeyboardControler::GloveBox()
{
	char userInput;
	std::cout <<

		"Press (number) to:" << std::endl <<

		"(1)" << "open the glove box" << std::endl <<
		"(2)" << "close the glove box" << std::endl <<
		"(3)" << "Go back" << std::endl <<

		std::endl;

	userInput = getchar();
	getchar();

	switch (userInput)
	{
	case '1':
		lightControlModule.GloveboxOpened();
		break;
	case '2':
		lightControlModule.GloveboxClosed();
		break;
	case '3':
		return;
	default:
		break;
	}
}
void KeyboardControler::Key()
{
	char userInput;
	std::cout <<

		"Press (number) to:" << std::endl <<

		"(1)" << "to unlock the car" << std::endl <<
		"(2)" << "to lock the car" << std::endl <<
		"(3)" << "open the trunk" << std::endl <<
		"(4)" << "close the trunk" << std::endl <<
		"(5)" << "Go back" << std::endl <<

		std::endl;

	userInput = getchar();
	getchar();

	switch (userInput)
	{
	case '1':
		lightControlModule.CarUnlocked();
		break;
	case '2':
		lightControlModule.CarLocked();
		break;
	case '3':
		lightControlModule.TrunkOpen();
		break;
	case '4':
		lightControlModule.TrunkClosed();
	case '5':
		return;
	default:
		break;
	}
}
void KeyboardControler::SteeringWheelStick()
{
	char userInput;
	std::cout <<

		"Press (number) to:" << std::endl <<

		"(1)" << "turn on day lights" << std::endl <<
		"(2)" << "turn off day lights" << std::endl <<
		"(3)" << "turn on low beam" << std::endl <<
		"(4)" << "turn off low beam" << std::endl <<
		"(5)" << "turn on high beam" << std::endl <<
		"(6)" << "turn off high beam" << std::endl <<
		"(7)" << "turn on left blinkers" << std::endl <<
		"(8)" << "turn off left blinkers" << std::endl <<
		"(9)" << "turn on right blinkers" << std::endl <<
		"(0)" << "turn off right blinkers" << std::endl <<
		"(a)" << "blink left blinkers 5 times" << std::endl <<
		"(b)" << "blink right blinkers 5 times" << std::endl <<
		"(c)" << "turn on fog lights" << std::endl <<
		"(d)" << "turn off fog lights" << std::endl <<
		"(e)" << "Go back" << std::endl <<

		std::endl;

	userInput = getchar();
	getchar();

	switch (userInput)
	{
	case '1':
		lightControlModule.DayLightsOn();
		break;
	case '2':
		lightControlModule.DayLightsOff();
		break;
	case '3':
		lightControlModule.LowBeamOn();
		break;
	case '4':
		lightControlModule.LowBeamOff();
		break;
	case '5':
		lightControlModule.HighBeamOn();
		break;
	case '6':
		lightControlModule.HighBeamOff();
		break;
	case '7':
		lightControlModule.BlinkersLeftOn();
		break;
	case '8':
		lightControlModule.BlinkersLeftOff();
		break;
	case '9':
		lightControlModule.BlinkersRightOn();
		break;
	case '0':
		lightControlModule.BlinkersRightOff();
		break;
	case 'a':
		lightControlModule.BlinkersLeftFiveBlinks();
		break;
	case 'b':
		lightControlModule.BlinkersRightFiveBlinks();
		break;
	case 'c':
		lightControlModule.FogLightsOn();
		break;
	case 'd':
		lightControlModule.FogLightsOff();
		break;
	case 'e':
		return;
	default:
		break;
	}
}
void KeyboardControler::HeadUnit()
{
	char userInput;
	std::cout <<

		"Press (number) to:" << std::endl <<

		"(1)" << "turn on warning lights" << std::endl <<
		"(2)" << "turn off warning lights" << std::endl <<
		"(3)" << "switch ambient lights colour" << std::endl <<
		"(4)" << "turn up ambient lights brightness" << std::endl <<
		"(5)" << "turn down ambient lights brightness" << std::endl <<
		"(6)" << "turn on the ambient lights" << std::endl <<
		"(7)" << "turn off the ambient lights" << std::endl <<
		"(8)" << "turn up coupe lights brightness" << std::endl <<
		"(9)" << "turn down coupe lights brightness" << std::endl <<
		"(0)" << "turn on front coupe light" << std::endl <<
		"(a)" << "turn off front coupe light" << std::endl <<
		"(b)" << "turn on back left coupe light" << std::endl <<
		"(c)" << "turn off back left coupe light" << std::endl <<
		"(d)" << "turn on back right coupe light" << std::endl <<
		"(e)" << "turn off back right coupe light" << std::endl <<
		"(f)" << "only turn on trunk lights" << std::endl <<
		"(g)" << "only turn off trunk lights" << std::endl <<
		"(h)" << "turn up glovebox light brightness" << std::endl <<
		"(i)" << "turn down glovebox light brightness" << std::endl <<
		"(j)" << "Go back" << std::endl <<

		std::endl;

	userInput = getchar();
	getchar();

	switch (userInput)
	{
	case '1':
		lightControlModule.WarningLights_On();
		break;
	case '2':
		lightControlModule.WarningLights_Off();
		break;
	case '3':
		lightControlModule.SwitchAmbientLightColour();
		break;
	case '4':
		lightControlModule.TurnUpAmbientBrightness();
		break;
	case '5':
		lightControlModule.TurnDownAmbientBrightness();
		break;
	case '6':
		lightControlModule.TurnOnAmbientLights();
		break;
	case '7':
		lightControlModule.TurnOffAmbientLights();
		break;
	case '8':
		lightControlModule.TurnUpCoupeLightsBrightness();
		break;
	case '9':
		lightControlModule.TurnDownCoupeLightsBrightness();
		break;
	case '0':
		lightControlModule.TurnOnCoupeLight_front();
		break;
	case 'a':
		lightControlModule.TurnOffCoupeLight_front();
		break;
	case 'b':
		lightControlModule.TurnOnCoupeLight_backLeft();
		break;
	case 'c':
		lightControlModule.TurnOffCoupeLight_backLeft();
		break;
	case 'd':
		lightControlModule.TurnOnCoupeLight_backRight();
		break;
	case 'e':
		lightControlModule.TurnOffCoupeLight_backRight();
		break;
	case 'f':
		lightControlModule.TurnOnTrunkLights();
		break;
	case 'g':
		lightControlModule.TurnOffTrunkLights();
		break;
	case 'h':
		lightControlModule.TurnUpGloveboxBrightness();
		break;
	case 'i':
		lightControlModule.TurnDownGloveboxBrightness();
			break;
	case 'j':
		return;
	default:
		break;
	}
}
void KeyboardControler::Diagnostics()
{
	char userInput;
	std::cout <<

		"Press (number) to:" << std::endl <<

		"(1)" << "test lights on" << std::endl <<
		"(2)" << "test lights off" << std::endl <<
		"(3)" << "display lights status" << std::endl <<
		"(4)" << "replace lights" << std::endl <<
		"(5)" << "Go back" << std::endl <<

		std::endl;

	userInput = getchar();
	getchar();


	switch (userInput)
	{
	case '1':
		lightControlModule.LightsTestOn();
		break;
	case '2':
		lightControlModule.LightsTestOff();
		break;
	case '3':
		Diagnostics_DisplayStatus();
		break;
	case '4':
		Diagnostics_ReplaceLight();
		break;
	case '5':
		return;
	default:
		break;
	}
}
void KeyboardControler::Diagnostics_DisplayStatus()
{
	char userInput;
	std::cout <<

		"Press (number) to:" << std::endl <<

		"(1)" << "display left trunk light status" << std::endl <<
		"(2)" << "display right trunk light status" << std::endl <<
		"(3)" << "display left stop light status" << std::endl <<
		"(4)" << "display right stop light status" << std::endl <<
		"(5)" << "display front left door light status" << std::endl <<
		"(6)" << "display front right door light status" << std::endl <<
		"(7)" << "display back left door light status" << std::endl <<
		"(8)" << "display back right door light status" << std::endl <<
		"(9)" << "display glovebox light status" << std::endl <<
		"(0)" << "display front ceiling light status" << std::endl <<
		"(a)" << "display back left ceiling light status" << std::endl <<
		"(b)" << "display back right ceiling light status" << std::endl <<
		"(c)" << "display left floor light status" << std::endl <<
		"(d)" << "display right floor light status" << std::endl <<
		"(e)" << "display front left blinker status" << std::endl <<
		"(f)" << "display front right blinker status" << std::endl <<
		"(g)" << "display side left blinker status" << std::endl <<
		"(h)" << "display side right blinker status" << std::endl <<
		"(i)" << "display back left blinker status" << std::endl <<
		"(j)" << "display back right blinker status" << std::endl <<
		"(k)" << "display left low beam light status" << std::endl <<
		"(l)" << "display right low beam light status" << std::endl <<
		"(m)" << "display left day light status" << std::endl <<
		"(n)" << "display right day light status" << std::endl <<
		"(o)" << "display left high beam light status" << std::endl <<
		"(p)" << "display right high beam light status" << std::endl <<
		"(q)" << "display left fog light status" << std::endl <<
		"(r)" << "display right fog light status" << std::endl <<
		"(s)" << "display left back light status" << std::endl <<
		"(t)" << "display right back light status" << std::endl <<
		"(u)" << "display left number plate light status" << std::endl <<
		"(v)" << "display right number plate light status" << std::endl <<
		"(w)" << "display the status of all lights" << std::endl <<
		"(x)" << "Go back" << std::endl <<
		
		std::endl;

	userInput = getchar();
	getchar();

	switch (userInput)
	{
	case '1':
		lightControlModule.DisplayStatus_TrunkLight_left();
		break;
	case '2':
		lightControlModule.DisplayStatus_TrunkLight_right();
		break;
	case '3':
		lightControlModule.DisplayStatus_StopLight_left();
		break;
	case '4':
		lightControlModule.DisplayStatus_StopLight_right();
		break;
	case '5':
		lightControlModule.DisplayStatus_DoorLight_frontLeft();
		break;
	case '6':
		lightControlModule.DisplayStatus_DoorLight_frontRight();
		break;
	case '7':
		lightControlModule.DisplayStatus_DoorLight_backLeft();
		break;
	case '8':
		lightControlModule.DisplayStatus_DoorLight_backRight();
		break;
	case '9':
		lightControlModule.DisplayStatus_GloveboxLight_top();
		break;
	case '0':
		lightControlModule.DisplayStatus_CeilingLight_front();
		break;
	case 'a':
		lightControlModule.DisplayStatus_CeilingLight_backLeft();
		break;
	case 'b':
		lightControlModule.DisplayStatus_CeilingLight_backRight();
		break;
	case 'c':
		lightControlModule.DisplayStatus_FloorLight_left();
		break;
	case 'd':
		lightControlModule.DisplayStatus_FloorLight_right();
		break;
	case 'e':
		lightControlModule.DisplayStatus_BlinkerLight_frontLeft();
		break;
	case 'f':
		lightControlModule.DisplayStatus_BlinkerLight_frontRight();
		break;
	case 'g':
		lightControlModule.DisplayStatus_BlinkerLight_sideLeft();
		break;
	case 'h':
		lightControlModule.DisplayStatus_BlinkerLight_sideRight();
		break;
	case 'i':
		lightControlModule.DisplayStatus_BlinkerLight_backLeft();
		break;
	case 'j':
		lightControlModule.DisplayStatus_BlinkerLight_backRight();
		break;
	case 'k':
		lightControlModule.DisplayStatus_LowBeamLight_left();
		break;
	case 'l':
		lightControlModule.DisplayStatus_LowBeamLight_right();
		break;
	case 'm':
		lightControlModule.DisplayStatus_DayLight_left();
		break;
	case 'n':
		lightControlModule.DisplayStatus_DayLight_right();
		break;
	case 'o':
		lightControlModule.DisplayStatus_HighBeamLight_left();
		break;
	case 'p':
		lightControlModule.DisplayStatus_HighBeamLight_right();
		break;
	case 'q':
		lightControlModule.DisplayStatus_FogLight_left();
		break;
	case 'r':
		lightControlModule.DisplayStatus_FogLight_right();
		break;
	case 's':
		lightControlModule.DisplayStatus_BackLight_left();
		break;
	case 't':
		lightControlModule.DisplayStatus_BackLight_right();
		break;
	case 'u':
		lightControlModule.DisplayStatus_NumberPlateLight_left();
		break;
	case 'v':
		lightControlModule.DisplayStatus_NumberPlateLight_right();
		break;
	case 'w':
		lightControlModule.DisplayStatus_All();
		break;
	case 'x':
		return;
	default:
		break;
	}

}
void KeyboardControler::Diagnostics_ReplaceLight()
{
	char userInput;
	std::cout <<

		"Press (number) to:" << std::endl <<

		"(1)" << "replace left trunk light" << std::endl <<
		"(2)" << "replace right trunk light" << std::endl <<
		"(3)" << "replace left stop light" << std::endl <<
		"(4)" << "replace right stop light" << std::endl <<
		"(5)" << "replace front left door light" << std::endl <<
		"(6)" << "replace front right door light" << std::endl <<
		"(7)" << "replace back left door light" << std::endl <<
		"(8)" << "replace back right door light" << std::endl <<
		"(9)" << "replace glovebox light" << std::endl <<
		"(0)" << "replace front ceiling light" << std::endl <<
		"(a)" << "replace back left ceiling light" << std::endl <<
		"(b)" << "replace back right ceiling light" << std::endl <<
		"(c)" << "replace left floor light" << std::endl <<
		"(d)" << "replace right floor light" << std::endl <<
		"(e)" << "replace front left blinker" << std::endl <<
		"(f)" << "replace front right blinker" << std::endl <<
		"(g)" << "replace side left blinker" << std::endl <<
		"(h)" << "replace side right blinker" << std::endl <<
		"(i)" << "replace back left blinker" << std::endl <<
		"(j)" << "replace back right blinker" << std::endl <<
		"(k)" << "replace left low beam light" << std::endl <<
		"(l)" << "replace right low beam light" << std::endl <<
		"(m)" << "replace left day light" << std::endl <<
		"(n)" << "replace right day light" << std::endl <<
		"(o)" << "replace left high beam light" << std::endl <<
		"(p)" << "replace right high beam light" << std::endl <<
		"(q)" << "replace left fog light " << std::endl <<
		"(r)" << "replace right fog light" << std::endl <<
		"(s)" << "replace left back light" << std::endl <<
		"(t)" << "replace right back light" << std::endl <<
		"(u)" << "replace left number plate light" << std::endl <<
		"(v)" << "replace right number plate light" << std::endl <<
		"(w)" << "replace all lights" << std::endl <<
		"(x)" << "Go back" << std::endl <<

		std::endl;

	userInput = getchar();
	getchar();

	switch (userInput)
	{
	case '1':
		lightControlModule.Replace_TrunkLight_left();
		break;
	case '2':
		lightControlModule.Replace_TrunkLight_right();
		break;
	case '3':
		lightControlModule.Replace_StopLight_left();
		break;
	case '4':
		lightControlModule.Replace_StopLight_right();
		break;
	case '5':
		lightControlModule.Replace_DoorLight_frontLeft();
		break;
	case '6':
		lightControlModule.Replace_DoorLight_frontRight();
		break;
	case '7':
		lightControlModule.Replace_DoorLight_backLeft();
		break;
	case '8':
		lightControlModule.Replace_DoorLight_backRight();
		break;
	case '9':
		lightControlModule.Replace_GloveboxLight_top();
		break;
	case '0':
		lightControlModule.Replace_CeilingLight_front();
		break;
	case 'a':
		lightControlModule.Replace_CeilingLight_backLeft();
		break;
	case 'b':
		lightControlModule.Replace_CeilingLight_backRight();
		break;
	case 'c':
		lightControlModule.Replace_FloorLight_left();
		break;
	case 'd':
		lightControlModule.Replace_FloorLight_right();
		break;
	case 'e':
		lightControlModule.Replace_BlinkerLight_frontLeft();
		break;
	case 'f':
		lightControlModule.Replace_BlinkerLight_frontRight();
		break;
	case 'g':
		lightControlModule.Replace_BlinkerLight_sideLeft();
		break;
	case 'h':
		lightControlModule.Replace_BlinkerLight_sideRight();
		break;
	case 'i':
		lightControlModule.Replace_BlinkerLight_backLeft();
		break;
	case 'j':
		lightControlModule.Replace_BlinkerLight_backRight();
		break;
	case 'k':
		lightControlModule.Replace_LowBeamLight_left();
		break;
	case 'l':
		lightControlModule.Replace_LowBeamLight_right();
		break;
	case 'm':
		lightControlModule.Replace_DayLight_left();
		break;
	case 'n':
		lightControlModule.Replace_DayLight_right();
		break;
	case 'o':
		lightControlModule.Replace_HighBeamLight_left();
		break;
	case 'p':
		lightControlModule.Replace_HighBeamLight_right();
		break;
	case 'q':
		lightControlModule.Replace_FogLight_left();
		break;
	case 'r':
		lightControlModule.Replace_FogLight_right();
		break;
	case 's':
		lightControlModule.Replace_BackLight_left();
		break;
	case 't':
		lightControlModule.Replace_BackLight_right();
		break;
	case 'u':
		lightControlModule.Replace_NumberPlateLight_left();
		break;
	case 'v':
		lightControlModule.Replace_NumberPlateLight_right();
		break;
	case 'w':
		lightControlModule.Replace_All();
		break;
	case 'x':
		return;
	default:
		break;
	}
}