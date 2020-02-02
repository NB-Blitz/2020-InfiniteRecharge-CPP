#include "DriveTrain.hpp"

Blitz::DriveTrain::DriveTrain()
{

}

void Blitz::DriveTrain::SetMotorDirection(int Motor, int dir)
{
    MotorDirs[Motor] = dir;
}

double Blitz::DriveTrain::GetMotorSetPoint(int MotorID)
{
    return motorValues[MotorID];
}

double Blitz::DriveTrain::GetMotorOutput(int MotorID)
{
    switch(MotorID)
    {
        case 0:
            return LeftFrontEncoder.GetVelocity();
        case 1 :
            return LeftBackEncoder.GetVelocity();
        case 2 :
            return RightFrontEncoder.GetVelocity();
        case 3 :
            return RightBackEncoder.GetVelocity();
    }

    return 0;
}

void Blitz::DriveTrain::EnablePID(bool Enabled)
{
    usePID = Enabled;
}

void Blitz::DriveTrain::TuneF(int MotorID, double FGain)
{
    switch(MotorID)
    {
        case 0:
            LeftFrontPID.SetFF(FGain);
            break;
        case 1 :
            LeftBackPID.SetFF(FGain);
            break;
        case 2 :
            RightFrontPID.SetFF(FGain);
            break;
        case 3 :
            RightBackPID.SetFF(FGain);
            break;
    }
}

void Blitz::DriveTrain::TuneP(int MotorID, double PGain)
{
    switch(MotorID)
    {
        case 0:
            LeftFrontPID.SetP(PGain);
            break;
        case 1 :
            LeftBackPID.SetP(PGain);
            break;
        case 2 :
            RightFrontPID.SetP(PGain);
            break;
        case 3 :
            RightBackPID.SetP(PGain);
            break;
    }
}

void Blitz::DriveTrain::TuneI(int MotorID, double IGain)
{
    switch(MotorID)
    {
        case 0:
            LeftFrontPID.SetI(IGain);
            break;
        case 1 :
            LeftBackPID.SetI(IGain);
            break;
        case 2 :
            RightFrontPID.SetI(IGain);
            break;
        case 3 :
            RightBackPID.SetI(IGain);
            break;
    }
}

void Blitz::DriveTrain::TuneD(int MotorID, double DGain)
{
    switch(MotorID)
    {
        case 0:
            LeftFrontPID.SetD(DGain);
            break;
        case 1 :
            LeftBackPID.SetD(DGain);
            break;
        case 2 :
            RightFrontPID.SetD(DGain);
            break;
        case 3 :
            RightBackPID.SetD(DGain);
            break;
    }
}

void Blitz::DriveTrain::Initialize()
{
    LeftFrontPID.SetOutputRange(-1, 1);
    LeftFrontMotor.SetClosedLoopRampRate(DriveReference::RAMP_RATE);

    LeftBackPID.SetOutputRange(-1, 1);
    LeftBackMotor.SetClosedLoopRampRate(DriveReference::RAMP_RATE);

    RightFrontPID.SetOutputRange(-1, 1);
    RightFrontMotor.SetClosedLoopRampRate(DriveReference::RAMP_RATE);

    RightBackPID.SetOutputRange(-1, 1);
    RightBackMotor.SetClosedLoopRampRate(DriveReference::RAMP_RATE);
}