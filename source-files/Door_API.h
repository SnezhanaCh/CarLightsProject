#pragma once

class Door_API 
{
public:
    virtual void FrontLeftDoorOpened() = 0;
    virtual void FrontRightDoorOpened() = 0;
    virtual void BackLeftDoorOpened() = 0;
    virtual void BackRightDoorOpened() = 0;
    virtual void FrontLeftDoorClosed() = 0;
    virtual void FrontRightDoorClosed() = 0;
    virtual void BackLeftDoorClosed() = 0;
    virtual void BackRightDoorClosed() = 0;
    
    virtual void AllDoorsOpened() = 0;
    virtual void AllDoorsClosed() = 0;
};