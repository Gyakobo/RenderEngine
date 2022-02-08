#ifndef MAIN_H
#define MAIN_H

// General Dependancies
#include <iostream>
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Texture and Meshes
//#include "../src/utils/fileutils.h" // Opens and Reads and can even write .txt files
#include "Shader.h"
#include "Buffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"

// Render Machine
#include "Renderer2D.h"
#include "Renderable2D.h"
#include "Simple2DRenderer.h"
#include "static_sprite.h"

// Window
#include "Window.h"

// Math
#include "vect.h"
#include "mat4.h"
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"

#endif
