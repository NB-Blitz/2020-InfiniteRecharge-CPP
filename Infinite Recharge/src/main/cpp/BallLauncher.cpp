#include "BallLauncher.hpp"

Blitz::BallLauncher::BallLauncher() :
    UltraSonic(0)
{
    // TurretMotorPID.SetP(TURRET_PGAIN);
    // TurretMotorPID.SetI(TURRET_IGAIN);
    // TurretMotorPID.SetD(TURRET_DGAIN);
    // TurretMotorPID.SetIZone(TURRET_IZONE);
    // TurretMotorPID.SetFF(TURRET_FEED_FORWARD);
    // TurretMotorPID.SetOutputRange(MIN_OUTPUT, MAX_OUTPUT);
    // TurretMotorEncoder.SetPositionConversionFactor(TURRET_POSITION_CONVERSION);

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

void Blitz::BallLauncher::HomeLauncher()
{
    //TurretMotorEncoder.SetPosition(0);
}

bool Blitz::BallLauncher::SetLauncherRotationRelative(double angle)
{
    TurretRotationSetPoint = GetTurretAngle() + angle;

    return SetTurretPostion(TurretRotationSetPoint);
}

bool Blitz::BallLauncher::SetLauncherRotationAbsolute(double angle)
{
    TurretRotationSetPoint = angle;

    return SetTurretPostion(TurretRotationSetPoint);
}

void Blitz::BallLauncher::RotateLauncherSpeed(double speed)
{
    TurretMotor.Set(speed);
}

bool Blitz::BallLauncher::SetLauncherSpeed(int rpm, int backSpin)
{
    int topRPM = -(rpm - (backSpin/2));
    int bottomRPM = (rpm + (backSpin/2));

    SetTopMotorRPM(topRPM);
    SetBottomMotorRPM(bottomRPM);

    bool isTopMotorAtSpeed = (GetTopMotorRPM() > (topRPM - RPM_BUFFER) && GetTopMotorRPM() < (topRPM + RPM_BUFFER));
    bool isBottomMotorAtSpeed = (GetBottomMotorRPM() > (bottomRPM - RPM_BUFFER) && GetBottomMotorRPM() < (bottomRPM + RPM_BUFFER));

    return isTopMotorAtSpeed && isBottomMotorAtSpeed;
}

bool Blitz::BallLauncher::PrimeLauncher(bool prime)
{
    int rpm = CalculateLaunchVelocity(getUltrasonicDistance());
    
    if(prime)
    {
        return SetLauncherSpeed(rpm, BACK_SPIN);
    }
    else
    {
        return SetLauncherSpeed(0, 0);
    }
}

bool Blitz::BallLauncher::PrimeLauncher(int rpm)
{
    if(rpm == 0)
    {
        return SetLauncherSpeed(rpm, 0);
    }
    else
    {
        return SetLauncherSpeed(rpm, BACK_SPIN);
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

double Blitz::BallLauncher::GetTurretAngle()
{
    return 0;//TurretMotorEncoder.GetPosition();
}

void Blitz::BallLauncher::TuneTopPID(double f, double p, double i, double d)
{
    TopMotorPID.SetP(p);
    TopMotorPID.SetI(i);
    TopMotorPID.SetD(d);
    TopMotorPID.SetFF(f);
}

void Blitz::BallLauncher::TuneBottomPID(double f, double p, double i, double d)
{
    BottomMotorPID.SetP(p);
    BottomMotorPID.SetI(i);
    BottomMotorPID.SetD(d);
    BottomMotorPID.SetFF(f);
}

double Blitz::BallLauncher::getUltrasonicDistance()
{
    return ((UltraSonic.GetVoltage()*1024*5)/(5*304.8)); //converts ultrasonic voltage to feet 
}



//Private Methods
bool Blitz::BallLauncher::SetTurretPostion(double angle)
{
    //TurretMotorPID.SetReference(angle, rev::ControlType::kPosition);

    double CurrentAngle = 0;//TurretMotorEncoder.GetPosition();

    return (CurrentAngle <= (angle + TURRET_ANGLE_THRESHOLD)) && (CurrentAngle >= (angle - TURRET_ANGLE_THRESHOLD));
}

void Blitz::BallLauncher::SetTopMotorRPM(int rpm)
{
    TopMotorPID.SetReference(rpm, rev::ControlType::kVelocity);
}

void Blitz::BallLauncher::SetBottomMotorRPM(int rpm)
{
    BottomMotorPID.SetReference(rpm, rev::ControlType::kVelocity);
}

double Blitz::BallLauncher::CalculateLaunchVelocity(double dist)
{
    //add launch velocity calculation
    double rpm = 0;
    if(dist <= 18 && dist >= 10)
    {
        rpm = (-95*dist) + 4540;
    }

    return rpm;
}