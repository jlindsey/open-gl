#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <thread>
#include "config.h"

int main(void) {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", nullptr, nullptr);

  glfwMakeContextCurrent(window);

  glewExperimental = GL_TRUE;
  glewInit();

  GLuint verexBuffer;
  glGenBuffers(1, &verexBuffer);

  while(!glfwWindowShouldClose(window)) {
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();

  return 0;
}

