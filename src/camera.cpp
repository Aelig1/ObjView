#include "camera.h"

namespace ObjView
{

Camera::Camera() :
	Camera(false, 1, 0, 1)
{
}

Camera::Camera(bool perspective, float fov, float near, float far) :
	m_perspective(perspective),
	m_fov(fov),
	m_near(near),
	m_far(far)
{
}

}
