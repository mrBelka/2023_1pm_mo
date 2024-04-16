#include <MyLib/include/math.hpp>

namespace mt
{
    String::String(char* str)
    {
        std::cout << "Const" << std::endl;
        m_length = strlen(str);
        m_str = new char[m_length + 1];
        for (int i = 0; i < m_length; i++)
            m_str[i] = str[i];
        m_str[m_length] = '\0';
    }

    String::~String()
    {
        std::cout << "Destr" << std::endl;
        delete[] m_str;
    }

    unsigned long long String::length()
    {
        return m_length;
    }
}