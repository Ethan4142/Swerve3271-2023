#include "subsystems/pchsSwerve.h"

#include "cmath"


Swerve::Swerve(SwerveMod &leftFrt, SwerveMod &leftBck, SwerveMod &rightFrt, SwerveMod &rightBck, ctre::phoenix::sensors::BasePigeon &inertial):
moduleLF{&leftFrt},
moduleLB{&leftBck},
moduleRF{&rightFrt},
moduleRB{&rightBck},
IMU{&inertial}
{}




   
// double Swerve::getHeadingX(){ 
//  return(IMU.GetYaw());
// }

// double Swerve::getHeadingY(){
//  return(90 + IMU.GetYaw());
// }

// Swerve::direction Swerve::getX(){
//  Swerve::direction x;
//  if((getHeadingX() > (midFrnt - df))||(getHeadingX() < (midFrnt + df))){
//   x = Swerve::direction::fwd;
//  }else if((getHeadingX() > (midBack - df))||(getHeadingX() < (midBack + df))){
//   x = Swerve::direction::bck;
//  }else if((getHeadingX() > (midLeft - df))||(getHeadingX() < (midLeft + df))){
//   x = Swerve::direction::lft; 
//  }else if((getHeadingX() > (midRight - df))||(getHeadingX() < (midRight + df))){
//   x = Swerve::direction::rgt;
//  }
//  return(x);
// }

// Swerve::direction Swerve::getY(){
//  Swerve::direction y;
//  if((getHeadingY() > (midRight - df))||(getHeadingY() < (midRight + df))){
//     y = Swerve::direction::rgt;
//  }else if((getHeadingY() > (midLeft - df))||(getHeadingY() < (midLeft +df))){
//     y = Swerve::direction::lft;
//  }else if((getHeadingY() > (midFrnt - df))||(getHeadingY() < (midFrnt + df))){
//     y = Swerve::direction::fwd;
//  }else if((getHeadingY() > (midBack - df))||(getHeadingY() < (midBack + df))){
//     y = Swerve::direction::bck;
//  }
//  return(y);
// }

