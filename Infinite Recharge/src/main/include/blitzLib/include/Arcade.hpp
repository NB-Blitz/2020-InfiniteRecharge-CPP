#pragma once

#include "DriveTrain.hpp"

using namespace std;
using namespace frc;

namespace Blitz
{
    class Arcade : public Blitz::DriveTrain
    {
        public:
            Arcade() :
                DriveTrain()
            {

            }
            
            void Drive() override;
            void Drive(double y, double z);

        private:
    };
}