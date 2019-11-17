#pragma once
#include "main.h"
#include "okapi/api.hpp"

class Arm{
public:
  okapi::Motor* arm = nullptr;
  Arm(int);
  void moveUp();
  void moveDown();
  void stop();
};
