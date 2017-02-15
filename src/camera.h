#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

namespace ObjView
{

class Camera
{
public:
	Camera();
	Camera(bool perspective, float fov, float near, float far);

	void setPerspective(bool status);
	bool isPerspective() const;
	void setFOV(float fov);
	float getFOV() const;
	void setNear(float near);
	float getNear() const;
	void setFar(float far);
	float getFar() const;

private:
	glm::mat4 m_matrix;
	bool m_perspective;
	float m_fov;
	float m_near;
	float m_far;

};

}

#endif // CAMERA_H