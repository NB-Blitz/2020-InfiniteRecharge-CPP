#include "Robot.h"

Robot::Robot() :
  Xbox(0),
  DriveTrain(),
  timer(),
  autonomousJoy(1),
  rotation {SPI::Port::kMXP}
{

}

void Robot::RobotInit() 
{
  DriveTrain.Initialize();

  DriveTrain.SetMotorDirection(1, LEFT_FRONT_DIR);
  DriveTrain.SetMotorDirection(2, LEFT_BACK_DIR);
  DriveTrain.SetMotorDirection(3, RIGHT_FRONT_DIR);
  DriveTrain.SetMotorDirection(4, RIGHT_BACK_DIR);

  DriveTrain.TuneF(0, LEFT_FRONT_FGAIN);
  DriveTrain.TuneP(0, LEFT_FRONT_PGAIN);
  DriveTrain.TuneI(0, LEFT_FRONT_IGAIN);
  DriveTrain.TuneD(0, LEFT_FRONT_DGAIN);
  
  DriveTrain.TuneF(1, LEFT_BACK_FGAIN);
  DriveTrain.TuneP(1, LEFT_BACK_PGAIN);
  DriveTrain.TuneI(1, LEFT_BACK_IGAIN);
  DriveTrain.TuneD(1, LEFT_BACK_DGAIN);
  
  DriveTrain.TuneF(2, RIGHT_FRONT_FGAIN);
  DriveTrain.TuneP(2, RIGHT_FRONT_PGAIN);
  DriveTrain.TuneI(2, RIGHT_FRONT_IGAIN);
  DriveTrain.TuneD(2, RIGHT_FRONT_DGAIN);
  
  DriveTrain.TuneF(3, RIGHT_BACK_FGAIN);
  DriveTrain.TuneP(3, RIGHT_BACK_PGAIN);
  DriveTrain.TuneI(3, RIGHT_BACK_IGAIN);
  DriveTrain.TuneD(3, RIGHT_BACK_DGAIN);
}

void Robot::AutonomousInit() 
{
  stage = 0;
  rotation.ZeroYaw();
  timer.Reset();
  timer.Start();
}

void Robot::AutonomousPeriodic()
{
  if (autonomousJoy.GetRawButton(1) || autonomousJoy.GetRawButton(2))
  {
    double z = 0;
    double y = 0;
    if (stage == 0)
    {
      if (timer.Get() < AUTONOMOUS_FORWARD)
      {
        y = .5;
      }
      else
      {
        stage = 1;
      }
    }
    if (stage == 1)
    {
      z = -.5;
      if (rotation.GetAngle() > 180)
      {
        stage = 4;
      }
    }
    /*
    if (stage == 2)
    {
      if (turnTowardsTarget())
      {
        stage = 3;
      }
    }
    if (stage == 3)
    {
      if(shootBalls())
      {
        stage = 4;
      }
    }
    */
    if (stage == 4)
    {
      z = .5;
      if (rotation.GetAngle() < 0)
      {
        stage = 5;
        timer.Reset();
        timer.Start();
      }
    }
    if(stage == 5)
    {
      if (timer.Get() < AUTONOMOUS_FORWARD)
      {
        y = -.5;
      }
    }

    frc::SmartDashboard::PutNumber("Timer", timer.Get());
    frc::SmartDashboard::PutNumber("Rotation", rotation.GetAngle());
    frc::SmartDashboard::PutNumber("y", y);
    frc::SmartDashboard::PutNumber("z", z);


    DriveTrain.Drive(0, z, y);
  }
  if (autonomousJoy.GetRawButton(3))
  {
    double y = 0;
    if (stage == 0)
    {
      if (timer.Get() < AUTONOMOUS_FORWARD)
      {
        y = .5;
      }
      else
      {
        stage = 1;
      }
    }
    if(stage == 1)
    {
      if (timer.Get() < AUTONOMOUS_FORWARD + AUTONOMOUS_FORWARD)
      {
        y = -.5;
      }
    }

    frc::SmartDashboard::PutNumber("Timer", timer.Get());
    frc::SmartDashboard::PutNumber("y", y);


    DriveTrain.Drive(0, 0, y);
  }
}

void Robot::TeleopInit() 
{
  
}

void Robot::TeleopPeriodic()
{
  Xbox.update();

  double XValue = Xbox.GetLeftX();
  double YValue = Xbox.GetLeftY();
  double ZValue = Xbox.GetRightX();

  DriveTrain.Drive(-XValue, -ZValue, -YValue);

  SmartDashboard::PutNumber("Rotation", rotation.GetFusedHeading());

  SmartDashboard::PutNumber("DriveMotor 1 Speed", DriveTrain.GetMotorOutput(0));
  SmartDashboard::PutNumber("DriveMotor 2 Speed", DriveTrain.GetMotorOutput(1));
  SmartDashboard::PutNumber("DriveMotor 3 Speed", DriveTrain.GetMotorOutput(2));
  SmartDashboard::PutNumber("DriveMotor 4 Speed", DriveTrain.GetMotorOutput(3));
  
  SmartDashboard::PutNumber("DriveMotor 1 SetPoint", DriveTrain.GetMotorSetPoint(0));
  SmartDashboard::PutNumber("DriveMotor 2 SetPoint", DriveTrain.GetMotorSetPoint(1));
  SmartDashboard::PutNumber("DriveMotor 3 SetPoint", DriveTrain.GetMotorSetPoint(2));
  SmartDashboard::PutNumber("DriveMotor 4 SetPoint", DriveTrain.GetMotorSetPoint(3));
}

#ifndef RUNNING_FRC_TESTS
START_ROBOT_CLASS(Robot)
#endif