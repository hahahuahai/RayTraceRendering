#include "PerspectiveCamera.h"



PerspectiveCamera::PerspectiveCamera()
{
}


PerspectiveCamera::~PerspectiveCamera()
{
}

PerspectiveCamera::PerspectiveCamera(std::shared_ptr<vector3> eye, std::shared_ptr<vector3> front,
	std::shared_ptr<vector3> up, double fov)
	: m_eye(eye)
	, m_front(front)
	, m_refUp(up)
	, m_fov(fov)
{

}

void PerspectiveCamera::init()
{
	m_right = std::make_shared<vector3>(m_front->cross(*m_refUp));
	m_up = std::make_shared<vector3>(m_right->cross(*m_front));
	m_fovScale = tan(m_fov *0.5* PI / 180.0) * 2;//m_fovScale是fov的一半的弧度制（角度制转弧度制）
}
//参数为：归一化之后的x,y坐标
std::shared_ptr<Ray> PerspectiveCamera::generate_ray(double x, double y)
{
	vector3&& r = (*m_right)*((x - 0.5)*m_fovScale);
	vector3&& u = (*m_up)*((y - 0.5)*m_fovScale);
	vector3&& v = (*m_front + r + u).normalize();

	std::shared_ptr<Ray> ray = std::make_shared<Ray>(Ray(m_eye, std::make_shared<vector3>(v)));
	return ray;
}


