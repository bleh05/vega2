#include "Intake.hpp"
#include "main.h"
#include "okapi/api.hpp"
using namespace okapi;
Intake::Intake(int p,int p2):
intake_l(new Motor(p,false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees)),
intake_r(new Motor(p,true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees)){}
void Intake::moveUp(){
  intake_l->move_velocity(200);
  intake_r->move_velocity(200);
}
void Intake::moveDown(){
  intake_l->move_velocity(-55);
  intake_r->move_velocity(-55);
}
void Intake::stop(){
  intake_l->move_velocity(0);
  intake_r->move_velocity(0);
}
