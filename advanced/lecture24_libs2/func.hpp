#include <iostream>
#include <string.h>

extern "C" 
{
    __declspec(dllexport) int add(int a);
    __declspec(dllexport) int sum(int a, int b);
}