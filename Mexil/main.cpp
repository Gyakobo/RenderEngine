#include "headers/main.h"

using namespace std;

int main(void) {
	//string file = read_file("main.cpp");
	//cout << file << endl;
	
	Window window("ExampleName", 960, 540);		

 
	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);



	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	//shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4, 3, 0)));
	//shader.setUniformMat4("ml_matrix", mat4::translation(vec3(2, 2, 0)) * mat4::rotation(30.0f, vec3(0, 0, 1)));




	static_sprite sprite(5, 5, 4, 4, vec4(1, 0, 1, 1), shader);	
	static_sprite sprite2(7, 1, 2, 3, vec4(0.5f, 0, 0.2f, 1), shader);	
	Simple2DRenderer renderer;



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

		renderer.submit(&sprite);
		renderer.submit(&sprite2);
		renderer.flush();

		window.update();
	}

	return 0;
}




