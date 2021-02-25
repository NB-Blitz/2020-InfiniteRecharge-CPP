#include "Robot.h"

Robot::Robot() :
  DriverXbox(0),
  ManipulatorXbox(1),
  DriveTrain(),
  BallStorage(),
  Launcher(),
  Climber()
{

}

void Robot::RobotInit() 
{
  // Controls
  ManipulatorXbox.EnableAButtonToggle(true);
  ManipulatorXbox.EnableBButtonToggle(true);

  DriverXbox.SetUniversalDeadband(.1);
  DriverXbox.ReCenterLeftX();
  DriverXbox.ReCenterLeftY();
  DriverXbox.ReCenterRightX();
  DriverXbox.ReCenterRightY();

  ManipulatorXbox.SetUniversalDeadband(.15);

  // SmartDashboard
  frc::SmartDashboard::PutNumber("TOP PGain", TOP_PGAIN);
  frc::SmartDashboard::PutNumber("TOP IGain", TOP_IGAIN);
  frc::SmartDashboard::PutNumber("TOP DGain", TOP_DGAIN);
  frc::SmartDashboard::PutNumber("TOP Feed Forward", TOP_FEED_FORWARD);

  frc::SmartDashboard::PutNumber("BOTTOM PGain", BOTTOM_PGAIN);
  frc::SmartDashboard::PutNumber("BOTTOM IGain", BOTTOM_IGAIN);
  frc::SmartDashboard::PutNumber("BOTTOM DGain", BOTTOM_DGAIN);
  frc::SmartDashboard::PutNumber("BOTTOM Feed Forward", BOTTOM_FEED_FORWARD);

  // DriveTrain
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
  AutoManager.Initialize(&DriveTrain);
}

void Robot::AutonomousPeriodic()
{
  Blitz::Pose deltaPose = AutoManager.CalcVector();
  DriveTrain.Drive(
    deltaPose.x,
    deltaPose.y,
    deltaPose.r
  );
}

void Robot::TeleopInit() 
{
  DriverXbox.ReCenterLeftX();
  DriverXbox.ReCenterLeftY();
  DriverXbox.ReCenterRightX();
  DriverXbox.ReCenterRightY();

  SmartDashboard::PutNumber("Shooter RPM", 0);
}

void Robot::TeleopPeriodic()
{
  // Controls
  DriverXbox.update();
  ManipulatorXbox.update();

  // Manipulator Controls
  bool PrimeShooter = ManipulatorXbox.GetLeftTrigger() > TRIGGER_ACTIVATION_THRESHOLD;
  bool ShootBalls = ManipulatorXbox.GetRightTrigger() > TRIGGER_ACTIVATION_THRESHOLD;
  bool AutoAimTurret = false;//ManipulatorXbox.GetAButton();
  double ManualAimLauncher = ManipulatorXbox.GetRightX();
  bool IntakeBalls = ManipulatorXbox.GetBButton();
  bool PukeBalls = ManipulatorXbox.GetXButton();
  double MoveLiftSpeed = -ManipulatorXbox.GetLeftY();
  double MoveWinchSpeed = ManipulatorXbox.GetRightY();

  // Drive Controls
  double XValue = -DriverXbox.GetLeftX() * .2; // +
  double YValue = DriverXbox.GetLeftY()  * .2; // -
  double ZValue = DriverXbox.GetRightX() * .2; // +

  // Tune Launcher PID
  double topPGain = frc::SmartDashboard::GetNumber("TOP PGain", TOP_PGAIN);
  double topIGain = frc::SmartDashboard::GetNumber("TOP IGain", TOP_IGAIN);
  double topDGain = frc::SmartDashboard::GetNumber("TOP DGain", TOP_DGAIN);
  double topFeedForward = frc::SmartDashboard::GetNumber("TOP Feed Forward", TOP_FEED_FORWARD);

  double bottomPGain = frc::SmartDashboard::GetNumber("BOTTOM PGain", BOTTOM_PGAIN);
  double bottomIGain = frc::SmartDashboard::GetNumber("BOTTOM IGain", BOTTOM_IGAIN);
  double bottomDGain = frc::SmartDashboard::GetNumber("BOTTOM DGain", BOTTOM_DGAIN);
  double bottomFeedForward = frc::SmartDashboard::GetNumber("BOTTOM Feed Forward", BOTTOM_FEED_FORWARD);

  // SmartDashboard
  int SmartDashboardRPM = SmartDashboard::GetNumber("Shooter RPM", 0);

  // Shooter PID
  Launcher.TuneTopPID(topFeedForward, topPGain, topIGain, topDGain);
  Launcher.TuneBottomPID(bottomFeedForward, bottomPGain, bottomIGain, bottomDGain);

  int LauncherRPM = 3000;
  if(SmartDashboardRPM != 0)
  {
    LauncherRPM = SmartDashboardRPM;
  }

  // Ball Launcher
  bool ReadyToShoot = false;
  if(PrimeShooter)
  {
    //ReadyToShoot = Launcher.PrimeLauncher(LauncherRPM); // <-- Removed for 2021 season
  }
  else
  {
    //ReadyToShoot = Launcher.PrimeLauncher(0); // <-- Removed for 2021 season
  }

  // Feeder
  SmartDashboard::PutBoolean("Storage Full", BallStorage.IsFull());
  if(PukeBalls)
  {
    BallStorage.Puke();
  }
  else if(ShootBalls)// && ReadyToShoot)
  {
    BallStorage.FeedShooter();
  }
  else if(IntakeBalls)
  {
    BallStorage.IntakeBalls();
  }
  else 
  {
    BallStorage.StopIntake();
  }

  // Turret
  if(!AutoAimTurret)
  {
    //Launcher.RotateLauncherSpeed(ManualAimLauncher); // <-- Removed for 2021 season
  }
  else
  {
    // TODO: Automatically Aim the turret
  }

  // Lift
  //Climber.MoveLiftSpeed(MoveLiftSpeed * .3); // <-- Removed for 2021 season

  // Winch
  //Climber.RunWinch(MoveWinchSpeed); // <-- Removed for 2021 season

  // Drive Robot
  DriveTrain.Drive(XValue, YValue, ZValue);

  // Controls
  SmartDashboard::PutBoolean("Manipulator: Prime Shooter", PrimeShooter);
  SmartDashboard::PutBoolean("Manipulator: Shoot Balls", ShootBalls);
  SmartDashboard::PutBoolean("Manipulator: Automatic Turret", AutoAimTurret);
  SmartDashboard::PutBoolean("Manipulator: Intake Balls", IntakeBalls);
  SmartDashboard::PutBoolean("Manipulator: Puke Balls", PukeBalls);
  SmartDashboard::PutNumber("Manipulator: Manual Turret Speed", ManualAimLauncher);
  SmartDashboard::PutNumber("Driver: X-Value", XValue);
  SmartDashboard::PutNumber("Driver: Y-Value", YValue);
  SmartDashboard::PutNumber("Driver: Z-Value", ZValue);

  // Launcher
  SmartDashboard::PutNumber("Top Motor RPM", Launcher.GetTopMotorRPM());
  SmartDashboard::PutNumber("Bottom Motor RPM", Launcher.GetBottomMotorRPM());
  SmartDashboard::PutNumber("Turret Angle", Launcher.GetTurretAngle());
  SmartDashboard::PutNumber("Lidar Distance", Launcher.getLidarDistance());
  SmartDashboard::PutBoolean("Motors at Speed", ReadyToShoot);

  // Motors
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
int main() { return frc::StartRobot<Robot>(); }
#endif