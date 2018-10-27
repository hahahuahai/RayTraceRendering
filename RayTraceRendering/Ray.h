#pragma once
#include <memory>
#include "vector3.h"

class Ray
{
public:
	Ray(std::shared_ptr<vector3> origin, std::shared_ptr<vector3> direction);
	~Ray();

	std::shared_ptr<vector3> getPoint(double t);//t «æ‡¿Î
	inline std::shared_ptr<vector3> getOrigin() { return m_origin; };
	inline std::shared_ptr<vector3> getDirection() { return m_direction; };

private:
	std::shared_ptr<vector3> m_origin;
	std::shared_ptr<vector3> m_direction;
};

