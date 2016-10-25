#include "System.h"
#include "stdafx.h"
#include <iostream>

#ifndef OUTPUT_STRING_H
#define OUTPUT_STRING_H

void output_string_cmd() {
  /*if (System.getArg2().getValue() == System.getRx().getValue()) {
    std::cout << (char)System.getRx().getValue();
  } else if (System.getArg2().getValue() == System.getRy().getValue()) {
    std::cout << (char)System.getRy().getValue();
  } else if (System.getArg2().getValue() == System.getRz().getValue()) {
    std::cout << (char)System.getRz().getValue();
  } else {
    std::cout << "[ TBI ]:[ OUT_STR ]:[ NOTFOUND:"
              << System.getArg2().getValue()
              << " ] Konnte die Variable nicht finden!" << std::endl;
  }*/

  if (System.getVar(System.getArg2().getValue()).getID() == -23) {
    std::cout << "[ TBI ]:[ OUT_STR ]:[ NOTFOUND:"
              << System.getArg2().getValue() << "="
              << System.getVar(System.getArg2().getID()).getID()
              << " ] Can't find the cell!" << std::endl;
  } else {
    std::cout << (char)System.getVar(System.getArg2().getValue()).getValue();
  }
}

#endif
