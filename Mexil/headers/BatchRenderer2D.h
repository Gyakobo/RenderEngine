#ifndef BATCHRENDERER2D_H
#define BATCHRENDERER2D_H

#include <iostream>
#include "Renderer2D.h"
#include "IndexBuffer.h"

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"

#define MAX_SPRITES	10000
#define VERTEX_SIZE 	sizeof(VertexData)
#define SPRITE_SIZE	VERTEX_SIZE * 4 
#define BUFFER_SIZE	SPRITE_SIZE * MAX_SPRITES
#define INDICES_SIZE	MAX_SPRITES * 6

#define SHADER_VERTEX_INDEX	0 
#define SHADER_COLOR_INDEX	1 

using namespace std;

class BatchRenderer2D : public Renderer2D {
private:
	GLuint VAO;
	GLuint VBO; // 60,000
	VertexData* m_Buffer;
	IndexBuffer* IBO;
	GLsizei IndexCount;

	void init();
public:
	BatchRenderer2D();
	~BatchRenderer2D();
	void begin();
	void submit(const Renderable2D* renderable) override;
	void end();

	void flush() override;
};

#endif




