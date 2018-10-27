#include "Vector3.h"
#include"outputInfo.h"
#include <algorithm>
#include <iostream>

vector3::vector3():m_x(0),m_y(0),m_z(0)
{
	outputInfo::output("vector3::vector3()");
}

vector3::vector3(const double x, const double y, const double z):m_x(x),m_y(y),m_z(z)
{
}


vector3::~vector3()
{
}
