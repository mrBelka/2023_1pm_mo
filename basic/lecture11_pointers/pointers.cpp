#include <iostream>
#include <vector>

int main()
{
    // Загадка
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
        std::cout << v[i] << std::endl;


    /*int mas[10000];
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
        std::cin >> mas[i];

    for (int i = 0; i < n; i++)
        std::cout << mas[i];*/
}