#include <iostream>
#include "functions.hpp"

int main()
{
	int a = 1;
	int b = 2;
	mt::swap(a, b);
	std::cout << a << " " << b << std::endl;

	int x = 123;
	mt::sumOfDigits(x);
	x;


	/*char str[100] = "Abcde, world";

	for (int i = 0; i < strlen(str); i++)
		str[i] = mt::to_lower(str[i]);

	//std::cout << str << std::endl;

	int n = 0;
	char words[100][100];
	// Распаковка слов
	// TODO Символ в конце
	int len = strlen(str);
	str[len] = '.';
	str[len + 1] = '\0';


	int i = 0;
	int size = 0;
	char word[100] = "";

	while (i < strlen(str))
	{
		if (mt::isLetter(str[i]))
		{
			word[size] = str[i];
			size++;
		}
		else
		{
			word[size] = '\0';
			if (strlen(word) != 0)
			{
				//word[size] = '\0';
				strcpy_s(words[n], word);
				n++;
				size = 0;
			}
		}
		i++;
	}

	for (int i = 0; i < n; i++)
	{
		std::cout << words[i] << std::endl;
		
		bool flag = true; // предположение, что символы упорядочены
		for(int j=0;j<strlen(words[i])-1;j++)
			if (words[i][j] > words[i][j + 1])
			{
				flag = false;
				break;
			}
		if (flag)
			std::cout << "Ordered" << std::endl;
		else
			std::cout << "Unordered" << std::endl;
	}*/

	// Задача дублирования
	int n = 5;
	int mas[10] = { 1,3,4,1,2 };

	// По ссылке
	// По значению
	mt::DuplicateOdd(mas, n);

	for (int i = 0; i < n; i++)
		std::cout << mas[i] << std::endl;

	return 0;
}