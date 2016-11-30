#include <iostream>

using namespace std;

class GNode;
template<typename T> class Graph;

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
    GNode* nextArc;  //下一条弧
public:
    GNode() :nextArc(nullptr) {}
};

template<typename T>
class Graph
{
    Vex<T>* heads;
    int count;
public:
    int Count()
    {
        return count;
    }

    Graph<T>(int c) :count(c), heads(new Vex<T>[c])
    {
    }

    void InsertVex(Vex<T>& v)
    {
        count++;
        Vex<T>* tmp = new Vex<T>[count];
        memcpy(tmp, heads, sizeof(Vex<T>)*(count - 1));
        tmp[count].data = v.data;
    }
};

int main()
{
    Graph<int> g(3);
    Vex<int> v(1);
    g.InsertVex(v);
}