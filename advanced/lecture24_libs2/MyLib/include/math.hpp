#pragma once
#include <iostream>

namespace mt
{
    class String
    {
    private:
        // поля
        char* m_str;                    // 8 + 1000
        unsigned long long m_length;    // 8

    public:
        // методы
        // Конструктор
        String(char* str);

        // Конструктор копирования
        // Оператор присваивания копированием

        // Деструктор
        ~String();

        unsigned long long length();
    };
}