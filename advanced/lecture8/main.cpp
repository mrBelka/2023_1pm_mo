#include <iostream>
#include <thread>

int main()
{
	// Указатель - обычная переменная, которая хранит адрес
	int* p;   // стек
	char* c;

	p = new int; // куча
	c = new char;

	*p = 10;     // * - разыменование
	*c = 97;

	// С-style cast
	// static_cast
	// reinterpret_cast
	// const_cast
	// dynamic_cast

	std::cout << p << std::endl;
	std::cout << (void*)(c) << std::endl;
	std::cout << *p << std::endl;
	std::cout << *c << std::endl;
	std::cout << sizeof(p) << std::endl;
	std::cout << sizeof(*p) << std::endl;
	std::cout << sizeof(c) << std::endl;
	std::cout << sizeof(*c) << std::endl;

	// Сколько байтов занимает указатель?
	// Диапозон значений?

	delete p;
	delete c;

	for (int i = 0; i < 1000; i++)
	{
		int* p = new int[1000000];
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		delete[] p;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

	return 0;
}