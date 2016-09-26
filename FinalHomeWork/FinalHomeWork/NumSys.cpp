#include "Collection.h"
#include "NumSys.h"

using namespace std;

/// <summary>
/// M 进制数字转 10 进制
/// </summary>
/// <param name="c">The c.</param>
/// <returns></returns>
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

/// <summary>
/// 10 进制数字转到 M 进制
/// </summary>
/// <param name="digital">The digital.</param>
/// <returns></returns>
char ConvertToMD(int digital)
{
	if (digital >= 0 && digital <= 9)
	{
		return '0' + digital;
	}
	else
	{
		return digital - 10 + 'a';
	}
}

/// <summary>
/// M 进制数转 10 进制
/// </summary>
/// <param name="M">The m.</param>
/// <param name="x">The x.</param>
/// <returns></returns>
double ConvertOctWithStack(int M, string x)
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

/// <summary>
/// M 进制数转 10 进制
/// </summary>
/// <param name="M">The m.</param>
/// <param name="x">The x.</param>
/// <returns></returns>
double ConvertOctWithArray(int M, string x)
{
	char reverse[100];
	int index = 0;
	for (char n : x)
	{
		reverse[index++] = n;
	}
	double res = 0;
	for (int i = 0; index > 0; i++, index--)
	{
		res += (ConvertToOctD(reverse[i]))*pow(M, i);
	}

	return res;
}

/// <summary>
/// 从 10 进制转到 M 进制
/// </summary>
/// <param name="M">The m.</param>
/// <param name="x">The x.</param>
/// <returns></returns>
string FromOctToWithStack(int M, int x)
{
	Stack<char> res;
	while (x)
	{
		res.Push(ConvertToMD(x%M));
		x /= M;
	}
	string result = "";
	while (res.Length > 0)
	{
		result += res.Pop();
	}
	return result;
}

/// <summary>
/// 从 10 进制转到 M 进制
/// </summary>
/// <param name="M">The m.</param>
/// <param name="x">The x.</param>
/// <returns></returns>
string FromOctToWithArray(int M, int x)
{
	char res[100];
	int index = 0;
	while (x)
	{
		res[index++] = (ConvertToMD(x%M));
		x /= M;
	}
	string result = "";
	while (index-- >= 0)
	{
		result += res[index];
	}
	return result;
}