#pragma once
#include <iostream>

namespace mt
{
    class String
    {
    private:
        // ����
        char* m_str;                    // 8 + 1000
        unsigned long long m_length;    // 8

    public:
        // ������
        // �����������
        String(char* str);

        // ����������� �����������
        // �������� ������������ ������������

        // ����������
        ~String();

        unsigned long long length();
    };
}