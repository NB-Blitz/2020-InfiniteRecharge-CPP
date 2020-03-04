#include "JoySticks.hpp"

void Blitz::Joysticks::XboxController::update()
{
    //update previous states
    PreAButton = AButton;
    PreBButton = BButton;
    PreXButton = XButton;
    PreYButton = YButton;
    PreLeftBumper = LeftBumper;
    PreRightBumper = RightBumper;
    PreSelectButton = SelectButton;
    PreStartButton = StartButton;
    PreLeftStickButton = LeftStickButton;
    PreRightStickButton = RightStickButton;

    //Update Buttons
    AButton = GetRawButton(A_BUTTON_ID);
    BButton = GetRawButton(B_BUTTON_ID);
    XButton = GetRawButton(X_BUTTON_ID);
    YButton = GetRawButton(Y_BUTTON_ID);
    LeftBumper = GetRawButton(LEFT_BUMPER_ID);
    RightBumper = GetRawButton(RIGHT_BUMPER_ID);
    LeftStickButton = GetRawButton(LEFT_STICK_BUTTON_ID);
    RightStickButton = GetRawButton(RIGHT_STICK_BUTTON_ID);

    //Update Axis
    LeftX = GetRawAxis(LEFT_X_AXIS_ID);
    LeftY = GetRawAxis(LEFT_Y_AXIS_ID);
    RightX = GetRawAxis(RIGHT_X_AXIS_ID);
    RightY = GetRawAxis(RIGHT_Y_AXIS_ID);
    LeftTrigger = GetRawAxis(LEFT_TRIGGER_ID);
    RightTrigger = GetRawAxis(RIGHT_TRIGGER_ID);

    if(AButton && !PreAButton)
    {
        AButtonToggle = !AButtonToggle;
    }

    if(BButton && !PreBButton)
    {
        BButtonToggle = !BButtonToggle;
    }

    if(XButton && !PreXButton)
    {
        XButtonToggle = !XButtonToggle;
    }

    if(YButton && !PreYButton)
    {
        YButtonToggle = !YButtonToggle;
    }

    if(LeftBumper && !PreLeftBumper)
    {
        LeftBumperToggle = !LeftBumperToggle;
    }

    if(RightBumper && !PreRightBumper)
    {
        RightBumperToggle = !RightBumperToggle;
    }

    if(SelectButton && !PreSelectButton)
    {
        SelectButtonToggle = !SelectButtonToggle;
    }

    if(StartButton && !PreStartButton)
    {
        StartButtonToggle = !StartButtonToggle;
    }

    if(LeftStickButton && !PreLeftStickButton)
    {
        LeftStickButtonToggle = !LeftStickButtonToggle;
    }

    if(RightStickButton && !PreRightStickButton)
    {
        RightStickButtonToggle = !RightStickButtonToggle;
    }
    
}

bool Blitz::Joysticks::XboxController::GetAButton()
{
    if(UseAButtonToggle)
    {
        return AButtonToggle;
    }
    else
    {
        return AButton;
    }
}

bool Blitz::Joysticks::XboxController::GetBButton()
{
    if(UseBButtonToggle)
    {
        return BButtonToggle;
    }
    else
    {
        return BButton;
    }
}

bool Blitz::Joysticks::XboxController::GetXButton()
{
    if(UseXButtonToggle)
    {
        return XButtonToggle;
    }
    else
    {
        return XButton;
    }
}

bool Blitz::Joysticks::XboxController::GetYButton()
{
    if(UseYButtonToggle)
    {
        return YButtonToggle;
    }
    else
    {
        return YButton;
    }
}

bool Blitz::Joysticks::XboxController::GetLeftBumper()
{
    if(UseLeftBumperToggle)
    {
        return LeftBumperToggle;
    }
    else
    {
        return LeftBumper;
    }
}

bool Blitz::Joysticks::XboxController::GetRightBumper()
{
    if(UseRightBumperToggle)
    {
        return RightBumperToggle;
    }
    else
    {
        return RightBumper;
    }
}

