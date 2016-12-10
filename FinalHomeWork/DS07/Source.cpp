#include "stdafx.h"
#include<stdio.h>
#include<cstdlib>

using namespace std;

class GNode;
template<typename T> class Graph;

// 图的顶点类
template<typename T>
class Vex
{
    friend class GNode;
    friend class Graph<T>;
    T data;
    GNode* arc = nullptr;

public:
    Vex(T value) :data(value)
    {}

    Vex() {};

};

class GNode
{
public:
    int index;          // 顶点所在位置
    GNode* nextArc;     //下一条弧
    GNode() :nextArc(nullptr) {}
    GNode(int i) :nextArc(nullptr), index(i) {}
};

template<typename T>
class Graph
{
    Vex<T>* heads;
    int count;

    bool IsValidIndex(int a)
    {
        return 0 <= a && a < count;
    }
public:
    int Count()
    {
        return count;
    }

    Graph<T>() : count(0), heads(new Vex<T>[1])
    {
    }

    void InsertVex(Vex<T>& v)
    {
        count++;
        Vex<T>* tmp = new Vex<T>[count];
        memcpy(tmp, heads, sizeof(Vex<T>)*(count - 1));
        tmp[count - 1].data = v.data;
        delete[] heads;
        heads = tmp;
    }

    void InsertArc(int a, int b)
    {
        if (!IsValidIndex(a) || !IsValidIndex(b))
        {
            throw new out_of_range("index out of range");
        }
        GNode* i = heads[a].arc;
        if (i == nullptr)
        {
            heads[a].arc = new GNode(b);
        }
        else
        {
            for (; i->nextArc != nullptr; i = i->nextArc)
            {
            }
            i->nextArc = new GNode(b);
        }
    }

    void DeleteVex(int a)
    {
        count--;
        memcpy(heads + a, heads + a + 1, sizeof(Vex<T>)*count - a);

        for (int i = 0; i < count; i++)
        {
            GNode* that = heads[i].arc;
            while (that != nullptr && that->nextArc != nullptr)
            {
                if (that->index == a)
                {
                    heads[i].arc = that->nextArc;
                    delete that;
                    break;
                }
                if (that->nextArc->index == a)
                {
                    that->nextArc = that->nextArc->nextArc;
                    delete that->nextArc;
                    break;
                }
                that = that->nextArc;
            }
        }
    }

    void DeleteArc(int a, int b)
    {
        GNode* that = heads[a].arc;
        if (that == nullptr)
        {
            return;
        }
        if (heads[a].arc->index == b)
        {
            heads[a].arc = heads[a].arc->nextArc;
            delete that;
            return;
        }
        while (that != nullptr && that->nextArc != nullptr)
        {
            if (that->index == b)
            {
                heads[a].arc = that->nextArc->nextArc;
                delete that;
                break;
            }
            if (that->nextArc->index == b)
            {
                that->nextArc = that->nextArc->nextArc;
                delete that->nextArc;
                break;
            }
            that = that->nextArc;
        }
    }

    bool HasRouteBetween(int a, int b)
    {
        int* trace = new int[count];
        memset(trace, 0, sizeof(trace));
        bool res = DFS(trace, a, b);
        delete[] trace;
        return res;
    }

    bool DFS(int* trace, int current, int target)
    {
        trace[current] = 1;
        if (trace[current] == 1)
        {
            return false;
        }
        GNode* that = heads[current].arc;
        while (that != nullptr)
        {
            if (that->index == target)
            {
                return true;
            }
            if (DFS(trace, that->index, target))
            {
                return true;
            }
            that = that->nextArc;
        }
        return false;
    }

    bool HasArcBetween(int a, int b)
    {
        GNode* that = heads[a].arc;
        if (that == nullptr)
        {
            return false;
        }
        if (heads[a].arc->index == b)
        {
            return true;
        }
        while (that != nullptr && that->nextArc != nullptr)
        {
            if (that->index == b)
            {
                return true;
            }
            if (that->nextArc->index == b)
            {
                return true;
            }
            that = that->nextArc;
        }
        return false;
    }
};

void DfsTest()
{
    Graph<int> g;
    Vex<int> v(1);
    Vex<int> v2(2);
    g.InsertVex(v2);
    g.InsertVex(v);
    g.InsertVex(v);
    g.InsertVex(v);
    g.InsertVex(v2);
    g.InsertArc(0, 2);
    g.InsertArc(1, 3);
    g.InsertArc(1, 0);
    g.InsertArc(4, 0);
    g.InsertArc(3, 4);
    g.InsertArc(2, 3);
    cout << g.HasRouteBetween(0, 1);
}

int main()
{
    
}