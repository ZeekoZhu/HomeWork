#pragma once
#include<vector>

template<typename T>
class Tuple
{
public:
    int Col;
    T Data;

    Tuple() :Col(-1), Data(0)
    {
    }
};

template<typename T>
class TupleMatrix
{
public:
    int* Row;
    Tuple<T>* Tuples;
    int RowCount;   // 行数
    int ColCount;   // 列数
    int Tn;         // 非零元个数


/// <summary>
/// Gets the value.
/// </summary>
/// <param name="row">The row index.</param>
/// <param name="col">The col index.</param>
/// <returns></returns>
    T& GetValue(int row, int col)
    {
        if (row<1 || row>RowCount || col<1 || col>ColCount)
        {
            throw new std::out_of_range("Index out of range");
        }
        // get the begining position of the row
        int that = Row[row - 1];
        // get the end position of the row
        int end = row != RowCount ? Row[row] : Tn;
        for (int i = 0; i < col && that != end; i++)
        {
            // col index is matched, we find the element
            if (Tuples[that + i].Col == col)
            {
                return Tuples[that + i];
            }
            // col index is less than target, we should go futher
            else if (Tuples[that+i].Col < col)
            {
                continue;
            }
            // col index is greater than target. return the defualt value of T
            else
            {
                return *(new T());
            }
        }
    }
};