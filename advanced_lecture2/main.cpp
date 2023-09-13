// Подключение библиотеки 
#include <iostream>
#include <iomanip>
#include <string>

namespace mt
{
    void to_string() {}
}

// Точка входа в программу
int main()
{
    setlocale(LC_ALL, "Rus");

    // Символьный
    char ch = 'д';
    std::cout << ch << std::endl;

    // Целочисленные типы
    char d = 10; // -128..127, 1 байт
    unsigned char d1 = 257; // 0..255, 1 байт

    std::cout << (int)d1 << std::endl;

    // short - 2 байта, -2^15 .. 2^15-1
    // unsinged short, 2 байта, 0..2^16-1

    // int - 4 байт, -2^31 .. 2^31-1
    // unsinged int - 4 байт, 0..2^32-1

    // long long - 8 байт, -2^63 .. 2^63-1
    // unsigned long long - 8 байт, 0..2^64-1

    // больше 8 байтов - длинная арифметика

    // Вещественные типы
    float f = 1.23456789012345678f; // 4 байта
    double d2 = 1.23456789012345678; // 8 байтов

    std::cout << std::setprecision(18) << d2 << std::endl;

    // Логический тип
    bool f1 = true; // true/false, 1/0

    bool f2 = 256;
    std::cout << f2 << std::endl;

    // Присваивание
    int x = 10;

    // Арфиметические действия
    // +, -, *, /, %, ++, --
    int a = 7;
    int b = 2;
    float c = a / b;

    std::cout << c << std::endl;

    // Битовые операции
    // |, &, ~, <<, >>
    unsigned char a1 = 0b0111;
    int b1 = 0b0001;
    int c1 = a1 & b1;

    unsigned char aa = !a1;

    std::cout << (int)aa << std::endl;
    
    std::cout << (20 >> 3) << std::endl;

    

    
    return 0; 
}