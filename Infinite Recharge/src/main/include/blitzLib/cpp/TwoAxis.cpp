#include "JoySticks.hpp"

void Blitz::Joysticks::TwoAxisJoystick::update()
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

    //Update Buttons
    Trigger = GetRawButton(TRIGGER_ID);
    Button2 = GetRawButton(BUTTON2_ID);
    Button3 = GetRawButton(BUTTON3_ID);
    Button4 = GetRawButton(BUTTON4_ID);
    Button5 = GetRawButton(BUTTON5_ID);
    Button6 = GetRawButton(BUTTON6_ID);
    Button7 = GetRawButton(BUTTON7_ID);
    Button8 = GetRawButton(BUTTON8_ID);

    //Update Axis
    XAxis = GetRawAxis(X_AXIS_ID);
    YAxis = GetRawAxis(Y_AXIS_ID);
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
}

bool Blitz::Joysticks::TwoAxisJoystick::GetTrigger()
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

bool Blitz::Joysticks::TwoAxisJoystick::GetButton2()
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

bool Blitz::Joysticks::TwoAxisJoystick::GetButton3()
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

bool Blitz::Joysticks::TwoAxisJoystick::GetButton4()
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

bool Blitz::Joysticks::TwoAxisJoystick::GetButton5()
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

bool Blitz::Joysticks::TwoAxisJoystick::GetButton6()
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

bool Blitz::Joysticks::TwoAxisJoystick::GetButton7()
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

bool Blitz::Joysticks::TwoAxisJoystick::GetButton8()
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

void Blitz::Joysticks::TwoAxisJoystick::EnableTriggerToggle(bool enabled)
{
    UseTriggerToggle = enabled;
}

void Blitz::Joysticks::TwoAxisJoystick::EnableButton2Toggle(bool enabled)
{
    UseButton2Toggle = enabled;
}

void Blitz::Joysticks::TwoAxisJoystick::EnableButton3Toggle(bool enabled)
{
    UseButton3Toggle = enabled;
}

void Blitz::Joysticks::TwoAxisJoystick::EnableButton4Toggle(bool enabled)
{
    UseButton4Toggle = enabled;
}

void Blitz::Joysticks::TwoAxisJoystick::EnableButton5Toggle(bool enabled)
{
    UseButton5Toggle = enabled;
}

void Blitz::Joysticks::TwoAxisJoystick::EnableButton6Toggle(bool enabled)
{
    UseButton6Toggle = enabled;
}

void Blitz::Joysticks::TwoAxisJoystick::EnableButton7Toggle(bool enabled)
{
    UseButton7Toggle = enabled;
}

void Blitz::Joysticks::TwoAxisJoystick::EnableButton8Toggle(bool enabled)
{
    UseButton8Toggle = enabled;
}

double Blitz::Joysticks::TwoAxisJoystick::GetXAxis()
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

double Blitz::Joysticks::TwoAxisJoystick::GetYAxis()
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

double Blitz::Joysticks::TwoAxisJoystick::GetDial()
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

void Blitz::Joysticks::TwoAxisJoystick::ReCenterXAxis()
{
    XAxisCenter = GetRawAxis(X_AXIS_ID);
}

void Blitz::Joysticks::TwoAxisJoystick::ReCenterYAxis()
{
    YAxisCenter = GetRawAxis(Y_AXIS_ID);
}

void Blitz::Joysticks::TwoAxisJoystick::ReCenterDial()
{
    DialCenter = GetRawAxis(DIAL_ID);
}

void Blitz::Joysticks::TwoAxisJoystick::SetUniversalDeadband(double Deadband)
{
    XAxisDeadband = Deadband;
    YAxisDeadband = Deadband;
    DialDeadband = Deadband;
}

void Blitz::Joysticks::TwoAxisJoystick::SetXAxisDeadband(double Deadband)
{
    XAxisDeadband = Deadband;
}

void Blitz::Joysticks::TwoAxisJoystick::SetYAxisDeadband(double Deadband)
{
    YAxisDeadband = Deadband;
}

void Blitz::Joysticks::TwoAxisJoystick::SetDialDeadband(double Deadband)
{
    DialDeadband = Deadband;
}

void Blitz::Joysticks::TwoAxisJoystick::SetUniversalRampRate(double RampRate)
{
    XAxisRampRate = RampRate;
    YAxisRampRate = RampRate;
    DialRampRate = RampRate;
}

void Blitz::Joysticks::TwoAxisJoystick::SetXAxisRampRate(double RampRate)
{
    XAxisRampRate = RampRate;
}

void Blitz::Joysticks::TwoAxisJoystick::SetYAxisRampRate(double RampRate)
{
    YAxisRampRate = RampRate;
}

void Blitz::Joysticks::TwoAxisJoystick::SetDialRampRate(double RampRate)
{
    DialRampRate = RampRate;
}