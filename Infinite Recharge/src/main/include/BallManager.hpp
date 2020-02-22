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

            bool SecondBallMoved = false;
            int UnblockedCount = 0;
            int BlockedCount = 0;
            int IntakeStuckCounter = 0;


            frc::DigitalInput BallAtIntakeSwitch;
            frc::DigitalInput FirstStageSwitch;
            frc::DigitalInput StorageFullSwitch;

            rev::CANSparkMax IntakeMotor{10, rev::CANSparkMax::MotorType::kBrushless};
            rev::CANSparkMax MainFeederMotor{9, rev::CANSparkMax::MotorType::kBrushed};
            
            rev::CANEncoder IntakeMotorEncoder = IntakeMotor.GetEncoder();

            TalonSRX LauncherFeedMotor;

            const int BALL_AT_INTAKE_SWITCH_ID = 1;
            const int FIRST_STAGE_SWITCH_ID = 2;
            const int STORAGE_FULL_SWITCH_ID = 3;

            const int INTAKE_MOTOR_ID = 10;
            const int MAIN_FEED_MOTOR_ID = 9;
            const int LAUNCHER_FEED_MOTOR_ID = 8;

            const double MOTOR_OFF = 0;
            const double INTAKE_SPEED = .25;
            const double STORAGE_INTAKE_SPEED = .25;
            const double STORAGE_SHOOT_SPEED = .25;
            const double LAUNCHER_FEED_SPEED = 1;
    };
}