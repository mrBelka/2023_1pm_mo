﻿#include <iostream>
#include <func.hpp>
#include <math.hpp>

int main()
{
	std::cout << mt::sum(2, 2) << std::endl;

	mt::String s("Hello, world!");
	std::cout << s.length() << std::endl;

	return 0;
}