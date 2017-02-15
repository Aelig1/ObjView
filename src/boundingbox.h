#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include "mesh.h"
#include "transform.h"

namespace ObjView
{

class BoundingBox
{
public:
	BoundingBox();
	BoundingBox(Mesh* mesh, Transform* transform);

	Mesh getAsMesh() const;
	void update(Mesh* mesh, Transform* transform);


private:
	float left, right, top, bottom, front, back;

};

}

#endif // BOUNDINGBOX_H