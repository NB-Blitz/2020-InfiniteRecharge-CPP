#pragma once

#include <frc/SPI.h>
#include <AHRS.h>
#include <math.h>

#define PI 3.14159265

namespace Blitz
{
    class Point
    {
        public:
            Point(double xP=0, double yP=0) {
                x = xP;
                y = yP;
            }

            double x = 0;
            double y = 0;
    };

    class AutoManager
    {
        public:
            void Initialize();
            Point CalcSpline(double t, double x[], double y[]);
            double GetDriveVector(Point robot);

        private:
            // Hardware
            AHRS IMU{frc::SPI::Port::kMXP};
            
            // Vars
            int currentPoint = 0;
            bool pause = false;

            // Points
            const Point POINTS[5] = {
                Point(0, 0),
                Point(1, 1),
                Point(1, 4),
                Point(2, 5),
                Point(9, 9)
            };
            const int POINT_COUNT = 2;

            // Constants
            const double DIST_TO_POINT = 1;
            const double SPLINE_ARC = 3.0;
            const double T_DISTANCE = 0.2;

            const double X_MULTIPLIER = 1;
            const double Y_MULTIPLIER = 1;
            const double Z_MULTIPLIER = 1;
    };
}