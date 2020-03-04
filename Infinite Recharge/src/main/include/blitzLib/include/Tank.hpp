#pragma once

#include "DriveTrain.hpp"

using namespace std;
using namespace frc;

namespace Blitz
{
    class Tank : public Blitz::DriveTrain
    {
        public:
            Tank() :
                DriveTrain()
            {

            }

            void Drive() override;
            void Drive(double left, double right);

        private:
        
    };
}