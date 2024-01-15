#pragma once

namespace mt
{

	struct Point {
		// public:
		float x;
		float y;
	};

	class Circle {

		//private:
			// Поля класса
		float m_r;
		Point m_p;

		float Dist(Point p1, Point p2);

	public:
		// Конструктор по умолчанию
		Circle() = default; // Circle() {}

		// Конструктор
		Circle(float x, float y, float r);

		// Деструктор
		~Circle();

		void Setup(float x, float y, float r);

		// Сеттеры
		void SetR(float r);

		// Геттеры
		float GetR()
		{
			return m_r;
		}

		void Move(float dx, float dy)
		{
			m_p.x += dx;
			m_p.y += dy;
		}

		void Print();

		bool CheckCross(Circle other)
		{
			return Dist(m_p, other.m_p) <= m_r + other.m_r;
		}

	}; // Circle c1;

}