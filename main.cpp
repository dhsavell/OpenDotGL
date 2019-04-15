// main.cpp
//
// This file contains a barebones, general-purpose launcher for running any of
// the demos. They can be launched either interactively or from a command-line
// argument.
//
// To add/remove/edit demos, view the declarations in demos.hpp. This file
// needs no updating as demos change.

#include <cstdlib>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "demos.hpp"

int main(int argc, char* argv[]) {
  int selection = -1;

  if (argc > 1) {
    auto selected_demo = std::string(argv[1]);

    try {
      selection = std::stoi(std::string(selected_demo));
    } catch (std::exception) {
      selection = -1;
    }
  }

  while (selection == -1 || selection >= kDemos.size()) {
    for (unsigned int i = 0; i < kDemos.size(); i++) {
      std::cout << i << ": " << kDemos[i].first << std::endl;
    }

    std::cout << "> ";

    std::string line;
    std::getline(std::cin, line);

    try {
      selection = std::stoi(line);
    } catch (std::exception) {
      selection = -1;
    }

    std::cout << std::endl;
  }

  std::cout << "Running demo " << selection << ": " << kDemos[selection].first
            << std::endl
            << std::endl;

  return kDemos[selection].second();
}