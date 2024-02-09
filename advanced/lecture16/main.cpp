#include <iostream>

class Counter
{
public:
    Counter() = default;
    Counter(int n)
    {
        value = n;
    }
    void print() const
    {
        std::cout << "value: " << value << std::endl;
    }
    operator int() {
        return value;
    }
private:
    int value;
};

struct Lattitude
{
    double m_lattitude;
    int n;
    Counter c;

    operator Counter() {
        return m_lattitude;
    }

    operator double()
    {
        return m_lattitude;
    }
};

class Array
{
    int n = 100;
    int arr[100] = { 1,2,3 };
    int mat[100][100];

public:
    int at(int index)
    {
        if (index >= 0 && index < n)
        {
            return arr[index];
        }

        // Исключение
        std::cerr << "Out of range" << std::endl;
        return 0;
    }

    /*int& operator[](int index)
    {
        return arr[index];
    }*/

    int operator()(int index)
    {
        return arr[index];
    }

    int operator()(int i, int j)
    {
        return mat[i][j];
    }

    int* operator[](int rowIndex)
    {
        return mat[rowIndex];
    }
};

// Не более 1000 цифр в числе
class Complex
{
    float a;
    float b;
    char str[1000];

    bool operator==(const Complex& other)
    {
        //return (a == other.a) && (b == other.b);
        return strcmp(str, other.str) == 0;
    }

    bool operator!=(const Complex& other)
    {
        return !(*this == other);
    }

    bool operator<(const Complex& other)
    {
        return strcmp(str, other.str) < 0; // 
    }

    bool operator>(const Complex& other)
    {
        return !(*this < other) && !(*this == other); // 
    }
};

int main()
{
    //unsigned long long ll = 0;// 0..2^64-1
    
    
    Array arr;
    arr.at(1);

    //int tmp = arr[1];
    arr(1);

    //arr[2] = 2;

    arr[1][1];

    arr(1, 1);


    /*Lattitude lat = {54.123};

    double tmp = lat;

    std::cout << tmp << std::endl;*/
}