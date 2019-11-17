#pragma once
#include "main.h"
#include "okapi/api.hpp"

class Intake{
public:
  okapi::Motor* intake_l = nullptr;
  okapi::Motor* intake_r = nullptr;
  Intake(int,int);
  void moveUp();
  void moveDown();
  void stop();
};
