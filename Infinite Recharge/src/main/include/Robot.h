#pragma once

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SmartDashboard.h>
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
        Blitz::Joysticks::XboxController DriverXbox;
        Blitz::Joysticks::XboxController ManipulatorXbox;

        Blitz::Mecanum DriveTrain;

        static constexpr double LEFT_FRONT_FGAIN = 0;
        static constexpr double LEFT_FRONT_PGAIN = 0;
        static constexpr double LEFT_FRONT_IGAIN = 0;
        static constexpr double LEFT_FRONT_DGAIN = 0;
        static constexpr double LEFT_FRONT_DIR = -1;

        static constexpr double LEFT_BACK_FGAIN = 0;
        static constexpr double LEFT_BACK_PGAIN = 0;
        static constexpr double LEFT_BACK_IGAIN = 0;
        static constexpr double LEFT_BACK_DGAIN = 0;
        static constexpr double LEFT_BACK_DIR = -1;

        static constexpr double RIGHT_FRONT_FGAIN = 0;
        static constexpr double RIGHT_FRONT_PGAIN = 0;
        static constexpr double RIGHT_FRONT_IGAIN = 0;
        static constexpr double RIGHT_FRONT_DGAIN = 0;
        static constexpr double RIGHT_FRONT_DIR = 1;

        static constexpr double RIGHT_BACK_FGAIN = 0;
        static constexpr double RIGHT_BACK_PGAIN = 0;
        static constexpr double RIGHT_BACK_IGAIN = 0;
        static constexpr double RIGHT_BACK_DGAIN = 0;
        static constexpr double RIGHT_BACK_DIR = 1;
  
};
