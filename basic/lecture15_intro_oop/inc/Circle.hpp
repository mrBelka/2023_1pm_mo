#pragma once

namespace mt
{
	// Хранение данных
	struct Point {
		// Поля
		int x;
		int y;
	};

	class Circle {
	private:
		// Поля
		float m_r;
		Point m_p;
	public:
		// Методы
		// Конструктор
		Circle(float r, Point p);
		~Circle();

		// Сеттеры
		void setR(float r);

		// Геттеры
		float getR();

		float Square();
	};

}