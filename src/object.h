#ifndef OBJECT_H
#define OBJECT_H

#include "mesh.h"
#include "boundingbox.h"
#include "transform.h"
#include <memory>

namespace ObjView
{

class Object
{
public:
	Object();
	Object(std::shared_ptr<Mesh> mesh);
	Object(std::shared_ptr<Mesh> mesh, Transform transform);

	void update();
	void setMesh(std::shared_ptr<Mesh> mesh);
	std::shared_ptr<Mesh> getMesh() const;
	void setTransform(Transform transform);
	Transform getTransform() const;
	
private:
	//BoundingBox m_bounding_box;
	std::shared_ptr<Mesh> m_mesh;
	Transform m_transform;

};

}

#endif // OBJECT_H