#ifndef STATIC_SPRITE_H
#define STATIC_SPRITE_H

#include <iostream>
#include "Renderable2D.h"
#include "vec4.h"

using namespace std;

class static_sprite : public Renderable2D {
private:
	Shader& m_Shader;
	VertexArray* vertexArray;
	IndexBuffer* indexBuffer;
public:
	static_sprite(float x, float y, float width, float height, const vec4& color, Shader& shader);
	~static_sprite();

	inline const VertexArray* getVAO() const { return vertexArray; } // Gets Vertex Array    
	inline const IndexBuffer* getIBO() const { return indexBuffer; } // Gets Index Buffer

	inline Shader& getShader() const { return m_Shader; }
};


#endif
