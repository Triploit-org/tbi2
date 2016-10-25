#include "System.h"
#include <iostream>

#ifndef sub1
#define sub1
void sub_cmd() {
  System.setSubVar(System.getArg2().getValue(),
                   System.getVar(System.getArg1().getValue()).getValue());
}
#endif
