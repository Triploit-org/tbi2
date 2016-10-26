#include "System.h"
#include <iostream>
#include <string>

#ifndef mul
#define mul
void mul_cmd() {
  System.setMulVar(System.getArg2().getValue(),
                   System.getVar(System.getArg1().getValue()).getValue());
}
#endif
