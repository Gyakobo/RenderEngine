#include "../headers/BatchRenderer2D.h"

BatchRenderer2D::BatchRenderer2D() {
	init();
}
BatchRenderer2D::~BatchRenderer2D() {
	delete IBO;
	glDeleteBuffers(1, &VBO);
}

void BatchRenderer2D::init() {
	glGenVertexArrays(1, &VAO);	
	glGenBuffers(1, &VBO);
	
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
	glEnableVertexAttribArray(SHADER_COLOR_INDEX);
	glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, VERTEX_SIZE, (const GLvoid*) 0);
	glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_FLOAT, GL_FALSE, VERTEX_SIZE, (const GLvoid*) (3 * sizeof(GLfloat)));
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	GLushort indices[INDICES_SIZE];
	
	int offset = 0;
	
	for(int i=0; i < INDICES_SIZE; i+=6) {
		indices[i] = offset;
		indices[i+1] = offset + 1;
		indices[i+2] = offset + 2;
		
		indices[i+3] = offset + 2;
		indices[i+4] = offset + 3;
		indices[i+5] = offset;

		offset += 4;
	}

	IBO = new IndexBuffer(indices, INDICES_SIZE);
	
	glBindVertexArray(0);
}



void BatchRenderer2D::begin() {
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	m_Buffer = (VertexData*) glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
} 



void BatchRenderer2D::submit(const Renderable2D* renderable) {
	const vec3& position	= renderable->getPosition();
	const vec2& size	= renderable->getSize();
	const vec4& color	= renderable->getColor();

	m_Buffer->vertex	= position;
	m_Buffer->color		= color;
	m_Buffer++;	

	m_Buffer->vertex	= vec3(position.x, position.y + size.y, position.z); 
	m_Buffer->color		= color;
	m_Buffer++;	

	m_Buffer->vertex	= vec3(position.x + size.x, position.y + size.y, position.z);
	m_Buffer->color		= color;
	m_Buffer++;	

	m_Buffer->vertex	= vec3(position.x + size.x, position.y, position.z);
	m_Buffer->color		= color;
	m_Buffer++;	
	
	IndexCount += 6;
}


void BatchRenderer2D::end() {
	glUnmapBuffer(GL_ARRAY_BUFFER);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}


void BatchRenderer2D::flush() {
	glBindVertexArray(VAO);
	IBO->bind();

	glDrawElements(GL_TRIANGLES, IndexCount, GL_UNSIGNED_SHORT, NULL);
	
	IBO->unbind();
	glBindVertexArray(0);

	IndexCount = 0;
}








