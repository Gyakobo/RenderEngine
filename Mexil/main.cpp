#include "headers/main.h"

using namespace std;

int main(void) {
	//string file = read_file("main.cpp");
	//cout << file << endl;
	
	Window window("ExampleName", 960, 540);		

	GLfloat vertices[] = {
		0, 0, 0,	 
		0, 3, 0,	
		8, 3, 0,	
		8, 0, 0 
	};

	GLushort indices[] = {
		0, 1, 2,
		2, 3, 0
	};



	GLfloat colorsA[] = {
		1, 0, 1, 1,
		1, 0, 1, 1,
		1, 0, 1, 1,
		1, 0, 1, 1
	};
	GLfloat colorsB[] = {
		0.2f, 0.3f, 0.8f, 1,
		0.2f, 0.3f, 0.8f, 1,
		0.2f, 0.3f, 0.8f, 1,
		0.2f, 0.3f, 0.8f, 1
	};


	
	VertexArray	sprite1, sprite2; // Vertex Array Object
	IndexBuffer	ibo(indices, 6); // Index Buffer Object

	sprite1.addBuffer(new Buffer(vertices, 4*3, 3), 0); 
	sprite1.addBuffer(new Buffer(colorsA, 4*4, 4), 1);

	sprite2.addBuffer(new Buffer(vertices, 4*3, 3), 0); 
	sprite2.addBuffer(new Buffer(colorsB, 4*4, 4), 1); // The zero refers to the location=0 in "basic.vert"
 



	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);


	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	//shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4, 3, 0)));
	//shader.setUniformMat4("ml_matrix", mat4::translation(vec3(2, 2, 0)) * mat4::rotation(30.0f, vec3(0, 0, 1)));


	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
	shader.setUniform4f("colour", vec4(0.2f, 0.3f, 0.8f, 1.0f));





	while (!window.closed()) {
		window.clear();

		double x, y;
	
		//if (window.isKeyPressed(GLFW_KEY_A)) cout << "Pressed" << endl; // key pressed
		//if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT)) cout << "Pressed" << endl; // mouse clicked
		/*double x, y;
		window.getMousePosition(x, y);
		cout << "x = " << x << ", y = " << y << endl; // position of mouse */ 

		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));


		sprite1.bind();
		ibo.bind();
		shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4, 3, 0)));
		glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);
		ibo.bind();
		sprite1.unbind();
		
	
		sprite2.bind();
		ibo.bind();
		shader.setUniformMat4("ml_matrix", mat4::translation(vec3(0, 0, 0)));
		glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);
		ibo.bind();
		sprite2.unbind();

		window.update();
	}

	return 0;
}




