#include "stdafx.h"

#ifndef COMMAND_H
#define COMMAND_H

class Command {
private:
  void (*fooFunc)();
  int ID;

public:
  Command(int id, void (*foo)()) {
    ID = id;
    fooFunc = foo;
  }

  void setFunction() {}

  void runFunction() { fooFunc(); }

  int getName() { return ID; }

  void setName(int i) { ID = i; }
};

#endif
