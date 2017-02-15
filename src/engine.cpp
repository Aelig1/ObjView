#include "engine.h"
#include <memory>

namespace ObjView
{

Engine::Engine() :
	m_window(nullptr)
{
}

void Engine::setWindow(Window* window)
{
	m_window = window;
}

void Engine::startMainLoop()
{
	if (!m_window)
	{
		return;
	}
	
	m_scene.addObject(m_object_factory.create("resources/icosphere.obj"));

	while(!m_window->shouldClose())
	{
		m_scene.update();
		
		// TODO: Rerender not needed if nothing changes in scene
		m_renderer.clear();
		m_renderer.renderScene(&m_scene);
		
		//////// poista
		glBegin(GL_POINTS);
		glVertex2f(0,0);
		glEnd();
		//////// poista
		
		m_window->swapBuffers();
		m_window->pollEvents();
	}
}

}
