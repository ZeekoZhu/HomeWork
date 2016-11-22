//
// Created by Zeeko on 2016/11/22.
//

#ifndef FINALHOMEWORK_MARKET_H
#define FINALHOMEWORK_MARKET_H

#include <iostream>
#include <vector>

using namespace std;

int Dijkstra()
{
    int row;
    int column;
    cin >> row >> column;
    auto matrix = new vector<vector<int>>(row,vector<int>(column,0));
    int tmp;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            cin >> tmp;
            (*matrix)[i].push_back(tmp);
        }
    }

    return 0;
}

#endif //FINALHOMEWORK_MARKET_H
