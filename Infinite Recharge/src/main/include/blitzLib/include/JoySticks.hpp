#pragma once

#include <frc/Joystick.h>

using namespace frc;

namespace Blitz
{
    class JoystickInterface : public frc::Joystick
    {
        public:
            JoystickInterface(int port) :
                Joystick(port)
            {

            }

            virtual void update() {}

        protected:
            double RampAxis(double inputValue, double rampedValue, double center, double deadband, double rampRate);

    };

    namespace Joysticks
    {
        class XboxController : public Blitz::JoystickInterface
        {
            public:

                XboxController(int port) :
                    JoystickInterface(port)
                {

                }

                void update() override;

                bool GetAButton();
                bool GetBButton();
                bool GetXButton();
                bool GetYButton();
                bool GetLeftBumper();
                bool GetRightBumper();
                bool GetSelectButton();
                bool GetStartButton();
                bool GetLeftStickButton();
                bool GetRightStickButton();

                void EnableAButtonToggle(bool enabled);
                void EnableBButtonToggle(bool enabled);
                void EnableXButtonToggle(bool enabled);
                void EnableYButtonToggle(bool enabled);
                void EnableLeftBumperToggle(bool enabled);
                void EnableRightBumperToggle(bool enabled);
                void EnableSelectButtonToggle(bool enabled);
                void EnableStartButtonToggle(bool enabled);
                void EnableLeftStickButtonToggle(bool enabled);
                void EnableRightStickButtonToggle(bool enabled);

                double GetLeftX();
                double GetLeftY();
                double GetRightX();
                double GetRightY();
                double GetLeftTrigger();
                double GetRightTrigger();

                void ReCenterLeftX();
                void ReCenterLeftY();
                void ReCenterRightX();
                void ReCenterRightY();
                void ReCenterLeftTrigger();
                void ReCenterRightTrigger();

                void SetUniversalDeadband(double Deadband);
                void SetLeftXDeadband(double Deadband);
                void SetLeftYDeadband(double Deadband);
                void SetRightXDeadband(double Deadband);
                void SetRightYDeadband(double Deadband);
                void SetLeftTriggerDeadband(double Deadband);
                void SetRightTriggerDeadband(double Deadband);

                void SetUniversalRampRate(double RampRate);
                void SetLeftXRampRate(double RampRate);
                void SetLeftYRampRate(double RampRate);
                void SetRightXRampRate(double RampRate);
                void SetRightYRampRate(double RampRate);
                void SetLeftTriggerRampRate(double RampRate);
                void SetRightTriggerRampRate(double RampRate);


            private:

                //Buttons
                bool AButton = false;
                bool BButton = false;
                bool XButton = false;
                bool YButton = false;
                bool LeftBumper = false;
                bool RightBumper = false;
                bool SelectButton = false;
                bool StartButton = false;
                bool LeftStickButton = false;
                bool RightStickButton = false;

                //Button Toggles
                bool AButtonToggle = false;
                bool BButtonToggle = false;
                bool XButtonToggle = false;
                bool YButtonToggle = false;
                bool LeftBumperToggle = false;
                bool RightBumperToggle = false;
                bool SelectButtonToggle = false;
                bool StartButtonToggle = false;
                bool LeftStickButtonToggle = false;
                bool RightStickButtonToggle = false;

                //Previous Button States
                bool PreAButton = false;
                bool PreBButton = false;
                bool PreXButton = false;
                bool PreYButton = false;
                bool PreLeftBumper = false;
                bool PreRightBumper = false;
                bool PreSelectButton = false;
                bool PreStartButton = false;
                bool PreLeftStickButton = false;
                bool PreRightStickButton = false;

                //Use Button Toggles
                bool UseAButtonToggle = false;
                bool UseBButtonToggle = false;
                bool UseXButtonToggle = false;
                bool UseYButtonToggle = false;
                bool UseLeftBumperToggle = false;
                bool UseRightBumperToggle = false;
                bool UseSelectButtonToggle = false;
                bool UseStartButtonToggle = false;
                bool UseLeftStickButtonToggle = false;
                bool UseRightStickButtonToggle = false;

                //Axes
                double LeftX = 0;
                double LeftY = 0;
                double RightX = 0;
                double RightY = 0;
                double LeftTrigger = 0;
                double RightTrigger = 0;

                //Ramped Axes
                double LeftXRamp = 0;
                double LeftYRamp = 0;
                double RightXRamp = 0;
                double RightYRamp = 0;
                double LeftTriggerRamp = 0;
                double RightTriggerRamp = 0;

                //Axis Centers
                double LeftXCenter = 0;
                double LeftYCenter = 0;
                double RightXCenter = 0;
                double RightYCenter = 0;
                double LeftTriggerCenter = 0;
                double RightTriggerCenter = 0;

                //Axis Deadbands
                double LeftXDeadband = 0;
                double LeftYDeadband = 0;
                double RightXDeadband = 0;
                double RightYDeadband = 0;
                double LeftTriggerDeadband = 0;
                double RightTriggerDeadband = 0;

