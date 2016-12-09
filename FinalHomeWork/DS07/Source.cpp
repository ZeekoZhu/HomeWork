#include "stdafx.h"

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

    int index;          // 顶点所在位置
    GNode* nextArc;     //下一条弧
public:
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
        if (IsValidIndex(a) && IsValidIndex(b))
        {
            throw new out_of_range("index out of range");
        }
        if (heads[a]->arc == nullptr)
        {
            heads[a]->arc = new GNode(b);
        }
    }


};

int main()
{
    Graph<int> g;
    Vex<int> v(1);
    g.InsertVex(v);
    g.InsertVex(v);
    g.InsertVex(v);

}