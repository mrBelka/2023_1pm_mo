#include <iostream>
#include <vector>

namespace mt
{
	template <typename T>
	void swap(T& a, T& b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

	template <typename T>
	class Matrix
	{
		T** m_mat;
		int m_n, m_m;

	public:
		Matrix(int n, int m)
		{
			m_n = n;
			m_m = m;
			m_mat = new T* [m_n];
			for (int i = 0; i < m_n; i++)
				m_mat[i] = new T[m_m];
		}

		Matrix(const Matrix& other) = delete;
		Matrix& operator=(const Matrix& other) = delete;

		~Matrix()
		{
			for (int i = 0; i < m_n; i++)
				delete[] m_mat[i];
			delete[] m_mat;
		}

		T& operator()(int i, int j)
		{
			return m_mat[i][j];
		}

		T* operator[](int i)
		{
			return m_mat[i];
		}

		void Print()
		{
			for (int i = 0; i < m_n; i++)
			{
				for (int j = 0; j < m_m; j++)
					std::cout << m_mat[i][j] << " ";
				std::cout << std::endl;
			}
		}
	};

	template <typename T, int N, int M>
	class MegaMatrix
	{
		T m_mat[N][M];

	public:
		MegaMatrix() = default;

		T& operator()(int i, int j)
		{
			return m_mat[i][j];
		}

		template <int L>
		MegaMatrix<T, N, L> operator*(const MegaMatrix<T, M, L>& other)
		{
			MegaMatrix<T, N, L> mat;
			mat(0, 0) = 1;
			// TODO умножение
			return mat;
		}

		void Print()
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
					std::cout << m_mat[i][j] << " ";
				std::cout << std::endl;
			}
		}

		T Det()
		{
			if constexpr (N == 1)
			{
				m_mat[0][0];
			}
			else if constexpr (N == 2)
			{
				m_mat[1][1];
			}
			else if constexpr (N == 3)
			{
				m_mat[2][2];
			}
		}
	};

	using Vector2i = MegaMatrix<int, 2, 1>;
	using Vector2f = MegaMatrix<float, 2, 1>;
	using Matrix22i = MegaMatrix<int, 2, 1>;

	template <typename T>
	class vector
	{
	public:
		void Print()
		{
			std::cout << "Any type, not bool" << std::endl;
		}

		void push_back()
		{

		}
	};

	// Специализация шаблона
	template <>
	class vector<bool>
	{
		unsigned char* m_buf;
	public:
		void Print()
		{
			std::cout << "Only bool" << std::endl;
		}

		void push_back(bool b)
		{

		}
	};
}

class Cats
{

};

int main()
{
	std::vector<Cats*> v;
	Cats* cat = new Cats;
	// ...

	v.push_back(cat);

	//
	for (auto& cat : v)
		delete cat;
	v.clear();

	mt::vector<int> v1;
	mt::vector<bool> v2;
	v1.Print();
	v2.Print();

	//std::vector<char> vec;		// 1 байт
	//std::vector<bool> vecbool;	// 1 байт


	mt::MegaMatrix<int, 2, 2> m1;
	mt::MegaMatrix<int, 2, 2> m2;

	auto m = m2 * m1;
	m.Print();



	float a = 10;
	float b = 5;

	mt::swap(a, b); // Неявно
	mt::swap<float>(a, b); // Явно

	mt::Matrix<char> mat1(3, 3);
	mat1(0, 0) = 'a';
	mat1(0, 1) = 'b';

	mt::Matrix<float> mat2(3, 1);
	mat2(0, 0) = 5.5f;
	mat2(1, 0) = 3.24f;
	mat2[2][0] = 0.2f;

	//mat1.Print();
	//mat2.Print();

	mt::MegaMatrix<int, 2, 2> mat3;
	mat3(0, 0) = 2;
	mat3(1, 0) = 3;
	mat3(0, 1) = 4;
	mat3(1, 1) = 5;

	mt::Vector2i vec1;

	mat3.Print();

	return 0;
}