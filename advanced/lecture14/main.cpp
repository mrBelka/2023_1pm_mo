#include <iostream>
#include <mutex>

class String
{
	char* m_str;
	size_t m_size; // size_t == unsigned long long

public:
	String(const char* s) 
	{
		std::cout << "Constr" << std::endl;

		m_size = strlen(s) + 1;
		m_str = new char[m_size];
		
		// Неэффективно
		//for (size_t i = 0; i < m_size; i++)
		//	m_str[i] = s[i];
		// std::copy, memcpy
		// Копирует по 8 байтов
		std::copy(s, s + m_size, m_str);
	}
	
	// Правило трех (Rules of Three): деструктор, констр. копирования, оператор присваивания копир.
	// Конструктор копирования
	String(const String& other) : String(other.m_str)
	{
		std::cout << "Copy constr" << std::endl;

		/*
		// Без делегирующего конструктора
		m_size = other.m_size;
		m_str = new char[m_size];
		std::copy(other.m_str, other.m_str + m_size, m_str);*/
	}

	// Оператор присваивания копированием
	// слева - this, справа - other
	// s2 = (s2 = s1);

private:
	void Swap(String& s)
	{
		std::swap(m_str, s.m_str);
		std::swap(m_size, s.m_size);
	}

public:
	String& operator=(String copy)
	{
		std::cout << "Copy operator " << m_str << std::endl;
		Swap(copy);
		return *this;
	}

	// move-семантика
	// Конструктор перемещения
	// Оператор присваивания перемещением

	void Print() const
	{
		// константный указатель
		//char const* p1;
		//m_str = nullptr; ERROR
		// m_str[1] = 2; OK
		// указатель на константу
		//const char* p2;
		// m_str = nullptr; OK
		// m_str[1] = 2; ERROR
		// константный указатель на константу
		//const char* const p3 = m_str;

		// String const& s
		// const String&
		std::cout << m_str << std::endl;
	}

	~String() 
	{
		std::cout << "Destr" << std::endl;
		delete[] m_str;
	}
};

void f(String s)
{
	s.Print();
}

struct Longitude
{
private:
	double m_value;
public:
	explicit Longitude(double value)
	{
		m_value = value;
	}
};

struct Latitude
{
private:
	double m_value;
public:
	explicit Latitude(double value)
	{
		m_value = value;
	}
};

void g(Latitude lat, Longitude longitude)
{
	// ...
}

int main() {
	//Latitude lat(54.123);
	//Longitude longitude(20.5);
	//g(lat, longitude);

	String s1("Hello");
	//s1.Print();
	//f("Hello");

	String s3("abc");


	String s2 = "111";		// Конструктор копирования
	s3 = s2 = s1;			// Оператор присваивания копированием
	s2.Print();

	//s3 = s2 + 'a';

	return 0;
}