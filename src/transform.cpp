#include "transform.h"
#include <glm/gtc/matrix_transform.hpp>
#include <stdio.h>

namespace ObjView
{

Transform::Transform(glm::vec3 position, glm::quat rotation, glm::vec3 scale) :
	m_position(position),
	m_rotation(glm::normalize(rotation)),
	m_scale(scale)
{
	calculateMatrix();
}

Transform::Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) :
	m_position(position),
	m_scale(scale)
{
	setRotation(rotation);
	calculateMatrix();
}
	
glm::mat4 Transform::matrix() const
{
	return m_matrix;
}

void Transform::setPosition(glm::vec3 position)
{
	m_position = position;
	calculateMatrix();
}

void Transform::translate(glm::vec3 vector)
{
	// TODO: Translation by matrix multiplication without matrix recalculation.
	m_position += vector;
	calculateMatrix();
}

void Transform::translate(float x, float y, float z)
{
	translate(glm::vec3(x, y, z));
}

glm::vec3 Transform::position() const
{
	return m_position;
}

void Transform::setRotation(glm::quat rotation)
{
	m_rotation = glm::normalize(rotation);
	calculateMatrix();
}

void Transform::setRotation(glm::vec3 rotation)
{
	setRotation(eulerToQuaternion(rotation));
}

void Transform::rotate(glm::quat quaternion)
{
	quaternion = glm::normalize(quaternion);
	m_rotation *= quaternion;
}

void Transform::rotate(float x, float y, float z, float w)
{
	rotate(glm::normalize(glm::quat(w, x, y, z)));
}

void Transform::rotate(glm::vec3 euler)
{
	rotate(eulerToQuaternion(euler));
}

void Transform::rotate(float x, float y, float z)
{
	rotate(eulerToQuaternion(glm::vec3(x, y, z)));
}

glm::quat Transform::rotation() const
{
	return m_rotation;
}

glm::vec3 Transform::eulerRotation() const
{
	return quaternionToEuler(m_rotation);
}

glm::quat Transform::eulerToQuaternion(glm::vec3 euler) const
{
	return glm::quat(euler);
}

glm::vec3 Transform::quaternionToEuler(glm::quat quaternion) const
{
	return glm::eulerAngles(quaternion);
}

void Transform::setScale(glm::vec3 scale)
{
	m_scale = scale;
	calculateMatrix();
}

void Transform::setScale(float x, float y, float z)
{
	setScale(glm::vec3(x, y, z));
}

glm::vec3 Transform::scale() const
{
	return m_scale;
}

void Transform::calculateMatrix()
{
	m_matrix = glm::mat4(1.0);
	m_matrix *= glm::mat4_cast(m_rotation);
	m_matrix = glm::scale(m_matrix, m_scale);
	m_matrix[3][0] = m_position.x;
	m_matrix[3][1] = m_position.y;
	m_matrix[3][2] = m_position.z;
}

}
