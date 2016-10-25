#include "Add.h"
#include "Command.h"
#include "DD.h"
#include "Div.h"
#include "Inp.h"
#include "Move.h"
#include "Mul.h"
#include "OutString.h"
#include "Output.h"
#include "Sub.h"
#include "stdafx.h"

#ifndef INIT_H
#define INIT_H

class Init {
private:
public:
  Parser initCommands(Parser p) {
    Command out = Command(4, output_cmd);
    Command outs = Command(5, output_string_cmd);
    Command mov = Command(6, mov_cmd);

    Command add_ = Command(7, add_cmd);
    Command mul_ = Command(8, mul_cmd);
    Command div1_ = Command(9, div_cmd);
    Command sub_ = Command(12, sub_cmd);

    Command inp_ = Command(10, inp_cmd);
    Command dd_ = Command(11, dd_cmd);

    p.addCommand(out);
    p.addCommand(outs);
    p.addCommand(mov);

    p.addCommand(add_);
    p.addCommand(mul_);
    p.addCommand(div1_);

    p.addCommand(inp_);
    p.addCommand(dd_);
    return p;
  }
};

#endif
