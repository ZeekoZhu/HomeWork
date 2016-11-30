#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class Shape
{
public:
    double virtual GetArea() = 0;
};

class Triangle : public Shape
{
public:

    double first;
    double second;
    double third;
    double GetArea()
    {
        double p = (first + second + third) / 2;
        return sqrt(p*(p - first)*(p - second)*(p - third));
    }
};

int main()
{
    int row;
    cin >> row;
    int* columns = new int[row];
    for (int i = 0; i < row; i++)
    {
        cin >> columns[i];
    }
    vector<vector<int> > m[2];
    for (int i = 0; i < 2; i++)
    {
        m[i] = vector<vector<int> >(row, vector<int>());
        for (int j = 0; j < row; j++)
        {
            m[i][j] = vector<int>(columns[j], 0);
            for (int c = 0; c < columns[j]; c++)
            {
                cin >> m[i][j][c];
            }
        }
    }
    vector<vector<int> >res(row, vector<int>());
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < columns[i]; j++)
        {
            res[i].push_back(m[0][i][j] + m[1][i][j]);
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < columns[i]; j++)
        {
            cout << setw(5) << m[0][i][j];
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < columns[i]; j++)
        {
            cout << setw(5) << m[1][i][j];
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < columns[i]; j++)
        {
            cout << setw(5) << res[i][j];
        }
        cout << endl;
    }
    return 0;
}