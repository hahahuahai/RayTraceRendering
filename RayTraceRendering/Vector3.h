#pragma once
#include "CImg.h"
#include <complex>
#include <memory>

//三维向量
class vector3
{
public:
	vector3();
	vector3(const double x, const double y, const double z);
	vector3(const vector3& v);
	vector3(vector3&& v);
	~vector3();

	vector3& operator=(const vector3& v);
	vector3& operator=(vector3&& v);
	vector3 operator+(const vector3& v)const;
	vector3 operator-(const vector3& v)const;
	vector3 operator*(double a)const;
	vector3 operator/(double a)const;
	vector3 operator-()const;
	bool operator==(const vector3& v)const;

	double dot(const vector3& v)const;//点乘
	vector3 cross(const vector3& v)const;//叉乘

	inline double x()const { return m_x; }//得到x、y、z值
	inline double y()const { return m_y; }
	inline double z()const { return m_z; }

	inline double length() { return std::sqrt(m_x * m_x + m_y * m_y + m_z * m_z); }//计算向量长度
	inline double squareLength() { return m_x * m_x + m_y * m_y + m_z * m_z; }//计算向量长度的平方
	vector3 normalize();//归一化
	vector3& swap(vector3&);
public:
	static std::shared_ptr<vector3> Zero;
private:
	double m_x, m_y, m_z;//向量的三个元素值
};

