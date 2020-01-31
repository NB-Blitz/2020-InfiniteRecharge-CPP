#include "Robot.h"

Robot::Robot() :
  Xbox(0),
  DriveTrain(),
  timer(),
  autonomousJoy(1),
  rotation()
{

}

void Robot::RobotInit() 
{
  DriveTrain.Initialize();

  DriveTrain.SetMotorDirection(0, LEFT_FRONT_DIR);
  DriveTrain.SetMotorDirection(1, LEFT_BACK_DIR);
  DriveTrain.SetMotorDirection(2, RIGHT_FRONT_DIR);
  DriveTrain.SetMotorDirection(3, RIGHT_BACK_DIR);

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
  timer.start();
}

void Robot::AutonomousPeriodic()
{
  if (autonomousJoy.getRawButton(1))
  {
    int stage = 1;
    double z = 1;
    if (stage == 1)
    {
      if (rotation.getRawHeading() > 180)
      {
        stage = 2;
      }
    }
    if (stage == 2)
    {
      if (turnTowardsTarget())
      {
        stage = 3;
      }
    }
    if (stage == 3)
    {
      
    }


    
      DriveTrain.Drive(0, 0, 1);
  }
  if (autonomousJoy.getRawButton(3))
  {
    double y = .5;
    if (timer.get() > AUTONOMOUS_FORWARD)
    {
      y = -.5;
    }
    if (timer.get() > AUTONOMOUS_FORWARD + AUTONOMOUS_FORWARD)
    {
      y = 0;
    }

    DriveTrain.Drive(0, y, 0);
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

  DriveTrain.Drive(XValue, YValue, ZValue);


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