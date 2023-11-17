#include "mystring.hpp"
#include <string.h>

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

    void strcat(char* dst, char src)
    {
        int len_dst = strlen(dst);
        dst[len_dst] = src;
        dst[len_dst + 1] = '\0';
    }

    char tolower(char c)
    {
        if ('A' <= c && c <= 'Z')
            return c + 32;
        if ('А' <= c && c <= 'Я')
            return c + 32;
        if (c == 'Ё')
            return 'ё';
        return c;
    }

    void tolower(char* str)
    {
        for (int i = 0; i < strlen(str); i++)
            str[i] = tolower(str[i]);
    }

    bool isLetter(char c)
    {
        c = tolower(c);
        if (('а' <= c && c <= 'я') || c == 'ё')
            return true;
        return false;
    }

    bool isVowel(char c)
    {
        c = tolower(c);
        char vowels[11] = { 'а', 'е', 'ё', 'и', 'о', 'у', 'ы', 'э', 'ю', 'я' };

        for (int i = 0; i < strlen(vowels); i++)
            if (c == vowels[i])
                return true;
        return false;
    }

    void splitText(char text[1000], char words[500][50], int& n)
    {
        char word[50] = { 0 };
        int size = 0;

        // последний символ!!!
        char endLetter[2] = ".";
        mt::strcat(text, endLetter);

        for (int i = 0; i < strlen(text); i++)
        {
            if (mt::isLetter(text[i]))
            {
                word[size] = text[i];
                size++;
            }
            else
            {
                if (size == 0)
                    continue;

                word[size] = '\0';
                strcpy_s(words[n], word);
                n++;
                size = 0;
            }
        }
    }

    bool isTwoWordsEqual(char words[500][50], int n)
    {
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (strcmp(words[i], words[j]) == 0)
                    return true;
        return false;
    }

    int numOfVolews(char word[50])
    {
        int result = 0;
        for (int i = 0; i < strlen(word); i++)
            if (isVowel(word[i]))
                result++;
        return result;
    }

    bool isConsonant(char c)
    {
        c = tolower(c);
        char consonant[12] = { 'б', 'в', 'г', 'ж', 'з', 'д', 'й', 'л', 'м', 'н', 'р' };

        for (int i = 0; i < strlen(consonant); i++)
            if (c == consonant[i])
                return true;
        return false;
    }

    void duplicateConsonant(char word[50])
    {
        for (int i = 0; i < strlen(word); i++)
        {
            if (mt::isConsonant(word[i]))
            {
                for (int j = strlen(word) + 1; j >= i; j--)
                    word[j + 1] = word[j];
                i++;
            }
        }
    }

    void removeVowels(char word[50])
    {
        for (int i = 0; i < strlen(word); i++)
        {
            if (mt::isVowel(word[i]))
            {
                for (int j = i; j <= strlen(word); j++)
                    word[j] = word[j + 1];
                i--;
            }
        }
    }

    bool isMyLetter(char letters[50], char c)
    {
        c = tolower(c);
        for (int i = 0; i < strlen(letters); i++)
            if (c == letters[i])
                return true;
        return false;
    }

    void myDuplicate(char letters[50], char word[50])
    {
        for (int i = 0; i < strlen(word); i++)
        {
            if (mt::isMyLetter(letters, word[i]))
            {
                for (int j = strlen(word) + 1; j >= i; j--)
                    word[j + 1] = word[j];
                i++;
            }
        }
    }

}