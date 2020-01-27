#include "Robot.h"

Robot::Robot() :
  ThreeAxis(0),
  TwoAxis(1),
  Xbox(2),
  DriveTrain()
{

}

void Robot::RobotInit() 
{

}

//Autonomous used for drive testing
void Robot::AutonomousInit() 
{
  int dir = 1;
  bool TestPID = false;
  
  DriveTrain.Initialize();

  DriveTrain.SetMotorDirection(0, dir);
  DriveTrain.SetMotorDirection(1, dir);
  DriveTrain.SetMotorDirection(2, dir);
  DriveTrain.SetMotorDirection(3, dir);

  DriveTrain.EnablePID(TestPID);
  DriveTrain.TuneF(0, 0);
  DriveTrain.TuneP(0, 0);
  DriveTrain.TuneI(0, 0);
  DriveTrain.TuneD(0, 0);
  
  DriveTrain.TuneF(1, 0);
  DriveTrain.TuneP(1, 0);
  DriveTrain.TuneI(1, 0);
  DriveTrain.TuneD(1, 0);
  
  DriveTrain.TuneF(2, 0);
  DriveTrain.TuneP(2, 0);
  DriveTrain.TuneI(2, 0);
  DriveTrain.TuneD(2, 0);
  
  DriveTrain.TuneF(3, 0);
  DriveTrain.TuneP(3, 0);
  DriveTrain.TuneI(3, 0);
  DriveTrain.TuneD(3, 0);


}

void Robot::AutonomousPeriodic()
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

//Tele-op used for joystick testing
void Robot::TeleopInit() 
{
  // ThreeAxis.ReCenterXAxis();
  // ThreeAxis.ReCenterYAxis();
  // ThreeAxis.ReCenterZAxis();
  // ThreeAxis.ReCenterDial();

  // ThreeAxis.SetXAxisDeadband(.2);
  // ThreeAxis.SetYAxisDeadband(.3);
  // ThreeAxis.SetZAxisDeadband(.4);
  // ThreeAxis.SetDialDeadband(.5);

  
  // TwoAxis.ReCenterXAxis();
  // TwoAxis.ReCenterYAxis();
  // TwoAxis.ReCenterDial();

  // TwoAxis.SetXAxisDeadband(.2);
  // TwoAxis.SetYAxisDeadband(.3);
  // TwoAxis.SetDialDeadband(.4);

  // Xbox.ReCenterLeftX();
  // Xbox.ReCenterLeftY();
  // Xbox.ReCenterRightX();
  // Xbox.ReCenterRightY();
  // Xbox.ReCenterLeftTrigger();
  // Xbox.ReCenterRightTrigger();

  // Xbox.SetLeftXDeadband(.2);
  // Xbox.SetLeftYDeadband(.3);
  // Xbox.SetRightXDeadband(.4);
  // Xbox.SetRightYDeadband(.5);
  // Xbox.SetLeftTriggerDeadband(.6);
  // Xbox.SetRightTriggerDeadband(.7);

  bool toggles = true;

  ThreeAxis.EnableTriggerToggle(toggles);
  ThreeAxis.EnableButton2Toggle(toggles);
  ThreeAxis.EnableButton3Toggle(toggles);
  ThreeAxis.EnableButton4Toggle(toggles);
  ThreeAxis.EnableButton5Toggle(toggles);
  ThreeAxis.EnableButton6Toggle(toggles);
  ThreeAxis.EnableButton7Toggle(toggles);
  ThreeAxis.EnableButton8Toggle(toggles);
  ThreeAxis.EnableButton9Toggle(toggles);
  ThreeAxis.EnableButton10Toggle(toggles);
  ThreeAxis.EnableButton11Toggle(toggles);
  ThreeAxis.EnableButton12Toggle(toggles);

  
  TwoAxis.EnableTriggerToggle(toggles);
  TwoAxis.EnableButton2Toggle(toggles);
  TwoAxis.EnableButton3Toggle(toggles);
  TwoAxis.EnableButton4Toggle(toggles);
  TwoAxis.EnableButton5Toggle(toggles);
  TwoAxis.EnableButton6Toggle(toggles);
  TwoAxis.EnableButton7Toggle(toggles);
  TwoAxis.EnableButton8Toggle(toggles);

  Xbox.EnableAButtonToggle(toggles);
  Xbox.EnableBButtonToggle(toggles);
  Xbox.EnableXButtonToggle(toggles);
  Xbox.EnableYButtonToggle(toggles);
  Xbox.EnableLeftBumperToggle(toggles);
  Xbox.EnableRightBumperToggle(toggles);
  Xbox.EnableSelectButtonToggle(toggles);
  Xbox.EnableStartButtonToggle(toggles);
  Xbox.EnableLeftStickButtonToggle(toggles);
  Xbox.EnableRightStickButtonToggle(toggles);

}

