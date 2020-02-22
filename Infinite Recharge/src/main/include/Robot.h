#pragma once

#include <frc/TimedRobot.h>
#include <frc/Timer.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <BlitzLib/BlitzLib.hpp>
#include "BallManager.hpp"
#include "BallLauncher.hpp"


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

        Blitz::BallManager BallStorage;
        Blitz::BallLauncher Launcher;

        frc::Timer timer;

        static constexpr double TRIGGER_ACTIVATION_THRESHOLD = .5;

        static constexpr double LEFT_FRONT_FGAIN = 0;
        static constexpr double LEFT_FRONT_PGAIN = 0;
        static constexpr double LEFT_FRONT_IGAIN = 0;
        static constexpr double LEFT_FRONT_DGAIN = 0;
        static constexpr double LEFT_FRONT_DIR = 1;

        static constexpr double LEFT_BACK_FGAIN = 0;
        static constexpr double LEFT_BACK_PGAIN = 0;
        static constexpr double LEFT_BACK_IGAIN = 0;
        static constexpr double LEFT_BACK_DGAIN = 0;
        static constexpr double LEFT_BACK_DIR = 1;

        static constexpr double RIGHT_FRONT_FGAIN = 0;
        static constexpr double RIGHT_FRONT_PGAIN = 0;
        static constexpr double RIGHT_FRONT_IGAIN = 0;
        static constexpr double RIGHT_FRONT_DGAIN = 0;
        static constexpr double RIGHT_FRONT_DIR = -1;

        static constexpr double RIGHT_BACK_FGAIN = 0;
        static constexpr double RIGHT_BACK_PGAIN = 0;
        static constexpr double RIGHT_BACK_IGAIN = 0;
        static constexpr double RIGHT_BACK_DGAIN = 0;
        static constexpr double RIGHT_BACK_DIR = -1;

        const double TOP_PGAIN = 0.0002;
        const double TOP_IGAIN = 0;
        const double TOP_DGAIN = 0.01;
        const double TOP_IZONE = 0;
        const double TOP_FEED_FORWARD = 0.000167;
        
        const double BOTTOM_PGAIN = 0.0002;
        const double BOTTOM_IGAIN = 0;
        const double BOTTOM_DGAIN = 0.01;
        const double BOTTOM_IZONE = 0;
        const double BOTTOM_FEED_FORWARD = 0.000167;
  
};
