#include "JoySticks.hpp"

void Blitz::Joysticks::ThreeAxisJoystick::update()
{
    //update previous states
    PreTrigger = Trigger;
    PreButton2 = Button2;
    PreButton3 = Button3;
    PreButton4 = Button4;
    PreButton5 = Button5;
    PreButton6 = Button6;
    PreButton7 = Button7;
    PreButton8 = Button8;
    PreButton9 = Button9;
    PreButton10 = Button10;
    PreButton11 = Button11;
    PreButton12 = Button12;

    //Update Buttons
    Trigger = GetRawButton(TRIGGER_ID);
    Button2 = GetRawButton(BUTTON2_ID);
    Button3 = GetRawButton(BUTTON3_ID);
    Button4 = GetRawButton(BUTTON4_ID);
    Button5 = GetRawButton(BUTTON5_ID);
    Button6 = GetRawButton(BUTTON6_ID);
    Button7 = GetRawButton(BUTTON7_ID);
    Button8 = GetRawButton(BUTTON8_ID);
    Button9 = GetRawButton(BUTTON9_ID);
    Button10 = GetRawButton(BUTTON10_ID);
    Button11 = GetRawButton(BUTTON11_ID);
    Button12 = GetRawButton(BUTTON12_ID);

    //Update Axis
    XAxis = GetRawAxis(X_AXIS_ID);
    YAxis = GetRawAxis(Y_AXIS_ID);
    ZAxis = GetRawAxis(Z_AXIS_ID);
    Dial = GetRawAxis(DIAL_ID);

    if(Trigger && !PreTrigger)
    {
        TriggerToggle = !TriggerToggle;
    }

    if(Button2 && !PreButton2)
    {
        Button2Toggle = !Button2Toggle;
    }

    if(Button3 && !PreButton3)
    {
        Button3Toggle = !Button3Toggle;
    }

    if(Button4 && !PreButton4)
    {
        Button4Toggle = !Button4Toggle;
    }

    if(Button5 && !PreButton5)
    {
        Button5Toggle = !Button5Toggle;
    }

    if(Button6 && !PreButton6)
    {
        Button6Toggle = !Button6Toggle;
    }

    if(Button7 && !PreButton7)
    {
        Button7Toggle = !Button7Toggle;
    }

    if(Button8 && !PreButton8)
    {
        Button8Toggle = !Button8Toggle;
    }

    if(Button9 && !PreButton9)
    {
        Button9Toggle = !Button9Toggle;
    }

    if(Button10 && !PreButton10)
    {
        Button10Toggle = !Button10Toggle;
    }

    if(Button11 && !PreButton11)
    {
        Button11Toggle = !Button11Toggle;
    }

    if(Button12 && !PreButton12)
    {
        Button12Toggle = !Button12Toggle;
    }
}

bool Blitz::Joysticks::ThreeAxisJoystick::GetTrigger()
{
    if(UseTriggerToggle)
    {
        return TriggerToggle;
    }
    else
    {
        return Trigger;
    }
}

bool Blitz::Joysticks::ThreeAxisJoystick::GetButton2()
{
    if(UseButton2Toggle)
    {
        return Button2Toggle;
    }
    else
    {
        return Button2;
    }
}

bool Blitz::Joysticks::ThreeAxisJoystick::GetButton3()
{
    if(UseButton3Toggle)
    {
        return Button3Toggle;
    }
    else
    {
        return Button3;
    }
}

bool Blitz::Joysticks::ThreeAxisJoystick::GetButton4()
{
    if(UseButton4Toggle)
    {
        return Button4Toggle;
    }
    else
    {
        return Button4;
    }
}

bool Blitz::Joysticks::ThreeAxisJoystick::GetButton5()
{
    if(UseButton5Toggle)
    {
        return Button5Toggle;
    }
    else
    {
        return Button5;
    }
}

bool Blitz::Joysticks::ThreeAxisJoystick::GetButton6()
{
    if(UseButton6Toggle)
    {
        return Button6Toggle;
    }
    else
    {
        return Button6;
    }
}

bool Blitz::Joysticks::ThreeAxisJoystick::GetButton7()
{
    if(UseButton7Toggle)
    {
        return Button7Toggle;
    }
    else
    {
        return Button7;
    }
}

bool Blitz::Joysticks::ThreeAxisJoystick::GetButton8()
{
    if(UseButton8Toggle)
    {
        return Button8Toggle;
    }
    else
    {
        return Button8;
    }
}

bool Blitz::Joysticks::ThreeAxisJoystick::GetButton9()
{
    if(UseButton9Toggle)
    {
        return Button9Toggle;
    }
    else
    {
        return Button9;
    }
}

bool Blitz::Joysticks::ThreeAxisJoystick::GetButton10()
{
    if(UseButton10Toggle)
    {
        return Button10Toggle;
    }
    else
    {
        return Button10;
    }
}

bool Blitz::Joysticks::ThreeAxisJoystick::GetButton11()
{
    if(UseButton11Toggle)
    {
        return Button11Toggle;
    }
    else
    {
        return Button11;
    }
}

bool Blitz::Joysticks::ThreeAxisJoystick::GetButton12()
{
    if(UseButton12Toggle)
    {
        return Button12Toggle;
    }
    else
    {
        return Button12;
    }
}

void Blitz::Joysticks::ThreeAxisJoystick::EnableTriggerToggle(bool enabled)
{
    UseTriggerToggle = enabled;
}

