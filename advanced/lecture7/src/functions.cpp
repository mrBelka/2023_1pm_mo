#include <functions.hpp>
#include <cmath>

namespace mt
{
	char to_lower(char c)
	{
		if (c >= 65 && c <= 91)
			c += 32;
		return c;
	}

	bool isLetter(char c)
	{
		c = to_lower(c);
		if (c >= 97 && c <= 122)
			return true;
		return false;
	}

	bool isPrime(int x)
	{
		for (int d = 2; d <= sqrt(x); d++)
			if (x % d == 0)
				return false;
		return true;
	}

	void DuplicateOdd(int* mas, int& n)
	{
		int i = 0;
		while (i < n)		// n
		{
			if (mas[i] % 2 == 1)
			{
				for (int j = n; j > i; j--) // n/2
					mas[j] = mas[j - 1];
				n++;
				i++;
			}
			i++;
		}
	}

	void swap(int& a, int& b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}

	int sumOfDigits(int x)
	{
		int sum = 0;
		while (x > 0)
		{
			sum += x % 10;
			x /= 10;
		}
		return sum;
	}
}