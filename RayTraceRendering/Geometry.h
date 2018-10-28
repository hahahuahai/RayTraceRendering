#pragma once
#include <memory>
#include "Material.h"
#include "IntersectResult.h"
#include "Ray.h"

//几何类(抽象类)
class Geometry:public std::enable_shared_from_this<Geometry>
{
public:
	Geometry():m_material(nullptr){};
	~Geometry();

	virtual void init() = 0;
	virtual std::shared_ptr<IntersectResult> intersect(std::shared_ptr<Ray>) = 0;

	inline void setMaterial(std::shared_ptr<Material> pMaterial) { m_material = pMaterial; };
	inline std::shared_ptr<Material> getMaterial() { return m_material; };
private:
	std::shared_ptr<Material> m_material;
};

