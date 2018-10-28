#include "IntersectResult.h"



IntersectResult::IntersectResult() :
	m_geometry(nullptr),
	m_distance(0),
	m_position(vector3::Zero),
	m_normal(vector3::Zero)
{
}

IntersectResult::IntersectResult(std::shared_ptr<Geometry> ptrGeo, double dis, std::shared_ptr<vector3> pos, std::shared_ptr<vector3> normal) :
	m_geometry(ptrGeo),
	m_distance(dis),
	m_position(pos),
	m_normal(normal)
{
}

IntersectResult::IntersectResult(std::shared_ptr<Geometry> ptrGeo, double dis, const vector3& pos, const vector3& normal) :
	m_geometry(ptrGeo),
	m_distance(dis),
	m_position(std::make_shared<vector3>(pos)),
	m_normal(std::make_shared<vector3>(normal))
{
}


IntersectResult::~IntersectResult()
{
}

std::shared_ptr<IntersectResult> IntersectResult::NoHit = std::make_shared<IntersectResult>();
