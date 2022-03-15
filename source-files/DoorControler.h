#pragma once
#include "Light.h"

class DoorControler 
{
private:
    Light frontLeft;
    Light frontRight;
    Light backLeft;
    Light backRight;
    bool isOn_frontLeft = false;
    bool isOn_frontRight = false;
    bool isOn_backLeft = false;
    bool isOn_backRight = false;
public:
    DoorControler();
    void TurnOnFrontLeft();
    void TurnOnFrontRight();
    void TurnOnBackLeft();
    void TurnOnBackRight();
    void TurnOffFrontLeft();
    void TurnOffFrontRight();
    void TurnOffBackLeft();
    void TurnOffBackRight();
    
    void TurnOnAll();
    void TurnOffAll();

    void DisplayInfo_frontLeft();
    void DisplayInfo_frontRight();
    void DisplayInfo_backLeft();
    void DisplayInfo_backRight();

    void Replace_frontLeft();
    void Replace_frontRight();
    void Replace_backLeft();
    void Replace_backRight();
};
