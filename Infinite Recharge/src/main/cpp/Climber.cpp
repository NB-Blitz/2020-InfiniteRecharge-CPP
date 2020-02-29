#include "Climber.hpp"

Blitz::Climber::Climber() :
    LeftLiftMotor(12),
    WinchMotor(14)
{

}

void Blitz::Climber::HomeLift()
{
    LeftLiftMotor.SetSelectedSensorPosition(0);
}

void Blitz::Climber::MoveLiftSpeed(double speed)
{
    LeftLiftMotor.Set(ControlMode::PercentOutput, speed);
}

void Blitz::Climber::RunWinch(double speed)
{
    WinchMotor.Set(ControlMode::PercentOutput, speed);
}