// 0. Sanity Check
// See: https://open.gl/context#GLFW
//
// This application simply tries to initialize and then terminate a GLFW
// context.

#include <GLFW/glfw3.h>
#include <iostream>
#include <thread>

int main() {
  // Initialize our GLFW context.
  glfwInit();

  // Do some "work."
  std::cout << "GLFW initialized! Terminating in 1 second..." << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << "Terminating GLFW. Goodbye!" << std::endl;

  // Clean up and terminate the context.
  glfwTerminate();
}
