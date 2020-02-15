#pragma once

#include <frc/DigitalInput.h>
#include <rev/CANSparkMax.h>
#include <ctre/Phoenix.h>
#include <frc/smartdashboard/SmartDashboard.h>

namespace Blitz
{
    class BallManager
    {
        public:
            BallManager();

            void IntakeBalls();

            void FeedShooter();

            void Puke();

            void StopIntake();

            bool IsFull();

        private:

            frc::DigitalInput BallAtIntakeSwitch;
            frc::DigitalInput FirstStageSwitch;
            frc::DigitalInput StorageFullSwitch;

            rev::CANSparkMax IntakeMotor{INTAKE_MOTOR_ID, rev::CANSparkMax::MotorType::kBrushless};
            rev::CANSparkMax MainFeederMotor{MAIN_FEED_MOTOR_ID, rev::CANSparkMax::MotorType::kBrushed};

            TalonSRX LauncherFeedMotor;

            const int BALL_AT_INTAKE_SWITCH_ID = 1;
            const int FIRST_STAGE_SWITCH_ID = 2;
            const int STORAGE_FULL_SWITCH_ID = 3;

            const int INTAKE_MOTOR_ID = 10;
            const int MAIN_FEED_MOTOR_ID = 9;
            const int LAUNCHER_FEED_MOTOR_ID = 8;

            const double MOTOR_OFF = 0;
            const double INTAKE_SPEED = 1;
            const double STORAGE_INTAKE_SPEED = .5;
            const double STORAGE_SHOOT_SPEED = 1;
            const double LAUNCHER_FEED_SPEED = 1;
    };
}