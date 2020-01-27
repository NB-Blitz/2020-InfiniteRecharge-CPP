#include "JoySticks.hpp"

double Blitz::JoystickInterface::RampAxis(double inputValue, double rampedValue, double center, double deadband, double rampRate)
{
    double expectedValue = inputValue + center;

    //return 0 if value is within deadband
    if(fabs(expectedValue) < deadband)
    {
        return 0;
    }

    //increase rampedValue if it is less than expectedValue
    if(rampedValue < expectedValue)
    {
        if((expectedValue - rampedValue) < rampRate)
        {
            rampedValue = expectedValue;
        }
        else
        {
            rampedValue += rampRate;
        }
    }

    //decrease rampedValue if it is greater than expectedValue
    if(rampedValue > expectedValue)
    {
        if((rampedValue - expectedValue) < rampRate)
        {
            rampedValue = expectedValue;
        }
        else
        {
            rampedValue -= rampRate;
        }
    }

    return rampedValue;
}