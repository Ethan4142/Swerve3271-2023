#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/pchsSwerve.h"


class swerveMovement : public frc2::Command {
public:
swerveMovement(Swerve &swerveDrive, int power);

void Execute();

private:

Swerve &drive;
int pwr;

};
