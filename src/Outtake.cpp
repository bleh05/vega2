#include "Outtake.hpp"
#include "main.h"
#include "okapi/api.hpp"
using namespace okapi;
OuttakeT::OuttakeT(int p):
outtake(new Motor(p,true, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees)){
}
void OuttakeT::moveUp(){
  IntegratedEncoder* enc = new IntegratedEncoder(*outtake);
  enc->reset();
  outtake->moveVelocity(200);
}
void OuttakeT::moveDown(){
  IntegratedEncoder* enc = new IntegratedEncoder(*outtake);
  enc->reset();
  outtake->moveVelocity(-200);
}
void OuttakeT::stop(){
  IntegratedEncoder* enc = new IntegratedEncoder(*outtake);
  enc->reset();
  outtake->move_velocity(0);
}
void OuttakeT::disable(){
  disa=true;
}
void OuttakeT::enable(){
  disa=false;
}
int OuttakeT::getState(){
  return encV[state];
}
void OuttakeT::setState(int st){
  state=st;
}
bool OuttakeT::keepState(){
  IntegratedEncoder* enc = new IntegratedEncoder(*outtake);
  if(enc->get()<getState()){
    if(enc->get()>4500){
      outtake->moveVelocity(134);
    }
    else{
      outtake->moveVelocity(200);
    }
    return true;
  }
  else if(enc->get()<getState()+5&&enc->get()>getState()){
    outtake->moveVelocity(0);
      return false;
  }
  else{
      outtake->moveVelocity(-200);
      return true;
  }
}
