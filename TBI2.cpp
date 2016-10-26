#include "Parser.h"
#include "stdafx.h"
#include <cstring>
#include <iostream>
#include <string>

// COMMANDS
#include "Init.h"
#include "Output.h"
#include "System.h"

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
  System.init();

  System.addNypp5Code("{main}");
  System.addNypp5Code("   defi RXX, [n];");
  System.addNypp5Code("   defi RYX, [n];");
  System.addNypp5Code("   defi RZX, [n];");
  System.addNypp5Code("   defs STMP, [n];");

  if (argc == 2) {
    p.executeFile(args[1]);
  } else if (argc == 3) {
    if (strcmp("-nc", args[1]) == 0) {
      System.setNC(true);
      p.executeFile(args[2]);

      std::string name;
      std::cout << "Ny++5 Output-File-Name? >> ";
      std::cin >> name;
      std::fstream datei(name, std::ios::out);

      for (int i = 0; i < System.getNypp5Code().size(); i++) {
        datei << System.getNypp5Code()[i] << std::endl;
      }
    }
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
