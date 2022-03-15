#include "AmbientLight.h"
#define waveLengthStep (maxColour-minColour) / 20
#define brightnessAdjust 51

//--------------------------------------------
// FUNCTION: NextColour()
// Sets the colour to the
// the next colour in the spectrum
//----------------------------------------------
void AmbientLight::NextColour()
{
	// Calculate the wave length next colour in the spectrum
	currentColour += waveLengthStep;
	if (currentColour > maxColour)
	{
		currentColour = minColour;
	}
	// Convert it to RGB
	waveLengthToRGBConverter(currentColour, &redValue, &greenValue, &blueValue);

	// Inform user
	std::cout << "Ambient light set to colour: " << currentColour << "nm, " <<
		"R: " << redValue * 100 / 255 << "% " <<
		"G:" << greenValue * 100 / 255 << "% " <<
		"B:" << blueValue * 100 / 255 << "% " <<
		std::endl;
	if (brightness != 0)
	{
		red.SetBrightness(redValue * brightness / 255);
		green.SetBrightness(greenValue * brightness / 255);
		blue.SetBrightness(blueValue * brightness / 255);
	}
}

//--------------------------------------------
// FUNCTION: On()
// Turns on the ambient light
//----------------------------------------------
void AmbientLight::On()
{
	// Set the brightness of the lights

	red.SetBrightness(redValue);
	green.SetBrightness(greenValue);
	blue.SetBrightness(blueValue);

	std::cout << "Ambient light turned on: " <<
		"R: " << redValue * 100 / 255 << "% " <<
		"G:" << greenValue * 100 / 255 << "% " <<
		"B:" << blueValue * 100 / 255 << "% " <<
		std::endl;
}

//--------------------------------------------
// FUNCTION: Off()
// Turns off the ambient light
//----------------------------------------------
void AmbientLight::Off()
{
	red.SetBrightness(0);
	green.SetBrightness(0);
	blue.SetBrightness(0);
	std::cout << "Ambient light turned off." << std::endl;
}

//--------------------------------------------
// FUNCTION: TurnUpBrightness()
// Turns up the brightness of the
// ambient light by brightnessAdjust
//----------------------------------------------
void AmbientLight::TurnUpBrightness()
{
	// Check if we can increase the brightness more
	if (brightness == 255)
	{
		// We can't
		std::cout << "Ambient light is already turned on at 100% power." << std::endl;

		return;
	}

	// Check if the new value will overflow
	if (brightness + brightnessAdjust < 255)
	{
		brightness += brightnessAdjust;
	}
	else
	{
		// It will, set it to the max possible value
		brightness = 255;
	}

	// Update the brightnesses
	red.SetBrightness(redValue * brightness / 255);
	green.SetBrightness(greenValue * brightness / 255);
	blue.SetBrightness(blueValue * brightness / 255);

	// Inform the user
	std::cout << "Ambient light turned on at " << brightness * 100 / 255 << " % power " <<
		"R: " << redValue * 100 / 255 << "% " <<
		"G: " << greenValue * 100 / 255 << "% " <<
		"B: " << blueValue * 100 / 255 << "% " << std::endl;
}

//--------------------------------------------
// FUNCTION: TurnDownBrightness()
// Turns down the brightness of the
// ambient light by brightnessAdjust
//----------------------------------------------
void AmbientLight::TurnDownBrightness()
{
	// Check if we can decrease the brightness more
	if (brightness == 0)
	{
		// We can't
		std::cout << "Ambient light is already turned off at 0% power." << std::endl;

		return;
	}

	// Check if the new value will overflow
	if (brightness - brightnessAdjust > 0)
	{
		// It will not
		brightness -= brightnessAdjust;
	}
	else
	{
		// It will, set it to the minimum possible value
		brightness = 0;
	}
	// Update the brightnesses
	red.SetBrightness(redValue * brightness / 255);
	green.SetBrightness(greenValue * brightness / 255);
	blue.SetBrightness(blueValue * brightness / 255);

	// Inform the user
	std::cout << "Ambient light turned on at " << brightness * 100 / 255 << " % power " <<
		"R: " << redValue * 100 / 255 << "% " <<
		"G: " << greenValue * 100 / 255 << "% " <<
		"B: " << blueValue * 100 / 255 << "% " << std::endl;
}
//--------------------------------------------
// FUNCTION: waveLengthToRGBConverter()
// Transforms a given waveLenght to
// appropriate RGB colour configuration
// 
// PARAMETERS:
// waveLength:
//		The given wave length
// outR:
//		Pointer to the storage where the
//		function should return the value
//		of the red light
// outG:
//		Pointer to the storage where the
//		function should return the value
//		of the green light
// outB:
//		Pointer to the storage where the
//		function should return the value
//		of the blue light
//----------------------------------------------
void AmbientLight::waveLengthToRGBConverter(uint16_t waveLength, uint8_t* outR, uint8_t* outG, uint8_t* outB)
{
	float R = 0, G = 0, B = 0;
	// Math is done here
	// https://www.scientificbulletin.upb.ro/rev_docs_arhiva/full49129.pdf
	if (waveLength >= 380 && waveLength <= 410)
	{
		R = 0.6 - 0.41 * (410.0 - waveLength) / 30.0;
		G = 0.0;
		B = 0.39 + 0.6 * (410.0 - waveLength) / 30.0;
	}
	else if (waveLength > 410 && waveLength <= 440)
	{
		R = 0.19 - 0.19 * (440.0 - waveLength) / 30.0;
		G = 0.0;
		B = 1.0;
	}
	else if (waveLength > 440 && waveLength <= 490)
	{
		R = 0;
		G = 1 - (490.0 - waveLength) / 50.0;
		B = 1.0;
	}
	else if (waveLength > 490 && waveLength <= 510)
	{
		R = 0;
		G = 1;
		B = (510.0 - waveLength) / 20.0;
	}
	else if (waveLength > 510 && waveLength <= 580)
	{
		R = 1 - (580.0 - waveLength) / 70.0;
		G = 1;
		B = 0;
	}
	else if (waveLength > 580 && waveLength <= 640)
	{
		R = 1;
		G = (640.0 - waveLength) / 60.0;
		B = 0;
	}
	else if (waveLength > 640 && waveLength <= 700)
	{
		// The paper says so
		R = 1; 
		G = 0;
		B = 0;
	}
	else if (waveLength > 700 && waveLength <= 780)
	{
		R = 0.35 + 0.65 * (780.0 - waveLength) / 80.0;
		G = 0;
		B = 0;
	}

	*outR = 255 * R;
	*outG = 255 * G;
	*outB = 255 * B;
}