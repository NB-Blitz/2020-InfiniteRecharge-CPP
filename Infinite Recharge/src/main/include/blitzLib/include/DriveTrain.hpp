#pragma once

#include <rev/CANSparkMax.h>

#include "DriveReferences.hpp"

namespace Blitz
{
    class DriveTrain
    {
        public:
            DriveTrain();

            void SetMotorDirection(int Motor, int dir);
            double GetMotorSetPoint(int MotorID);
            double GetMotorOutput(int MotorID);

            void EnablePID(bool enabled);
            void TuneF(int MotorID, double FGain);
            void TuneP(int MotorID, double PGain);
            void TuneI(int MotorID, double IGain);
            void TuneD(int MotorID, double DGain);

            void Initialize();
            virtual void Drive() {}

        protected:
            int MotorDirs[4] = {1, 1, 1, 1};
            double motorValues[4] = {0, 0, 0, 0};
            bool usePID = false;

            rev::CANSparkMax LeftFrontMotor{DriveReference::LEFT_FRONT_MOTOR_ID, rev::CANSparkMax::MotorType::kBrushless};
            rev::CANSparkMax LeftBackMotor{DriveReference::LEFT_BACK_MOTOR_ID, rev::CANSparkMax::MotorType::kBrushless};
            rev::CANSparkMax RightFrontMotor{DriveReference::RIGHT_FRONT_MOTOR_ID, rev::CANSparkMax::MotorType::kBrushless};
            rev::CANSparkMax RightBackMotor{DriveReference::RIGHT_BACK_MOTOR_ID, rev::CANSparkMax::MotorType::kBrushless};

            rev::CANPIDController LeftFrontPID = LeftFrontMotor.GetPIDController();
            rev::CANPIDController LeftBackPID = LeftBackMotor.GetPIDController();
            rev::CANPIDController RightFrontPID = RightFrontMotor.GetPIDController();
            rev::CANPIDController RightBackPID = RightBackMotor.GetPIDController();

            rev::CANEncoder LeftFrontEncoder = LeftFrontMotor.GetEncoder();
            rev::CANEncoder LeftBackEncoder = LeftBackMotor.GetEncoder();
            rev::CANEncoder RightFrontEncoder = RightFrontMotor.GetEncoder();
            rev::CANEncoder RightBackEncoder = RightBackMotor.GetEncoder();

    };
}