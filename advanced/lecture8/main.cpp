#include <iostream>
#include <thread>

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	// Ссылки
	int sumOfDigitsOfEvenNumber = 13;
	int& s = sumOfDigitsOfEvenNumber; // 1. Псевдоним
	s += 10;

	int a = 10, b = 5;
	swap(a, b);
	std::cout << a << " " << b << std::endl;

	// Указатель - обычная переменная, которая хранит адрес
	int* p;   // стек
	char* c;	// 8 байтов при x64, 4 байта при x86 (32 бита)

	p = new int; // куча
	c = new char;

	*p = 10;     // * - разыменование
	*c = 97;

	// утечка памяти (memory leak)

	// С-style cast
	// static_cast
	// reinterpret_cast
	// const_cast
	// dynamic_cast

	/*std::cout << p << std::endl;
	std::cout << (void*)(c) << std::endl;
	std::cout << *p << std::endl;
	std::cout << *c << std::endl;
	std::cout << sizeof(p) << std::endl;
	std::cout << sizeof(*p) << std::endl;
	std::cout << sizeof(c) << std::endl;
	std::cout << sizeof(*c) << std::endl;*/

	/*std::cout << p << std::endl;
	std::cout << &p << std::endl;	// получить адрес переменной p (указатель)
	std::cout << &(*p) << std::endl;*/

	// Сколько байтов занимает указатель?
	// Диапозон значений?

	delete p;
	delete c;

	/*for (int i = 0; i < 1000; i++)
	{
		int* p = new int[1000000];
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		delete[] p;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}*/

	//int* a = new int;
	//int** b = &a;

	int n = 10;
	//std::cin >> n;

	// Массив фикс. длины
	// + безопасность
	// + скорость (за счет стека)
	// - возможное неэффективное использование памяти
	// - небольшой размер стека

	// Динамический массив
	// - безопасность (vector, RAII (умные указатели))
	// - скорость (allocator)
	// + эффективное использование памяти
	// + существенно больший размер кучи

	/*int* mas = new int[n]; // 10 блоков памяти по 4 байта

	mas[0] = 10;
	mas[1] = 20;
	std::cout << mas << std::endl;
	std::cout << mas+1 << std::endl;

	//std::cout << mas << std::endl;
	//std::cout << *mas << std::endl;

	delete[] mas;*/

	//char* mas_char = new char;
	/*mas_char[0] = 'H';
	mas_char[1] = 'e';
	mas_char[2] = 'l';
	mas_char[3] = 'l';
	mas_char[4] = 'o';
	mas_char[5] = 0;*/

	//delete mas_char;

	// Двумерный динамический массив
	/*int** matrix = new int* [10];
	for (int i = 0; i < 10; i++)
		matrix[i] = new int[20];

	matrix[0][0] = 10;

	for (int i = 0; i < 10; i++)
		delete[] matrix[i];
	delete[] matrix;*/

	// Передатчик, который передает сообщение по байтам
	// есть приемник, который должен это сообщение собрать и представить пользователю

	/*int* mas = new int[2];
	mas[0] = 1000;
	mas[1] = 1001;

	unsigned char* cmas = reinterpret_cast<unsigned char*>(mas);
	for (int i = 0; i < 8; i++)
		std::cout << (int)*(cmas+i) << std::endl;

	int* newmas = reinterpret_cast<int*>(cmas);
	std::cout << newmas[0] << std::endl;
	std::cout << newmas[1] << std::endl;

	delete[] mas;
	delete[] newmas;
	delete[] cmas;*/

	return 0;
}