bool Blitz::Joysticks::XboxController::GetSelectButton()
{
    if(UseSelectButtonToggle)
    {
        return SelectButtonToggle;
    }
    else
    {
        return SelectButton;
    }
}

bool Blitz::Joysticks::XboxController::GetStartButton()
{
    if(UseStartButtonToggle)
    {
        return StartButtonToggle;
    }
    else
    {
        return StartButton;
    }
}

bool Blitz::Joysticks::XboxController::GetLeftStickButton()
{
    if(UseLeftStickButtonToggle)
    {
        return LeftStickButtonToggle;
    }
    else
    {
        return LeftStickButton;
    }
}

bool Blitz::Joysticks::XboxController::GetRightStickButton()
{
    if(UseRightStickButtonToggle)
    {
        return RightStickButtonToggle;
    }
    else
    {
        return RightStickButton;
    }
}

void Blitz::Joysticks::XboxController::EnableAButtonToggle(bool enabled)
{
    UseAButtonToggle = enabled;
}

void Blitz::Joysticks::XboxController::EnableBButtonToggle(bool enabled)
{
    UseBButtonToggle = enabled;
}

void Blitz::Joysticks::XboxController::EnableXButtonToggle(bool enabled)
{
    UseXButtonToggle = enabled;
}

void Blitz::Joysticks::XboxController::EnableYButtonToggle(bool enabled)
{
    UseYButtonToggle = enabled;
}

void Blitz::Joysticks::XboxController::EnableLeftBumperToggle(bool enabled)
{
    UseLeftBumperToggle = enabled;
}

void Blitz::Joysticks::XboxController::EnableRightBumperToggle(bool enabled)
{
    UseRightBumperToggle = enabled;
}

void Blitz::Joysticks::XboxController::EnableSelectButtonToggle(bool enabled)
{
    UseSelectButtonToggle = enabled;
}

void Blitz::Joysticks::XboxController::EnableStartButtonToggle(bool enabled)
{
    UseStartButtonToggle = enabled;
}

void Blitz::Joysticks::XboxController::EnableLeftStickButtonToggle(bool enabled)
{
    UseLeftStickButtonToggle = enabled;
}

void Blitz::Joysticks::XboxController::EnableRightStickButtonToggle(bool enabled)
{
    UseRightStickButtonToggle = enabled;
}

double Blitz::Joysticks::XboxController::GetLeftX()
{
    if(LeftXRampRate <= 0)
    {
        return LeftX;
    }
    else
    {
        LeftXRamp = RampAxis(LeftX, LeftXRamp, LeftXCenter, LeftXDeadband, LeftXRampRate);
        return LeftXRamp;
    }
}

double Blitz::Joysticks::XboxController::GetLeftY()
{
    if(LeftYRampRate <= 0)
    {
        return LeftY;
    }
    else
    {
        LeftYRamp = RampAxis(LeftY, LeftYRamp, LeftYCenter, LeftYDeadband, LeftYRampRate);
        return LeftYRamp;
    }
}

double Blitz::Joysticks::XboxController::GetRightX()
{
    if(RightXRampRate <= 0)
    {
        return RightX;
    }
    else
    {
        RightXRamp = RampAxis(RightX, RightXRamp, RightXCenter, RightXDeadband, RightXRampRate);
        return RightXRamp;
    }
}

double Blitz::Joysticks::XboxController::GetRightY()
{
    if(RightYRampRate <= 0)
    {
        return RightY;
    }
    else
    {
        RightYRamp = RampAxis(RightY, RightYRamp, RightYCenter, RightYDeadband, RightYRampRate);
        return RightYRamp;
    }
}

double Blitz::Joysticks::XboxController::GetLeftTrigger()
{
    if(LeftTriggerRampRate <= 0)
    {
        return LeftTrigger;
    }
    else
    {
        LeftTriggerRamp = RampAxis(LeftTrigger, LeftTriggerRamp, LeftTriggerCenter, LeftTriggerDeadband, LeftTriggerRampRate);
        return LeftTriggerRamp;
    }
}

