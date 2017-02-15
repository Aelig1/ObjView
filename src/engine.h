#ifndef ENGINE_H
#define ENGINE_H

#include "window.h"
#include "renderer.h"
#include "scene.h"
#include "objectfactory.h"

namespace ObjView
{

class Engine
{
public:
	Engine();

	void setWindow(Window* window);
	void startMainLoop();

private:
	Window* m_window;
	Renderer m_renderer;
	Scene m_scene;
	ObjectFactory m_object_factory;

};

}

#endif // ENGINE_H