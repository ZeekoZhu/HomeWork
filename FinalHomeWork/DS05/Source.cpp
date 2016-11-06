#include <iostream>
#include <string>

using namespace std;

#define MAXSIZE 10000
#define MAXEDGE 100

using namespace std;

/// <summary>
/// Converts string to int.
/// </summary>
/// <param name="s">The string.</param>
/// <returns></returns>
int Str2Int(string s)
{
    int res = 0;
    for (char c : s)
    {
        res = res * 10 + c - '0';
    }
    return res;
}

class Matrix
{
public:
    int Index = 0;
    int MaxRow = 0;
    int MaxCol = -1;
    int V[MAXSIZE];
    int B[MAXEDGE][MAXEDGE];
    
    /// <summary>
    /// Gets the matrix from console.
    /// </summary>
    void GetMatrix()
    {
        cout << "请输入一个矩阵，元素间使用空格分隔，使用'\\'换行" << endl;
        string tmp;
        int col = 0;
        while ((cin >> tmp) && (MaxCol < 0 || col - 1 <= MaxCol))
        {
            // if reads '\' then shifts to new row
            if (tmp == "\\")
            {
                MaxCol = MaxCol < 0 ? col - 1 : MaxCol;
                MaxRow++;
                col = 0;
            }
            else
            {
                int num = Str2Int(tmp);
                if (num)
                {
                    V[Index++] = num;
                }
                // if num != 0, add the value to the data domain
                B[MaxRow][col] = num == 0 ? 0 : 1;
                col++;
            }
        }
        MaxCol = MaxCol < 0 ? col - 1 : MaxCol;
        cin.clear();
    }
    
    /// <summary>
    /// Adds the specified matrix b.
    /// </summary>
    /// <param name="b">The b.</param>
    /// <returns>The sum.</returns>
    Matrix& Add(Matrix& b)
    {
        Matrix result;
        result.MaxCol = b.MaxCol;
        result.MaxRow = b.MaxRow;
        int ia = 0;
        int ib = 0;
        for (int i = 0; i <= b.MaxRow; i++)
        {
            for (int j = 0; j <= b.MaxCol; j++)
            {
                result.B[i][j] = B[i][j] | b.B[i][j];
                int tmp = 0;
                if (B[i][j])
                {
                    tmp += V[ia++];
                }
                if (b.B[i][j])
                {
                    tmp += b.V[ib++];
                }
                // if the sum != 0, then append it to the data domain.
                if (tmp)
                {
                    result.V[result.Index++] = tmp;
                }
            }
        }
        return result;
    }
    
    /// <summary>
    /// Prints this matrix.
    /// </summary>
    void Print()
    {
        int index = 0;
        for (int i = 0; i <= MaxRow; i++)
        {
            for (int j = 0; j <= MaxCol; j++)
            {
                if (B[i][j])
                {
                    cout << V[index++] << " ";
                }
                else
                {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }

};





int main()
{
    Matrix a;
    a.GetMatrix();
    Matrix b;
    b.GetMatrix();
    Matrix c = a.Add(b);
    c.Print();
    return 0;
}


