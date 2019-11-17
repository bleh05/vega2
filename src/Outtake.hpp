#pragma once
#include "main.h"
#include "okapi/api.hpp"

class OuttakeT{
public:
  okapi::Motor* outtake=nullptr;
  OuttakeT(int);
  int encV [3]= {0,1820,6200};
  bool disa = false;
  int state=0;
  void disable();
  void enable();
  bool keepState();
  void moveDown();
  void moveUp();
  void stop();
  int getState();
  void setState(int st);
};
