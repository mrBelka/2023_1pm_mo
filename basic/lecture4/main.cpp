//#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <thread>

class Test
{
private:
	std::string m_name;
public:
	Test(const std::string& name)
	{
		m_name = name;
		std::cout << "Const " << m_name << std::endl;
	}
	~Test()
	{
		std::cout << "Destr " << m_name << std::endl;
	}
};

int main()
{
	/*std::cout << 0 << std::endl;
	std::cout << 1 << std::endl;
	std::cout << 2 << std::endl;*/

	/*// 1
	int i = 0; // счетчик, итератор
	while (i <= 10)
	{
		std::cout << i << std::endl;
		i++;
	}

	// 2
	i = 0;
	do
	{
		std::cout << i << std::endl;
		i++;
	} while (i <= 10);

	// 3
	for (int i = 0; i <= 10; i++)
		std::cout << i << std::endl;*/

	/*// Сумма всех четных чисел
	int n;
	int sum = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		std::cin >> x;

		if (x % 2 == 0)
			sum += x;
	}

	std::cout << sum << std::endl;*/

	// Алгоритм распаковки натурального числа
	// 123 -> 1 2 3

	/*int max = 0;
	int k = 123;
	while (k)
	{
		int digit = k % 10;

		if (digit > max)
			max = digit;

		std::cout << digit << std::endl;
		k /= 10;
	}*/

	/*// Определение простоты числа
	bool flag = true;
	int p = 100;
	for (int d = 2; d <= sqrt(p); d++)
	{
		if (p % d == 0)
		{
			flag = false;
			break;
		}
	}

	if (flag)
		std::cout << "Prime" << std::endl;
	else
		std::cout << "Complex" << std::endl;*/

	/*int n;
	int sum = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		std::cin >> x;

		if (x % 2 == 0)
			continue;
			
		sum += x;
	}

	int i = 0;
	while (i < 10)
	{
		int x;
		std::cin >> x;

		if (x % 2 == 0)
		{
			i++;
			continue;
		}

		sum += x;
		i++;
	}*/

	//int i = 0;

	/*for (int i = 0; i < 10; i++)
	{

	}*/

	Test x("10");

	{
		Test x("12");
	}
	
	std::cout << "After {}" << std::endl;

	//int mas[1'000'000];


	for (;;)
	{
		int* p = new int[10'000'000];
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
	// ...
	//delete[] p;

	return 0;
}