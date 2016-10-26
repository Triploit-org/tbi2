#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
#include <vector>

#include "Command.h"
#include "System.h"

#ifndef PARSER_H
#define PARSER_H

class Parser {
private:
  std::string txt;
  int tcmd;
  std::vector<Command> commands;
  std::vector<std::string> input_bin;
  std::vector<int> decs;
  void filexe(const char *f) { executeFile(f); }

public:
  void save() {
    std::string name;
    std::cout << "Filename? >> ";
    std::cin >> name;
    std::fstream datei(name, std::ios::out);

    for (int i = 0; i < input_bin.size(); i++) {
      datei << input_bin[i] << std::endl;
    }
  }

  void saveAndExit() {
    save();
    exit(0);
  }

  void addCommand(Command c) { commands.push_back(c); }

  int parseBinaryString(std::string s) {
    int num;
    int bit;
    int bim;
    num = 0;
    int i2 = 0;

    // for (int i = 0; i < s.size(); i++) {
    for (int i = s.size() - 1; i >= 0; i--) {
      // std::cout << "[ P ] " << s[i] << std::endl;
      if (s[i] != '0' && s[i] != '1' && s[i] != '@') {

        if (s[i] == 'i') {
          std::cout << "RXX " << System.getRx().getValue() << std::endl;
          std::cout << "RYX " << System.getRy().getValue() << std::endl;
          std::cout << "RZX " << System.getRz().getValue() << std::endl;
          return 0;
        }

        if (s == "wd") {
          // if (s[i] == 'w' && s[i + 1] == 'd') {
          for (int j = 0; j < decs.size(); j++) {
            std::cout << decs[j] << std::endl;
          }
          return 0;
        }

        if (s[i] == 'c') {
          input_bin.clear();
          decs.clear();

          System.getArg1().setValue(0);
          System.getArg2().setValue(0);
          return 0;
        }

        if (s[i] == 'w') {
          for (int j = 0; j < input_bin.size(); j++) {
            std::cout << input_bin[j] << std::endl;
          }
          return 0;
        }

        if (s[i] == 'l') {
          s = s.substr(2, s.size() - 1);
          filexe(s.c_str());
          return 0;
        }

        if (s[i] == 'q') {
          std::string in;
          while (in != "n" && in != "y") {
            std::cout << "Would you like to save? y/n: ";
            std::cin >> in;

            if (in == "n")
              exit(0);
            else if (in == "y")
              saveAndExit();
            else
              std::cout << "[ TBI ]:[ SAVE ]:[ INVALID_INPUT ] That's the "
                           "wrong answer!"
                        << std::endl;
          }
        }

        std::cout << "[ TBI ]:[ PARSER ]:[ EX=INVALID_BINARY_NUMBER[" << i
                  << "]:" << s[i] << " ] The binary Command \"" << s
                  << "\" contains invalid characters." << std::endl;
        return 0;
      } else {

        if (s[i] == '@') {
          if (!System.isNC())
            std::cout << std::endl;

          System.addNypp5Code("@");
          continue;
        }

        std::string c;
        c = s[i];

        bim = pow(2, i2);
        bit = std::stoi(c) * bim;

        // std::cout << "[ P ] " << s[i] << " * " << bim << " ==> " << bit
        //<< std::endl;
        num = num + bit;
      }

      i2++;
    }

    input_bin.push_back(s);
    decs.push_back(num);
    return num;
  }

  void printCommands() {
    for (int i = 0; i < commands.size(); i++) {
      std::cout << "[ COMMAND:" << i << " ] ID=" << commands[i].getName()
                << std::endl;
    }
  }

  void execute(int id) {
    int argc = 0;
    for (int i = 0; i < commands.size(); i++) {
      if (commands[i].getName() == id) {
        commands[i].runFunction();
      } else {
        argc++;
        if (argc == (commands.size()) && id != commands[i].getName()) {
          System.setArg1(System.getArg2().getValue());
          System.setArg2(id);
        }
        // std::cout << argc << "/" << commands.size() << std::endl;
      }
    }
  }

  void executeFile(const char *f) {
    std::fstream datei(f, std::ios::in);
    std::string zeile;
    while (getline(datei, zeile, '\n')) {
      std::string input = zeile;
      std::istringstream ss(input);
      std::string token;

      while (std::getline(ss, token, ' ')) {
        execute(parseBinaryString(token));
      }
    }
  }
};

#endif
