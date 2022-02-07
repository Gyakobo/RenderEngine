#include "../headers/BatchRenderer2D.h"

BatchRenderer2D::BatchRenderer2D() {
	init();
}
BatchRenderer2D::~BatchRenderer2D() {
	delete IBO;
	glDeleteBUffers(1, &VBO);
}

void BatchRenderer2D::init() {
	glGenVertexArrays(1, &VAO);	
	glGenBuffers(1, &VBO);
	
	glBIndVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
	glEnableVertexAttribArray(SHADER_COLOR_INDEX);
	glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, VERTEX_SIZE, (const GLvoid*) 0);
	glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_FLOAT, GL_FALSE, VERTEX_SIZE, (const GLvoid*) (3 * GL_FLOAT));
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	GLushort indices[INDICES_SIZE];
		
	for(int i=0; i < RENDERER_INDICES_SIZE; i++) {
		indices[i] = offset;
		indices[i+1] = offset + 1;
		indices[i+2] = offset + 2;
		
		indices[i+3] = offset + 2;
		indices[i+4] = offset + 3;
		indices[i+5] = offset + 0;

		offset += 4;
	}

	IBO = new IndexBuffer(indices, INDICES_SIZE);
	
	glBindVertexArray(0);
}


void BatchRenderer2D::submit(Renderable2D* renderable) {
		

}














