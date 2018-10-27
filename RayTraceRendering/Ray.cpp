#include "Ray.h"


Ray::Ray(std::shared_ptr<vector3> origin, std::shared_ptr<vector3> direction) :m_origin(origin), m_direction(direction)
{

}

Ray::~Ray()
{
}

std::shared_ptr<vector3> Ray::getPoint(double t)
{
	std::shared_ptr<vector3> result = std::make_shared<vector3>((*m_origin) + (*m_direction)*t);
	return result;
}

