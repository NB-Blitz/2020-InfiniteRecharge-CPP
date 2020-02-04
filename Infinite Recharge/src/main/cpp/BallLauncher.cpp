#include "BallLauncher.hpp"

Blitz::BallLauncher::BallLauncher() :
    TurretHomeSwitch(1)
{
    TurretMotorPID.SetP(TURRET_PGAIN);
    TurretMotorPID.SetI(TURRET_IGAIN);
    TurretMotorPID.SetD(TURRET_DGAIN);
    TurretMotorPID.SetIZone(TURRET_IZONE);
    TurretMotorPID.SetFF(TURRET_FEED_FORWARD);
    TurretMotorPID.SetOutputRange(MIN_OUTPUT, MAX_OUTPUT);
    TurretMotorEncoder.SetPositionConversionFactor(TURRET_POSITION_CONVERSION);

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

bool Blitz::BallLauncher::HomeLauncher()
{
    if(!FastHome)
    {
        if(!TurretHomeSwitch.Get())
        {
            TurretMotor.Set(FastHomeSpeed);
        }  
        else
        {
            TurretMotor.Set(0); 
            FastHome = true;
            FastHomeReleased = false;
        }
    }
    else if(!FastHomeReleased)
    {
        if(TurretHomeSwitch.Get())
        {
            TurretMotor.Set(-FastHomeSpeed);
        }
        else
        {
            TurretMotor.Set(0);
            FastHomeReleased = true;
        }
    }
    else if(!Homed)
    {
        if(!TurretHomeSwitch.Get())
        {
            TurretMotor.Set(SlowHomeSpeed);
        }
        else
        {
            TurretMotorEncoder.SetPosition(0);
            TurretMotor.Set(0);
            Homed = true;
        }
    }

    return Homed;
}

void Blitz::BallLauncher::SetTargetDistance(double dist)
{
    TargetDistance = dist;
}

void Blitz::BallLauncher::SetLauncherRotationRelative(double angle)
{
    TurretRotationSetPoint = GetTurretAngle() + angle;

    SetTurretPostion(TurretRotationSetPoint);
}

void Blitz::BallLauncher::SetLauncherRotationAbsolute(double angle)
{
    TurretRotationSetPoint = angle;

    SetTurretPostion(TurretRotationSetPoint);
}

void Blitz::BallLauncher::RotateLauncherSpeed(double speed)
{
    TurretMotor.Set(speed);
}

bool Blitz::BallLauncher::SetLauncherSpeed(int rpm, int backSpin)
{
    int topRPM = rpm - (backSpin/2);
    int bottomRPM = -(rpm + (backSpin/2));

    SetTopMotorRPM(topRPM);
    SetBottomMotorRPM(bottomRPM);

    bool isTopMotorAtSpeed = (GetTopMotorRPM() > (topRPM - RPM_BUFFER) && GetTopMotorRPM() < (topRPM + RPM_BUFFER));
    bool isBottomMotorAtSpeed = (GetBottomMotorRPM() > (bottomRPM - RPM_BUFFER) && GetBottomMotorRPM() < (bottomRPM + RPM_BUFFER));

    return isTopMotorAtSpeed && isBottomMotorAtSpeed;
}

bool Blitz::BallLauncher::PrimeLauncher()
{
    int rpm = CalculateLaunchVelocity(TargetDistance, TARGET_HEIGHT);
    return SetLauncherSpeed(rpm, BACK_SPIN);
}

void Blitz::BallLauncher::FeedBalls()
{
    bool LauncherReady = PrimeLauncher();
    if(LauncherReady)
    {
        //turn on feed motors;
    }
}

double Blitz::BallLauncher::GetTopMotorRPM()
{
    return TopMotorEncoder.GetVelocity();
}

double Blitz::BallLauncher::GetBottomMotorRPM()
{
    return BottomMotorEncoder.GetVelocity();
}

void Blitz::BallLauncher::SetTurretPostion(double angle)
{
    TurretMotorPID.SetReference(angle, rev::ControlType::kPosition);
}

double Blitz::BallLauncher::GetTurretAngle()
{
    return TurretMotorEncoder.GetPosition();
}

void Blitz::BallLauncher::SetTopMotorRPM(int rpm)
{
    TopMotorPID.SetReference(rpm, rev::ControlType::kVelocity);
}

void Blitz::BallLauncher::SetBottomMotorRPM(int rpm)
{
    BottomMotorPID.SetReference(rpm, rev::ControlType::kVelocity);
}

double Blitz::BallLauncher::CalculateLaunchVelocity(double dist, double height)
{
    double velocity = 0;

    double rpm = velocity;

    return rpm;
}