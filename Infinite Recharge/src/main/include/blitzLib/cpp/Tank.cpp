#include "Tank.hpp"

void Blitz::Tank::Drive()
{
    Drive(0, 0);
}

void Blitz::Tank::Drive(double left, double right)
{
    motorValues[0] = (left);
    motorValues[1] = (left);
    motorValues[2] = (right);
    motorValues[3] = (right);

    double maxMagnitude = 0;

    for (double checkValue : motorValues)
    {
        checkValue = std::fabs(checkValue);

        if (maxMagnitude < checkValue)
        {
            maxMagnitude = checkValue;
        }
    }

    if (maxMagnitude > DriveReference::MAX_OUPUT)
    {
        for (int i = 0; i < 4; i++)
        {
            motorValues[i] = motorValues[i] / maxMagnitude;
        }
    }


    if(usePID)
    {
        LeftFrontPID.SetReference(motorValues[0] * MotorDirs[0] * DriveReference::MAX_RPM, rev::ControlType::kVelocity);
        LeftBackPID.SetReference(motorValues[1] * MotorDirs[1] * DriveReference::MAX_RPM, rev::ControlType::kVelocity);
        RightFrontPID.SetReference(motorValues[2] * MotorDirs[2] * DriveReference::MAX_RPM, rev::ControlType::kVelocity);
        RightBackPID.SetReference(motorValues[3] * MotorDirs[3] * DriveReference::MAX_RPM, rev::ControlType::kVelocity);
    }
    else
    {
        LeftFrontMotor.Set(motorValues[0] * MotorDirs[0]);
        LeftBackMotor.Set(motorValues[1] * MotorDirs[1]);
        RightFrontMotor.Set(motorValues[2] * MotorDirs[2]);
        RightBackMotor.Set(motorValues[3] * MotorDirs[3]);
    }
}