#include <iostream>

#ifndef VaV
#define VaV

class tvar {
private:
  int val;
  int ID;

public:
  tvar(int id, int value) {
    ID = id;
    val = value;
  }
  int getValue() { return val; }
  void setValue(int i) {
    // std::cout << "[ VAV ]:[ VAL ]:[ SET ] " << ID << " = " << i <<
    // std::endl;
    val = i;
  }
  int getID() { return ID; }
};

#endif