                //Axis Ramp Rates
                double LeftXRampRate = 1;
                double LeftYRampRate = 1;
                double RightXRampRate = 1;
                double RightYRampRate = 1;
                double LeftTriggerRampRate = 1;
                double RightTriggerRampRate = 1;


                //Button ids
                const int A_BUTTON_ID = 1;
                const int B_BUTTON_ID = 2;
                const int X_BUTTON_ID = 3;
                const int Y_BUTTON_ID = 4;
                const int LEFT_BUMPER_ID = 5;
                const int RIGHT_BUMPER_ID = 6;
                const int SELECT_BUTTON = 7;
                const int START_BUTTON = 8;
                const int LEFT_STICK_BUTTON_ID = 9;
                const int RIGHT_STICK_BUTTON_ID = 10;

                //axis ids
                const int LEFT_X_AXIS_ID = 0;
                const int LEFT_Y_AXIS_ID = 1;
                const int LEFT_TRIGGER_ID = 2;
                const int RIGHT_TRIGGER_ID = 3;
                const int RIGHT_X_AXIS_ID = 4;
                const int RIGHT_Y_AXIS_ID = 5;

        };

        class ThreeAxisJoystick : public Blitz::JoystickInterface
        {
            public:

                ThreeAxisJoystick(int port) :
                    JoystickInterface(port)
                {

                }

                void update() override;

                bool GetTrigger();
                bool GetButton2();
                bool GetButton3();
                bool GetButton4();
                bool GetButton5();
                bool GetButton6();
                bool GetButton7();
                bool GetButton8();
                bool GetButton9();
                bool GetButton10();
                bool GetButton11();
                bool GetButton12();

                void EnableTriggerToggle(bool enabled);
                void EnableButton2Toggle(bool enabled);
                void EnableButton3Toggle(bool enabled);
                void EnableButton4Toggle(bool enabled);
                void EnableButton5Toggle(bool enabled);
                void EnableButton6Toggle(bool enabled);
                void EnableButton7Toggle(bool enabled);
                void EnableButton8Toggle(bool enabled);
                void EnableButton9Toggle(bool enabled);
                void EnableButton10Toggle(bool enabled);
                void EnableButton11Toggle(bool enabled);
                void EnableButton12Toggle(bool enabled);

                double GetXAxis();
                double GetYAxis();
                double GetZAxis();
                double GetDial();

                void ReCenterXAxis();
                void ReCenterYAxis();
                void ReCenterZAxis();
                void ReCenterDial();

                void SetUniversalDeadband(double Deadband);
                void SetXAxisDeadband(double Deadband);
                void SetYAxisDeadband(double Deadband);
                void SetZAxisDeadband(double Deadband);
                void SetDialDeadband(double Deadband);

                void SetUniversalRampRate(double RampRate);
                void SetXAxisRampRate(double RampRate);
                void SetYAxisRampRate(double RampRate);
                void SetZAxisRampRate(double RampRate);
                void SetDialRampRate(double RampRate);

            private:
                //Buttons
                bool Trigger = false;
                bool Button2 = false;
                bool Button3 = false;
                bool Button4 = false;
                bool Button5 = false;
                bool Button6 = false;
                bool Button7 = false;
                bool Button8 = false;
                bool Button9 = false;
                bool Button10 = false;
                bool Button11 = false;
                bool Button12 = false;

                //Button Toggles
                bool TriggerToggle = false;
                bool Button2Toggle = false;
                bool Button3Toggle = false;
                bool Button4Toggle = false;
                bool Button5Toggle = false;
                bool Button6Toggle = false;
                bool Button7Toggle = false;
                bool Button8Toggle = false;
                bool Button9Toggle = false;
                bool Button10Toggle = false;
                bool Button11Toggle = false;
                bool Button12Toggle = false;

                
                //Previous Button States
                bool PreTrigger = false;
                bool PreButton2 = false;
                bool PreButton3 = false;
                bool PreButton4 = false;
                bool PreButton5 = false;
                bool PreButton6 = false;
                bool PreButton7 = false;
                bool PreButton8 = false;
                bool PreButton9 = false;
                bool PreButton10 = false;
                bool PreButton11 = false;
                bool PreButton12 = false;
                
                //Use Button Toggles
                bool UseTriggerToggle = false;
                bool UseButton2Toggle = false;
                bool UseButton3Toggle = false;
                bool UseButton4Toggle = false;
                bool UseButton5Toggle = false;
                bool UseButton6Toggle = false;
                bool UseButton7Toggle = false;
                bool UseButton8Toggle = false;
                bool UseButton9Toggle = false;
                bool UseButton10Toggle = false;
                bool UseButton11Toggle = false;
                bool UseButton12Toggle = false;

                //axes
                double XAxis = 0;
                double YAxis = 0;
                double ZAxis = 0;
                double Dial = 0;

                //Ramped Axes
                double XAxisRamp = 0;
                double YAxisRamp = 0;
                double ZAxisRamp = 0;
                double DialRamp = 0;

