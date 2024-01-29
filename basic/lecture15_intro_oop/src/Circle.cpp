#include <Circle.hpp>
#include <iostream>

namespace mt 
{

	Circle::Circle(float r, Point p)
	{
		std::cout << "Constr" << std::endl;
		m_r = r; // (*this).r
		m_p = p;
	}

	Circle::~Circle()
	{
		std::cout << "Destr" << std::endl;
	}

	// Сеттеры
	void Circle::setR(float r)
	{
		if (r < 0)
		{
			std::cout << "Negative radius" << std::endl;
			return;
		}
		m_r = r;
	}

	// Геттеры
	float Circle::getR()
	{
		return m_r;
	}

	float Circle::Square()
	{
		return acos(-1) * m_r * m_r;
	}

}