#pragma once

#include <frc/SPI.h>
#include <AHRS.h>
#include <math.h>
#include <BlitzLib/BlitzLib.hpp>
#include <frc/smartdashboard/SmartDashboard.h>

#define PI 3.14159265
#define DEG_TO_RAD 0.01745329
#define RAD_TO_DEG 57.2957795

namespace Blitz
{
    /*
            Miscellaneous Classes and Functions
    */
    struct Pose
    {
        Pose(double xp=0, double yp=0, double rotation=0)
        {
            x = xp;
            y = yp;
            r = rotation;
        };

        double x;
        double y;
        double r;
    };
    
    struct Point
    {
        Point(double xP=0, double yP=0) {
            x = xP;
            y = yP;
        }

        double x = 0;
        double y = 0;
    };

    enum AutoMode {
        BARREL,
        SLALOM,
        BOUNCE,
        SEARCH,
        PAUSED
    };

    /*
            Autonomous Manager
    */

    class AutoManager
    {
        public:
            void Initialize(Mecanum* Drivetrain);

            Pose CalcVector(bool hasIntaked);
            Pose CalcBallVector(bool hasIntaked);
            Pose CalcNavVector();
            void CalcEncDisposition();

            Point CalcSpline(double t, double x[], double y[]);

        private:
            // Hardware
            AHRS IMU{frc::SPI::Port::kMXP};
            Mecanum* Drivetrain;
            
            // Vars
            int currentPoint = 0;
            int pointCount = 0;
            double lastYaw = 0;
            const Point *points;
            AutoMode currentMode;
            Pose robotPose;

            // Points
            const Point BARREL[7] = { 
                Point(0, 0),
                Point(1, 0),
                Point(2, 0),
                Point(3, 0),
                Point(9, 0),
                Point(9, 0),
                Point(9, 0)
            };
            const Point SLALOM[7] = { 
                Point(0, 0),
                Point(1, 1),
                Point(1, 4),
                Point(2, 5),
                Point(9, 9),
                Point(9, 9),
                Point(9, 9)
            };
            const Point BOUNCE[7] = { 
                Point(0, 0),
                Point(1, 1),
                Point(1, 4),
                Point(2, 5),
                Point(9, 9),
                Point(9, 9),
                Point(9, 9)
            };

            // Constants
            const double DIST_TO_POINT = 1;
            const double T_DISTANCE = 0.2;
            const double COUNTER_STEER = 0; // .1
            const double ROBOT_SPEED = 0.4; // .1
            const double FLICK_SPEED = 3.8;
            const double ROTATE_SPEED = 0.5;
            
            // Encoders
            const double WHEEL_DIST = .7;
            const double WHEEL_CIRCUMFERENCE = .7;
            const double WHEEL_ANGLE = (720.0 * WHEEL_CIRCUMFERENCE) / (PI * WHEEL_DIST);
            const double ENC_SCALE = 0.025;
    };
}