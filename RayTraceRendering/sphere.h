#pragma once
#include <memory>
#include "Vector3.h"
#include "IntersectResult.h"
#include "Ray.h"
#include "Geometry.h"

class sphere:public Geometry
{
public:
	sphere();
	sphere(std::shared_ptr<vector3> center, double radius);
	sphere(sphere&);
	~sphere();

	sphere operator=(const sphere&);

	virtual void init();
	virtual std::shared_ptr<IntersectResult> intersect(std::shared_ptr<Ray>);

	std::shared_ptr<vector3> getCenter()const { return m_center; }
	inline double getRadius()const { return m_radius; }


private:
	std::shared_ptr<vector3> m_center;
	double m_radius;
	double m_sqrRadius;
};

