#pragma once

class Headunit_API {
public:
    virtual void WarningLights_On() = 0;
    virtual void WarningLights_Off() = 0;
    virtual void SwitchAmbientLightColour() = 0;
    virtual void TurnUpAmbientBrightness() = 0;
    virtual void TurnDownAmbientBrightness() = 0;
    virtual void TurnOnAmbientLights() = 0;
    virtual void TurnOffAmbientLights() = 0;
    virtual void TurnUpCoupeLightsBrightness() = 0;
    virtual void TurnDownCoupeLightsBrightness() = 0;
    virtual void TurnUpGloveboxBrightness() = 0;
    virtual void TurnDownGloveboxBrightness() = 0;


    virtual void TurnOnCoupeLight_front() = 0;
    virtual void TurnOnCoupeLight_backLeft() = 0;
    virtual void TurnOnCoupeLight_backRight() = 0;
    virtual void TurnOffCoupeLight_front() = 0;
    virtual void TurnOffCoupeLight_backLeft() = 0;
    virtual void TurnOffCoupeLight_backRight() = 0;

    virtual void TurnOnTrunkLights() = 0;
    virtual void TurnOffTrunkLights() = 0;
};
