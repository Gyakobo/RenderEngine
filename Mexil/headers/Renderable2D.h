#ifndef RENDERABLE2D_H
#define RENDERABLE2D_H

#include <iostream>

#include "Buffer.h" 
#include "VertexArray.h" 
#include "IndexBuffer.h" 

#include "Renderable2D.h"
#include "Renderer2d.h"

#include "vec2.h" 
#include "vec3.h" 
#include "vec4.h" 
#include "mat4.h"

#include "Shader.h" 

using namespace std;

class Renderable2D {
protected:
	vec3 Position;
	vec2 Size;
	vec4 Color;

	Shader& m_Shader;

	VertexArray* vertexArray;
	IndexBuffer* indexBuffer; 

public:	
	Renderable2D(vec3 position, vec2 size, vec4 color, Shader& shader) 
	: Position(position), Size(size), Color(color), m_Shader(shader)
	{
		vertexArray = new VertexArray();

		GLfloat vertices[] = {
			0, 0, 0,
			0, size.y, 0,
			size.x, size.y, 0,
			size.x, 0, 0
		};

		GLfloat colors[] = {
			color.x, color.y, color.z, color.w,
			color.x, color.y, color.z, color.w,
			color.x, color.y, color.z, color.w,
			color.x, color.y, color.z, color.w
		};

		vertexArray->addBuffer(new Buffer(vertices, 12, 3), 0);
		vertexArray->addBuffer(new Buffer(colors, 16, 4), 1);
	
		GLushort indices[] = { 0, 1, 2, 2, 3, 0};
		indexBuffer = new IndexBuffer(indices, 6);			
	}

	~Renderable2D() {
		delete vertexArray;
		delete indexBuffer;
	}

public:

	inline const VertexArray* getVAO() const { return vertexArray; } // Gets Vertex Array
	inline const IndexBuffer* getIBO() const { return indexBuffer; } // Gets Index Buffer

	inline Shader& getShader() const { return m_Shader; }

	inline const vec3& getPosition() const { return Position; }
	inline const vec2& getSize() const { return Size; }
	inline const vec4& getColor() const { return Color; }

};

#endif
