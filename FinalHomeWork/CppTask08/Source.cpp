#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Point
{
    Point(int d, int a, int b) : data(d), x(a), y(b)
    {}
    int data;
    int x;
    int y;
};

Point getUpPoint(const vector<vector<int> >& matrix, const Point& temp);

Point getBelowPoint(const vector<vector<int> >& matrix, const Point& temp);

Point getLeftPoint(const vector<vector<int> >& matrix, const Point& temp);

Point getRightPoint(const vector<vector<int> >& matrix, const Point& temp);

int main()
{
    int i, j;
    cin >> i >> j;

    vector<vector<int> > matrix;
    stack<Point> s;
    for (int a = 0; a < i; a++)
    {
        vector<int> temp;
        int c = 0;
        for (int b = 0; b < j; b++)
        {
            cin >> c;
            temp.push_back(c);
        }
        matrix.push_back(temp);
    }

    int count = 0;
    for (int a = 0; a < i; a++)
    {
        for (int b = 0; b < j; b++)
        {
            if (matrix[a][b] > 0)
            {
                s.push(Point(matrix[a][b], a, b));
                while (!s.empty())
                {
                    Point temp = s.top();
                    s.pop();
                    if (temp.x - 1 >= 0 && matrix[temp.x - 1][temp.y] == temp.data)
                    {
                        s.push(getUpPoint(matrix, temp));
                    }
                    if (temp.x + 1 < i && matrix[temp.x + 1][temp.y] == temp.data)
                    {
                        s.push(getBelowPoint(matrix, temp));
                    }
                    if (temp.y - 1 >= 0 && matrix[temp.x][temp.y - 1] == temp.data)
                    {
                        s.push(getLeftPoint(matrix, temp));
                    }
                    if (temp.y + 1 < j && matrix[temp.x][temp.y + 1] == temp.data)
                    {
                        s.push(getRightPoint(matrix, temp));
                    }
                    matrix[temp.x][temp.y] = -1;
                }
                count++;
            }
        }
    }
    cout << count;
    return 0;
}

Point getRightPoint(const vector<vector<int> >& matrix, const Point& temp)
{ return Point(matrix[temp.x][temp.y + 1], temp.x, temp.y + 1); }

Point getLeftPoint(const vector<vector<int> >& matrix, const Point& temp)
{ return Point(matrix[temp.x][temp.y - 1], temp.x, temp.y - 1); }

Point getBelowPoint(const vector<vector<int> >& matrix, const Point& temp)
{ return Point(matrix[temp.x + 1][temp.y], temp.x + 1, temp.y); }

Point getUpPoint(const vector<vector<int> >& matrix, const Point& temp)
{ return Point(matrix[temp.x - 1][temp.y], temp.x - 1, temp.y); }