#pragma once
#include "Geometry.h"

class plane:public Geometry
{
public:
	plane();
	plane(std::shared_ptr<vector3> normal, double distance);
	plane(const plane &);
	~plane();

	plane operator=(const plane&);
	virtual void init() override;
	virtual std::shared_ptr<IntersectResult> intersect(std::shared_ptr<Ray>);
	inline std::shared_ptr<vector3> getNormal()const { return m_normal; }
	inline std::shared_ptr<vector3> getPosition()const { return m_position; }
	inline double getDistance()const { return m_distance; }

private:
	std::shared_ptr<vector3> m_normal;
	double m_distance;
	std::shared_ptr<vector3> m_position;
};

