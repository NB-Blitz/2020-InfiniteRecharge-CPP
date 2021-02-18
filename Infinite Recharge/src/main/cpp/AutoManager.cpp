#include "AutoManager.hpp"

void Blitz::AutoManager::Initialize()
{
    pause = false;
}

Blitz::Point Blitz::AutoManager::CalcSpline(double t, double x[], double y[])
{
    Blitz::Point output;
    output.x = (pow(1 - t, 3) * x[0]) + (SPLINE_ARC * t * pow(1 - t, 2) * x[1]) + (SPLINE_ARC * pow(t, 2) * (1.0 - t) * x[2]) + (pow(t, 3) * x[3]);
    output.y = (pow(1 - t, 3) * y[0]) + (SPLINE_ARC * t * pow(1 - t, 2) * y[1]) + (SPLINE_ARC * pow(t, 2) * (1.0 - t) * y[2]) + (pow(t, 3) * y[3]);
    return output;
}

double Blitz::AutoManager::GetDriveVector(Blitz::Point robot)
{
    // Return if Stopped
    if (pause)
        return 0;

    // Check Off Point if Within Range
    double distance = 0;
    do {
        Blitz::Point nextPoint = POINTS[currentPoint];
        distance = sqrt(pow(nextPoint.x - robot.x, 2) + pow(nextPoint.y - robot.y, 2));
        if (distance < DIST_TO_POINT)
        {
            currentPoint++;
            if (currentPoint >= POINT_COUNT)
            {
                pause = true;
            }
        }
    } while (distance < DIST_TO_POINT);
    
    // Calculate Vector
    Blitz::Point p1 = POINTS[currentPoint+0];
    Blitz::Point p2 = POINTS[currentPoint+1];
    Blitz::Point p3 = POINTS[currentPoint+2];
    
    double xPoints[] = {
        robot.x,
        p1.x,
        p2.x,
        p3.x
    };

    double yPoints[] = {
        robot.y,
        p1.y,
        p2.y,
        p3.y
    };

    Blitz::Point targetPoint = CalcSpline(T_DISTANCE, xPoints, yPoints);
    double deltaAngle = atan2(targetPoint.y - robot.y, targetPoint.x - robot.x) * (PI / 180) * Z_MULTIPLIER;
    double deltaDist = sqrt(pow(targetPoint.y - robot.y, 2) + pow(targetPoint.x - robot.x, 2));

    // TODO Use Delta Distance

    return deltaAngle;
}