#pragma once
#include <memory>

class Color {
	double m_rgb[3] = { 0 };
public:
	Color();
	Color(double r, double g, double b);
	Color(const Color &);
	Color(Color &&);
	Color& operator = (const Color&);
	Color& operator = (Color&&);
	~Color();
	Color operator + (const Color&);
	Color operator - (const Color&);
	Color operator * (double f);
	Color operator / (double f);
	bool operator == (const Color&);
	Color modulate(const Color&);
	inline double r() const { return m_rgb[0]; };
	inline double g() const { return m_rgb[1]; };
	inline double b() const { return m_rgb[2]; };
public:
	static const std::shared_ptr<Color> Black;
	static const std::shared_ptr<Color> White;
	static const std::shared_ptr<Color> Red;
	static const std::shared_ptr<Color> Green;
	static const std::shared_ptr<Color> Blue;
};
