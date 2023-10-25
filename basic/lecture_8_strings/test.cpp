#include <iostream>
#include <fstream>

namespace mt
{
    unsigned int strlen(char* str)
    {
        int len = 0;
        while (str[len] != '\0')
            len++;
        return len;
    }

    void strcat(char* dst, char* src)
    {
        int len_dst = strlen(dst);
        int len_src = strlen(src);

        for (int i = 0; i < len_src; i++)
            dst[len_dst + i] = src[i];

        dst[len_dst + len_src] = '\0';
    }

    char tolower(char c)
    {
        if ('A' <= c && c <= 'Z')
            return c + 32;
        return c;
    }

    void tolower(char* str)
    {
        for (int i = 0; i < strlen(str); i++)
            str[i] = tolower(str[i]);
    }
}

int main()
{
    char ch = 'a'; // 97
    char str[100] = "Hello!";

    std::cout << str << std::endl;

    // Обратиться к символу по индексу
    std::cout << str[0] << std::endl;

    // Длина строки
    std::cout << mt::strlen(str) << std::endl;

    // Копирование строк
    char copy[100];
    strcpy_s(copy, str);

    std::cout << copy << std::endl;

    // Сложение строк (конкатенация)
    mt::strcat(copy, str);
    std::cout << copy << std::endl;

    // Лексикографический порядок
    char str1[100] = "aaa";
    char str2[100] = "Aaa";
    mt::tolower(str1);
    mt::tolower(str2);
    std::cout << strcmp(str1, str2) << std::endl;

    // Файл
    std::ifstream in("assets/input.txt");
    if (!in.is_open())
    {
        std::cout << "File error" << std::endl;
        return -1;
    }

    // до первого пробела
    //in >> str;

    // чтение всей строчки
    //in.getline(str, 100);

    // посимвольное чтение
    /*while (!in.eof())
    {
        in >> ch;
        std::cout << ch << std::endl;
    }*/

    char word[10][100];
    int n = 0;
    while (!in.eof())
    {
        in >> word[n];
        mt::tolower(word[n]);
        n++;
    }

    for (int i = 0; i < n; i++)
        std::cout << "<" << word[i] << ">" << std::endl;

    for(int i=0;i<n-1;i++)
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(word[i], word[j]))
            {
                char tmp[100];
                strcpy_s(tmp, word[i]);
                strcpy_s(word[i], word[j]);
                strcpy_s(word[j], tmp);
            }
        }

    for (int i = 0; i < n; i++)
        std::cout << "<" << word[i] << ">" << std::endl;

    return 0;
}