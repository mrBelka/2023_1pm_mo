#include <iostream>
#include <iomanip>

int main() 
{
	// Операции для сравнения
	// ==, !=, <, <=, >, >=
	//int a = 10;
	//int b = 1;

	//bool f = (a == b);

	// Логические операции
	// &&, ||, !, ^

	//std::cout << ((0 < a && a < 100) || (b==8 && a>50) && !a) << std::endl;

	//std::cout << (!a) << std::endl;

	//std::cout << (--b) << std::endl;

	//std::cout << b << std::endl;

	/*int a;
	std::cin >> a;
	if (a > 0)
	{
		std::cout << a;
		a = a + 10;
	}
	else
		a = a * 2;
	std::cout << a;

	// if
	if (a > 0)
	{
		std::cout << a;
		a = a + 10;
	}

	// if..else
	if (a > 0)
	{

	}
	else
	{

	}

	// if..else if..else
	if (a>0)
	{

	}
	else if (a < 100)
	{

	}
	else
	{

	}

	// 
	if (a > 0)
		if (a < 100)
			std::cout << "Consist" << std::endl;

	if(a>0 && a<100)
		std::cout << "Consist" << std::endl;

	bool f = false;
	if (!f)
	{
		std::cout << "Test" << std::endl;
	}*/

	// switch
	int errorCode = 2;
	if (errorCode == 0)
		std::cout << "File error";
	else if (errorCode == 1)
		std::cout << "System error";
	else
		std::cout << "Unknown error";

	switch (errorCode)
	{
		case 0:std::cout << "File error";
			   break;
		case 1:std::cout << "System error";
			   break;
		default:std::cout << "Unknown error";
	}

	// Тернарный оператор
	bool f = true;
	std::cout << (f == 0 ? "True" : "False") << std::endl;

	int x = -100;
	bool g = x > 0 ? 1 : -1;

	if (x > 0)
		g = 1;
	else
		g = 0;

	// Циклы
	std::cout << 0 << std::endl;
	std::cout << 1 << std::endl;
	std::cout << 2 << std::endl;
	std::cout << 3 << std::endl;
	//...
	std::cout << 9 << std::endl;

	int i = 0;	// Счетчик, итератор
	while (i < 10)
	{
		std::cout << i << std::endl;
		i++;
	}


	
}