#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

namespace mt
{

	class Ship
	{
		float m_x, m_y;
		float m_alpha;
		float m_v;
		sf::Texture m_textureShip;
		sf::Sprite m_spriteShip;

	public:
		Ship() = default;
		// !!!
		Ship(float x, float y)
		{
			m_x = x;
			m_y = y;
		}

		bool Setup(float x, float y)
		{
			m_x = x;
			m_y = y;
			m_alpha = 0;
			m_v = 0;

			// Загрузка текстуры фона
			if (!m_textureShip.loadFromFile("assets\\falcon.png"))
			{
				std::cout << "Error while loading falcon.png" << std::endl;
				return false;
			}
			m_spriteShip.setTexture(m_textureShip);

			m_spriteShip.setScale(0.2f, 0.2f);
			m_spriteShip.setOrigin(m_textureShip.getSize().x / 2, m_textureShip.getSize().y / 2);
			m_spriteShip.setPosition(m_x, m_y);
			m_spriteShip.setRotation(m_alpha);
		}

		void setVelocity(float dv)
		{
			m_v += dv;
		}

		void Move()
		{
			float alphaRad = acos(-1) * m_alpha / 180;
			m_x += m_v * cos(alphaRad);
			m_y += m_v * sin(alphaRad);
			m_spriteShip.setPosition(m_x, m_y);
		}

		void Rotate(float dalpha)
		{
			m_alpha += dalpha;
			m_spriteShip.setRotation(m_alpha);
		}

		sf::Sprite Get()
		{
			return m_spriteShip;
		}
	};

}