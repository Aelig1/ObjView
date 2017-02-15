#include "renderer.h"
#include "transform.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#ifdef _WIN32
#include <windows.h>
#endif

#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>

namespace ObjView
{

Renderer::Renderer()
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);
}

void Renderer::renderScene(Scene* scene)
{
	// Camera
	//glm::mat4 projection = glm::perspective(glm::radians(90.0f), 16.0f/9.0f, 0.01f, 10.0f);
	//glm::mat4 ortho = glm::ortho(-5, 5, -5, 5, -5, 5);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0f, 4.0f/3.0f, 0.01f, 100.0f);
	gluLookAt(0, 0, -5, 0, 0, 0, 0, 1, 0);
	//glLoadMatrixf(&ortho[0][0]);
	
	// TODO: Cull objects by their bounding box and camera frustum.
	std::vector<std::shared_ptr<Object>> objects = scene->getObjects();
	for (auto object = objects.begin(); object != objects.end(); object++)
	{
		renderObject(object->get());
	}
}

void Renderer::renderObject(Object* object)
{
	Mesh* mesh = object->getMesh().get();
	if (mesh == nullptr)
	{
		// No mesh
		return;
	}

	auto p = mesh->vertices.begin();
	if (p == mesh->vertices.end())
	{
		// Mesh has no verties
		return;
	}
	
	glm::mat4 transform = object->getTransform().matrix();
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glLoadMatrixf(&transform[0][0]);
	
	glBegin(GL_LINES);
	while (true)
	{
		glVertex3f(p->x, p->y, p->z);
		if (++p == mesh->vertices.end())
		{
			p = mesh->vertices.begin();
			glVertex3f(p->x, p->y, p->z);
			break;
		}
		glVertex3f(p->x, p->y, p->z);
	}
	glEnd();
}

void Renderer::clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

}
