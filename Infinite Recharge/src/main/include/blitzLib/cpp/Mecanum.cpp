#include "Mecanum.hpp"

void Blitz::Mecanum::Drive()
{
    Drive(0, 0, 0);
}

void Blitz::Mecanum::Drive(double x, double y, double z)
{
    motorValues[0] = (x + y - z);
    motorValues[1] = (-x + y - z);
    motorValues[2] = (-x + y + z);
    motorValues[3] = (x + y + z);

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
        LeftFrontMotor.Set(motorValues[1] * MotorDirs[1]);
        LeftFrontMotor.Set(motorValues[2] * MotorDirs[2]);
        LeftFrontMotor.Set(motorValues[3] * MotorDirs[3]);
    }
}