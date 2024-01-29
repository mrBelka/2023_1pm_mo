#include <iostream>

class Complex
{
private:
	int m_a, m_b;

public:
	Complex()
	{
		std::cout << "Constr" << std::endl;
	}
	Complex(int a, int b)
	{
		std::cout << "Constr" << std::endl;
		m_a = a;
		m_b = b;
	}

	Complex(const Complex& other)
	{
		std::cout << "Copy Constr" << std::endl;
		m_a = other.m_a;
		m_b = other.m_b;
	}

	Complex& operator=(const Complex& other)
	{
		std::cout << "Copy Assign Oper" << std::endl;
		m_a = other.m_a;
		m_b = other.m_b;
		return *this;
	}

	~Complex()
	{
		std::cout << "Destr" << std::endl;
	}

	void Print()
	{
		std::cout << m_a << "+" << m_b << "*i" << std::endl;
	}

	// Арифметический оператор +
	Complex& operator+=(const Complex& other)
	{
		std::cout << "Oper +=" << std::endl;
		m_a += other.m_a;
		m_b += other.m_b;
		return *this;
	}

	// Return value optimization
	Complex operator+(const Complex& other)
	{
		std::cout << "Oper +" << std::endl;
		Complex tmp(other);
		tmp += *this;
		return tmp;
	}

	Complex operator+(int a)
	{
		std::cout << "Oper +" << std::endl;
		Complex tmp(*this);
		tmp.m_a += a;
		return tmp;
	}

	friend Complex operator+(int a, const Complex& other);
	friend std::istream& operator>>(std::istream& in, Complex& other);
	friend std::ostream& operator<<(std::ostream& out, const Complex& other);

	// -, /, *

	// ++, --
	// Префиксный
	Complex& operator++() // int i; ++i, i++;
	{
		m_a++;
		return *this;
	}

	// Постфиксный
	Complex operator++(int) // RVO
	{
		Complex tmp(*this);
		m_a++;
		return tmp;
	}

	// Сравнение
	bool operator==(const Complex& other)
	{
		if (m_a == other.m_a && m_b == other.m_b)
			return true;
		return false;
	}

	// (), []
	// double, int
};

Complex operator+(int a, const Complex& other)
{
	std::cout << "Oper + outside" << std::endl;
	Complex tmp(other);
	tmp.m_a += a;
	return tmp;
}

std::istream& operator>>(std::istream& in, Complex& other)
{
	std::cin >> other.m_a >> other.m_b;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Complex& other)
{
	out << other.m_a << "+" << other.m_b << "*i";
	return out;
}

int main()
{
	Complex a(1, 1);
	Complex b(2, 3);

	Complex c = a + b; // copy ellision (пропуск копирования)

	Complex d = a + 1;
	Complex e = 1 + a;

	Complex f = a++;
	std::cout << f << std::endl;

	Complex g;
	std::cin >> g;
	g++;
	std::cout << (g==f) << std::endl;

	return 0;
}
