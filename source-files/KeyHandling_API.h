#pragma once

class KeyHandling_API 
{
public:
    virtual void CarUnlocked() = 0;
    virtual void CarLocked() = 0;
    virtual void OpenTrunk() = 0;
    virtual void CloseTrunk() = 0;
};

