sudo g++ -std=c++11 main.cpp src/Window.cpp src/vect.cpp src/matrix.cpp src/vec2.cpp src/vec3.cpp src/vec4.cpp src/mat4.cpp src/Shader.cpp -o main -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor -lGL -lGLEW

sudo ./main