void Blitz::Joysticks::ThreeAxisJoystick::EnableButton2Toggle(bool enabled)
{
    UseButton2Toggle = enabled;
}

void Blitz::Joysticks::ThreeAxisJoystick::EnableButton3Toggle(bool enabled)
{
    UseButton3Toggle = enabled;
}

void Blitz::Joysticks::ThreeAxisJoystick::EnableButton4Toggle(bool enabled)
{
    UseButton4Toggle = enabled;
}

void Blitz::Joysticks::ThreeAxisJoystick::EnableButton5Toggle(bool enabled)
{
    UseButton5Toggle = enabled;
}

void Blitz::Joysticks::ThreeAxisJoystick::EnableButton6Toggle(bool enabled)
{
    UseButton6Toggle = enabled;
}

void Blitz::Joysticks::ThreeAxisJoystick::EnableButton7Toggle(bool enabled)
{
    UseButton7Toggle = enabled;
}

void Blitz::Joysticks::ThreeAxisJoystick::EnableButton8Toggle(bool enabled)
{
    UseButton8Toggle = enabled;
}

void Blitz::Joysticks::ThreeAxisJoystick::EnableButton9Toggle(bool enabled)
{
    UseButton9Toggle = enabled;
}

void Blitz::Joysticks::ThreeAxisJoystick::EnableButton10Toggle(bool enabled)
{
    UseButton10Toggle = enabled;
}

void Blitz::Joysticks::ThreeAxisJoystick::EnableButton11Toggle(bool enabled)
{
    UseButton11Toggle = enabled;
}

void Blitz::Joysticks::ThreeAxisJoystick::EnableButton12Toggle(bool enabled)
{
    UseButton12Toggle = enabled;
}

double Blitz::Joysticks::ThreeAxisJoystick::GetXAxis()
{
    if(XAxisRampRate <= 0)
    {
        return XAxis;
    }
    else
    {
        XAxisRamp = RampAxis(XAxis, XAxisRamp, XAxisCenter, XAxisDeadband, XAxisRampRate);
        return XAxisRamp;
    }
}

double Blitz::Joysticks::ThreeAxisJoystick::GetYAxis()
{
    if(YAxisRampRate <= 0)
    {
        return YAxis;
    }
    else
    {
        YAxisRamp = RampAxis(YAxis, YAxisRamp, YAxisCenter, YAxisDeadband, YAxisRampRate);
        return YAxisRamp;
    }
}

double Blitz::Joysticks::ThreeAxisJoystick::GetZAxis()
{
    if(ZAxisRampRate <= 0)
    {
        return ZAxis;
    }
    else
    {
        ZAxisRamp = RampAxis(ZAxis, ZAxisRamp, ZAxisCenter, ZAxisDeadband, ZAxisRampRate);
        return ZAxisRamp;
    }
}

double Blitz::Joysticks::ThreeAxisJoystick::GetDial()
{
    if(DialRampRate <= 0)
    {
        return Dial;
    }
    else
    {
        DialRamp = RampAxis(Dial, DialRamp, DialCenter, DialDeadband, DialRampRate);
        return DialRamp;
    }
}

void Blitz::Joysticks::ThreeAxisJoystick::ReCenterXAxis()
{
    XAxisCenter = GetRawAxis(X_AXIS_ID);
}

void Blitz::Joysticks::ThreeAxisJoystick::ReCenterYAxis()
{
    YAxisCenter = GetRawAxis(Y_AXIS_ID);
}

void Blitz::Joysticks::ThreeAxisJoystick::ReCenterZAxis()
{
    ZAxisCenter = GetRawAxis(Z_AXIS_ID);
}

void Blitz::Joysticks::ThreeAxisJoystick::ReCenterDial()
{
    DialCenter = GetRawAxis(DIAL_ID);
}

void Blitz::Joysticks::ThreeAxisJoystick::SetUniversalDeadband(double Deadband)
{
    XAxisDeadband = Deadband;
    YAxisDeadband = Deadband;
    ZAxisDeadband = Deadband;
    DialDeadband = Deadband;
}

void Blitz::Joysticks::ThreeAxisJoystick::SetXAxisDeadband(double Deadband)
{
    XAxisDeadband = Deadband;
}

void Blitz::Joysticks::ThreeAxisJoystick::SetYAxisDeadband(double Deadband)
{
    YAxisDeadband = Deadband;
}

void Blitz::Joysticks::ThreeAxisJoystick::SetZAxisDeadband(double Deadband)
{
    ZAxisDeadband = Deadband;
}

void Blitz::Joysticks::ThreeAxisJoystick::SetDialDeadband(double Deadband)
{
    DialDeadband = Deadband;
}

void Blitz::Joysticks::ThreeAxisJoystick::SetUniversalRampRate(double RampRate)
{
    XAxisRampRate = RampRate;
    YAxisRampRate = RampRate;
    ZAxisRampRate = RampRate;
    DialRampRate = RampRate;
}

void Blitz::Joysticks::ThreeAxisJoystick::SetXAxisRampRate(double RampRate)
{
    XAxisRampRate = RampRate;
}

void Blitz::Joysticks::ThreeAxisJoystick::SetYAxisRampRate(double RampRate)
{
    YAxisRampRate = RampRate;
}

void Blitz::Joysticks::ThreeAxisJoystick::SetZAxisRampRate(double RampRate)
{
    ZAxisRampRate = RampRate;
}

void Blitz::Joysticks::ThreeAxisJoystick::SetDialRampRate(double RampRate)
{
    DialRampRate = RampRate;
}