#pragma once
#include <memory>
#include "Vector3.h"
#include "Color.h"
#include "Ray.h"

//材质类，定义射线交点向某方向（如往视点的方向）发出的光的颜色
class Material:public std::enable_shared_from_this<Material>
{
public:
	Material();
	Material(double reflectiveness) :m_reflectiveness(reflectiveness) {};
	~Material();

	virtual std::shared_ptr<Color> sample(std::shared_ptr<Ray> ray, std::shared_ptr<vector3> position, std::shared_ptr<vector3> normal) = 0;
	inline double getReflectiveness() { return m_reflectiveness; };
public:
	static std::shared_ptr<vector3> LightDir;
	static std::shared_ptr<Color> LightColor;
protected:
	double m_reflectiveness;
};

class CheckMaterial:public Material
{
public:
	CheckMaterial(double scale,double reflectiveness = 0);
	std::shared_ptr<Color> sample(std::shared_ptr<Ray> ray, std::shared_ptr<vector3> position, std::shared_ptr<vector3> normal) override;
private:
	double m_scale;
};

class PhongMaterial:public Material
{
public:
	PhongMaterial(std::shared_ptr<Color> diffuse, std::shared_ptr<Color> specular, int shininess, double reflectiveness = 0);
	std::shared_ptr<Color> sample(std::shared_ptr<Ray> ray, std::shared_ptr<vector3> position, std::shared_ptr<vector3> normal) override;
	std::shared_ptr<Color> getDiffuse() { return m_diffuse; }
private:
	std::shared_ptr<Color> m_diffuse, m_specular;
	int m_shininess;
};

