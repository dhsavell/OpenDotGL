// 1. Context Creation
// See: https://open.gl/context#GLFW
//
// This application brings up a blank 800x600 window that can be closed with the
// escape key.
//
// If this all seems overly verbose, don't worry. The next few demos are less
// obsessively-commented as by then, the fundamentals will have been
// established, leaving us to focus on the primary topics.

// In our case, we'll be using GLEW to handle dynamic linking of OpenGL
// functionality. It's not used directly in this example but will be in the
// future.
#include <GL/glew.h>

// GLFW does the heavy lifting in terms of setting up a GL environment and
// performing some common tasks.
#include <GLFW/glfw3.h>

#include <iostream>

namespace context_creation {

// kWidth and kHeight our the width and height of our window-- fairly
// self-explanatory.
const int kWidth = 800;
const int kHeight = 600;

int main() {
  // glfwInit initializes the GLFW context for our use. This is a critical step,
  // as we won't be able to use any GLFW functions without it.
  glfwInit();

  // This block tells GLFW about the context we want to operate in. In order, we
  // tell GLFW that:
  //  - We want to work with OpenGL >= 3.2 (3 and 2 are the major and minor
  //    version numbers).
  //  - We want a context that "only supports the new core functionality," as
  //	the guide puts it.
  //  - Our OpenGL context should be forward-compatible.
  //  - Our window shouldn't be resizable (it will always be kWidth x kHeight).
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  // Here's where we actually create our window, given the context setup above.
  GLFWwindow* window =
      glfwCreateWindow(kWidth, kHeight, "Howdy!", nullptr, nullptr);

  // We also tell GLFW that this window is where the magic will be happening,
  // binding it to our context. All further operations will deal with this
  // window.
  glfwMakeContextCurrent(window);

  // Now that our context is all set up, we can initialize GLEW. We want to
  // enable "experimental" features in order to use modern OpenGL.
  glewExperimental = GL_TRUE;
  glewInit();

  // Here's a quick GLEW sanity check. We wouldn't be able to use glGenBuffers
  // if GLEW wasn't properly set up, since it does the dirty work of dynamically
  // linking the function.
  GLuint vertex_buffer;
  glGenBuffers(1, &vertex_buffer);
  std::cout << "Hello, GLEW! Here's a vertex buffer (which should just be 1): "
            << vertex_buffer << std::endl;

  // Next, we wenter a main loop. While the window has no reason to close, what
  // should we be doing with it?
  while (!glfwWindowShouldClose(window)) {
    // We start by swapping the "front" and "back" buffers. The OpenGL wiki
    // explains this concept well:
    // https://www.khronos.org/opengl/wiki/Default_Framebuffer#Double_buffering
    // In a nutshell, there's a "front" buffer which is what is displayed in the
    // window and a "back" buffer which the program renders to.
    glfwSwapBuffers(window);

    // glfwPollEvents checks for events like keyboard presses, which we use
    // below.
    glfwPollEvents();

    // When the escape key has been pressed, we should close the window. Note
    // that we don't just exit from here-- we want to give GLFW a chance to
    // clean up by running glfwTerminate at the end.
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      glfwSetWindowShouldClose(window, GL_TRUE);
    }
  }

  glfwTerminate();
  return 0;
}

}  // namespace context_creation