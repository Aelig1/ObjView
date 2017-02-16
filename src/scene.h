#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "object.h"
#include <vector>
#include <memory>

namespace ObjView
{

class Scene
{
public:
	Scene();
	
	void update();
	void clear();
	bool addObject(std::shared_ptr<Object> object);
	//void removeObject(Object* object);
	std::vector<std::shared_ptr<Object>> getObjects() const;
	//std::vector<Object*>::const_iterator findObject(Object* object) const;
	void addCamera(std::shared_ptr<Camera> camera);
	//void removeCamera(Camera* camera);
	//std::vector<Camera*> getCameras() const;
	void makeCameraCurrent(Camera* camera);
	const Camera* getCurrentCamera() const;

private:
	Camera* m_current_camera;
	std::vector<std::shared_ptr<Camera>> m_cameras;
	std::vector<std::shared_ptr<Object>> m_objects;

};

}

#endif // SCENE_H