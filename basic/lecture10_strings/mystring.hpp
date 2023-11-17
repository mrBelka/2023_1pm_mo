#pragma once

namespace mt
{

    unsigned int strlen(char* str);
    void strcat(char* dst, char* src);
    void strcat(char* dst, char src);
    char tolower(char c);
    void tolower(char* str);
    bool isLetter(char c);
    bool isVowel(char c);
    void splitText(char text[1000], char words[500][50], int& n);
    bool isTwoWordsEqual(char words[500][50], int n);
    int numOfVolews(char word[50]);
    bool isConsonant(char c);
    void duplicateConsonant(char word[50]);
    void removeVowels(char word[50]);
    bool isMyLetter(char letters[50], char c);
    void myDuplicate(char letters[50], char word[50]);

}