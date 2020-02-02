#pragma once

#include <frc/WPILib.h>
#include <rev/CANSparkMax.h>

namespace Blitz
{
    class BallLauncher 
    {
        public:
            BallLauncher();

            bool HomeLauncher();

            void SetTargetDistance(double dist);
            void SetLauncherRotationRelative(double angle);
            void SetLauncherRotationAbsolute(double angle);

            bool PrimeLauncher();       //Ramp Up launch Motors
            void FeedBalls();           //Feed Balls into Launcher

            double GetTopMotorRPM();
            double GetBottomMotorRPM();


        private:
            void SetTurretPostion(double angle);
            double GetTurretAngle();

            void SetTopMotorRPM(int rpm);
            void SetBottomMotorRPM(int rpm);

            double CalculateLaunchVelocity(double dist, double height);
            bool SetLauncherSpeed(int rpm, int backSpin);

            double TargetDistance = 0;
            double TurretRotationSetPoint = 0;

            bool FastHome = false;
            bool FastHomeReleased = false;
            double FastHomeSpeed = .5;

            bool Homed = false;
            double SlowHomeSpeed = .1;

            const double BACK_SPIN = 2000;

            const double TARGET_HEIGHT = 8; //target height in feet

            const int TOP_MOTOR_CAN_ID = 1;
            const int BOTTOM_MOTOR_CAN_ID = 2;
            const int TURRET_MOTOR_CAN_ID = 7;

            const double TURRET_PGAIN = 0;
            const double TURRET_IGAIN = 0;
            const double TURRET_DGAIN = 0;
            const double TURRET_IZONE = 0;
            const double TURRET_FEED_FORWARD = 0;
            const double TURRET_POSITION_CONVERSION = 1;

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

            const int RPM_BUFFER = 100;
            
            frc::DigitalInput TurretHomeSwitch;

            //Turret Motor
            rev::CANSparkMax TurretMotor{TURRET_MOTOR_CAN_ID, rev::CANSparkMax::MotorType::kBrushless};
            
            rev::CANPIDController TurretMotorPID = TurretMotor.GetPIDController();

            rev::CANEncoder TurretMotorEncoder = TurretMotor.GetEncoder();

            //Launcher Motors
            rev::CANSparkMax TopMotor{TOP_MOTOR_CAN_ID, rev::CANSparkMax::MotorType::kBrushless};
            rev::CANSparkMax BottomMotor{BOTTOM_MOTOR_CAN_ID, rev::CANSparkMax::MotorType::kBrushless};

            rev::CANPIDController TopMotorPID = TopMotor.GetPIDController();
            rev::CANPIDController BottomMotorPID = BottomMotor.GetPIDController();

            rev::CANEncoder TopMotorEncoder = TopMotor.GetEncoder();
            rev::CANEncoder BottomMotorEncoder = BottomMotor.GetEncoder();

    };
}