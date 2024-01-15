#include "Circle.hpp"
#include <iostream>

namespace mt
{
	void Circle::Setup(float x, float y, float r)
	{
		m_p.x = x;
		m_p.y = y;
		m_r = r;
		// (*this).r === this->r
	}

	Circle::Circle(float x, float y, float r) {
		Setup(x, y, r);
		std::cout << "Const" << std::endl;
	}

	Circle::~Circle() {
		std::cout << "Dest" << std::endl;
	}

	float Circle::Dist(Point p1, Point p2)
	{
		return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
	}

	void Circle::SetR(float r)
	{
		if (r < 0)
		{
			std::cout << "Error R < 0" << std::endl;
			return;
		}
		m_r = r;
	}

	void Circle::Print()
	{
		std::cout << m_p.x << " " << m_p.y << " " << m_r << std::endl;
	}

}