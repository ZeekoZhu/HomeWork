#include "Collection.h"
#include <string>
#include "Number.h"


using namespace std;


Number::Number()
{
}

Number::Number(string number)
{
    for (char c : number)
    {
        Data.Add(c - '0');
    }
}

/// <summary>
/// 将数字转换到字符串
/// </summary>
/// <returns></returns>
string Number::ToString()
{
    string result;
    bool valid = Data.Length == 1;
    for (int i = 0; i < Data.Length; i++)
    {
        if (Data[i] < 0)
        {
            result.append(1, '-');
        }
        else
        {
            char c = Data[i] + '0';
            if (c != '0' || valid)
            {
                valid = true;
                result.append(1, c);
            }
        }
    }
    return result;
}

/// <summary>
/// 加法
/// </summary>
/// <param name="other">The other.</param>
/// <returns></returns>
Number Number::operator+(Number& other)
{
    Number result;
    result.Data.Clear();
    int tmp = 0;
    int i = Data.Length - 1;
    int j = other.Data.Length - 1;
    while (i >= 0 && j >= 0)
    {
        int a = Data[i];
        int b = other.Data[j];
        result.Data.InsertAt((a + b) % 10 + tmp, 0);
        tmp = (a + b) / 10;
        i--;
        j--;
    }
    while (i >= 0)
    {
        result.Data.InsertAt(Data[i] + tmp, 0);
        tmp = 0;
        i--;
    }
    while (j >= 0)
    {
        result.Data.InsertAt(other.Data[j] + tmp, 0);
        tmp = 0;
        j--;
    }
    return result;
}

/// <summary>
/// 减法
/// </summary>
/// <param name="other">The other.</param>
/// <returns></returns>
Number Number::operator-(Number& other)
{
    Number result;
    bool isZero = true;
    bool isNagetive = other > *this;
    Number na = isNagetive ? other : *this;
    Number nb = isNagetive ? *this : other;
    int i = na.Data.Length - 1;
    int j = nb.Data.Length - 1;
    while (i >= 0 && j >= 0)
    {
        int a = na.Data[i];
        int b = nb.Data[j];
        int tmp = a - b;
        if (tmp != 0)
        {
            isZero = false;
        }
        if (tmp < 0)
        {
            if (i - 1 < 0)
            {
                isNagetive = true;
            }
            else
            {
                na.Data[i - 1]--;
                tmp += 10;
            }
        }
        result.Data.InsertAt(tmp, 0);
        i--; j--;
    }
    while (i >= 0)
    {
        isZero = false;
        result.Data.InsertAt(na.Data[i], 0);
        i--;
    }
    while (j >= 0)
    {
        isZero = false;
        result.Data.InsertAt(nb.Data[j], 0);
        j--;
    }
    if (isZero)
    {
        result.Data.Clear().Add(0);
    }
    if (isNagetive && !isZero)
    {
        result.Data.InsertAt(-1, 0);
    }
    return result;
}


bool Number::operator>(Number& other)
{
    if (Data.Length == other.Data.Length)
    {
        for (int i = 0; i < Data.Length; i++)
        {
            if (Data[i] != other.Data[i])
            {
                return Data[i] > other.Data[i];
            }
        }
    }
    else
    {
        return Data.Length > other.Data.Length;
    }
}