sudo g++ -std=c++11 main.cpp src/BatchRenderer2D.cpp src/static_sprite.cpp src/sprite.cpp src/Simple2DRenderer.cpp src/Buffer.cpp src/VertexArray.cpp src/IndexBuffer.cpp src/Window.cpp src/vect.cpp src/matrix.cpp src/vec2.cpp src/vec3.cpp src/vec4.cpp src/mat4.cpp src/Shader.cpp -o main -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor -lGL -lGLEW

sudo ./main
