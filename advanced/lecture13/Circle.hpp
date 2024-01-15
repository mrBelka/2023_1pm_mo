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
			// ���� ������
		float m_r;
		Point m_p;

		float Dist(Point p1, Point p2);

	public:
		// ����������� �� ���������
		Circle() = default; // Circle() {}

		// �����������
		Circle(float x, float y, float r);

		// ����������
		~Circle();

		void Setup(float x, float y, float r);

		// �������
		void SetR(float r);

		// �������
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