#include "scene.h"
#include <stdio.h>

namespace ObjView
{

Scene::Scene() :
	m_current_camera(nullptr)
{
}

void Scene::update()
{
	for (auto obj_it = m_objects.begin(); obj_it != m_objects.end(); obj_it++)
	{
		(*obj_it)->update();
	}
}

void Scene::clear()
{
	m_current_camera = nullptr;
	m_cameras.clear();
	m_objects.clear();
}

void Scene::addObject(std::shared_ptr<Object> object)
{
	m_objects.push_back(std::move(object));
}
/*
void Scene::removeObject(Object* object)
{
	auto obj_it = findObject(object);
	
	if (obj_it != m_objects.end())
	{
		m_objects.erase(obj_it);
	}
}
*/
std::vector<std::shared_ptr<Object>> Scene::getObjects() const
{
	return m_objects;
}

/*
std::vector<Object*>::const_iterator Scene::findObject(Object* object) const
{
	std::vector<Object*>::const_iterator obj_it;
	
	for (obj_it = m_objects.begin(); obj_it != m_objects.end(); obj_it++)
	{
		if ((*obj_it) == object)
		{
			break;
		}
	}
	
	return obj_it;
}
*/
void Scene::addCamera(std::shared_ptr<Camera> camera)
{
	
}

/*
void Scene::removeCamera(Camera* camera)
{
	
}

std::vector<Camera*> Scene::getCameras() const
{
	return m_cameras;
}
*/
void Scene::makeCameraCurrent(Camera* camera)
{
	m_current_camera = camera;
}

const Camera* Scene::getCurrentCamera() const
{
	return m_current_camera;
}

}
