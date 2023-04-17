#pragma once

#include "SwerveModule.h"

#include <frc/I2C.h>
#include <frc2/command/Commands.h>
#include <frc/kinematics/SwerveDriveKinematics.h>
#include <frc/kinematics/SwerveDriveOdometry.h>

#include <AHRS.h>

class Swerve : frc2::SubsystemBase{
 enum class direction{fwd,lft,bck,rgt};

 //Friend class with the Swerve Modules to borrow public functions
 friend class SwerveMod;

 public: Swerve(); 
 //Swerve Drive Constructor using the Swerve Drive IDS for each Module
 public:
 
 frc::SwerveDriveKinematics<swerveConstants::swerveCount>* pchsSwerveKinematics; //Kinematics Object for the Swerve drive

 //Tele-Operated Commands 
 frc2::CommandPtr teleOp(double x, double y, double theta);

 frc2::CommandPtr test();

 void innit();

 

 private:
 //Swerve Module contructors for the Drive
 SwerveMod moduleLF; //Left front Swerve Module
 SwerveMod moduleLB; //Left back Swerve Module
 SwerveMod moduleRF; //Right front Swerve Module
 SwerveMod moduleRB; //Right back Swerve Module

 AHRS IMU;//NavX 2 Micro Gyro

 /*************Position Tracking For Swerve Drive***********************/
 public:

  double getHeadingX(); //Gets the Heading for positive X movement ( + 0 degrees)

  double getHeadingY(); //Gets the Heading for positive Y movement ( + 90 degrees)

  direction getX(); //Gets the direction the chassis would be going in the positive x direction

  direction getY(); //Gets the direction the chassis would be going in the positive y direction

  
};