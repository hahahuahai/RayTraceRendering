#pragma once
#include <memory>
#include "Geometry.h"

//这个类只用来记录交点的几何物件(geometry)、距离(distance)、位置(position)和法向量(normal)。 IntersectResult.noHit的geometry为null，代表光线没有和任何几何物件相交。
class IntersectResult
{
public:
	IntersectResult();
	IntersectResult(std::shared_ptr<Geometry>,double, std::shared_ptr<vector3>, std::shared_ptr<vector3>);
	IntersectResult(std::shared_ptr<Geometry>, double, const vector3&, const vector3&);
	~IntersectResult();

	void setGeometry(std::shared_ptr<Geometry> ptrGeo) { m_geometry = ptrGeo; };
	std::shared_ptr<Geometry>  getGeometry() { return m_geometry; };

	double getDistance() { return m_distance; };
	std::shared_ptr<vector3> getPosition() { return m_position; };
	std::shared_ptr<vector3> getNormal() { return m_normal; };
private:
	std::shared_ptr<Geometry> m_geometry;
	double m_distance;
	std::shared_ptr<vector3> m_position;
	std::shared_ptr<vector3> m_normal;

	static std::shared_ptr<IntersectResult> NoHit;
};

