#include "Light.h"
#define brightnessAdjust 51

//--------------------------------------------
// FUNCTION: UpdateLifeRate()
// Updates the life left in the light
//----------------------------------------------
void Light::UpdateLifeRate()
{
	// Calculate the time that has passed since the last time lifeRate was updated
	uint64_t elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - workingTime).count();

	// Calculate how much life has been used based on the power usage
	float ratio = brightness / static_cast<float>(255);
	elapsed = (elapsed * ratio);

	// Reduce the life left in the bulb with the apropriate amount
	if (lifeRate - elapsed < 0)
	{
		lifeRate = 0;
	}
	else
	{
		lifeRate -= elapsed;
	}

	// Update the current time
	workingTime = std::chrono::steady_clock::now();
}

//--------------------------------------------
// FUNCTION: SetBrightness()
// Sets the current brightness of the light
// 
// PARAMETERS:
// _brightness:
//		The value of the brightness. It must
//		be between 0 and 100 otherwise returns
//		an error
//----------------------------------------------
void Light::SetBrightness(char _brightness)
{
	// Update the life remaining
	UpdateLifeRate();
	
	// Check if the light has any life left in it
	if (lifeRate <= 0)
	{
		// It doesn't so it doesnt turn on
		std::cout << name << " is broken." << std::endl;
		return;
	}
	else
	{
		// Set the light to the level specified
		brightness = _brightness;
	}
}

//--------------------------------------------
// FUNCTION: TurnUpBrightness()
// Turns up the brightness of the light
// by brightnessAdjust
//----------------------------------------------
void Light::TurnUpBrightness()
{
	// Check if we can increase the brightness more
	if (brightness == 255)
	{
		// We can't
		std::cout << name << " is already turned on at 100% power." << std::endl;

		// Update the life remaining
		UpdateLifeRate();
		return;
	}

	// Check if the new value will overflow
	if (brightness + brightnessAdjust < 255)
	{
		// It will not
		SetBrightness(brightness + brightnessAdjust);
	}
	else
	{
		// It will, set it to the max possible value
		SetBrightness(255);
	}
	// Inform the user
	std::cout << name << " turned on at " << brightness * 100 / 255 << "% power." << std::endl;
}

//--------------------------------------------
// FUNCTION: TurnDownBrightness()
// Turns down the brightness of the light
// by brightnessAdjust
//----------------------------------------------
void Light::TurnDownBrightness()
{
	// Check if we can decrease the brightness more
	if (brightness == 0)
	{
		// We can't
		std::cout << name << " is already turned on at 0% power." << std::endl;
		// Update the life remaining
		UpdateLifeRate();
		return;
	}

	// Check if the new value will overflow
	if (brightness - brightnessAdjust > 0)
	{
		// It will not
		SetBrightness(brightness - brightnessAdjust);
	}
	else
	{
		// It will, set it to the minimum possible value
		SetBrightness(0);
	}
	// Inform the user
	std::cout << name << " turned on at " << brightness * 100 / 255 << "% power." << std::endl;
}

//--------------------------------------------
// FUNCTION: On()
// Turns the light on at 100% power
//----------------------------------------------
void Light::On()
{
	std::cout << name << " turned on." << std::endl;
	SetBrightness(255);
}

//--------------------------------------------
// FUNCTION: Off()
// Turns the light off.
//----------------------------------------------
void Light::Off()
{
	std::cout << name << " turned off." << std::endl;
	SetBrightness(0);
}

//--------------------------------------------
// FUNCTION: Diagnose()
// Displays information about the remaining working hours of the light.
//----------------------------------------------
void Light::Diagnose()
{
	UpdateLifeRate();
	std::chrono::milliseconds ms(lifeRate); 
	std::chrono::seconds s = std::chrono::duration_cast<std::chrono::seconds> (ms);
	std::chrono::hours h = std::chrono::duration_cast<std::chrono::hours> (ms);
	std::cout << name << " remaining working hours " << h.count();
	std::cout << " (" << s.count() << " secs)" << std::endl;
}

//--------------------------------------------
// FUNCTION: Replace()
// Replace the current light with a new one.
//----------------------------------------------
void Light::Replace()
{
	Light tmp(this->name);
	*this = tmp;
	std::cout << name << " has been replaced with a new one" << std::endl;
}

