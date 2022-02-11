#ifndef SPRITE_H
#define SPRITE_H

#include "Renderable2D.h"

class Sprite : public Renderable2D {
private:
public:	
	Sprite(float x, float y, float width, float height, const vec4& color);	
};

#endif
