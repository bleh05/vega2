#include "Arm.hpp"
#include "main.h"
#include "okapi/api.hpp"
using namespace okapi;
Arm::Arm(int p):
arm(new Motor(p,false, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees)){}
void Arm::moveUp(){
  arm->move_velocity(200);
}
void Arm::moveDown(){
  arm->move_velocity(-200);
}
void Arm::stop(){
  arm->move_velocity(0);
}
