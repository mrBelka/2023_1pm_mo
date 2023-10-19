#include "functions.hpp"
#include <iostream>

namespace mt
{
	void Read(int matrix[N_Max][N_Max], int& n, int& m)
	{
		std::cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				std::cin >> matrix[i][j];
	}

	void Write(int matrix[N_Max][N_Max], int n, int m)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				std::cout << matrix[i][j] << " ";
			std::cout << std::endl;
		}
	}

	bool isPrime(int x)
	{
		if (x < 2)
			return false;
		for (int d = 2; d < sqrt(x) + 1; d++)
			if (x % d == 0)
				return false;
		return true;
	}

	bool isPrimeExistsInMatrix(int matrix[N_Max][N_Max], int n, int m)
	{
		for (int i = 0; i < n; i++)
		{
			bool flag = false; // Нет простого числа в строке
			for (int j = 0; j < m; j++)
				if (isPrime(matrix[i][j]))
					flag = true;
			if (!flag)
				return false;
		}
		return true;
	}

	bool isConsistSeven(int x)
	{
		while (x)
		{
			if (x % 10 == 7)
				return true;
			x /= 10;
		}
		return false;
	}

	bool isConsistSevenInMatrix(int matrix[N_Max][N_Max], int n, int m)
	{
		for (int i = 0; i < n; i++)
		{
			bool flag = false; // Нет числа с цифрой 7 в строке
			for (int j = 0; j < m; j++)
				if (isConsistSeven(matrix[i][j]))
					flag = true;
			if (!flag)
				return false;
		}
		return true;
	}

	void findBiggestElems(int matrix[N_Max][N_Max], int biggestElems[N_Max], int n, int m)
	{
		for (int i = 0; i < n; i++)
		{
			biggestElems[i] = matrix[i][0];
			for (int j = 1; j < m; j++)
				if (biggestElems[i] < matrix[i][j])
					biggestElems[i] = matrix[i][j];
		}
	}

	void replaceDiagonal(int matrix[N_Max][N_Max], int biggestElems[N_Max], int n, int m)
	{
		for (int i = 0; i < n; i++)
			matrix[i][i] = biggestElems[i];
	}
}