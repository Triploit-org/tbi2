#include "System.h"
#include <iostream>
#include <string>

#ifndef div
#define div
void div_cmd() {
  System.setDivVar(System.getArg2().getValue(),
                   System.getVar(System.getArg1().getValue()).getValue());
}
#endif
