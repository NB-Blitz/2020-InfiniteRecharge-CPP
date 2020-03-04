#pragma once

namespace Blitz
{
    class DriveReference
    {
        public:
            static constexpr int LEFT_FRONT_MOTOR_ID = 1;
            static constexpr int LEFT_BACK_MOTOR_ID = 2;
            static constexpr int RIGHT_FRONT_MOTOR_ID = 3;
            static constexpr int RIGHT_BACK_MOTOR_ID = 4;

            static constexpr double RAMP_RATE = .4;

            static constexpr double ENCODER_UNITS_PER_ROTATION = 42;
            static constexpr double MAX_RPM = 5500;

            static constexpr double MAX_OUPUT = 1;
    };
}