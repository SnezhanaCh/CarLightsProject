#pragma once

#include <iostream>
#include <string>

#include "LightControlModule.h"

class KeyboardControler
{
private:
	LightControlModule lightControlModule;
public:
	KeyboardControler()
	{

	}
public:
	void Start();
private:
	void Trunk();
	void Doors();
	void Brakes();
	void Key();
	void SteeringWheelStick();
	void HeadUnit();
	void Diagnostics();
	void GloveBox();
	void Diagnostics_DisplayStatus();
	void Diagnostics_ReplaceLight();
};