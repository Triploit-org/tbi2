#include "Parser.h"
#include "stdafx.h"
#include <iostream>
#include <string>

// COMMANDS
#include "Init.h"
#include "Output.h"

// argc 1 = Prog
// argc 2 = File

// args[0] = Prog
// args[1] = File

int main(int argc, char *args[]) {
  std::cout << "TBI2 Interpreter - V2_1.1a" << std::endl
            << "Rights reserved." << std::endl
            << std::endl;

  Parser p;
  std::string input;

  Init i;
  p = i.initCommands(p);

  if (argc == 2) {
    p.executeFile(args[1]);
  } else if (argc < 2) {
    while (true) {
      std::cout << "> ";
      std::getline(std::cin, input);

      p.execute(p.parseBinaryString(input));
    }
  } else {
    std::cout << "[ TBI ]:[ MAIN ]:[ ARGS ] Too many arguments!" << std::endl;
  }

  return 0;
}
