#pragma once

#include <string>
#include <iostream>
#include <chrono>
#include <cstdint>
#define MAX_LIFE_RATE_ms 31536000000

class Light
{
private:
	std::string name;
	uint8_t brightness;

	uint64_t lifeRate;
	std::chrono::steady_clock::time_point workingTime;
public:
	//--------------------------------------------
	// FUNCTION: Light()
	// Constructor for the class
	// 
	// PARAMETERS:
	// _name:
	//		The name of the light
	// _colour: 
	//		The colour of the light.
	//		By default is White.
	// _lifeRate:
	//		The remaing lifespan of the light.
	//		By default is 1 year (31,536,000,000 miliseconds)
	//		1000 miliseconds * 60 seconds * 60 minutes * 24 hours * 365 days
	//----------------------------------------------
	Light(std::string _name, uint64_t _lifeRate = (MAX_LIFE_RATE_ms)) :
		name(_name), 
		lifeRate(_lifeRate), 
		brightness(0), 
		workingTime(std::chrono::steady_clock::now()) {}
private:
	void UpdateLifeRate();
public:
	void SetBrightness(char _brightness);
	void On();
	void Off();
	void TurnUpBrightness();
	void TurnDownBrightness();
	void Diagnose();
	void Replace();
};