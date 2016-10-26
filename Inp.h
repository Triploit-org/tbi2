#include "System.h"

#ifndef inp
#define inp
void inp_cmd() {
  int tmp;

  if (!System.isNC())
    std::cin >> tmp;

  System.setVar(3, tmp);
  System.addNypp5Code("   inp RXX;");
}
#endif
