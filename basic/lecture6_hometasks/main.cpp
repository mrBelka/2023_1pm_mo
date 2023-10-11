#include <iostream>

int main()
{
	/*Дана последовательность натуральных чисел{ aj }j = 1...n(n <= 10000).
	Если в последовательности нет ни одного простого числа, 
	упорядочить последовательность по невозрастанию.*/

	// Ввод
	int mas[10'000];
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> mas[i];

	// Проверка на наличие простого числа
	

	bool existPrimeInMas = false; // Предположение, что нет простого в массиве
	for (int i = 0; i < n; i++)
	{
		// Проверка на простоту
		bool isPrime = true; // Предположение, что число простое
		int x = mas[i];
		for(int d=2;d<=sqrt(x);d++)
			if (x % d == 0)
			{
				isPrime = false;
				break;
			}

		if (isPrime)
			existPrimeInMas = true;
	}

	// Сортировка, если нет ни одного простого
	if (existPrimeInMas == false)
	{
		// Сортировка обменами
	}

	// Вывод
	for (int i = 0; i < n; i++)
		std::cout << mas[i] << " ";

	/*
	Дана последовательность натуральных чисел {Aj}j=1...n (n<=10000).
	Удалить из последовательности нечетные числа,
	а среди оставшихся продублировать числа с последней цифрой 2.
	*/
	/*// Ввод
	int mas[20'000];
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> mas[i];

	// Удалить
	int i = 0;
	while (i < n)
	{
		if (mas[i] % 2 == 1)
		{
			for (int j = i; j < n - 1; j++)
				mas[j] = mas[j + 1];
			n--;
		}
		else i++;
	}


	// Дублировать
	i = 0;
	while (i < n)
	{
		if (mas[i] % 10 == 2)
		{
			for (int j = n; j > i; j--)
				mas[j] = mas[j - 1];
			n++;
			i++;
		}
		i++;
	}


	// Вывод
	for (int i = 0; i < n; i++)
		std::cout << mas[i] << " ";*/

	/*
	Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000).
	Упорядочить последовательность по неубыванию первой цифры числа,
	числа с одинаковыми первыми цифрами дополнительно упорядочить
	по неубыванию произведения цифр числа, числа с одинаковыми
	первыми цифрами и одинаковыми произведениями цифр дополнительно
	упорядочить по неубыванию самого числа.
	*/
	/*const int N_Max = 1000;
	int mas[N_Max];
	int first[N_Max];
	int mult[N_Max];

	// Считывание
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> mas[i];

	// Вычисление условий
	// Первая цифра числа
	for (int i = 0; i < n; i++)
	{
		first[i] = mas[i];
		while (first[i] > 9) first[i] /= 10;

		mult[i] = 1;
		int tmp = mas[i];
		while (tmp > 0)
		{
			mult[i] *= tmp % 10;
			tmp /= 10;
		}
	}

	// Сортировка
	for(int i=0;i<n-1;i++)
		for (int j = i + 1; j < n; j++)
		{
			// Обмен
			if (first[i] > first[j] ||
				(first[i] == first[j] && mult[i] > mult[j]) ||
				(first[i] == first[j] && mult[i] == mult[j] && mas[i] > mas[j]))
			{
				std::swap(mas[i], mas[j]);
				int tmp = first[i];
				first[i] = first[j];
				first[j] = tmp;
				int tmp = mult[i];
				mult[i] = mult[j];
				mult[j] = tmp;
			}
		}

	// Вывод
	for (int i = 0; i < n; i++)
		std::cout << mas[i] << std::endl;*/
}