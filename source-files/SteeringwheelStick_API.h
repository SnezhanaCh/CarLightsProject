#pragma once

class SteeringwheelStick_API 
{
public:
    virtual void DayLightsOn() = 0;
    virtual void DayLightsOff()  = 0;
    virtual void LowBeamOn()  = 0;
    virtual void LowBeamOff()  = 0;
    virtual void HighBeamOn()  = 0;
    virtual void HighBeamOff()  = 0;
    virtual void BlinkersLeftOn()  = 0;
    virtual void BlinkersLeftOff()  = 0;
    virtual void BlinkersRightOn()  = 0;
    virtual void BlinkersRightOff()  = 0;
    virtual void BlinkersLeftFiveBlinks()  = 0;
    virtual void BlinkersRightFiveBlinks()  = 0;
    virtual void FogLightsOn() = 0;
    virtual void FogLightsOff() = 0;
};
