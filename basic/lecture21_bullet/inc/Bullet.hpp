#pragma once
#include <SFML/Graphics.hpp>

namespace mt
{

	class Bullet
	{
		float m_r;
		float m_x, m_y;
		float m_vx, m_vy;
		sf::CircleShape m_shape;

		bool m_available = false;

	public:
		Bullet() = default;

		Bullet(float x, float y, float r, float vx, float vy)
		{
			Setup(x, y, r, vx, vy);
		}

		void Setup(float x, float y, float r, float vx, float vy)
		{
			m_x = x;
			m_y = y;
			m_r = r;
			m_vx = vx;
			m_vy = vy;
			m_shape.setOrigin(m_r, m_r);
			m_shape.setRadius(m_r);
			m_shape.setPosition(m_x, m_y);
			int color_r = 255;
			int color_g = 0;
			int color_b = 0;
			m_shape.setFillColor(sf::Color::Color(color_r, color_b, color_g, 255));
		}

		sf::CircleShape Get()
		{
			return m_shape;
		}

		float X() { return m_x; }
		void X(float value) { m_x = value; m_shape.setPosition(m_x, m_y); }
		void Y(float value) { m_y = value; m_shape.setPosition(m_x, m_y); }
		float Y() { return m_y; }
		float R() { return m_r; }
		float Vx() { return m_vx; }
		float Vy() { return m_vy; }

		void Move(float dt)
		{
			m_x += m_vx * dt;
			m_y += m_vy * dt;
			m_shape.setPosition(m_x, m_y);
		}

		bool Available() { return m_available; }
		void Available(bool value) { m_available = value; }
	};

}