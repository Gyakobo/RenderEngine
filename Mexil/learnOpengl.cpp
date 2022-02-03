#include <iostream>
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

int main() {
	Window window;

	//if (glfwInit()) return -1;

	window = glfwCreateWindow(640, 480, "Hello World");

	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	while (!window.closed()) {
		window.clear();

		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
	
		glDrawArrays(GL_triangles, 0, 3);	
		
		window.update();
	}

	return 0;
}



