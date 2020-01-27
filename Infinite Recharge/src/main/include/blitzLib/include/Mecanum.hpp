#pragma once

#include "DriveTrain.hpp"

using namespace std;
using namespace frc;

namespace Blitz
{
    class Mecanum : public Blitz::DriveTrain
    {
        public:
            Mecanum() :
                DriveTrain()
            {
                
            }

            void Drive() override;
            void Drive(double x, double y, double z);
            
        private:

    };
}