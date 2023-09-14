#include <iostream>

int main() {

    setlocale(LC_ALL, "Rus");
    // 1. Кодировка файла
    // 2. SetConsoleOutputCP

    // Символьный тип
    char ch = 'Д';
    //std::cout << ch << std::endl;

    // Целочисленные типы
    char ch1 = 97; // 1 байт, -128..127
    unsigned char char2 = 240; // 1 байт, 0..255

    short sh; // 2 байта, -2^15..2^15-1
    unsigned short sh1; // 2 байта, 0..2^16-1

    int in; // 4 байта, -2^31..2^31-1
    unsigned int in1; // 4 байт, 0..2^32-1

    long long ll; // 8 байт, -2^63..2^63-1
    unsigned long long ll1; // 8 байт, 0..2^64-1

    // Вещественные типы
    float f;   // 4 байта, 7 значащих цифр
    double d;  // 8 байт, 15 значащих цифр

    // Логический тип
    bool flag = 256;  // 1 байт, 0/1, false/true
    unsigned char ch3 = 256;

    // Ввод-вывод
    //int x;
    double y;
    //std::cin >> x >> y;
    //std::cout << x << " " << y;

    // Арифметические операции
    // +,-,*,/,%,++,--
    int t = 10;
    std::cout << t++ << std::endl;

    /*int a = 7;
    int b = 2;
    int x = a % b;

    std::cout << x << std::endl;*/

    // Битовые операции
    // |, &, ~, <<, >>
    unsigned char x = 0b00000000; // 0-откл, 1-вкл

    // x        0b00000000
    // (1 << 3) 0b00001000
    //          0b01001010
    //          0b01000010
    x |= (1 << 3);  // 0b00000001, 0b00000010, 0b00000100

    x = x & (~(1 << 3));
    // x          0b01001010
    // 1 << 3     0b00001000
    // ~(1 << 3)  0b11110111
    // &
    //  x  0b01001010
    //     0b11110111
    // res 0b01000010


    


    return 0;
}