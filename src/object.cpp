#include "object.h"

namespace ObjView
{

Object::Object() :
	m_mesh(nullptr)
{
}

Object::Object(std::shared_ptr<Mesh> mesh) :
	m_mesh(mesh)
{	
}

Object::Object(std::shared_ptr<Mesh> mesh, Transform transform) :
	m_mesh(mesh),
	m_transform(transform)
{
}

void Object::update()
{
	
}

void Object::setMesh(std::shared_ptr<Mesh> mesh)
{	
	m_mesh = mesh;
}

std::shared_ptr<Mesh> Object::getMesh() const
{
	return m_mesh;
}

void Object::setTransform(Transform transform)
{
	m_transform = transform;
}

Transform Object::getTransform() const
{
	return m_transform;
}

}
