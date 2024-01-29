#include <iostream>
#include <fstream>
#include <Circle.hpp>

class Matrix
{
	int m_n, m_m;
	int** m_mat;
public:
	Matrix(int n, int m)
	{
		std::cout << "Constr" << std::endl;
		m_n = n;
		m_m = m;
		m_mat = new int*[n];
		for (int i = 0; i < n; i++)
			m_mat[i] = new int[m];
	}

	// Конструктор копирования
	Matrix(const Matrix& other) : Matrix(other.m_n, other.m_m)
	{
		std::cout << "Copy Constr" << std::endl;

		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
				m_mat[i][j] = other.m_mat[i][j];
	}

	// Оператор присваивания копирования
	Matrix& operator=(const Matrix& other)
	{
		for (int i = 0; i < m_n; i++)
			delete[] m_mat[i];
		delete[] m_mat;

		m_n = other.m_n;
		m_m = other.m_m;

		m_mat = new int* [m_n];
		for (int i = 0; i < m_n; i++)
			m_mat[i] = new int[m_m];

		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
				m_mat[i][j] = other.m_mat[i][j];

		return *this;
	}

	~Matrix()
	{
		std::cout << "Destr before" << std::endl;
		for (int i = 0; i < m_n; i++)
			delete[] m_mat[i];
		delete[] m_mat;
		std::cout << "Destr after" << std::endl;
	}
};

int main()
{
	Matrix A(2, 2);
	Matrix B(3, 3);
	Matrix C(2, 3);

	C = B = A;

	return 0;
}