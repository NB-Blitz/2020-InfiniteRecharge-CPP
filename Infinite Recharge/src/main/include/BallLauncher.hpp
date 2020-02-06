#pragma once

#include <frc/DigitalInput.h>
#include <rev/CANSparkMax.h>

namespace Blitz
{
    class BallLauncher 
    {
        public:
            BallLauncher();

            bool HomeLauncher();        //Moves turret to home and resets the encoder

            void SetTargetDistance(double dist);
            void SetLauncherRotationRelative(double angle);
            void SetLauncherRotationAbsolute(double angle);
            void RotateLauncherSpeed(double speed);
            
            bool SetLauncherSpeed(int rpm, int backSpin);

            bool PrimeLauncher();       //Ramp Up launch Motors
            bool PrimeLauncher(int rpm);       //Ramp Up launch Motors to rpm
            void FeedBalls();           //Feed Balls into Launcher

            double GetTopMotorRPM();
            double GetBottomMotorRPM();


        private:
            void SetTurretPostion(double angle);
            double GetTurretAngle();

            void SetTopMotorRPM(int rpm);
            void SetBottomMotorRPM(int rpm);

            double CalculateLaunchVelocity(double dist, double height);

            double TargetDistance = 0;
            double TurretRotationSetPoint = 0;

            bool FastHome = false;
            bool FastHomeReleased = false;
            double FastHomeSpeed = .5;

            bool Homed = false;
            double SlowHomeSpeed = .1;

            const double BACK_SPIN = 2000; //difference in RPM of wheels

            const double TARGET_HEIGHT = 8; //target height in feet

            //Turret Constants
            const double COUNTS_PER_MOTOR_REVOLUTION = 44.4;
            const double SMALL_GEAR_TEETH = 12;
            const double LARGE_GEAR_TEETH = 154;
            const double COUNTS_PER_TURRET_REVOLUTION = COUNTS_PER_MOTOR_REVOLUTION * (LARGE_GEAR_TEETH/SMALL_GEAR_TEETH);
            const double COUNTS_PER_DEGREE = COUNTS_PER_TURRET_REVOLUTION / 360;

            //Motor IDs
            const int TOP_MOTOR_CAN_ID = 5;
            const int BOTTOM_MOTOR_CAN_ID = 6;
            const int TURRET_MOTOR_CAN_ID = 7;

            //Motor Constants
            const double TURRET_PGAIN = 0;
            const double TURRET_IGAIN = 0;
            const double TURRET_DGAIN = 0;
            const double TURRET_IZONE = 0;
            const double TURRET_FEED_FORWARD = 0;
            const double TURRET_POSITION_CONVERSION = 1/COUNTS_PER_DEGREE;

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

            //max motor RPM difference from setpoint to start feeding
            const int RPM_BUFFER = 100;
            
            frc::DigitalInput TurretHomeSwitch;

            //Turret Motor
            rev::CANSparkMax TurretMotor{TURRET_MOTOR_CAN_ID, rev::CANSparkMax::MotorType::kBrushed};
            
            rev::CANPIDController TurretMotorPID = TurretMotor.GetPIDController();

            rev::CANEncoder TurretMotorEncoder = TurretMotor.GetEncoder(rev::CANEncoder::EncoderType::kHallSensor, 1); //set the encoder type and tells get position to output counts instead of RPM

            //Launcher Motors
            rev::CANSparkMax TopMotor{TOP_MOTOR_CAN_ID, rev::CANSparkMax::MotorType::kBrushless};
            rev::CANSparkMax BottomMotor{BOTTOM_MOTOR_CAN_ID, rev::CANSparkMax::MotorType::kBrushless};

            rev::CANPIDController TopMotorPID = TopMotor.GetPIDController();
            rev::CANPIDController BottomMotorPID = BottomMotor.GetPIDController();

            rev::CANEncoder TopMotorEncoder = TopMotor.GetEncoder();
            rev::CANEncoder BottomMotorEncoder = BottomMotor.GetEncoder();

    };
}