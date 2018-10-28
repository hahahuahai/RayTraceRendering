#pragma once
#include <memory>
//几何类(抽象类)
class Geometry:public std::enable_shared_from_this<Geometry>
{
public:
	Geometry();
	~Geometry();
private:

};

