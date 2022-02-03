#include "headers/main.h"

using namespace std;

int main(void) {
	
	//string file = read_file("main.cpp");
	//cout << file << endl;
	
	Window window("ExampleName", 960, 540);		
	//glClearColor(0.0f, 1.0f, 1.0f, 1.0f);


	GLfloat vertices[] = {
		0, 0, 0,	 
		8, 0, 0,	
		0, 3, 0,	
		0, 3, 0,	 
		8, 3, 0,	
		8, 0, 0	
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); //index, size, type, normalised, stride 
	glEnableVertexAttribArray(0);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	//shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4, 4, 0)));
	//shader.setUniformMat4("ml_matrix", mat4::translation(vec3(2, 2, 0)) * mat4::rotation(30.0f, vec3(0, 0, 1)));

	shader.setUniform2f("light_pos", vec2(8.0f, 4.5f));
	shader.setUniform4f("colour", vec4(0.2f, 0.3f, 0.8f, 1.0f));

	while (!window.closed()) {
		window.clear();
	
		//if (window.isKeyPressed(GLFW_KEY_A)) cout << "Pressed" << endl; // key pressed
		//if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT)) cout << "Pressed" << endl; // mouse clicked
		/*double x, y;
		window.getMousePosition(x, y);
		cout << "x = " << x << ", y = " << y << endl; // position of mouse */ 


		glDrawArrays(GL_TRIANGLES, 0, 6);

		window.update();
	}

	return 0;
}
