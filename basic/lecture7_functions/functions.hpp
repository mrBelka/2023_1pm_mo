#pragma once
#define N_Max 100

namespace mt
{
	void Read(int matrix[N_Max][N_Max], int& n, int& m);

	void Write(int matrix[N_Max][N_Max], int n, int m);

	bool isPrime(int x);

	bool isPrimeExistsInMatrix(int matrix[N_Max][N_Max], int n, int m);

	bool isConsistSeven(int x);

	bool isConsistSevenInMatrix(int matrix[N_Max][N_Max], int n, int m);

	void findBiggestElems(int matrix[N_Max][N_Max], int biggestElems[N_Max], int n, int m);

	void replaceDiagonal(int matrix[N_Max][N_Max], int biggestElems[N_Max], int n, int m);

}