double Blitz::Joysticks::XboxController::GetRightTrigger()
{
    if(RightTriggerRampRate <= 0)
    {
        return RightTrigger;
    }
    else
    {
        RightTriggerRamp = RampAxis(RightTrigger, RightTriggerRamp, RightTriggerCenter, RightTriggerDeadband, RightTriggerRampRate);
        return RightTriggerRamp;
    }
}

void Blitz::Joysticks::XboxController::ReCenterLeftX()
{
    LeftXCenter = GetRawAxis(LEFT_X_AXIS_ID);
}

void Blitz::Joysticks::XboxController::ReCenterLeftY()
{
    LeftYCenter = GetRawAxis(LEFT_Y_AXIS_ID);
}

void Blitz::Joysticks::XboxController::ReCenterRightX()
{
    RightXCenter = GetRawAxis(RIGHT_X_AXIS_ID);
}

void Blitz::Joysticks::XboxController::ReCenterRightY()
{
    RightYCenter = GetRawAxis(RIGHT_Y_AXIS_ID);
}

void Blitz::Joysticks::XboxController::ReCenterLeftTrigger()
{
    LeftTriggerCenter = GetRawAxis(LEFT_TRIGGER_ID);
}

void Blitz::Joysticks::XboxController::ReCenterRightTrigger()
{
    RightTriggerCenter = GetRawAxis(RIGHT_TRIGGER_ID);
}

void Blitz::Joysticks::XboxController::SetUniversalDeadband(double Deadband)
{
    LeftXDeadband = Deadband;
    LeftYDeadband = Deadband;
    RightXDeadband = Deadband;
    RightYDeadband = Deadband;
    LeftTriggerDeadband = Deadband;
    RightTriggerDeadband = Deadband;
}

void Blitz::Joysticks::XboxController::SetLeftXDeadband(double Deadband)
{
    LeftXDeadband = Deadband;
}

void Blitz::Joysticks::XboxController::SetLeftYDeadband(double Deadband)
{
    LeftYDeadband = Deadband;
}

void Blitz::Joysticks::XboxController::SetRightXDeadband(double Deadband)
{
    RightXDeadband = Deadband;
}

void Blitz::Joysticks::XboxController::SetRightYDeadband(double Deadband)
{
    RightYDeadband = Deadband;
}

void Blitz::Joysticks::XboxController::SetLeftTriggerDeadband(double Deadband)
{
    LeftTriggerDeadband = Deadband;
}

void Blitz::Joysticks::XboxController::SetRightTriggerDeadband(double Deadband)
{
    RightTriggerDeadband = Deadband;
}

void Blitz::Joysticks::XboxController::SetUniversalRampRate(double RampRate)
{
    LeftXRampRate = RampRate;
    LeftYRampRate = RampRate;
    RightXRampRate = RampRate;
    RightYRampRate = RampRate;
    LeftTriggerRampRate = RampRate;
    RightTriggerRampRate = RampRate;
}

void Blitz::Joysticks::XboxController::SetLeftXRampRate(double RampRate)
{
    LeftXRampRate = RampRate;
}

void Blitz::Joysticks::XboxController::SetLeftYRampRate(double RampRate)
{
    LeftYRampRate = RampRate;
}

void Blitz::Joysticks::XboxController::SetRightXRampRate(double RampRate)
{
    RightXRampRate = RampRate;
}

void Blitz::Joysticks::XboxController::SetRightYRampRate(double RampRate)
{
    RightYRampRate = RampRate;
}

void Blitz::Joysticks::XboxController::SetLeftTriggerRampRate(double RampRate)
{
    LeftTriggerRampRate = RampRate;
}

void Blitz::Joysticks::XboxController::SetRightTriggerRampRate(double RampRate)
{
    RightTriggerRampRate = RampRate;
}