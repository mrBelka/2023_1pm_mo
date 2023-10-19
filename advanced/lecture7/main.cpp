#include <iostream>
#include <fstream>
#include <functions.hpp>

int main()
{

	std::ifstream in("assets/input.txt");
	if (!in.is_open())
	{
		std::cerr << "File open error" << std::endl;
		return -1;
	}

	int a = 5, b = 10;
	mt::swap(a, b);
	std::cout << a << " " << b << std::endl;
}