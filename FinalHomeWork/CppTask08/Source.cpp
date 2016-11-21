#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Block
{
    int X;
    int Y;

    Block() : X(0), Y(0)
    {}

    Block(int x, int y) : X(x), Y(y)
    {}
};

class Matrix
{
    vector<vector<int> > *datas;
    vector<vector<bool> > *map;
    int row;
    int column;
    int visited;
public:
    Matrix(int row, int column) :
            datas(new vector<vector<int>>(row, vector<int>(column, 0))),
            map(new vector<vector<bool>>(row, vector<bool>(column, false))),
            row(row), column(column), visited(0)
    {
    }

    bool IsVisited(Block *block) const
    {
        return (*map)[block->X][block->Y];
    }

    void Visit(Block *block)
    {
        visited++;
        (*map)[block->X][block->Y] = true;
    }

    bool IsVisitedOut() const
    {
        return visited >= row * column;
    }

    Block *GetDownWithIt() const
    {
        Block *block = nullptr;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < column; ++j)
            {
                if (!(*map)[i][j])
                {
                    block = new Block(i, j);
                    return block;
                }
            }
        }
        return block;
    }

    int GetValue(Block *block) const
    {
        return (*datas)[block->X][block->Y];
    }

    void SetValue(int row, int column, int value) const
    {
        (*datas)[row][column] = value;
    }

    Block *GetBeLowBlock(Block *block) const
    {
        int x = block->X + 1;
        int y = block->Y;
        if (x > row - 1)
        {
            x = 0;
            y++;
        }
        return new Block(x, y);
    }

    Block *GetRightBlock(Block *block) const
    {
        int x = block->X;
        int y = block->Y + 1;
        if (y > column - 1)
        {
            x++;
            y = 0;
        }
        return new Block(x, y);
    }
};


int main()
{
    int row;
    int column;
    int tmp;
    cin >> row >> column;

    Matrix matrix(row, column);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; ++j)
        {
            cin >> tmp;
            matrix.SetValue(i, j, tmp);
        }
    }
    cout << "input end" << endl;

    stack<Block *> trace;
    Block *block;
    while (!matrix.IsVisitedOut())
    {
        block = matrix.GetDownWithIt();
        trace.push(block);
        matrix.Visit(block);
        int value = matrix.GetValue(block);
        while (!trace.empty())
        {
            if (!matrix.IsVisited(block) && value == matrix.GetValue(block))
            {
                matrix.Visit(block);
                block = matrix.GetBeLowBlock(block);
            }
            else
            {
                if (trace.empty())
                {
                    break;
                }
                block = matrix.GetRightBlock(trace.top());
                trace.pop();
            }
            trace.push(block);
        }
        cout << value << endl;
    }
    return 0;
}