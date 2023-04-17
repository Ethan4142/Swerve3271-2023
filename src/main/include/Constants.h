// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <cmath>

#include <frc/geometry/Translation2d.h>


/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace OperatorConstants {

constexpr double kDriverDeadband = 0.02;
constexpr int kDriverControllerPort = 0;

}  // namespace OperatorConstants

namespace swerveConstants {
const swerveCount = 4;
struct ids{
 const int lfDrive = 1;
 const int lbDrive = 2;
 const int rfDrive = 3;
 const int rbDrive = 4;

 const int lfSteer = 5;
 const int lbSteer = 6;
 const int rfSteer = 7;
 const int rbSteer = 8;
 
 const int lfEnc = 9;
 const int lbEnc = 10;
 const int rfEnc = 11;
 const int rbEnc = 12;

 //Module Offsets from the center of the robot- In Translation2D
 //Set Up for the Front of the Robot to be Positive X
 const frc::Translation2d leftFrnt{units::meter_t{1},units::meter_t{1}};
 const frc::Translation2d leftBack{units::meter_t{-1},units::meter_t{1}};
 const frc::Translation2d rightFrnt{units::meter_t{1},units::meter_t{-1}};
 const frc::Translation2d rightBack{units::meter_t{-1},units::meter_t{-1}};
};

enum class turnUnit {degrees , radians};
constexpr double kDegreesRatio = (180/M_PI);
constexpr double kRadiansRatio = (M_PI/180);

constexpr double kMetersRatio = 0 ;
constexpr double l1Ratio = 1/13.5; //L1 Swerve Drive Ratio for falcon 500 motors in ft/sec 

constexpr int midFrnt = 90;
constexpr int midBack = 270;
constexpr int midRight = 0;
constexpr int midLeft = 180;

constexpr int df = 45; //Degrees of freedom (is only perfect because the Gyro will not be perfect)

const double steerP = 0;
const double steerI = 0;
const double steerD = 0;
}