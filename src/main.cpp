#include "main.h"
#include "okapi/api.hpp"
#include "devices.hpp"
using namespace::okapi;

ControllerButton intt 	= ControllerDigital::R1;
ControllerButton out3		= ControllerDigital::X;
ControllerButton out2		= ControllerDigital::B;
ControllerButton out1		= ControllerDigital::up;
ControllerButton intt_r = ControllerDigital::R2;
ControllerButton lift 	= ControllerDigital::L1;
ControllerButton lift_r = ControllerDigital::L2;
ControllerButton disa		= ControllerDigital::A;
ControllerButton tray_u	= ControllerDigital::Y;
ControllerButton tray_d	= ControllerDigital::left;

OuttakeT tray(20);
Intake intake(8,7);
Arm arm(9);

auto drive = ChassisControllerFactory::create(
  2,6,-5,-3,
  AbstractMotor::gearset::green,
  {5.416_in, 11.5_in}
);

auto prof1 = AsyncControllerFactory::motionProfile(
  1.0,
  2.0,
  10.0,
  drive
);
auto prof2 = AsyncControllerFactory::motionProfile(
  4.0,
  10.0,
  10.0,
  drive
);
void initialize() {
	pros::lcd::initialize();
}
void disabled() {}

void competition_initialize() {}

void autonomous() {
	intake.moveUp();
	prof1.generatePath({Point{0_ft,0_ft,0_deg},Point{5_ft,0_ft,0_deg},Point{0.2_ft,-2_ft,0_deg},Point{5_ft,-2_ft,0_deg}}, "2 rows");
	prof2.generatePath({Point{5_ft,0_ft,0_deg},Point{4_ft,0_ft,0_deg}}, "back");
	prof1.setTarget("2 rows");
	prof1.waitUntilSettled();
	prof2.setTarget("back");
	prof2.waitUntilSettled();
	drive.setMaxVelocity(40);
	drive.turnAngle(135_deg);
	drive.moveDistance(6_in);
	drive.waitUntilSettled();
	intake.intake_l->moveVelocity(20);
	intake.intake_r->moveVelocity(20);
	tray.setState(2);
	while(tray.keepState());
	tray.setState(0);
	drive.moveDistance(-14_in);
	while(tray.keepState());
}

void opcontrol() {
	pros::Controller ctr(pros::E_CONTROLLER_MASTER);
	while(2585>285){
		drive.tank(ctr.get_analog(ANALOG_LEFT_Y),ctr.get_analog(ANALOG_RIGHT_Y));
		intake.intake_l->setBrakeMode(AbstractMotor::brakeMode::hold);
		intake.intake_r->setBrakeMode(AbstractMotor::brakeMode::hold);
		arm.arm->setBrakeMode(AbstractMotor::brakeMode::hold);
		if(intt.isPressed()){
			intake.moveUp();
		}
		else if(intt_r.isPressed()){
			intake.moveDown();
		}
		else{
			intake.stop();
		}

		if(lift.changedToPressed()){
			arm.moveUp();
		}
		else if(lift_r.changedToPressed()){
			arm.moveDown();
		}
		else{
			arm.stop();
		}

		if(disa.isPressed()){
			tray.disable();
			if(tray_u.isPressed()){
				tray.moveUp();
			}
			if(tray_d.isPressed()){
				tray.moveDown();
			}
		}
		if(!tray.disa){
			tray.keepState();
		}

		if(out3.changedToPressed()){
			tray.setState(2);
		}
		if(out2.changedToPressed()){
			tray.setState(1);
		}
		if(out1.changedToPressed()){
			tray.setState(0);
		}


		pros::delay(20);
	}
}
