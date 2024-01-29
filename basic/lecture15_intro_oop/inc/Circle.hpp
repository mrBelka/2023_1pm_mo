#pragma once

namespace mt
{
	// �������� ������
	struct Point {
		// ����
		int x;
		int y;
	};

	class Circle {
	private:
		// ����
		float m_r;
		Point m_p;
	public:
		// ������
		// �����������
		Circle(float r, Point p);
		~Circle();

		// �������
		void setR(float r);

		// �������
		float getR();

		float Square();
	};

}