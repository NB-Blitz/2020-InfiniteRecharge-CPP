#include "AutoManager.hpp"

/*
        Initialize
*/

void Blitz::AutoManager::Initialize(Mecanum* Drivetrain)
{
    // Network Tables
    SmartDashboard::PutNumber("Ball X", 0);
    SmartDashboard::PutNumber("Ball Y", 0);
    SmartDashboard::PutBoolean("See Ball", false);

    // IMU
    IMU.ZeroYaw();

    // Set Mode
    this->Drivetrain = Drivetrain;
    Drivetrain->ResetMotorDistance();
    currentMode = (AutoMode)SmartDashboard::GetNumber("Autonomous Mode", AutoMode::PAUSED);
    if (currentMode == AutoMode::PAUSED)
        SmartDashboard::PutNumber("Autonomous Mode", AutoMode::PAUSED);

    // Get Point DB
    switch (currentMode)
    {
        case Blitz::AutoMode::BARREL:
            points = BARREL;
            break;
        case Blitz::AutoMode::SLALOM:
            points = SLALOM;
            break;
        case Blitz::AutoMode::BOUNCE:
            points = BOUNCE;
            break;
        default:
            return;
    }
    pointCount = (sizeof(points) / sizeof(points[0])) - 3;
    SmartDashboard::PutNumber("Auto Point Count", pointCount);
}

/*
        Vector Calculators
*/

Blitz::Pose Blitz::AutoManager::CalcVector(bool hasIntaked)
{
    if (currentMode == Blitz::AutoMode::SEARCH)
        return CalcBallVector(hasIntaked);
    else if (currentMode != Blitz::AutoMode::PAUSED)
        return CalcNavVector();
    else
        return Pose();
}
Blitz::Pose Blitz::AutoManager::CalcBallVector(bool hasIntaked)
{
    double ballX = SmartDashboard::GetNumber("Ball X", 0);
    double ballY = SmartDashboard::GetNumber("Ball Y", 0);
    double ballArea = SmartDashboard::GetNumber("Last Area", 0);
    double maxArea = SmartDashboard::GetNumber("Max Area", 7500);
    bool seeBall = SmartDashboard::GetBoolean("See Ball", false);
    double yaw = IMU.GetYaw();
    Pose deltaPose;

    double flick = 0;

    if (seeBall && ballArea < maxArea && !hasIntaked)
    {
        deltaPose = Pose(
            0,
            ROBOT_SPEED,
            ballX * ballX * ballX * ROTATE_SPEED
        );
        lastYaw = yaw;
    }
    else if (seeBall && !hasIntaked)
    {
        deltaPose = Pose(
            0,
            ROBOT_SPEED / 3,
            0
        );
        lastYaw = yaw;
    }
    else if (hasIntaked)
    {
        double deltaYaw = lastYaw > 0 ? .15 : -.15;
        deltaPose = Pose(
            0,
            ROBOT_SPEED / 2,
            -deltaYaw * FLICK_SPEED
        );
        flick = -deltaYaw * FLICK_SPEED;
    }

    SmartDashboard::PutNumber("Flick", flick);

    return deltaPose;
}
Blitz::Pose Blitz::AutoManager::CalcNavVector()
{
    // Get Robot Disposition
    double robotYaw = IMU.GetYaw();
    bool robotChange  = SmartDashboard::GetBoolean("Robot Change", false);
    robotPose.r = robotYaw;

    if (robotChange)
    {
        double robotX = SmartDashboard::GetNumber ("Robot X", 0);
        double robotY = SmartDashboard::GetNumber ("Robot Y", 0);

        robotPose = Pose(robotX, robotY, robotYaw);
        SmartDashboard::PutBoolean("Robot Change", false);
    }
    else
    {
        CalcEncDisposition();
    }

    // Check Off Point if Within Range
    double distance = 0;
    do {
        Point nextPoint = points[currentPoint];
        distance = sqrt(pow(nextPoint.x - robotPose.x, 2) + pow(nextPoint.y - robotPose.y, 2));
        if (distance < DIST_TO_POINT)
        {
            currentPoint++;
            if (currentPoint >= pointCount)
            {
                currentMode = AutoMode::PAUSED;
            }
        }
    } while (distance < DIST_TO_POINT);

    // Calculate Vector
    Blitz::Point p1 = points[currentPoint+0];
    Blitz::Point p2 = points[currentPoint+1];
    Blitz::Point p3 = points[currentPoint+2];
    
    double xPoints[] = {
        robotPose.x,
        p1.x,
        p2.x,
        p3.x
    };

    double yPoints[] = {
        robotPose.y,
        p1.y,
        p2.y,
        p3.y
    };

    Point targetPoint = CalcSpline(T_DISTANCE, xPoints, yPoints);
    double targetAngle = atan2(targetPoint.y - robotPose.y, targetPoint.x - robotPose.x) * RAD_TO_DEG;
    double robotAngle = IMU.GetYaw();
    double robotZVel = IMU.GetRate();
    double deltaAngle = ((targetAngle - robotAngle) - (COUNTER_STEER * robotZVel));

    Pose deltaPose(
        0,
        -.1,
        deltaAngle / 180.0
    );
    return deltaPose;
}

/*
        Misc
*/

void Blitz::AutoManager::CalcEncDisposition()
{
    // Encoders
    double motor1 = Drivetrain->GetMotorDistance(0) * -ENC_SCALE;
    double motor2 = Drivetrain->GetMotorDistance(1) * -ENC_SCALE;
    double motor3 = Drivetrain->GetMotorDistance(2) * ENC_SCALE;
    double motor4 = Drivetrain->GetMotorDistance(3) * ENC_SCALE;
    Drivetrain->ResetMotorDistance();

    // Maths
    double l = (motor1 + motor2) / 2;
    double r = (motor3 + motor4) / 2;
    double a = (WHEEL_ANGLE * ((r - l) / 2)) + robotPose.r;
    double d = WHEEL_DIST * ((l + r) / 2);
    double x = robotPose.x + (d * cos(a * DEG_TO_RAD));
    double y = robotPose.y + (d * sin(a * DEG_TO_RAD));
    robotPose.x = x;
    robotPose.y = y;

    // Network Tables
    SmartDashboard::PutNumber("Enc X Displacement", x);
    SmartDashboard::PutNumber("Enc Y Displacement", y);
}
Blitz::Point Blitz::AutoManager::CalcSpline(double t, double x[], double y[])
{
    Blitz::Point output;
    output.x = (pow(1 - t, 3) * x[0]) + (3.0 * t * pow(1 - t, 2) * x[1]) + (3.0 * pow(t, 2) * (1.0 - t) * x[2]) + (pow(t, 3) * x[3]);
    output.y = (pow(1 - t, 3) * y[0]) + (3.0 * t * pow(1 - t, 2) * y[1]) + (3.0 * pow(t, 2) * (1.0 - t) * y[2]) + (pow(t, 3) * y[3]);
    return output;
}