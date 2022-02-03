#include <iostream>
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

int main() {
#if 0	
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
#endif

	int a=3, b=4;

	cout << a << " " << b << endl << "size(a) = " << sizeof(a) << ", size(b) = " << sizeof(b) << endl;

	int *p=&a, *q=&b;

	cout << p << " " << q << endl << "size(*p) = " << sizeof(*p) << ", size(*q) = " << sizeof(*q) << endl;
	cout << *p << " " << *q << endl;

	return 0;
}



