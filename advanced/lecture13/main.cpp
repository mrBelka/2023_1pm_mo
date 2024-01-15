#include <iostream>
#include "Circle.hpp"

int main()
{
	mt::Circle c1(0.0f, 0.0f, 2.0f);
	mt::Circle c2(2.0f, 0.0f, 2.0f);
	mt::Circle c[2];

	c1.Move(10, 5);

	c1.Print();

	bool flag = c1.CheckCross(c2);

	std::cout << flag << std::endl;

	/*for (int i = 0; i < 2; i++)
	{
		float r, x, y;
		std::cin >> x >> y >> r; // -10 -> ungigned int   4`280`000`000

		if (r < 0)
			continue;

		c[i].Setup(x, y, r);
	}*/

	return 0;
}