#include "Vector3.h"
#include"outputInfo.h"
#include <algorithm>
#include <iostream>

vector3::vector3() :m_x(0), m_y(0), m_z(0)
{
	outputInfo::output("vector3::vector3()");
}

vector3::vector3(const double x, const double y, const double z) : m_x(x), m_y(y), m_z(z)
{
	outputInfo::output("vector3::vector3(const double x, const double y, const double z)");
}

vector3::vector3(const vector3 &v)
{
	m_x = v.x();
	m_y = v.y();
	m_z = v.z();
}

vector3::vector3(vector3&& v) :m_x(0), m_y(0), m_z(0)
{
	m_x = v.m_x;
	m_y = v.m_y;
	m_z = v.m_z;
	v.m_x = 0;
	v.m_y = 0;
	v.m_z = 0;
}


vector3::~vector3()
{
	outputInfo::output("vector3::vector3(const double x, const double y, const double z)");
}

vector3& vector3::operator=(const vector3& v)
{
	m_x = v.x();
	m_y = v.y();
	m_z = v.z();

	return *this;
}

vector3& vector3::operator=(vector3&& v)
{
	v.swap(*this);
	return *this;
}

vector3 vector3::operator+(const vector3& v) const
{
	return vector3(m_x + v.x(), m_y + v.y(), m_z + v.z());
}

vector3 vector3::operator-(const vector3& v) const
{
	return vector3(m_x - v.x(), m_y - v.y(), m_z - v.z());
}

vector3 vector3::operator*(double a) const
{
	return vector3(m_x * a, m_y * a, m_z * a);
}

vector3 vector3::operator/(double a) const
{
	if (a == 0)
		return *this;
	return vector3(m_x / a, m_y / a, m_z / a);
}



