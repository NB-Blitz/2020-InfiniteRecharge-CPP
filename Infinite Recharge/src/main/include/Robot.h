#pragma once

#include <frc/WPILib.h>
#include <BlitzLib/BlitzLib.hpp>
#include <frc/util/color.h>
#include "rev/ColorSensorV3.h"
#include "rev/ColorMatch.h"
#include "rev/CANSparkMax.h"


class Robot : public frc::TimedRobot
{
    public:
        Robot();

        void RobotInit() override;
        void RobotPeriodic() override;
        void AutonomousInit() override;
        void AutonomousPeriodic() override;
        void TeleopInit() override;
        void TeleopPeriodic() override;

    private:
        Blitz::Joysticks::XboxController Xbox;

        Blitz::Mecanum DriveTrain;

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
        static constexpr double RIGHT_FRONT_DIR = 1;

        static constexpr double RIGHT_BACK_FGAIN = 0;
        static constexpr double RIGHT_BACK_PGAIN = 0;
        static constexpr double RIGHT_BACK_IGAIN = 0;
        static constexpr double RIGHT_BACK_DGAIN = 0;
        static constexpr double RIGHT_BACK_DIR = 1;

                
        static constexpr auto i2cPort = frc::I2C::Port::kOnboard;
        rev::ColorSensorV3 m_colorSensor{i2cPort};
        rev::ColorMatch m_colorMatcher;

        static constexpr frc::Color kBlueTarget = frc::Color(0.143, 0.427, 0.429);
        static constexpr frc::Color kGreenTarget = frc::Color(0.197, 0.561, 0.240);
        static constexpr frc::Color kRedTarget = frc::Color(0.561, 0.232, 0.114);
        static constexpr frc::Color kYellowTarget = frc::Color(0.411, 0.499, 0.088);
        static constexpr frc::Color kOtherTarget = frc::Color(0.354, 0.465, 0.180);
        static constexpr frc::Color kBlackTarget = frc::Color(0.333, 0.333, 0.333);
  
};
