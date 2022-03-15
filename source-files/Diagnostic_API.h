#pragma once

class Diagnostic_API 
{
public:
    virtual void LightsTestOn() = 0;
    virtual void LightsTestOff() = 0;
    virtual void DisplayStatus_TrunkLight_left() = 0;
    virtual void DisplayStatus_TrunkLight_right() = 0;
    virtual void DisplayStatus_StopLight_left() = 0;
    virtual void DisplayStatus_StopLight_right() = 0;
    virtual void DisplayStatus_DoorLight_frontLeft() = 0;
    virtual void DisplayStatus_DoorLight_frontRight() = 0;
    virtual void DisplayStatus_DoorLight_backLeft() = 0;
    virtual void DisplayStatus_DoorLight_backRight() = 0;
    virtual void DisplayStatus_GloveboxLight_top() = 0;
    virtual void DisplayStatus_CeilingLight_front() = 0;
    virtual void DisplayStatus_CeilingLight_backLeft() = 0;
    virtual void DisplayStatus_CeilingLight_backRight() = 0;
    virtual void DisplayStatus_FloorLight_left() = 0;
    virtual void DisplayStatus_FloorLight_right() = 0;
    virtual void DisplayStatus_BlinkerLight_frontLeft() = 0;
    virtual void DisplayStatus_BlinkerLight_frontRight() = 0;
    virtual void DisplayStatus_BlinkerLight_sideLeft() = 0;
    virtual void DisplayStatus_BlinkerLight_sideRight() = 0;
    virtual void DisplayStatus_BlinkerLight_backLeft() = 0;
    virtual void DisplayStatus_BlinkerLight_backRight() = 0;
    virtual void DisplayStatus_LowBeamLight_left() = 0;
    virtual void DisplayStatus_LowBeamLight_right() = 0;
    virtual void DisplayStatus_DayLight_left() = 0;
    virtual void DisplayStatus_DayLight_right() = 0;
    virtual void DisplayStatus_HighBeamLight_left() = 0;
    virtual void DisplayStatus_HighBeamLight_right() = 0;
    virtual void DisplayStatus_FogLight_left() = 0;
    virtual void DisplayStatus_FogLight_right() = 0;
    virtual void DisplayStatus_BackLight_left() = 0;
    virtual void DisplayStatus_BackLight_right() = 0;
    virtual void DisplayStatus_NumberPlateLight_left() = 0;
    virtual void DisplayStatus_NumberPlateLight_right() = 0;
    virtual void DisplayStatus_All() = 0;

    virtual void Replace_TrunkLight_left() = 0;
    virtual void Replace_TrunkLight_right() = 0;
    virtual void Replace_StopLight_left() = 0;
    virtual void Replace_StopLight_right() = 0;
    virtual void Replace_DoorLight_frontLeft() = 0;
    virtual void Replace_DoorLight_frontRight() = 0;
    virtual void Replace_DoorLight_backLeft() = 0;
    virtual void Replace_DoorLight_backRight() = 0;
    virtual void Replace_GloveboxLight_top() = 0;
    virtual void Replace_CeilingLight_front() = 0;
    virtual void Replace_CeilingLight_backLeft() = 0;
    virtual void Replace_CeilingLight_backRight() = 0;
    virtual void Replace_FloorLight_left() = 0;
    virtual void Replace_FloorLight_right() = 0;
    virtual void Replace_BlinkerLight_frontLeft() = 0;
    virtual void Replace_BlinkerLight_frontRight() = 0;
    virtual void Replace_BlinkerLight_sideLeft() = 0;
    virtual void Replace_BlinkerLight_sideRight() = 0;
    virtual void Replace_BlinkerLight_backLeft() = 0;
    virtual void Replace_BlinkerLight_backRight() = 0;
    virtual void Replace_LowBeamLight_left() = 0;
    virtual void Replace_LowBeamLight_right() = 0;
    virtual void Replace_DayLight_left() = 0;
    virtual void Replace_DayLight_right() = 0;
    virtual void Replace_HighBeamLight_left() = 0;
    virtual void Replace_HighBeamLight_right() = 0;
    virtual void Replace_FogLight_left() = 0;
    virtual void Replace_FogLight_right() = 0;
    virtual void Replace_BackLight_left() = 0;
    virtual void Replace_BackLight_right() = 0;
    virtual void Replace_NumberPlateLight_left() = 0;
    virtual void Replace_NumberPlateLight_right() = 0;
    virtual void Replace_All() = 0;
};

