#pragma once

#include <ctre/Phoenix.h>
#include <frc/smartdashboard/SmartDashboard.h>


namespace Blitz
{
    class Climber
    {
        public:
            Climber();

            void HomeLift();
            void MoveLiftSpeed(double speed);
            void RunWinch(double speed);


        private:
            TalonSRX LeftLiftMotor;
            TalonSRX WinchMotor;

            const int LIFT_ENCODER_MAX = 7000;

    };
}