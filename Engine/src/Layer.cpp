#include "../headers/Layer.h"

Layer::Layer(Renderer2D* renderer, Shader* shader, mat4 projectionMatrix)
: Renderer(renderer), m_Shader(shader), ProjectionMatrix(projectionMatrix)
 {
	m_Shader->enable();
	m_Shader->setUniformMat4("pr_matrix", ProjectionMatrix);
	m_SHader->disable();
}


Layer::~Layer() {
	delete m_Shader;
	delete Renderer;

	for (int i=0; i<Renderables.size(); i++) {
		delete Renderables[i];
	}
}


void Layer::add(Renderable2D* renderable) {
	Renderables.push_back(renderable);
}

void Layer::render() {
	m_Shader->enable();
	
	for(const Renderable2D* renderable: Renderable) {
		m_Renderer->submit(renderable);
	}	

	Renderer->flush();
	m_SHader->disable();
}


