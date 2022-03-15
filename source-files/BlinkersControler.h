#pragma once
#include "Light.h"
#include <chrono> // std::chrono::seconds
#include <thread> // std::this_thread::sleep_for
#include <mutex>

class BlinkersControler 
{
private:
    Light frontLeft;
    Light frontRight;
    Light sideLeft;
    Light sideRight;
    Light backLeft;
    Light backRight;
    bool isOn_frontLeft = false;
    bool isOn_frontRight = false;
    bool isOn_sideLeft = false;
    bool isOn_sideRight = false;
    bool isOn_backLeft = false;
    bool isOn_backRight = false;
    bool isBlinking_AllLeft = false;
    bool isBlinking_AllRight = false;
    const uint8_t BLINK_INTERVAL_SEC = 1;
private:
    bool blinking = false;
    bool activeThread = false;
    std::condition_variable cv;
    std::mutex mtx;
private:
    void TurnOnFrontLeft();
    void TurnOnFrontRight();
    void TurnOnSideLeft();
    void TurnOnSideRight();
    void TurnOnBackLeft();
    void TurnOnBackRight();
    void TurnOffFrontLeft();
    void TurnOffFrontRight();
    void TurnOffSideLeft();
    void TurnOffSideRight();
    void TurnOffBackLeft();
    void TurnOffBackRight();
    void BlinkOnceAllLeft();
    void BlinkOnceAllRight();
    void RunThread_BlinkingAllLeft();
    void RunThread_BlinkingAllRight();
    void RunThread_BlinkingAll();
public:
    BlinkersControler();
    void BlinkOnceAll();
    void TurnOnBlinkingAllLeft();
    void TurnOffBlinkingAllLeft();
    void TurnOnBlinkingAllRight();
    void TurnOffBlinkingAllRight();
    void TurnOnFiveBlinksAllLeft();
    void TurnOnFiveBlinksAllRight();
    void TurnOnBlinkingAll();
    void TurnOffBlinkingAll();
    void TurnOn_ConstantLightMode_All();
    void TurnOff_ConstantLightMode_All();

    void DisplayInfo_frontLeft();
    void DisplayInfo_frontRight();
    void DisplayInfo_sideLeft();
    void DisplayInfo_sideRight();
    void DisplayInfo_backLeft();
    void DisplayInfo_backRight();

    void Replace_frontLeft();
    void Replace_frontRight();
    void Replace_sideLeft();
    void Replace_sideRight();
    void Replace_backLeft();
    void Replace_backRight();
};