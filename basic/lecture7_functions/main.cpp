#include "functions.hpp"
/*
#16.Дана целочисленная матрица {Aij}i=1...n;j=1..n , n<=100. 
Если в каждой строке матрицы есть хотя бы одно простое число и хотя бы одно число, 
содержащее цифру 7, заменить диагональные элементы на наибольшие элементы 
соответствующих строк. Использовать процедуры и функции!
*/

int main()
{
	// Определение переменных
	int n, m;
	int matrix[N_Max][N_Max];

	// Ввод
	mt::Read(matrix, n, m);

	// Определить, есть ли хотя бы 1 простое число
	// Есть ли хотя бы 1 число, содержащее цифру 7
	if (mt::isPrimeExistsInMatrix(matrix, n, m) &&
		mt::isConsistSevenInMatrix(matrix, n, m))
	{
		int biggestElems[N_Max];
		// Найти наибольшие элементы строк
		mt::findBiggestElems(matrix, biggestElems, n, m);
		// Заменить диагональные элементы на наибольшие элементы строк
		mt::replaceDiagonal(matrix, biggestElems, n, m);
	}

	// Вывод
	mt::Write(matrix, n, m);


	// std::string - 
	// new -> allocator
	// 
	// char buf[1000][100];


	return 0;
}