                //Axis Centers
                double XAxisCenter = 0;
                double YAxisCenter = 0;
                double ZAxisCenter = 0;
                double DialCenter = 0;

                //Axis RampRates
                double XAxisRampRate = 1;
                double YAxisRampRate = 1;
                double ZAxisRampRate = 1;
                double DialRampRate = 1;

                //Axis Deadbands
                double XAxisDeadband = 0;
                double YAxisDeadband = 0;
                double ZAxisDeadband = 0;
                double DialDeadband = 0;

                //Button IDs
                const int TRIGGER_ID = 1;
                const int BUTTON2_ID = 2;
                const int BUTTON3_ID = 3;
                const int BUTTON4_ID = 4;
                const int BUTTON5_ID = 5;
                const int BUTTON6_ID = 6;
                const int BUTTON7_ID = 7;
                const int BUTTON8_ID = 8;
                const int BUTTON9_ID = 9;
                const int BUTTON10_ID = 10;
                const int BUTTON11_ID = 11;
                const int BUTTON12_ID = 12;

                //axis IDs
                const int X_AXIS_ID = 0;
                const int Y_AXIS_ID = 1;
                const int Z_AXIS_ID = 2;
                const int DIAL_ID = 3;

        };

        class TwoAxisJoystick : public Blitz::JoystickInterface
        {
            public:

                TwoAxisJoystick(int port) :
                    JoystickInterface(port)
                {

                }

                void update() override;

                bool GetTrigger();
                bool GetButton2();
                bool GetButton3();
                bool GetButton4();
                bool GetButton5();
                bool GetButton6();
                bool GetButton7();
                bool GetButton8();

                void EnableTriggerToggle(bool enabled);
                void EnableButton2Toggle(bool enabled);
                void EnableButton3Toggle(bool enabled);
                void EnableButton4Toggle(bool enabled);
                void EnableButton5Toggle(bool enabled);
                void EnableButton6Toggle(bool enabled);
                void EnableButton7Toggle(bool enabled);
                void EnableButton8Toggle(bool enabled);

                double GetXAxis();
                double GetYAxis();
                double GetDial();

                void ReCenterXAxis();
                void ReCenterYAxis();
                void ReCenterDial();

                void SetUniversalDeadband(double Deadband);
                void SetXAxisDeadband(double Deadband);
                void SetYAxisDeadband(double Deadband);
                void SetDialDeadband(double Deadband);

                void SetUniversalRampRate(double RampRate);
                void SetXAxisRampRate(double RampRate);
                void SetYAxisRampRate(double RampRate);
                void SetDialRampRate(double RampRate);

            private:

                //Buttons
                bool Trigger = false;
                bool Button2 = false;
                bool Button3 = false;
                bool Button4 = false;
                bool Button5 = false;
                bool Button6 = false;
                bool Button7 = false;
                bool Button8 = false;

                //Button Toggles
                bool TriggerToggle = false;
                bool Button2Toggle = false;
                bool Button3Toggle = false;
                bool Button4Toggle = false;
                bool Button5Toggle = false;
                bool Button6Toggle = false;
                bool Button7Toggle = false;
                bool Button8Toggle = false;

                
                //Previous Button States
                bool PreTrigger = false;
                bool PreButton2 = false;
                bool PreButton3 = false;
                bool PreButton4 = false;
                bool PreButton5 = false;
                bool PreButton6 = false;
                bool PreButton7 = false;
                bool PreButton8 = false;
                
                //Use Button Toggles
                bool UseTriggerToggle = false;
                bool UseButton2Toggle = false;
                bool UseButton3Toggle = false;
                bool UseButton4Toggle = false;
                bool UseButton5Toggle = false;
                bool UseButton6Toggle = false;
                bool UseButton7Toggle = false;
                bool UseButton8Toggle = false;

                //Axes
                double XAxis = 0;
                double YAxis = 0;
                double Dial = 0;

                //Ramped Axes
                double XAxisRamp = 0;
                double YAxisRamp = 0;
                double DialRamp = 0;

                //Axis Centers
                double XAxisCenter = 0;
                double YAxisCenter = 0;
                double DialCenter = 0;

                //Axis RampRates
                double XAxisRampRate = 1;
                double YAxisRampRate = 1;
                double DialRampRate = 1;

                //Axis Deadbands
                double XAxisDeadband = 0;
                double YAxisDeadband = 0;
                double DialDeadband = 0;

                //Button IDs
                const int TRIGGER_ID = 1;
                const int BUTTON2_ID = 2;
                const int BUTTON3_ID = 3;
                const int BUTTON4_ID = 4;
                const int BUTTON5_ID = 5;
                const int BUTTON6_ID = 6;
                const int BUTTON7_ID = 7;
                const int BUTTON8_ID = 8;

                //Axis IDs
                const int X_AXIS_ID = 0;
                const int Y_AXIS_ID = 1;
                const int DIAL_ID = 2;

        };   
    }
}