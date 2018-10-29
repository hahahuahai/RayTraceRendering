#pragma once
#include <memory>
#include "Vector3.h"
#include "Ray.h"

constexpr double PI = 3.141592653589793238463;

class PerspectiveCamera
{
public:
	PerspectiveCamera();
	~PerspectiveCamera();

	PerspectiveCamera(std::shared_ptr<vector3> eye, std::shared_ptr<vector3> front, std::shared_ptr<vector3> up, double fov);
	void init();
	std::shared_ptr<Ray> generate_ray(double x, double y);

private:
	std::shared_ptr<vector3> m_eye;
	std::shared_ptr<vector3> m_front;
	std::shared_ptr<vector3> m_up;
	std::shared_ptr<vector3> m_refUp;
	std::shared_ptr<vector3> m_right;
	double m_fov;
	double m_fovScale;

};

