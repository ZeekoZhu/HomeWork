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

	Number operator +(Number& other);
};
