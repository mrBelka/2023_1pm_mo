#include <iostream>
#include <vector>

int main() {
    // Логические операции
    // ||, &&, !, ==, <, >, <=, >=, !=
    bool f1 = true;
    bool f2 = false;

    int a = 10; // 0b1010
    int b = 7;  // 0b0111
    std::cout << (a < 100 && a > 0) << std::endl;

    // Условные конструкции
    // if..else
    if ((a < 100 && a > 0) || (b > 8 && !a))
    {
        std::cout << "Consists" << std::endl;
    }

    std::cout << std::boolalpha << (b > 6 && a++) << std::endl;
    std::cout << a << std::endl; 
    // && 

    if (a > 10)
    {
        std::cout << "True" << std::endl;
    }
    else
    {
        std::cout << "Else" << std::endl;
        a++;
    }

    if (a > 0)
    {
        if (b > 0)
        {

        }
        else if (a < 100)
        {

        }
    }

    // switch
    int d = 10;
    if (d == 0)
    {

    }
    else if (d == 1)
    {

    }

    int error = 10;
    switch (error)
    {
    case 0: std::cout << "File not open" << std::endl;
            break;
    case 1: std::cout << "System failed" << std::endl;
            break;
    default: std::cout << "default" << std::endl;
    }

    // тернарный оператор
    int g = 0;
    std::cout << (g == 0 && a > 10 ? "Zero" : "Not zero") << std::endl;

    char ch = g == 0 ? '+' : '-';

    char ch1 = '-';
    if (!g)
        ch1 = '+';

    bool flag = true;
    if (!flag)
        std::cout << "something" << std::endl;

    (g == 0) ? std::cout << "111" : std::cout << "222";

    if (a % 2)
    {

    }

    // 0b0101
    // 0b0001
    // 
    // 0b0100
    // 0b0001
    // 
    // 0b0110

    if (!(a & 1))
    {

    }

    // Циклы
    // while
    int i = 10; // Счетчик, итератор
    while (i > 0)
    {
        std::cout << i << std::endl;
        i--;
    }

    // do..while
    i = 0;
    do
    {
        std::cout << i << std::endl;
        i++;
    } while (i < 10);

    // for
    for (int i = 0; i < 10; i++)
        std::cout << i << std::endl;

    auto x = 10u;


    // Даны n элементов, посчитать их сумму
    int n;
    std::cin >> n;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        sum += x;
    }

    // Алгоритм распаковки натурального числа
    x = 123;
    int max = 0;
    sum = 0;
    while (x > 0)
    {
        int d = x % 10;
        if (max < d)
            max = d;
        x /= 10;
    }

    // Алгоритм проверки числа на простоту

    //
    i = 0;
    sum = 0;
    do
    {
        std::cin >> x;

        if (x < 0)
            continue;

        sum += x;

    } while (sum > 10);


    // Бесконечный цикл
/*    while (1)
    {

    }

    do
    {

    }while (1);*/


    // setup

    while (1)
    {

    }




    return 0;
}