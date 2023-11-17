#include <iostream>
#include <fstream>
#include "mystring.hpp"

/*
Дана строка, содержащая русский текст.
Если в тексте есть два одинаковых слова,
то вывести слова текста в алфавитном поpядке,
в противном случае удалить из слов текста гласные
и пpодублиpовать в словах, содеpжащих не более 3-х гласных,
звонкие согласные буквы. ( Звонкие согласные: бвгжздйлмнр )
*/
// ANSI, cp1251
#include <string>

int main()
{
    setlocale(LC_ALL, "Rus");


    int num[256] = { 0 };
    char letter[256] = { 0 };
    std::string str = "Привет, мир!";
    for (int i = 0; i < str.length(); i++)
    {
        //std::cout << (int)(unsigned char)str[i] << std::endl;
        num[(unsigned char)str[i]]++;
    }

    for (int i = 0; i < 256; i++)
    {
        letter[i] = i;
    }

    for(int i=0;i<256;i++)
        for(int j=i+1;j<256;j++)
            if (num[i] < num[j])
            {
                std::swap(num[i], num[j]);
                std::swap(letter[i], letter[j]);
            }

    for(int i=0;i<4;i++)
        std::cout << letter[i] << " " << num[i] << std::endl;

    return 0;


    std::string s = "Привет, мир!";
    s += '?';

    std::cout << (s.find('е') != std::string::npos) << std::endl;

    //s.erase(1, 2);

    //std::cout << s.substr(1,2) << std::endl;

    std::cout << s[1] << std::endl;


    return 0;

    // Ввод текста
    std::ifstream in("input.txt");
    
    char text[1000];
    in.getline(text, 1000);

    // Алгоритм распаковки слов
    char words[500][50];
    int n = 0;
    
    mt::splitText(text, words, n);

    if (mt::isTwoWordsEqual(words, n))
    {
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (strcmp(words[i], words[j]) == 1)
                {
                    char tmp[50];
                    strcpy_s(tmp, words[i]);
                    strcpy_s(words[i], words[j]);
                    strcpy_s(words[j], tmp);
                }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if(mt::numOfVolews(words[i]) <= 3)
                mt::duplicateConsonant(words[i]);

            mt::removeVowels(words[i]);
        } 
    }

    char letters[50] = {0};

    char a = 'и';
    
    mt::strcat(letters, a);

    std::cout << letters << std::endl;
    
    
    char word[50] = "абвгдп";
    
    bool flag = true; // согласные упорядочены
    char c = 0;

    for(int i=0;i<strlen(word);i++)
        if (mt::isConsonant(word[i]))
        {
            if (c == 0)
            {
                c = word[i];
                continue;
            }

            if (c < word[i])
            {
                c = word[i];
            }
            else
            {
                flag = false;
                break;
            }
        }

    //mt::myDuplicate(letters, word);
    std::cout << flag << std::endl;


    std::ofstream out("output.txt", std::ios::app);

    for (int i = 0; i < n; i++)
        out << "<" << words[i] << ">" << std::endl;

    return 0;
}