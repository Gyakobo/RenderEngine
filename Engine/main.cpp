#include "headers/main.h"

using namespace std;

int main(void) {
	//string file = read_file("main.cpp");
	//cout << file << endl;
	
	Window window("Mexil", 960, 540);		

 
	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);



	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	//shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4, 3, 0)));
	//shader.setUniformMat4("ml_matrix", mat4::translation(vec3(2, 2, 0)) * mat4::rotation(30.0f, vec3(0, 0, 1)));

	srand(time(NULL));

	vector<Renderable2D*> sprites;
	BatchRenderer2D renderer;

#if 1 	
	for(float y=0; y<9.0f; y+=0.05f) {
		for(float x=0; x<16.0f; x+=0.05f) {
			sprites.push_back(new Sprite(x, y, 0.05f, 0.05f, vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
		}
	}
#else
	sprites.push_back(new Sprite(1, 1, 1, 1, vec4(1, 0, 1, 1)));
	

#endif

	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
	shader.setUniform4f("colour", vec4(0.2f, 0.3f, 0.8f, 1.0f));


	cout << "Numb of sprites = " << sprites.size() << endl;

	float m_x = 0.0f;

	while (!window.closed()) {
		window.clear();

		double x, y;
	
		//if (window.isKeyPressed(GLFW_KEY_A)) cout << "Pressed" << endl; // key pressed
		//if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT)) cout << "Pressed" << endl; // mouse clicked
		/*double x, y;
		window.getMousePosition(x, y);
		cout << "x = " << x << ", y = " << y << endl; // position of mouse */ 

		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / window.getWidth()), (float)(9.0f - y * 9.0f / window.getHeight())));

		if (window.isKeyPressed(GLFW_KEY_RIGHT)) {
			m_x+=0.2f; 
			shader.setUniformMat4("ml_matrix", mat4::translation(vec3(m_x, 0, 0)));
		}
		if (window.isKeyPressed(GLFW_KEY_LEFT)) {
			m_x-=0.2f; 
			shader.setUniformMat4("ml_matrix", mat4::translation(vec3(m_x, 0, 0)));
		}
		
		renderer.begin();

		for (int i=0; i < sprites.size(); i++) {
			renderer.submit(sprites[i]);
		}

		renderer.end();		
		renderer.flush();

		window.update();
	}

	return 0;
}




