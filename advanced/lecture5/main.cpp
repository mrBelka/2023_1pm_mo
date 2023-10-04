#include <iostream>
#include <fstream>
#include <string>

int my_strlen(char* str);

int main()
{
	setlocale(LC_ALL, "Rus");

	// Конфигурационные параметры
	const int N = 100;
	const int M = 100;

	char ch = 'a'; // Символ
	char str[10] = "Hello1234";
	//str[9] = 'a';
	std::cout << str << std::endl;

	// длина строки
	std::cout << strlen(str) << std::endl;

	// копирование строк
	char str_copy[10];
	strcpy_s(str_copy, str);

	// конкатенация == сложение
	char str_concat[20];
	strcpy_s(str_concat, str);
	strcat_s(str_concat, str_copy);

	std::cout << str_concat << std::endl;

	// сравнение
	std::cout << strcmp("BBC", "bbc") << std::endl;

	char cmp1[4] = "BBC";
	char cmp2[4] = "bbc";
	for(int i=0;i<4;i++)
		if (66 < 98)
		{

		}

	// лексикографический порядок

	// ввод строк
	std::ifstream in("input.txt"); // идиома RAII

	if (!in.is_open())
	{
		std::cerr << "Open file error" << std::endl;
		return -1;
	}

	// Посимвольный ввод
	while (!in.eof())
	{
		char c;
		in >> c;
		std::cout << c << std::endl;
	}

	in.clear();
	in.seekg(0);

	// Ввод по словам
	while (!in.eof())
	{
		char s[100];
		in >> s;
		std::cout << s << std::endl;
	}

	in.clear();
	in.seekg(0);

	// Ввод по строкам
	while (!in.eof())
	{
		char line[10000];
		in.getline(line, 10000);
		std::cout << "<" << line << ">" << std::endl;
	}

	// ввод русского текста

	// простейшие функции
	std::cout << my_strlen(str_concat) << std::endl;

	return 0;
}

int my_strlen(char* str)
{
	int length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return length;
}