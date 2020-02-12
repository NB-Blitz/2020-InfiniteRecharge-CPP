#include "Robot.h"

Robot::Robot() :
  DriverXbox(0),
  ManipulatorXbox(1),
  DriveTrain(),
  BallStorage(),
  Launcher()
{

}

void Robot::RobotInit() 
{
  //Setup Joysticks
  ManipulatorXbox.EnableAButtonToggle(true);

  //Setup Drivetrain
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

}

void Robot::AutonomousPeriodic()
{

}

void Robot::TeleopInit() 
{
  //Initialize SmartDashboard Values
  SmartDashboard::PutNumber("Shooter RPM", 0);
  
}

void Robot::TeleopPeriodic()
{
  //update controller values
  DriverXbox.update();
  ManipulatorXbox.update();

  //Manipulator Controls
  bool PrimeShooter = ManipulatorXbox.GetLeftTrigger() > TRIGGER_ACTIVATION_THRESHOLD;
  bool ShootBalls = ManipulatorXbox.GetRightTrigger() > TRIGGER_ACTIVATION_THRESHOLD;
  bool AutoAimTurret = ManipulatorXbox.GetAButton();
  double ManualAimLauncher = ManipulatorXbox.GetLeftX();
  bool IntakeBalls = ManipulatorXbox.GetBButton();
  bool PukeBalls = ManipulatorXbox.GetXButton();

  //Drive Controls
  double XValue = DriverXbox.GetLeftX();
  double YValue = DriverXbox.GetLeftY();
  double ZValue = DriverXbox.GetRightX();

  //Get SmartDashboard Data
  int LauncherRPM = SmartDashboard::GetNumber("Shooter RPM", 0);

  //Run Ball Launcher
  bool ReadyToShoot = false;
  if(PrimeShooter)
  {
    ReadyToShoot = Launcher.PrimeLauncher(LauncherRPM);
  }
  else
  {
    ReadyToShoot = Launcher.PrimeLauncher(0);
  }

  //Run Feeder
  if(PukeBalls)
  {
    BallStorage.Puke();
  }
  else if(ShootBalls && ReadyToShoot)
  {
    BallStorage.FeedShooter();
  }
  else if(IntakeBalls)
  {
    BallStorage.IntakeBalls();
  }

  //Rotate Turret
  if(!AutoAimTurret)
  {
    Launcher.RotateLauncherSpeed(ManualAimLauncher);
  }
  else
  {
    //Automatically Aim the turret
  }

  //Drive Robot
  DriveTrain.Drive(XValue, YValue, ZValue);

  //Manipulator Joystick outputs
  SmartDashboard::PutBoolean("Manipulator: Prime Shooter", PrimeShooter);
  SmartDashboard::PutBoolean("Manipulator: Shoot Balls", ShootBalls);
  SmartDashboard::PutBoolean("Manipulator: Automatic Turret", AutoAimTurret);
  SmartDashboard::PutBoolean("Manipulator: Intake Balls", IntakeBalls);
  SmartDashboard::PutBoolean("Manipulator: Puke Balls", PukeBalls);
  SmartDashboard::PutNumber("Manipulator: Manual Turret Speed", ManualAimLauncher);
  
  //Driver Joystick outputs
  SmartDashboard::PutNumber("Driver: X-Value", XValue);
  SmartDashboard::PutNumber("Driver: Y-Value", YValue);
  SmartDashboard::PutNumber("Driver: Z-Value", ZValue);

  //Launcher outputs
  SmartDashboard::PutNumber("Top Motor RPM", Launcher.GetTopMotorRPM());
  SmartDashboard::PutNumber("Bottom Motor RPM", Launcher.GetBottomMotorRPM());

  //Output Motor Speeds
  SmartDashboard::PutNumber("DriveMotor 1 Speed", DriveTrain.GetMotorOutput(0));
  SmartDashboard::PutNumber("DriveMotor 2 Speed", DriveTrain.GetMotorOutput(1));
  SmartDashboard::PutNumber("DriveMotor 3 Speed", DriveTrain.GetMotorOutput(2));
  SmartDashboard::PutNumber("DriveMotor 4 Speed", DriveTrain.GetMotorOutput(3));
  
  //Output Motor Setpoints
  SmartDashboard::PutNumber("DriveMotor 1 SetPoint", DriveTrain.GetMotorSetPoint(0));
  SmartDashboard::PutNumber("DriveMotor 2 SetPoint", DriveTrain.GetMotorSetPoint(1));
  SmartDashboard::PutNumber("DriveMotor 3 SetPoint", DriveTrain.GetMotorSetPoint(2));
  SmartDashboard::PutNumber("DriveMotor 4 SetPoint", DriveTrain.GetMotorSetPoint(3));
}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif