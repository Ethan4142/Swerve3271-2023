#pragma once

#include "SwerveModule.h"

#include <ctre/phoenix/sensors/BasePigeon.h>
#include <frc2/command/Commands.h>
#include <frc/kinematics/SwerveDriveKinematics.h>
#include <frc/kinematics/SwerveDriveOdometry.h>



class Swerve : frc2::SubsystemBase{
 enum class direction{fwd,lft,bck,rgt};

 //Friend class with the Swerve Modules to borrow public functions
 friend class SwerveMod;

 Swerve(SwerveMod &leftFrt, SwerveMod &leftBck, SwerveMod &rightFrt, SwerveMod &rightBck, ctre::phoenix::sensors::BasePigeon &inertial);
 //Swerve Drive Constructor with arguments to swerve modules 
 public:
 
 //Tele-Operated Commands 
 frc2::CommandPtr teleOp();

 frc2::CommandPtr test();

 void innit();



 private:
 //Kinematics Object for the Swerve drive
 frc::SwerveDriveKinematics<swerveConstants::swerveCount>* kinematics;

 //Swerve Module contructors for the Drive
 SwerveMod* moduleLF; //Left front Swerve Module
 SwerveMod* moduleLB; //Left back Swerve Module
 SwerveMod* moduleRF; //Right front Swerve Module
 SwerveMod* moduleRB; //Right back Swerve Module

 ctre::phoenix::sensors::BasePigeon* IMU; //Inertial for the Swerve
 /*************Position Tracking For Swerve Drive***********************/
 public:

  double getHeadingX(); //Gets the Heading for positive X movement ( + 0 degrees)

  double getHeadingY(); //Gets the Heading for positive Y movement ( + 90 degrees)

  direction getX(); //Gets the direction the chassis would be going in the positive x direction

  direction getY(); //Gets the direction the chassis would be going in the positive y direction

  
};