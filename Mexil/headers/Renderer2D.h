#ifndef RENDERER2D_H
#define RENDERER2D_H

#include <iostream>
#include <GL/glew.h>

#include "Renderable2D.h"

using namespace std;

class Renderer2D {
protected:
	virtual void submit(const Renderable2D* renderable) = 0;
	virtual void flush() = 0;
};

#endif
