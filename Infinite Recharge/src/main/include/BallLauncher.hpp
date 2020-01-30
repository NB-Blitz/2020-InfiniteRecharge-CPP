#pragma once

#include <frc/WPILib.h>
#include <rev/CANSparkMax.h>

namespace Blitz
{
    class BallLauncher 
    {
        public:
            BallLauncher();

            void SetLauncherRotation(int angle);
            void SetLauncherSpeed(int rpm, int backSpin);

            double GetTopMotorRPM();
            double GetBottomMotorRPM();


        private:
            void SetTopMotorRPM(int rpm);
            void SetBottomMotorRPM(int rpm);

            const int TOP_MOTOR_CAN_ID = 1;
            const int BOTTOM_MOTOR_CAN_ID = 2;

            const double TOP_PGAIN = 0.0002;
            const double TOP_IGAIN = 0;
            const double TOP_DGAIN = 0.01;
            const double TOP_IZONE = 0;
            const double TOP_FEED_FORWARD = 0.000167;
            
            const double BOTTOM_PGAIN = 0.0002;
            const double BOTTOM_IGAIN = 0;
            const double BOTTOM_DGAIN = 0.01;
            const double BOTTOM_IZONE = 0;
            const double BOTTOM_FEED_FORWARD = 0.000167;

            const double MIN_OUTPUT = -1;
            const double MAX_OUTPUT = 1;
            const double RAMP_RATE = 1;

            rev::CANSparkMax TopMotor{TOP_MOTOR_CAN_ID, rev::CANSparkMax::MotorType::kBrushless};
            rev::CANSparkMax BottomMotor{BOTTOM_MOTOR_CAN_ID, rev::CANSparkMax::MotorType::kBrushless};

            rev::CANPIDController TopMotorPID = TopMotor.GetPIDController();
            rev::CANPIDController BottomMotorPID = BottomMotor.GetPIDController();

            rev::CANEncoder TopMotorEncoder = TopMotor.GetEncoder();
            rev::CANEncoder BottomMotorEncoder = BottomMotor.GetEncoder();

    };
}