#include "BallManager.hpp"

Blitz::BallManager::BallManager() :
    LauncherFeedMotor(LAUNCHER_FEED_MOTOR_ID),
    BallAtIntakeSwitch(BALL_AT_INTAKE_SWITCH_ID),
    FirstStageSwitch(FIRST_STAGE_SWITCH_ID),
    StorageFullSwitch(STORAGE_FULL_SWITCH_ID)
{

}


void Blitz::BallManager::IntakeBalls()
{
    // if(!IsFull())
    // {
    //     IntakeMotor.Set(INTAKE_SPEED);

    //     if(BallAtIntakeSwitch.Get())
    //     {
    //         MainFeederMotor.Set(STORAGE_INTAKE_SPEED);
    //     }
    //     else if(!BallAtIntakeSwitch.Get() && FirstStageSwitch.Get())
    //     {
    //         MainFeederMotor.Set(MOTOR_OFF);
    //     }
    // }
    // else
    // {
    //     IntakeMotor.Set(MOTOR_OFF);
    //     MainFeederMotor.Set(MOTOR_OFF);
    // }

    IntakeMotor.Set(INTAKE_SPEED);
    MainFeederMotor.Set(STORAGE_INTAKE_SPEED);

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
    MainFeederMotor.Set(-STORAGE_SHOOT_SPEED);
    LauncherFeedMotor.Set(ControlMode::PercentOutput, -LAUNCHER_FEED_SPEED);
}

void Blitz::BallManager::StopIntake()
{
    IntakeMotor.Set(MOTOR_OFF);
    MainFeederMotor.Set(MOTOR_OFF);
    LauncherFeedMotor.Set(ControlMode::PercentOutput, MOTOR_OFF);
}


bool Blitz::BallManager::IsFull()
{
    return StorageFullSwitch.Get();
}

