#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

int main() {
  if (!glfwInit()) {
    return -1;
  }

  GLFWwindow *window =
      glfwCreateWindow(800, 600, "Rabin Acharya - Triangle", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES); // GL_TRIANGELS
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0, 0.9f);
    glVertex2f(0.9f, -0.9f);
    glVertex2f(-0.9f, 0.9f);
    glEnd();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
