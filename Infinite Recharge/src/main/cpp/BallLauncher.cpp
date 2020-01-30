#include "BallLauncher.hpp"

Blitz::BallLauncher::BallLauncher()
{
    TopMotorPID.SetP(TOP_PGAIN);
    TopMotorPID.SetI(TOP_IGAIN);
    TopMotorPID.SetD(TOP_DGAIN);
    TopMotorPID.SetIZone(TOP_IZONE);
    TopMotorPID.SetFF(TOP_FEED_FORWARD);
    TopMotorPID.SetOutputRange(MIN_OUTPUT, MAX_OUTPUT);
    TopMotor.SetClosedLoopRampRate(RAMP_RATE);

    BottomMotorPID.SetP(BOTTOM_PGAIN);
    BottomMotorPID.SetI(BOTTOM_IGAIN);
    BottomMotorPID.SetD(BOTTOM_DGAIN);
    BottomMotorPID.SetIZone(BOTTOM_IZONE);
    BottomMotorPID.SetFF(BOTTOM_FEED_FORWARD);
    BottomMotorPID.SetOutputRange(MIN_OUTPUT, MAX_OUTPUT);
    BottomMotor.SetClosedLoopRampRate(RAMP_RATE);
}

void Blitz::BallLauncher::SetLauncherRotation(int angle)
{

}

void Blitz::BallLauncher::SetLauncherSpeed(int rpm, int backSpin)
{
    int topRPM = rpm - (backSpin/2);
    int bottomRPM = -(rpm + (backSpin/2));

    SetTopMotorRPM(topRPM);
    SetBottomMotorRPM(bottomRPM);
}

void Blitz::BallLauncher::SetTopMotorRPM(int rpm)
{
    TopMotorPID.SetReference(rpm, rev::ControlType::kVelocity);
}

void Blitz::BallLauncher::SetBottomMotorRPM(int rpm)
{
    BottomMotorPID.SetReference(rpm, rev::ControlType::kVelocity);
}

double Blitz::BallLauncher::GetTopMotorRPM()
{
    return TopMotorEncoder.GetVelocity();
}

double Blitz::BallLauncher::GetBottomMotorRPM()
{
    return BottomMotorEncoder.GetVelocity();
}