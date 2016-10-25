#include "System.h"
#include <iostream>

#ifndef add
#define add
void add_cmd() {
  System.setAddVar(System.getArg2().getValue(),
                   System.getVar(System.getArg1().getValue()).getValue());
}
#endif
