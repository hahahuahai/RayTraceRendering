#include "plane.h"



plane::plane()
{
}

plane::plane(std::shared_ptr<vector3> normal, double distance):
	m_normal(normal),
	m_distance(distance)
{
}

plane::plane(const plane& p)
{
	m_normal = p.getNormal();
	m_distance = p.getDistance();
}


plane::~plane()
{
}

plane plane::operator=(const plane& p)
{
	m_normal = p.getNormal();
	m_distance = p.getDistance();
	return *this;
}

void plane::init()
{
	m_position = std::make_shared<vector3>(*m_normal * m_distance);
}

std::shared_ptr<IntersectResult> plane::intersect(std::shared_ptr<Ray> ray)
{

}

