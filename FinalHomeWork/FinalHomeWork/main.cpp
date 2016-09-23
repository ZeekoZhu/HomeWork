#include <iostream>
#include "Collection.h"
#include <string>
#include <math.h>

using namespace std;

double ConvertOct(int, string);

int main()
{
	cout << ConvertOct(2, "111");
	return 0;
}

int ConvertToOctD(char c)
{
	if (c >= '0'&&c <= '9')
	{
		return c - '0';
	}
	else
	{
		return c - 'a' + 10;
	}
}
double ConvertOct(int M, string x)
{
	Stack<char> reverse;
	for (char n : x)
	{
		reverse.Push(n);
	}
	double res = 0;
	for (int i = 0; reverse.Length > 0; i++)
	{
		res += (ConvertToOctD(reverse.Pop()))*pow(M, i);
	}

	return res;
}

string FromOctTo(int M, int x)
{

}