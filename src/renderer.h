#ifndef RENDERER_H
#define RENDERER_H

#include "scene.h"
#include <memory>

namespace ObjView
{

class Renderer
{
public:
	Renderer();

	void renderScene(Scene* scene);
	void renderObject(Object* object);
	void clear();

private:
	
};

}

#endif // RENDERER_H