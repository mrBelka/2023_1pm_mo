#pragma once
#include <string>
#include <thread>

namespace mt
{

	const float pi = acos(-1);

	class Game
	{
		int m_width;
		int m_height;
		std::string m_capture;
		mt::Circle* m_c;
		bool* m_col;
		int m_n;
		sf::RenderWindow m_window;
		std::vector<sf::Vertex> m_coords;
		bool m_firstCollision = true;


	public:
		Game(int width, int height, const std::string& capture)
		{
			m_width = width;
			m_height = height;
			m_capture = capture;
			m_coords.push_back(sf::Vector2f(0, 0));
			m_coords.push_back(sf::Vector2f(0, 0));
		}

		void Setup(int n)
		{
			m_n = n;
			// Создание окна
			m_window.create(sf::VideoMode(m_width, m_height), m_capture);

			srand(time(0));

			m_c = new mt::Circle[m_n];
			m_col = new bool[m_n];
			m_c[0].Setup(300, 200, 50, 100, pi/2);
			m_c[1].Setup(300, 300, 50, 100, 2*pi/3);
			/*for (int i = 0; i < m_n; i++)
			{
				int r = rand() % 15 + 15;
				int x = rand() % (1000 - 2*r) + r;
				int y = rand() % (600 - 2*r) + r;
				int v = rand() % 50 + 10;
				float alfa = rand() % 7;
				m_c[i].Setup(x, y, r, v, alfa);
				m_col[i] = true;
			}*/
		}

		void TouchBorder(Circle& obj)
		{
			float x = obj.X();
			float y = obj.Y();
			float r = obj.R();

			if (x + r >= m_width || x - r <= 0)
			{
				obj.Alfa(pi - obj.Alfa());
			}

			if (y + r >= m_height || y - r <= 0)
			{
				obj.Alfa(2*pi-obj.Alfa());
			}
		}

		void Collision(Circle& c1, Circle& c2)
		{
			float dist = pow(c1.X() - c2.X(), 2) + pow(c1.Y() - c2.Y(), 2);
			if (dist <= pow(c1.R() + c2.R(),2))
			{
				if (m_firstCollision)
				{
					m_firstCollision = false;

					float xm = c1.X() + (c2.X() - c1.X()) * (c1.R() / (c1.R() + c2.R()));
					float ym = c1.Y() + (c2.Y() - c1.Y()) * (c1.R() / (c1.R() + c2.R()));

					float px = c2.Y() - c1.Y();
					float py = -(c2.X() - c1.X());

					m_coords.clear();
					m_coords.push_back(sf::Vector2f(xm + px * 10, ym + py*10));
					m_coords.push_back(sf::Vector2f(xm - px * 10, ym - py * 10));

					float len = sqrt(pow(c2.Y() - c1.Y(), 2) + pow(c2.X() - c1.X(), 2));
					float beta = acos((c2.Y() - c1.Y()) / len);

					std::cout << beta << std::endl;

					c1.Alfa((-(c1.Alfa() + beta) + 2 * pi) - beta);
					c2.Alfa((-(c1.Alfa() + beta) + 2 * pi) - beta);
					//c2.Alfa(pi/2 + c2.Alfa());

					std::cout << "Touch " << xm << " " << ym << std::endl;
				}
			}
			else
				m_firstCollision = true;
		}

		void LifeCycle()
		{
			sf::Clock clock;
			
			while (m_window.isOpen())
			{
				// Обработка событий
				sf::Event event;
				while (m_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						m_window.close();
				}

				//std::this_thread::sleep_for(std::chrono::milliseconds(1000));

				// Логика
				float dt = clock.getElapsedTime().asSeconds();
				clock.restart();

				// Перемещение шарика
				for (int i = 0; i < m_n; i++)
					m_c[i].Move(dt);

				// Столкновение шариков
				for (int i = 0; i < m_n - 1; i++)
					for (int j = i + 1; j < m_n; j++)
						Collision(m_c[i], m_c[j]);

				for (int i = 0; i < m_n; i++)
					TouchBorder(m_c[i]);

				// Отображение
				m_window.clear();
				for (int i = 0; i < m_n; i++)
					m_window.draw(m_c[i].Get());
				m_window.draw(m_coords.data(), 2, sf::Lines);
				m_window.display();
			}
		}
	};

}