#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

namespace mt
{

	class SpaceObject
	{
	protected:
		float m_x, m_y;
		float m_vx, m_vy;
		float m_r;
		sf::Texture m_textureShip;
		sf::Sprite m_spriteShip;

	public:
		SpaceObject() = default;
		virtual ~SpaceObject() {}

		bool Setup(float x, float y, float vx, float vy, 
			const std::string& texturePath, float scaleFactor)
		{
			m_x = x;
			m_y = y;
			m_vx = vx;
			m_vy = vy;

			// Загрузка текстуры фона
			if (!m_textureShip.loadFromFile(texturePath))
			{
				std::cout << "Error while loading " << texturePath << std::endl;
				return false;
			}
			m_spriteShip.setTexture(m_textureShip);

			m_spriteShip.setScale(scaleFactor, scaleFactor);
			m_spriteShip.setOrigin(m_textureShip.getSize().x / 2, m_textureShip.getSize().y / 2);
			m_spriteShip.setPosition(m_x, m_y);
			//m_spriteShip.setRotation(m_alpha);

			if (m_textureShip.getSize().x > m_textureShip.getSize().y)
				m_r = scaleFactor * m_textureShip.getSize().x / 2;
			else
				m_r = scaleFactor * m_textureShip.getSize().y / 2;
		}

		sf::Sprite Get()
		{
			return m_spriteShip;
		}

		void Move(float dt)
		{
			m_x += m_vx * dt;
			m_y += m_vy * dt;
			m_spriteShip.setPosition(m_x, m_y);
		}

		virtual void Attack() = 0;
		virtual void SpecialAbility() = 0;
	};
}