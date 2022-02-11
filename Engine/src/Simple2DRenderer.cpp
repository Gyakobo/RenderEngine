#include "../headers/Simple2DRenderer.h"

void Simple2DRenderer::submit(const Renderable2D* renderable) {
	RenderQueue.push_back((static_sprite*) renderable);
}

void Simple2DRenderer::flush() 	{
	while(!RenderQueue.empty()) {
		const static_sprite* sprite = RenderQueue.front();
		sprite->getVAO()->bind();	
		sprite->getIBO()->bind();

		sprite->getShader().setUniformMat4("ml_matrix", mat4::translation(sprite->getPosition()));
		glDrawElements(GL_TRIANGLES, sprite->getIBO()->getCount(), GL_UNSIGNED_SHORT, nullptr);
	
		sprite->getIBO()->unbind();
		sprite->getVAO()->unbind();	

		RenderQueue.pop_front();
	}
}

