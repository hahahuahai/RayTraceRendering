#include "sphere.h"



sphere::sphere()
{
}

sphere::sphere(std::shared_ptr<vector3> center, double radius):m_center(center), m_radius(radius)
{

}

sphere::sphere(sphere& s)
{
	m_center = std::make_shared<vector3>(*s.getCenter());
	m_radius = s.getRadius();
}


sphere::~sphere()
{
}

sphere sphere::operator=(const sphere& s)
{
	m_radius = s.getRadius();
	m_center = std::make_shared<vector3>(*s.getCenter());
	return *this;
}

void sphere::init()
{
	m_sqrRadius = m_radius * m_radius;
}
//根据数学公式
std::shared_ptr<IntersectResult> sphere::intersect(std::shared_ptr<Ray> ray)
{
	vector3&& v = *(ray->getOrigin()) - (*m_center);
	double a0 = v.squareLength() - m_sqrRadius;
	double DdotV = ray->getDirection()->dot(v);
	if(DdotV <= 0)
	{
		double discr = DdotV * DdotV - a0;
		if (discr >= 0) {
			auto distance = -DdotV - sqrtf(discr);
			auto position = ray->getPoint(distance);
			auto normal = (*position - *m_center).normalize();
			return std::make_shared<IntersectResult>(IntersectResult(shared_from_this(), distance, *position, normal));
		}
	}
	return IntersectResult::NoHit;
}



