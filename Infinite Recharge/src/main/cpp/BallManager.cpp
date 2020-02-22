#include "BallManager.hpp"

Blitz::BallManager::BallManager() :
    LauncherFeedMotor(8),
    BallAtIntakeSwitch(0),
    FirstStageSwitch(1),
    StorageFullSwitch(2)
{

}


void Blitz::BallManager::IntakeBalls()
{
    frc::SmartDashboard::PutBoolean("Intake Line Break", BallAtIntakeSwitch.Get());
    frc::SmartDashboard::PutBoolean("First Stage Line Break", FirstStageSwitch.Get());
    frc::SmartDashboard::PutBoolean("Storage Full Line Break", StorageFullSwitch.Get());
    if(StorageFullSwitch.Get())
    {    
        IntakeMotor.Set(INTAKE_SPEED);

        if(!BallAtIntakeSwitch.Get())
        {
            MainFeederMotor.Set(STORAGE_INTAKE_SPEED);
            SecondBallMoved = false;
            UnblockedCount = 0;
        }
        else if(SecondBallMoved && !FirstStageSwitch.Get())
        {
            if(BlockedCount <= 40)
            {
                BlockedCount++;
            }
            else
            {
                MainFeederMotor.Set(MOTOR_OFF);
                BlockedCount = 0;
            }
            
        }

        if(BallAtIntakeSwitch.Get() && UnblockedCount == 10)
        {
            SecondBallMoved = true;
        }
        else if(BallAtIntakeSwitch.Get())
        {
            UnblockedCount++;
        }
        
    }
    else
    {
        IntakeMotor.Set(MOTOR_OFF);
        MainFeederMotor.Set(MOTOR_OFF);
    }

    LauncherFeedMotor.Set(ControlMode::PercentOutput, MOTOR_OFF);
    
}

void Blitz::BallManager::FeedShooter()
{
    IntakeMotor.Set(INTAKE_SPEED);
    MainFeederMotor.Set(STORAGE_SHOOT_SPEED);
    LauncherFeedMotor.Set(ControlMode::PercentOutput, LAUNCHER_FEED_SPEED);
    frc::SmartDashboard::PutString("Feeding Balls", "Feeding2");
}

void Blitz::BallManager::Puke()
{
    IntakeMotor.Set(-INTAKE_SPEED);
    //MainFeederMotor.Set(-STORAGE_SHOOT_SPEED);
    //LauncherFeedMotor.Set(ControlMode::PercentOutput, -LAUNCHER_FEED_SPEED);
}

void Blitz::BallManager::StopIntake()
{
    IntakeMotor.Set(MOTOR_OFF);
    MainFeederMotor.Set(MOTOR_OFF);
    LauncherFeedMotor.Set(ControlMode::PercentOutput, MOTOR_OFF);
}


bool Blitz::BallManager::IsFull()
{
    frc::SmartDashboard::PutBoolean("Intake Line Break", BallAtIntakeSwitch.Get());
    frc::SmartDashboard::PutBoolean("First Stage Line Break", FirstStageSwitch.Get());
    frc::SmartDashboard::PutBoolean("Storage Full Line Break", StorageFullSwitch.Get());
    return !StorageFullSwitch.Get();
}
