#include "Collection.h"
#include <string>
#include "Number.h"
using namespace std;


Number::Number()
{
    Data.Add(0);
}

Number::Number(string number)
{
    for (char c : number)
    {
        Data.Add(c - '0');
    }
}

string Number::ToString()
{
    string result;
    Data.ForEach([&result](int n)->void
    {
        char c = n + '0';
        result.append(1, c);
    });
    return result;
}

Number Number::operator+(Number& other)
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
		result.Data.Add( Data[i] + tmp);
		tmp = 0;
		i--;
	}
	while (j >= 0)
	{
		result.Data.Add(other.Data[j] + tmp);
		tmp = 0;
		j--;
	}
	return result;
}
