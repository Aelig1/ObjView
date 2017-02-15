#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace ObjView
{

class Transform
{
public:
	Transform(glm::vec3 position = glm::vec3(0, 0, 0),
			  glm::quat rotation = glm::quat(1, 0, 0, 0),
			  glm::vec3 scale = glm::vec3(1, 1, 1));
	Transform(glm::vec3 position, glm::vec3 rotation,
			  glm::vec3 scale = glm::vec3(1, 1, 1));
	
	glm::mat4 matrix() const;
	void setPosition(glm::vec3 position);
	void translate(glm::vec3 vector);
	void translate(float x, float y, float z);
	glm::vec3 position() const;
	void setRotation(glm::quat rotation);
	void setRotation(glm::vec3 rotation);
	void rotate(glm::quat quaternion);
	void rotate(float x, float y, float z, float w);
	void rotate(glm::vec3 euler);
	void rotate(float x, float y, float z);
	glm::quat rotation() const;
	glm::vec3 eulerRotation() const;
	glm::quat eulerToQuaternion(glm::vec3 euler) const;
	glm::vec3 quaternionToEuler(glm::quat quaternion) const;
	void setScale(glm::vec3 scale);
	void setScale(float x, float y, float z);
	glm::vec3 scale() const;
	
private:
	void calculateMatrix();

	glm::mat4 m_matrix;
	glm::vec3 m_position;
	glm::quat m_rotation;
	glm::vec3 m_scale;
};

}

#endif // TRANSFORM_H