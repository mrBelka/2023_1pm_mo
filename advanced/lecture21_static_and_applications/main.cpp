#include <iostream>
#include <Log.hpp>

class Test
{
	static unsigned int m_cnt;
	int m_n;

public:
	Test()
	{
		m_cnt++;
		mt::LogSimple::Debug("Constructor");
	}

	void Print()
	{
		std::cout << m_cnt << std::endl;
	}

	static void PrintS()
	{
		std::cout << m_cnt << std::endl;
	}
};

unsigned int Test::m_cnt = 0;

int main()
{
	mt::LogSimple::SetLogFile("log.txt");
	mt::LogSimple::SetLogLevel(mt::Level::DEBUG);
	mt::LogSimple::Debug("Message 1" + std::to_string(10));
	mt::LogSimple::Warn("Message 2");

	qDebug() << "111" << 10 << 2.3;
	qWarn() << "111" << 10 << 2.3;
	//mt::LogExtra() << 10 << 2.3;
	//mt::LogExtra() << 2.3;
	//mt::LogExtra();

	//mt::Log log;
	//log.Write("message");

	// 10:37:01 Constuctor called - debug
	// 10:37:01 Process started - debug / release (white) - info
	// 11:00:00 Global error - debug / release (red) - error
	// 11:01:00 Warning - debug / release (yellow) - warn

	// ТЗ
	// Переключать режимы debug/release
	// Время
	// Цветовая маркировка
	// Файл логов


	Test t1;
	t1.PrintS();

	Test t2;
	t2.Print();

	Test t3;
	t1.Print();

	Test::PrintS();

	/*int n = 3;
	for (int i = 0; i < n; i++)
	{
		int x;
		std::cin >> x;

		static int max = x;

		if (max < x)
			max = x;

		std::cout << max << std::endl;
	}*/

	return 0;
}