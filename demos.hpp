// demos.hpp
//
// This file contains an index of all demos available to the launcher
// implemented in main.cpp.

#pragma once

#define DECLARE_DEMO(ns) \
  namespace ns {         \
  int main();            \
  }

DECLARE_DEMO(sanity_check);
DECLARE_DEMO(context_creation);

#define DEMO_ENTRY(ns) \
  { #ns, ns::main }

// kDemos is the actual list of demo names and their entry points.
const std::vector<std::pair<std::string, std::function<int(void)>>> kDemos = {
    DEMO_ENTRY(sanity_check),
    DEMO_ENTRY(context_creation),
};
