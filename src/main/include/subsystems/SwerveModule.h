#pragma once

#include "Constants.h"

#include <frc/Filesystem.h>
#include <frc/geometry/Pose2d.h>
#include <frc/geometry/Rotation2d.h>
#include <frc/kinematics/SwerveModuleState.h>
#include <frc/kinematics/SwerveModulePosition.h>
#include <frc/controller/PIDController.h>
#include <wpi/sendable/Sendable.h>
#include <wpi/sendable/SendableHelper.h>

#include <frc2/command/Command.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>

#include <ctre/phoenix/motorcontrol/can/WPI_TalonFX.h>
#include <ctre/phoenix/sensors/CANCoder.h>



class SwerveMod : frc2::SubsystemBase{
  public:

  enum class modSide {lf, lb, rf, rb}; //Enumerator for the Sides of the robot chassis and Swerve Modules

  SwerveMod(int drivePort, int steerPort, int encPort); //Swerve Module constructor

  void stop(ctre::phoenix::motorcontrol::NeutralMode driveMode, ctre::phoenix::motorcontrol::NeutralMode steerMode); //Stops the Motors on the Swerve Modules and sets the stopping modes

  frc::SwerveModuleState getState(); //Swerve Module State based through WPI LIB kinematics (I could not do it) :(

  void setState(frc::SwerveModuleState state);

  double getSteer(swerveConstants::turnUnit unit); //Gets the Steering angle of the Swerve Module

  double getCloseAng(int angI, int angF); //gets the closest angle for the Initial to Final

  double getDrive(); //Gets the distance in Meters driven by the Swerve Module

  void setSteer(double angle); //Sets the Steering angle of the Swerve module

  void setDrive(double pwr); //Set the Driving Motor to spin at a power

 private:
  frc::PIDController SteerPID{swerveConstants::steerP,swerveConstants::steerI,swerveConstants::steerD};
  //Base Motor Initialization of Module Electronics
  ctre::phoenix::motorcontrol::can::WPI_TalonFX driveM; //Driving Motor
  ctre::phoenix::motorcontrol::can::WPI_TalonFX steerM; //Steering Motor

  ctre::phoenix::sensors::CANCoder steerEnc; //Encoder to track the steering angle
  modSide side;// Side the Swerve module is relative to the base and robot

  //Starting configuration of the swerve
  double startSteer = 90; //starting config of the steering degree

 

};