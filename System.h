#include "VaV.h"
#include <iostream>

#ifndef SYS_H
#define SYS_H
class System {
private:
  tvar rxx = tvar(3, 0);
  tvar ryx = tvar(1, 0);
  tvar rzx = tvar(2, 0);

  tvar arg1 = tvar(9991, 0);
  tvar arg2 = tvar(9992, 0);

public:
  void setRx(int i) { rxx.setValue(i); }
  void setRy(int i) { ryx.setValue(i); }
  void setRz(int i) { rzx.setValue(i); }

  tvar getRx() { return rxx; }
  tvar getRy() { return ryx; }
  tvar getRz() { return rzx; }

  void setArg1(int i) { arg1.setValue(i); }
  void setArg2(int i) { arg2.setValue(i); }

  tvar getArg1() { return arg1; }
  tvar getArg2() { return arg2; }

  tvar getVar(int ID) {
    // std::cout << "{SEARCH " << ID << "}" << std::endl;
    if (ID == rxx.getID()) {
      return rxx;
    } else if (ID == ryx.getID()) {
      return ryx;
    } else if (ID == rzx.getID()) {
      return rzx;
    } else {
      return tvar(ID, ID);
    }
  }

  int setVar(int ID, int VAL) {
    /*if (VAL == rxx.getID()) {
      VAL = rxx.getValue();
    } else if (VAL == ryx.getID()) {
      VAL = ryx.getValue();
    } else if (VAL == rzx.getID()) {
      VAL = rzx.getValue();
    }*/

    if (ID == rxx.getID()) {
      rxx.setValue(VAL);
    } else if (ID == ryx.getID()) {
      ryx.setValue(VAL);
    } else if (ID == rzx.getID()) {
      rzx.setValue(VAL);
    } else {
      std::cout << "[ TBI ]:[ SYS ]:[ VAR ] Cell with ID " << ID
                << " not found!" << std::endl;
    }
  }

  int setAddVar(int ID, int VAL) {
    /*if (VAL == rxx.getID()) {
      VAL = rxx.getValue();
    } else if (VAL == ryx.getID()) {
      VAL = ryx.getValue();
    } else if (VAL == rzx.getID()) {
      VAL = rzx.getValue();
    }*/

    if (ID == rxx.getID()) {
      rxx.setValue(rxx.getValue() + VAL);
    } else if (ID == ryx.getID()) {
      ryx.setValue(ryx.getValue() + VAL);
    } else if (ID == rzx.getID()) {
      rzx.setValue(rzx.getValue() + VAL);
    } else {
      std::cout << "[ TBI ]:[ SYS ]:[ VAR ] Cell with ID " << ID
                << " not found!" << std::endl;
    }
  }

  int setDivVar(int ID, int VAL) {
    /*if (VAL == rxx.getID()) {
      VAL = rxx.getValue();
    } else if (VAL == ryx.getID()) {
      VAL = ryx.getValue();
    } else if (VAL == rzx.getID()) {
      VAL = rzx.getValue();
    }*/

    if (ID == rxx.getID()) {
      rxx.setValue(rxx.getValue() / VAL);
    } else if (ID == ryx.getID()) {
      ryx.setValue(ryx.getValue() / VAL);
    } else if (ID == rzx.getID()) {
      rzx.setValue(rzx.getValue() / VAL);
    } else {
      std::cout << "[ TBI ]:[ SYS ]:[ VAR ] Cell with ID " << ID
                << " not found!" << std::endl;
    }
  }

  int setSubVar(int ID, int VAL) {
    /*if (VAL == rxx.getID()) {
      VAL = rxx.getValue();
    } else if (VAL == ryx.getID()) {
      VAL = ryx.getValue();
    } else if (VAL == rzx.getID()) {
      VAL = rzx.getValue();
    }*/

    if (ID == rxx.getID()) {
      rxx.setValue(rxx.getValue() - VAL);
    } else if (ID == ryx.getID()) {
      ryx.setValue(ryx.getValue() - VAL);
    } else if (ID == rzx.getID()) {
      rzx.setValue(rzx.getValue() - VAL);
    } else {
      std::cout << "[ TBI ]:[ SYS ]:[ VAR ] Cell with ID " << ID
                << " not found!" << std::endl;
    }
  }

  int setMulVar(int ID, int VAL) {
    /*if (VAL == rxx.getID()) {
      VAL = rxx.getValue();
    } else if (VAL == ryx.getID()) {
      VAL = ryx.getValue();
    } else if (VAL == rzx.getID()) {
      VAL = rzx.getValue();
    }*/

    if (ID == rxx.getID()) {
      rxx.setValue(rxx.getValue() * VAL);
    } else if (ID == ryx.getID()) {
      ryx.setValue(ryx.getValue() * VAL);
    } else if (ID == rzx.getID()) {
      rzx.setValue(rzx.getValue() * VAL);
    } else {
      std::cout << "[ TBI ]:[ SYS ]:[ VAR ] Cell with ID " << ID
                << " not found!" << std::endl;
    }
  }
} System;
#endif
