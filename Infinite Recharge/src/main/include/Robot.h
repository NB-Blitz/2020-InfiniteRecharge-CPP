#pragma once

#include <frc/WPILib.h>
#include <BlitzLib/BlitzLib.hpp>


class Robot : public frc::TimedRobot
{
    public:
        Robot();

        void RobotInit() override;
        void AutonomousInit() override;
        void AutonomousPeriodic() override;
        void TeleopInit() override;
        void TeleopPeriodic() override;

    private:
        Blitz::Joysticks::ThreeAxisJoystick ThreeAxis;
        Blitz::Joysticks::TwoAxisJoystick TwoAxis;
        Blitz::Joysticks::XboxController Xbox;

        bool toggles = false;

        Blitz::Mecanum DriveTrain;
  
};
