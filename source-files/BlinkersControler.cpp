#include "BlinkersControler.h"


BlinkersControler::BlinkersControler()
	: frontLeft("Front left blinker"), frontRight("Front right blinker"),
	sideLeft("Side left blinker"), sideRight("Side right blinker"),
	backLeft("Back left blinker"), backRight("Back right blinker") {}

void BlinkersControler::TurnOnFrontLeft()
{
	//If the front left blinker light is off then it can be turned on
	if (!isOn_frontLeft) 
	{
		//Front left blinker light is marked as on
		isOn_frontLeft = true;
		//Turns on the front left blinker light
		frontLeft.On();
	}
}
void BlinkersControler::TurnOnFrontRight()
{
	//If the front right blinker light is off then it can be turned on
	if (!isOn_frontRight) 
	{
		//Front right blinker light is marked as on
		isOn_frontRight = true;
		//Turns on the front right blinker light
		frontRight.On();
	}
}
void BlinkersControler::TurnOnSideLeft()
{
	//If the side left blinker light is off then it can be turned on
	if (!isOn_sideLeft) 
	{
		//Side left blinker light is marked as on
		isOn_sideLeft = true;
		//Turns on the side left blinker light
		sideLeft.On();
	}
}
void BlinkersControler::TurnOnSideRight()
{
	//If the side right blinker light is off then it can be turned on
	if (!isOn_sideRight) 
	{
		//Side right blinker light is marked as on
		isOn_sideRight = true;
		//Turns on the side right blinker light
		sideRight.On();
	}
}
void BlinkersControler::TurnOnBackLeft()
{
	//If the back left blinker light is off then it can be turned on
	if (!isOn_backLeft) 
	{
		//Back left blinker light is marked as on
		isOn_backLeft = true;
		//Turns on the back left blinker light
		backLeft.On();
	}
}
void BlinkersControler::TurnOnBackRight()
{
	//If the back right blinker light is off then it can be turned on
	if (!isOn_backRight)
	{
		//Back right blinker light is marked as on
		isOn_backRight = true;
		//Turns on the back right blinker light
		backRight.On();
	}
}
void BlinkersControler::TurnOffFrontLeft()
{
	//If the front left blinker light is on then it can be turned off
	if (isOn_frontLeft) 
	{
		//Front left blinker light is marked as off
		isOn_frontLeft = false;
		//Turns off the front left blinker light
		frontLeft.Off();
	}
}
void BlinkersControler::TurnOffFrontRight()
{
	//If the front right blinker light is on then it can be turned off
	if (isOn_frontRight)
	{
		//Front right blinker light is marked as off
		isOn_frontRight = false;
		//Turns off the front right blinker light
		frontRight.Off();
	}
}
void BlinkersControler::TurnOffSideLeft()
{
	//If the side left blinker light is on then it can be turned off
	if (isOn_sideLeft) 
	{
		//Side left blinker light is marked as off
		isOn_sideLeft = false;
		//Turns off the side left blinker light
		sideLeft.Off();
	}
}
void BlinkersControler::TurnOffSideRight()
{
	//If the side right blinker light is on then it can be turned off
	if (isOn_sideRight) 
	{
		//Side right blinker light is marked as off
		isOn_sideRight = false;
		//Turns off the side right blinker light
		sideRight.Off();
	}
}
void BlinkersControler::TurnOffBackLeft()
{
	//If the back left blinker light is on then it can be turned off
	if (isOn_backLeft) 
	{
		//Back left blinker light is marked as off
		isOn_backLeft = false;
		//Turns off the back left blinker light
		backLeft.Off();
	}
}
void BlinkersControler::TurnOffBackRight()
{
	//If the back right blinker light is on then it can be turned off
	if (isOn_backRight)
	{
		//Back right blinker light is marked as off
		isOn_backRight = false;
		//Turns off the back right blinker light
		backRight.Off();
	}
}
void BlinkersControler::BlinkOnceAllLeft()
{
	
	TurnOnFrontLeft();
	TurnOnSideLeft();
	TurnOnBackLeft();
	//Blinker remains on for a certain period of time
	std::this_thread::sleep_for(std::chrono::seconds(BLINK_INTERVAL_SEC));
	TurnOffFrontLeft();
	TurnOffSideLeft();
	TurnOffBackLeft();
	//Blinker remains off for a certain period of time
	std::this_thread::sleep_for(std::chrono::seconds(BLINK_INTERVAL_SEC));
}
void BlinkersControler::BlinkOnceAllRight()
{
	TurnOnFrontRight();
	TurnOnSideRight();
	TurnOnBackRight();
	//Blinker remains on for a certain period of time
	std::this_thread::sleep_for(std::chrono::seconds(BLINK_INTERVAL_SEC));
	TurnOffFrontRight();
	TurnOffSideRight();
	TurnOffBackRight();
	//Blinker remains off for a certain period of time
	std::this_thread::sleep_for(std::chrono::seconds(BLINK_INTERVAL_SEC));
}
void BlinkersControler::BlinkOnceAll()
{
	TurnOnFrontLeft();
	TurnOnSideLeft();
	TurnOnBackLeft();
	TurnOnFrontRight();
	TurnOnSideRight();
	TurnOnBackRight();
	//Blinker remains on for a certain period of time
	std::this_thread::sleep_for(std::chrono::seconds(BLINK_INTERVAL_SEC));
	TurnOffFrontLeft();
	TurnOffSideLeft();
	TurnOffBackLeft();
	TurnOffFrontRight();
	TurnOffSideRight();
	TurnOffBackRight();
	//Blinker remains on for a certain period of time
	std::this_thread::sleep_for(std::chrono::seconds(BLINK_INTERVAL_SEC));
}
void BlinkersControler::RunThread_BlinkingAllLeft()
{
	std::unique_lock<std::mutex> lck(mtx);
	activeThread = true;
	blinking = true;
	lck.unlock();
	while (true)
	{
		BlinkOnceAllLeft();
		if (!blinking)
		{
			lck.lock();
			activeThread = false;
			lck.unlock();
			cv.notify_one();
			return;
		}
	}
}
void BlinkersControler::TurnOnBlinkingAllLeft()
{
	//If all blinkers are turned off then left side blinkers can be turned on
	if (!isBlinking_AllLeft && !isBlinking_AllRight)
	{
		//Blink mode on marked
		isBlinking_AllLeft = true;
		std::thread t1;
		if (activeThread)
		{
			std::unique_lock<std::mutex> lck(mtx);
			cv.wait(lck);
		}
		t1 = std::thread(&BlinkersControler::RunThread_BlinkingAllLeft, this);
		t1.detach();
	}
	else
	{
		std::cout << "[INFO] Working blinkers must be turned off before turning on any other ones.\n";
	}
}
void BlinkersControler::TurnOffBlinkingAllLeft()
{
	//If only all the left blinkers are in blink mode then they can exit blink mode
	if (isBlinking_AllLeft && !isBlinking_AllRight)
	{
		//Blink mode off marked
		isBlinking_AllLeft = false;

		//Causes the RunThread_Blinking...() function to return void
		std::unique_lock<std::mutex> lck(mtx);
		blinking = false;
		lck.unlock();
	}
}
void BlinkersControler::RunThread_BlinkingAllRight()
{
	std::unique_lock<std::mutex> lck(mtx);
	activeThread = true;
	blinking = true;
	lck.unlock();
	while (true)
	{
		BlinkOnceAllRight();
		if (!blinking)
		{
			lck.lock();
			activeThread = false;
			lck.unlock();
			cv.notify_one();
			return;
		}
	}
}
void BlinkersControler::TurnOnBlinkingAllRight()
{
	//If all blinkers are turned off then right side blinkers can be turned on
	if (!isBlinking_AllRight && !isBlinking_AllLeft)
	{
		//Blink mode on marked
		isBlinking_AllRight = true;
		std::thread t1;
		if (activeThread)
		{
			std::unique_lock<std::mutex> lck(mtx);
			cv.wait(lck);
		}
		t1 = std::thread(&BlinkersControler::RunThread_BlinkingAllRight, this);
		t1.detach();
	}
	else
	{
		std::cout << "[INFO] Working blinkers must be turned off before turning on any other ones.\n";
	}
}
void BlinkersControler::TurnOffBlinkingAllRight()
{
	//If only all the right blinkers are in blink mode then they can exit blink mode
	if (isBlinking_AllRight && !isBlinking_AllLeft) 
	{
		//Blink mode off marked
		isBlinking_AllRight = false;

		//Causes the RunThread_Blinking...() function to return void
		std::unique_lock<std::mutex> lck(mtx);
		blinking = false;
		lck.unlock();
	}
}
void BlinkersControler::TurnOnFiveBlinksAllLeft()
{
	//If all blinkers are turned off then left side blinkers can be turned on
	if (!isBlinking_AllLeft && !isBlinking_AllRight)
	{
		const uint8_t FIVE_BLINKS = 5;

		//Blink mode on marked
		isBlinking_AllLeft = true;
		for (int i = 0; i < FIVE_BLINKS; ++i)
		{
			BlinkOnceAllLeft();
		}
		//Blink mode off marked
		isBlinking_AllLeft = false;
	}
}
void BlinkersControler::TurnOnFiveBlinksAllRight()
{
	//If all blinkers are turned off then right side blinkers can be turned on
	if (!isBlinking_AllRight && !isBlinking_AllLeft)
	{
		const uint8_t FIVE_BLINKS = 5;

		//Blink mode on marked
		isBlinking_AllRight = true;
		for (int i = 0; i < FIVE_BLINKS; ++i)
		{
			BlinkOnceAllRight();
		}
		//Blink mode off marked
		isBlinking_AllRight = false;
	}
}
void BlinkersControler::RunThread_BlinkingAll()
{
	std::unique_lock<std::mutex> lck(mtx);
	activeThread = true;
	blinking = true;
	lck.unlock();
	while (true)
	{
		BlinkOnceAll();
		if (!blinking)
		{
			lck.lock();
			activeThread = false;
			lck.unlock();
			cv.notify_one();
			return;
		}
	}
}
void BlinkersControler::TurnOnBlinkingAll()
{
	//If all blinkers are turned off then all blinkers can be turned on
	if (!isBlinking_AllLeft && !isBlinking_AllRight) 
	{
		//Blink mode on marked
		isBlinking_AllLeft = true;
		//Blink mode on marked
		isBlinking_AllRight = true;
		//Independent thread spawned
		std::thread t1;
		if (activeThread)
		{
			std::unique_lock<std::mutex> lck(mtx);
			cv.wait(lck);
		}
		t1 = std::thread(&BlinkersControler::RunThread_BlinkingAll, this);
		t1.detach();
	}
	else
	{
		std::cout << "[INFO] Working blinkers must be turned off before turning on any other ones.\n";
	}
}
void BlinkersControler::TurnOffBlinkingAll()
{
	//If all blinkers are in blink mode then they can exit blink mode
	if (isBlinking_AllLeft && isBlinking_AllRight)
	{
		//Blink mode off marked
		isBlinking_AllRight = false;
		isBlinking_AllLeft = false;
		
		//Causes the RunThread_Blinking...() function to return void
		std::unique_lock<std::mutex> lck(mtx);
		blinking = false;
		lck.unlock();
	}
}
void BlinkersControler::TurnOn_ConstantLightMode_All()
{
	TurnOnFrontLeft();
	TurnOnFrontRight();
	TurnOnSideLeft();
	TurnOnSideRight();
	TurnOnBackLeft();
	TurnOnBackRight();
}
void BlinkersControler::TurnOff_ConstantLightMode_All()
{
	TurnOffFrontLeft();
	TurnOffFrontRight();
	TurnOffSideLeft();
	TurnOffSideRight();
	TurnOffBackLeft();
	TurnOffBackRight();
}

void BlinkersControler::DisplayInfo_frontLeft()
{
	frontLeft.Diagnose();
}
void BlinkersControler::DisplayInfo_frontRight()
{
	frontRight.Diagnose();
}
void BlinkersControler::DisplayInfo_sideLeft()
{
	sideLeft.Diagnose();
}
void BlinkersControler::DisplayInfo_sideRight()
{
	sideRight.Diagnose();
}
void BlinkersControler::DisplayInfo_backLeft()
{
	backLeft.Diagnose();
}
void BlinkersControler::DisplayInfo_backRight()
{
	backRight.Diagnose();
}

void BlinkersControler::Replace_frontLeft()
{
	frontLeft.Replace();
}
void BlinkersControler::Replace_frontRight()
{
	frontRight.Replace();
}
void BlinkersControler::Replace_sideLeft()
{
	sideLeft.Replace();
}
void BlinkersControler::Replace_sideRight()
{
	sideRight.Replace();
}
void BlinkersControler::Replace_backLeft()
{
	backLeft.Replace();
}
void BlinkersControler::Replace_backRight()
{
	backRight.Replace();
}