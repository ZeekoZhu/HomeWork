//
// Created by Zeeko on 2016/11/22.
//

#ifndef FINALHOMEWORK_MARKET_H
#define FINALHOMEWORK_MARKET_H

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int Dijkstra()
{
    int row;
    cout << "请输入草泥马的矩阵行数：" << endl;
    cin >> row;
    cout << "请输入邻接矩阵：" << endl;
    vector<vector<int>>* matrix = new vector<vector<int>>(row, vector<int>(row, 0));
    vector<vector<int>>* path = new vector<vector<int>>(row, vector<int>(row, -1));
    int tmp;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < row; ++j)
        {
            int tmp;
            cin >> tmp;
            tmp = tmp < 0 ? INT_MAX : tmp;
            (*matrix)[i][j] = tmp;
        }
    }

    int ux, uy, vx, vy;
    ux = uy = vx = vy = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            for (int k = 0; k < row; k++)
            {
                if ((*matrix)[i][j] > (*matrix)[i][k] + (*matrix)[k][j])
                {
                    (*matrix)[i][j] = (*matrix)[i][k] + (*matrix)[k][j];
                    (*path)[i][j] = k;
                }
            }
        }
    }


    return 0;
}

#endif //FINALHOMEWORK_MARKET_H
