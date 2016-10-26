#include "System.h"
#include <iostream>

#ifndef MOVE
#define MOVE

void mov_cmd() {
  // std::cout << "Args1 = " << System.getArg1().getValue() << std::endl;
  // std::cout << "Args2 = " << System.getArg2().getValue() << std::endl
  System.setVar(System.getArg2().getValue(), System.getArg1().getValue());
}
#endif
