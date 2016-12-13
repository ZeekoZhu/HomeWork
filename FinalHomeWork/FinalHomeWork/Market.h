#ifndef FINALHOMEWORK_MARKET_H
#define FINALHOMEWORK_MARKET_H

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int Floyd()
{
    int row;
    cout << "please enter the row number of the matrix :" << endl;
    cin >> row;
    cout << "please enter the matrix:" << endl;
    vector<vector<int>>* matrix = new vector<vector<int>>(row, vector<int>(row, -1));
    vector<vector<int>>* path = new vector<vector<int>>(row, vector<int>(row, -1));
    int tmp;
    // fill the matrix
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < row; ++j)
        {
            int tmp;
            cin >> tmp;
            tmp = tmp < 0 ? INT_MAX : tmp;
            (*matrix)[i][j] = tmp;
            (*path)[i][j] = j;
        }
    }

    // 中转点
    for (int k = 0; k < row; k++)
    {
        // 起点
        for (int i = 0; i < row; i++)
        {
            // 终点
            for (int j = 0; j < row; j++)
            {
                if ((*matrix)[i][j] > (*matrix)[i][k] + (*matrix)[k][j])
                {
                    (*matrix)[i][j] = (*matrix)[i][k] + (*matrix)[k][j];
                    (*path)[i][j] = (*path)[i][k];
                }
            }
        }
    }

    int begin, end;
    while (cin >> begin >> end)
    {
        cout << "from " << begin << " to " << end << " : " << endl << begin;
        int k = (*path)[begin][end];
        while (k != end)
        {
            cout << " -> " << k;
            k = (*path)[k][end];
        }
        cout << " -> " << k;
    }


    return 0;
}

#endif //FINALHOMEWORK_MARKET_H


/*
0 12 1000 1000 1000 16 14
12 0 10 1000 1000 7 1000
1000 10 0 3 5 6 1000
1000 1000 3 0 4 1000 1000
1000 1000 5 4 0 2 8
16 7 6 1000 2 0 9
14 1000 1000 1000 8 9 0
*/