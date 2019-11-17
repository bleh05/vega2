#include "main.h"
#include "Outtake.hpp"
#include "Intake.hpp"
#include "Arm.hpp"
using namespace::okapi;

extern okapi::ChassisScales scales;
std::shared_ptr<ChassisController> chassis;
std::shared_ptr<ChassisModel> model;
extern OuttakeT tray;
extern Arm arm;
extern Intake intake;
