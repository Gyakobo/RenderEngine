#include "../headers/static_sprite.h"

static_sprite::static_sprite(float x, float y, float width, float height, const vec4& color, Shader& shader) 
: Renderable2D(vec3(x, y, 0), vec2(width, height), color), m_Shader(shader)
{
	vertexArray = new VertexArray();                                               	
	GLfloat vertices[] = {
		0, 0, 0,
		0, height, 0,
		width, height, 0,
		width, 0, 0
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

static_sprite::~static_sprite() {
	delete vertexArray;
	delete indexBuffer;
}



