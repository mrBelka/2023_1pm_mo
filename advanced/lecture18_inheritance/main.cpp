#include <iostream>
#include <vector>

// Базовый класс -> Абстрактный класс
class Shape
{
// Только внутри класса, даже при наследовании
private:
	int tmp_var;

// Только внутри класса, также доступна в классах-наследниках
protected:
	std::string m_color; // enum class
	int* p;

public:
	Shape() = default;
	// Shape() {}

	Shape(const std::string& color) // member init. list
	{
		std::cout << "Parent const" << std::endl;
		m_color = color;
	}

	virtual ~Shape()
	{
		std::cout << "Parent destr" << std::endl;
	}

	void setColor(const std::string& color)
	{
		m_color = color;
	}

	std::string getColor()
	{
		return m_color;
	}

	// ???
	virtual double S() = 0;

	double P()
	{
		return 0;
	}
};

// Потомки
class Square : public Shape
{
private:
	double m_a;

public:
	Square() = default; //Square() : Shape() {}
	Square(double a, const std::string& color) : Shape(color)
	{
		std::cout << "Child const" << std::endl;
		m_a = a;
	}
	virtual ~Square()
	{
		std::cout << "Child destr" << std::endl;
	}

	void Setup(double a)
	{
		m_a = a;
	}

	double S() override
	{
		return m_a*m_a;
	}

	double P()
	{
		return 2*(m_a + m_a);
	}
};

class Rect : public Shape
{
private:
	double m_a, m_b;

public:
	Rect() = default; //Square() : Shape() {}
	Rect(double a, double b, const std::string& color) : Shape(color)
	{
		std::cout << "Child const" << std::endl;
		m_a = a;
		m_b = b;
	}
	void Setup(double a, double b)
	{
		m_a = a;
		m_b = b;
	}
	virtual ~Rect()
	{
		std::cout << "Child destr" << std::endl;
	}

	double S()
	{
		return m_a * m_b;
	}

	double P()
	{
		return 2 * (m_a + m_b);
	}
};

enum class Shapes
{
	SQUARE,
	RECT,
};

Shape* Factory(Shapes shape)
{
	if (shape == Shapes::SQUARE)
	{
		// Чтение конфиги, чтение с клавиатуры, рандом
		Shape* s = new Square(2, "red");
		return s;
	}
	else if (shape == Shapes::RECT)
	{
		// Чтение конфиги, чтение с клавиатуры, рандом
		Shape* s = new Rect(2, 3, "red");
		return s;
	}
}

class A
{
private:
	int a;
protected:
	int b;
public:
	int c;
};

class B : protected A
{
	void Test()
	{
		a;
		b;
	}
};

class C : public B
{
	void Test1()
	{
		b;
	}
};

int main()
{
	B bbb;
	//bbb.c;


	std::vector<Shape*> shapes;

	// Создание
	shapes.push_back(Factory(Shapes::SQUARE));
	shapes.push_back(Factory(Shapes::RECT));
	

	// Вывод площади
	for (int i = 0; i < shapes.size(); i++)
		std::cout << shapes[i]->S() << std::endl;

	// Освобождение памяти
	for (int i = 0; i < shapes.size(); i++)
	{
		delete shapes[i];
	}

	return 0;
}