void Robot::TeleopPeriodic()
{
  ThreeAxis.update();
  TwoAxis.update();
  Xbox.update();

  SmartDashboard::PutBoolean("ThreeAxis Trigger", ThreeAxis.GetTrigger());
  SmartDashboard::PutBoolean("ThreeAxis Button2", ThreeAxis.GetButton2());
  SmartDashboard::PutBoolean("ThreeAxis Button3", ThreeAxis.GetButton3());
  SmartDashboard::PutBoolean("ThreeAxis Button4", ThreeAxis.GetButton4());
  SmartDashboard::PutBoolean("ThreeAxis Button5", ThreeAxis.GetButton5());
  SmartDashboard::PutBoolean("ThreeAxis Button6", ThreeAxis.GetButton6());
  SmartDashboard::PutBoolean("ThreeAxis Button7", ThreeAxis.GetButton7());
  SmartDashboard::PutBoolean("ThreeAxis Button8", ThreeAxis.GetButton8());
  SmartDashboard::PutBoolean("ThreeAxis Button9", ThreeAxis.GetButton9());
  SmartDashboard::PutBoolean("ThreeAxis Button10", ThreeAxis.GetButton10());
  SmartDashboard::PutBoolean("ThreeAxis Button11", ThreeAxis.GetButton11());
  SmartDashboard::PutBoolean("ThreeAxis Button12", ThreeAxis.GetButton12());

  SmartDashboard::PutNumber("ThreeAxis XAxis", ThreeAxis.GetXAxis());
  SmartDashboard::PutNumber("ThreeAxis YAxis", ThreeAxis.GetYAxis());
  SmartDashboard::PutNumber("ThreeAxis ZAxis", ThreeAxis.GetZAxis());
  SmartDashboard::PutNumber("ThreeAxis Dial", ThreeAxis.GetDial());

  SmartDashboard::PutBoolean("TwoAxis Trigger", TwoAxis.GetTrigger());
  SmartDashboard::PutBoolean("TwoAxis Button2", TwoAxis.GetButton2());
  SmartDashboard::PutBoolean("TwoAxis Button3", TwoAxis.GetButton3());
  SmartDashboard::PutBoolean("TwoAxis Button4", TwoAxis.GetButton4());
  SmartDashboard::PutBoolean("TwoAxis Button5", TwoAxis.GetButton5());
  SmartDashboard::PutBoolean("TwoAxis Button6", TwoAxis.GetButton6());
  SmartDashboard::PutBoolean("TwoAxis Button7", TwoAxis.GetButton7());
  SmartDashboard::PutBoolean("TwoAxis Button8", TwoAxis.GetButton8());
  
  SmartDashboard::PutNumber("TwoAxis XAxis", TwoAxis.GetXAxis());
  SmartDashboard::PutNumber("TwoAxis YAxis", TwoAxis.GetYAxis());
  SmartDashboard::PutNumber("TwoAxis Dial", TwoAxis.GetDial());

  SmartDashboard::PutBoolean("Xbox A Button", Xbox.GetAButton());
  SmartDashboard::PutBoolean("Xbox B Button", Xbox.GetBButton());
  SmartDashboard::PutBoolean("Xbox X Button", Xbox.GetXButton());
  SmartDashboard::PutBoolean("Xbox Y Button", Xbox.GetYButton());
  SmartDashboard::PutBoolean("Xbox Left Bumper", Xbox.GetLeftBumper());
  SmartDashboard::PutBoolean("Xbox Right Bumper", Xbox.GetRightBumper());
  SmartDashboard::PutBoolean("Xbox Select Button", Xbox.GetSelectButton());
  SmartDashboard::PutBoolean("Xbox Start Button", Xbox.GetStartButton());
  SmartDashboard::PutBoolean("Xbox Left Stick Button", Xbox.GetLeftStickButton());
  SmartDashboard::PutBoolean("Xbox Right Stick Button", Xbox.GetRightStickButton());

  SmartDashboard::PutNumber("Xbox Left X", Xbox.GetLeftX());
  SmartDashboard::PutNumber("Xbox Left Y", Xbox.GetLeftY());
  SmartDashboard::PutNumber("Xbox Right X", Xbox.GetRightX());
  SmartDashboard::PutNumber("Xbox Right Y", Xbox.GetRightY());
  SmartDashboard::PutNumber("Xbox Left Trigger", Xbox.GetLeftTrigger());
  SmartDashboard::PutNumber("Xbox Right Trigger", Xbox.GetRightTrigger());
}

#ifndef RUNNING_FRC_TESTS
START_ROBOT_CLASS(Robot)
#endif