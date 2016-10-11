#pragma once
#include "Collection.h"
#include <string>
using namespace std;

class Number
{
public:
    List<int> Data;

    Number();

    Number(string number);

    string ToString();

    Number operator +(Number& other)
    {
        Number result;
        int tmp = 0;
        int i = Data.Length - 1;
        int j = other.Data.Length - 1;
        while (i >= 0 && j >= 0)
        {
            int a = Data[i];
            int b = other.Data[j];
            result.Data.Add((a + b) % 10 + tmp);
            tmp = (a + b) / 10;
            i--;
            j--;
        }
        while (i >= 0)
        {
            result.Data.InsertAt(0, Data[i] + tmp);
            tmp = 0;
            i--;
        }
        while (j >= 0)
        {
            result.Data.InsertAt(0, other.Data[j] + tmp);
            tmp = 0;
            j--;
        }
        return result;
    }
};
