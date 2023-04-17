#include "subsystems/pchsSwerve.h"

#include "cmath"

using namespace swerveConstants;
ids swerveIDs; //Creating struct of the Swerve Module ID's

Swerve::Swerve()
:
 moduleLF{swerveIDs.lfDrive,swerveIDs.lfSteer,swerveIDs.lfEnc},
 moduleLB{swerveIDs.lbDrive,swerveIDs.lbSteer,swerveIDs.lbEnc},
 moduleRF{swerveIDs.rfDrive,swerveIDs.rfSteer,swerveIDs.rfEnc},
 moduleRB{swerveIDs.rbDrive,swerveIDs.rbSteer,swerveIDs.rbEnc},
 IMU{frc::I2C::Port::kOnboard}
{}

void Swerve::innit(){
 IMU.Calibrate();
 
 pchsSwerveKinematics = new frc::SwerveDriveKinematics<swerveCount>(swerveIDs.leftFrnt,swerveIDs.leftBack,swerveIDs.rightFrnt,swerveIDs.rightBack);
}


   
double Swerve::getHeadingX(){ 
 return(IMU.GetYaw());
}

double Swerve::getHeadingY(){
 return(90 + IMU.GetYaw());
}

Swerve::direction Swerve::getX(){
 Swerve::direction x;
 if((getHeadingX() > (midFrnt - df))||(getHeadingX() < (midFrnt + df))){
  x = Swerve::direction::fwd;
 }else if((getHeadingX() > (midBack - df))||(getHeadingX() < (midBack + df))){
  x = Swerve::direction::bck;
 }else if((getHeadingX() > (midLeft - df))||(getHeadingX() < (midLeft + df))){
  x = Swerve::direction::lft; 
 }else if((getHeadingX() > (midRight - df))||(getHeadingX() < (midRight + df))){
  x = Swerve::direction::rgt;
 }
 return(x);
}

Swerve::direction Swerve::getY(){
 Swerve::direction y;
 if((getHeadingY() > (midRight - df))||(getHeadingY() < (midRight + df))){
    y = Swerve::direction::rgt;
 }else if((getHeadingY() > (midLeft - df))||(getHeadingY() < (midLeft +df))){
    y = Swerve::direction::lft;
 }else if((getHeadingY() > (midFrnt - df))||(getHeadingY() < (midFrnt + df))){
    y = Swerve::direction::fwd;
 }else if((getHeadingY() > (midBack - df))||(getHeadingY() < (midBack + df))){
    y = Swerve::direction::bck;
 }
 return(y);
}

