#include "Collection.h"
#include <string>

using namespace std;

class Number
{
public:
    List<int> Data;

    Number()
    {
        Data.Add(0);
    }

    Number(string number)
    {
        for (char c : number)
        {
            Data.Add(c - '0');
        }
    }

    Number operator +(const Number& other)
    {
        int tmp;
    }
};