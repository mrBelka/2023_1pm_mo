#include <iostream>
#include <vector>
#include <thread>
#include <memory>

//#define vs std::vector<std::string>

namespace mt
{
    const int x = 10;

    typedef std::vector<std::string> vs;
    
    using vs = std::vector<std::string>;
}

void print(int& n)
{
    vs t;
    t.push_back("1111");
}

void bar(int* n)
{
    *n = 10;
}

void foo(float*& mas, int n)
{
    mas[1] = 777;
    for (int i = 0; i < n; i++)
    {
        std::cout << mas[i] << std::endl;
    }
    std::cout << "====" << std::endl;
    delete[] mas;
    mas = nullptr;
}

void foo1(std::unique_ptr<int> p1, std::unique_ptr<int> p2)
{

}

int main()
{
    /*try {
        foo1(std::make_unique<int>(10), std::make_unique<int>(10));
    }
    catch ()
    {

    }

    std::unique_ptr<int> p = std::make_unique<int>(10);


    int mas[1'000'000];

    std::vector<int> n;
    // int* begin - 8 байтов
    // int* end - 8 байтов
    // int* cap - 8 байтов
    // 32 байта

    // int* begin = new int[1000];

    // Конструктор
    // Деструктор
    // RAII





    int mas[10] = { 1,2,3 }; // 40б стека Фиксированной длины

    int* p_mas = new int[10]; // 8б стека, 40б хипа (heap)

    delete[] p_mas;



    double d1 = 1.25;
    double d2 = 1.25;

    if (abs(d1 - d2) < 1e-12)
    {

    }

    // Ссылка
    // 1. Псевдоним
    int sumOfEvenDigitsOfNaturalNumbers = 10;
    
    int& s = sumOfEvenDigitsOfNaturalNumbers;

    {
        s = 10;
    }

    // 2. Передача по ссылке
    print(s);


    // Задача №2
    int t = 10;
    int r = *&t;



    int q = 5;
    bar(&q);
    std::cout << &q << std::endl; // адрес
    std::cout << q << std::endl;


    // Указатель
    float* p = new float;
    int n = 3;
    float* p_mas = new float[100] {1,2,3};

    for (int i = 0; i < n; i++)
    {
        std::cout << p_mas[i] << std::endl;
    }
    std::cout << "====" << std::endl;

    // Some code
    foo(p_mas, n);*/

    /*for (int i = 0; i < n; i++)
    {
        std::cout << p_mas[i] << std::endl;
    }*/

    //std::cout << p_mas << std::endl;

    //delete p;
    //delete[] p_mas;


    /*int n = 250;
    int m = 1000;
    float** p_matrix = nullptr;

    while (1)
    {
        float** p_matrix = new float*[n];
        for (int i = 0; i < n; i++)
            p_matrix[i] = new float[m];

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        p_matrix[0][1] = 3;

        for (int i = 0; i < n; i++)
            delete[] p_matrix[i];
        delete[] p_matrix;
    
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }*/

    // Ссылка


    /*// Загадка
    char arr[4] = { 232, 3, 0, 0 };

    int* q = (int*)arr;

    std::cout << *q << std::endl;


    return 0;


    // Массив
    int* mas = new int[2];

    //mas[0] = 10;
    *mas = 10;

    //mas[1] = 21;
    *(mas + 1) = 21;

    std::cout << mas << std::endl;
    std::cout << mas + 1 << std::endl;
    std::cout << mas[1] << std::endl;


    delete[] mas;

    return 0;


    // Указатели
    int* p = new int;

    std::cout << p << std::endl;
    std::cout << sizeof(p) << std::endl;

    *p = 10;  // разыменование

    delete p;

    p = new int;
    std::cout << p << std::endl;
    std::cout << *p << std::endl;

    delete p;

    return 0;

    std::vector<int> v;

    std::cout << v.size() << std::endl;

    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        v.push_back(x);
        std::cout << v.size() << " " << v.capacity() << std::endl;
    }

    std::cout << "Size = " << v.size() << std::endl;
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << std::endl;

    // удалять элементы
    v.erase(v.begin()+1);

    std::cout << "Size = " << v.size() << std::endl;
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << std::endl;

    // дублирование элементов
    v.insert(v.begin() + 1, 10);

    std::cout << "Size = " << v.size() << std::endl;
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << std::endl;

    // очистка
    //v.clear();

    std::cout << "Size = " << v.size() << std::endl;
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << std::endl;*/


    /*int mas[10000];
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
        std::cin >> mas[i];

    for (int i = 0; i < n; i++)
        std::cout << mas[i];*/
}