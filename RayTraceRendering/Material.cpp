#include "Material.h"
#include <algorithm>


Material::Material()
{
}


Material::~Material()
{
}

CheckMaterial::CheckMaterial(double scale, double reflectiveness) :
	Material(reflectiveness),
	m_scale(scale)
{

}

std::shared_ptr<Color> CheckMaterial::sample(std::shared_ptr<Ray> ray, std::shared_ptr<vector3> position,
	std::shared_ptr<vector3> normal)
{
	return abs((int(std::floor(position->x() * 0.1)) + int(std::floor(position->z() * m_scale))) % 2) < 1 ? Color::Black : Color::White;//scale=0.1��һ�����ӵĴ�СΪ10x10
}

PhongMaterial::PhongMaterial(std::shared_ptr<Color> diffuse, std::shared_ptr<Color>  specular, int shininess, double reflectiveness) :
	Material(reflectiveness),
	m_diffuse(diffuse),
	m_specular(specular),
	m_shininess(shininess)
{

}
//��Ϊδ�й�Դϵͳ��ֻ��ȫ���������һ����ʱ�Ĺ�Դ���򣬲�ֻ��������(diffuse)�;���(specular)
std::shared_ptr<Color> PhongMaterial::sample(std::shared_ptr<Ray> ray, std::shared_ptr<vector3> position,
	std::shared_ptr<vector3> normal)
{
	double NdotL = normal->dot(*LightDir);
	vector3&& H = (*LightDir - *(ray->getDirection())).normalize();
	double NdotH = normal->dot(H);
	Color&& diffuseTerm = *m_diffuse * (std::max(NdotL, 0.0));
	Color&& specularTerm = *m_specular * (double)(std::pow(std::max(NdotH, 0.0), m_shininess));
	Color result = Color::White->modulate(diffuseTerm + specularTerm);
	return std::make_shared<Color>(result);
};

std::shared_ptr<vector3>  Material::LightDir = std::make_shared<vector3>(vector3(1, 1, 1).normalize());
std::shared_ptr<Color>  Material::LightColor = Color::White;