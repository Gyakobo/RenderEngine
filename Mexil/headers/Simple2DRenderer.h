#ifndef SIMPLE2DRENDERER_H
#define SIMPLE2DRENDERER_H

#include <iostream>
#include <deque>

#include "Renderer2D.h"

#include "mat4.h"

using namespace std;

class Simple2DRenderer : public Renderer2d {
private:
	deque<const Renderable2D*> RenderQueue;

public:
	void submit(const Renderable2D* renderable) override;
	void flush() override;
};

#endif
