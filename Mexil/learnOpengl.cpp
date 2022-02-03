#include <iostream>
#include <GLFW/glfw3.h>

using namespace std;

int main() {
	GLFWwindow * window;

	if (glfwInit()) return -1;

	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES);
		
		
		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}



