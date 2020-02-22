#pragma once

#include <frc/DigitalInput.h>
#include <rev/CANSparkMax.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/AnalogInput.h>


namespace Blitz
{
    class BallLauncher 
    {
        public:
            BallLauncher();

            void HomeLauncher();

            bool SetLauncherRotationRelative(double angle);
            bool SetLauncherRotationAbsolute(double angle);
            void RotateLauncherSpeed(double speed);
            
            bool SetLauncherSpeed(int rpm, int backSpin);

            bool PrimeLauncher(bool prime);       //Ramp Up launch Motors
            bool PrimeLauncher(int rpm);       //Ramp Up launch Motors to rpm

            double GetTopMotorRPM();
            double GetBottomMotorRPM();
            
            double GetTurretAngle();

            void TuneTopPID(double f, double p, double i, double d);
            void TuneBottomPID(double f, double p, double i, double d);

            double getUltrasonicDistance();


        private:
            bool SetTurretPostion(double angle);

            void SetTopMotorRPM(int rpm);
            void SetBottomMotorRPM(int rpm);

            double CalculateLaunchVelocity(double dist);

            double TurretRotationSetPoint = 0;

            const double BACK_SPIN = 2000; //difference in RPM of wheels

            //Turret Constants
            const double COUNTS_PER_MOTOR_REVOLUTION = 44.4;
            const double SMALL_GEAR_TEETH = 12;
            const double LARGE_GEAR_TEETH = 154;
            const double COUNTS_PER_TURRET_REVOLUTION = COUNTS_PER_MOTOR_REVOLUTION * (LARGE_GEAR_TEETH/SMALL_GEAR_TEETH);
            const double COUNTS_PER_DEGREE = COUNTS_PER_TURRET_REVOLUTION / 360;

            const double TURRET_ANGLE_THRESHOLD = 5;
            

            //Motor IDs
            const int TOP_MOTOR_CAN_ID = 5;
            const int BOTTOM_MOTOR_CAN_ID = 6;
            const int TURRET_MOTOR_CAN_ID = 7;
            const int STORAGE_FEEDER_MOTOR_CAN_ID = 9;
            const int LAUNCHER_FEEDER_MOTOR_CAN_ID = 8;

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

            //Turret Motor
            rev::CANSparkMax TurretMotor{TURRET_MOTOR_CAN_ID, rev::CANSparkMax::MotorType::kBrushed};
            
            //rev::CANPIDController TurretMotorPID = TurretMotor.GetPIDController();

            //rev::CANEncoder TurretMotorEncoder = TurretMotor.GetEncoder(rev::CANEncoder::EncoderType::kHallSensor, 1); //set the encoder type and tells get position to output counts instead of RPM

            //Launcher Motors
            rev::CANSparkMax TopMotor{TOP_MOTOR_CAN_ID, rev::CANSparkMax::MotorType::kBrushless};
            rev::CANSparkMax BottomMotor{BOTTOM_MOTOR_CAN_ID, rev::CANSparkMax::MotorType::kBrushless};

            rev::CANPIDController TopMotorPID = TopMotor.GetPIDController();
            rev::CANPIDController BottomMotorPID = BottomMotor.GetPIDController();

            rev::CANEncoder TopMotorEncoder = TopMotor.GetEncoder();
            rev::CANEncoder BottomMotorEncoder = BottomMotor.GetEncoder();

            frc::AnalogInput UltraSonic;
    };
}