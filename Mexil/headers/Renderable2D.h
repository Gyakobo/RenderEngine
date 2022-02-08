#ifndef RENDERABLE2D_H
#define RENDERABLE2D_H

#include <iostream>

#include "Buffer.h" 
#include "VertexArray.h" 
#include "IndexBuffer.h" 

//#include "Renderer2D.h"

#include "vec2.h" 
#include "vec3.h" 
#include "vec4.h" 
#include "mat4.h"

#include "Shader.h" 

using namespace std;

struct VertexData {
	vec3 vertices;
	vec4 color;
};

class Renderable2D {
protected:
	vec3 Position;
	vec2 Size;
	vec4 Color;

public:	
	Renderable2D(vec3 position, vec2 size, vec4 color) 
	: Position(position), Size(size), Color(color) {}

	virtual ~Renderable2D() {}

	inline const vec3& getPosition() const { return Position; }
	inline const vec2& getSize() const { return Size; }
	inline const vec4& getColor() const { return Color; }

};

#endif
