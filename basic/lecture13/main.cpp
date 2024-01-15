#include <iostream>
#include <fstream>
#include <func.hpp>

int main()
{
	std::ifstream in("input.txt");

	if (!in.is_open())
	{
		std::cout << "File error!" << std::endl;
	}

	std::cout << sum(2, 3);
	return 0;
}