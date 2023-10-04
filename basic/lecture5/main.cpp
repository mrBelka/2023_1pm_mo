#include <iostream>
//#define N_Max 3000

int main()
{
	// Нам дана последовательность до N_max элементов
	// Отсортировать по последней цифре числа, если цифры равны, то отсортировать
	// по самому числу

	/*const int N_Max = 3000;
	int n;
	std::cin >> n;

	// массив фиксированной длины
	int mas[N_Max];
	int last_digit[N_Max];

	for (int i = 0; i < n; i++)
	{
		std::cin >> mas[i];
	}

	for (int i = 0; i < n; i++)
	{
		last_digit[i] = mas[i] % 10;
	}


	// Сортировка swap-sort
	for(int i=0;i<n-1;i++)  // n
		for(int j=i+1;j<n;j++) // n/2
			if ((last_digit[i] > last_digit[j]) ||
				(last_digit[i] == last_digit[j] && mas[i] > mas[j]))
			{
				int tmp = mas[i];
				mas[i] = mas[j];
				mas[j] = tmp;
				tmp = last_digit[i];
				last_digit[i] = last_digit[j];
				last_digit[j] = tmp;
			}


	for (int i = 0; i < n; i++)
	{
		std::cout << mas[i] << " ";
	}*/

	const int N_Max = 3;
	const int M_Max = 3;

	int matrixA[N_Max][M_Max], matrixB[N_Max][M_Max], result[N_Max][M_Max];
	int n, m;
	std::cin >> n >> m;

	if (n > N_Max || m > M_Max)
	{
		std::cout << "Dimension error!" << std::endl;
		return -1;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			std::cin >> matrixA[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			std::cin >> matrixB[i][j];

	// Перемножение
	//int p = matrix[0][0] * matrix[0][2];

	// Транспонирование
	/*for (int i = 0; i < n-1; i++)
		for (int j = i + 1; j < m; j++)
		{
			int tmp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = tmp;
		}*/

	// Умножение
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < n; k++)
			{
				//std::cout << "i = " << i << " j = " << j << std::endl;
				result[i][j] += matrixA[i][k] * matrixB[k][j];
				//std::cout << result[i][j] << " " << matrixA[i][k] << " " << matrixB[k][j] << std::endl;
			}
		}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			std::cout << result[i][j] << " ";
		std::cout << std::endl;
	}

	return 0;
}