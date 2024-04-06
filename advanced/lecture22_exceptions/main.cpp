#include <iostream>
#include <exception>

class B
{
public:
	~B() noexcept
	{
		// НЕЛЬЗЯ
		//throw std::runtime_error("Destr B");
	}
};

class A
{
	//B b;
	int m_a, m_b;
	int* m_buf;
public:
	A()
	{
		std::cout << "Constr a" << std::endl;
	}
	void Setup(int a, int b)
	{
		m_buf = new int[1000];
		if (a < 0)
			throw std::logic_error("Negative value");
		m_a = a;
		m_b = b;
	}
	~A() noexcept
	{
		std::cout << "Destr a" << std::endl;
		delete[] m_buf;
		// НЕЛЬЗЯ
		//throw std::runtime_error("Destr A");
	}
};

float f(float a, float b)
{
	if (b == 0)
		throw std::invalid_argument("Dividing by zero"); //"Dividing by zero"; // Бросить исключение
	if (a > 100)
		throw std::out_of_range("Upper limit of var a");
	if (b == 1)
		throw std::length_error("Length");
	return a / b;
}

void g(std::shared_ptr<A> p1, std::shared_ptr<B> p2)
{

}


int main()
{
	int x = 1, y = 2;
	//std::cin >> x >> y;

	g(std::make_shared<A>(), new B);

	try
	{
		A a;
		a.Setup(-2, 3);
		float d = f(x, y);
		std::cout << d << std::endl;
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << "Invalid arg " << e.what() << std::endl;
	}
	catch (const std::out_of_range& e)  // const char* msg
	{
		std::cout << "Out of range " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception error " << e.what() << std::endl;
	}
	/*catch (...)
	{
		std::cout << "111" << std::endl;
	}*/

	/*int errorCode = 0;
	float d = f(x,y, errorCode);

	if(errorCode == 0)
		std::cout << d << std::endl;
	else if(errorCode == -1)
		std::cout << "dividing by zero" << std::endl;*/

	//int a = 5, b = 10;
	//int sum = a + b;
	//std::cout << "Sum " << sum << std::endl;

	return 0;
}