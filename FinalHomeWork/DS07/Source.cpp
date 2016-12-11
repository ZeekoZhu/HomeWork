#include "stdafx.h"
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

class GNode;
template<typename T> class Graph;

// vertex
template<typename T>
class Vex
{
public:
    friend class GNode;
    friend class Graph<T>;
    T data;
    GNode* arc = nullptr;

    Vex(T value) :data(value)
    {}

    Vex() {};

};

// arc list's node
class GNode
{
public:
    int index;          // the index of target vertex
    GNode* nextArc;     // the next arc in the list
    GNode() :nextArc(nullptr) {}
    GNode(int i) :nextArc(nullptr), index(i) {}
};

template<typename T>
class Graph
{
public:
    vector<Vex<T>> heads;   // vertexs
    int count;

    bool IsValidIndex(int a)
    {
        return 0 <= a && a < count;
    }

    Graph<T>() : count(0)
    {
    }

    void InsertVex(Vex<T> v)
    {
        count++;
        heads.push_back(v);
    }

    void InsertArc(int a, int b)
    {
        if (!IsValidIndex(a) || !IsValidIndex(b))
        {
            throw new out_of_range("index out of range");
        }
        GNode* i = heads[a].arc;

        // if the vertex doesn't have any arc then add a new arc for it
        if (i == nullptr)
        {
            heads[a].arc = new GNode(b);
        }
        else
        {
            // find the tail of the list
            for (; i->nextArc != nullptr; i = i->nextArc)
            {
            }
            i->nextArc = new GNode(b);
        }
    }

    void DeleteVex(int a)
    {
        count--;
        auto it = heads.begin() + a;
        heads.erase(it);
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
        if (trace[current] == 1)
        {
            return false;
        }
        trace[current] = 1;
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
    cout << g.HasRouteBetween(2, 1);
    cout << g.HasRouteBetween(1, 2);
}

string Calc(int* trace, Graph<string>& g, int current)
{
    if (trace[current] == 1)
    {
        return g.heads[current].data;
    }
    trace[current] = 1;
    if (g.heads[current].arc == nullptr)
    {
        return g.heads[current].data;
    }
    g.heads[current].data =
        Calc(trace, g, g.heads[current].arc->index) +
        Calc(trace, g, g.heads[current].arc->nextArc->index) +
        g.heads[current].data;
    return g.heads[current].data;

}

void CalcTest()
{
    Graph<string> g;
    Vex<string> va(string("a"));
    Vex<string> vb(string("b"));
    Vex<string> vc(string("c"));
    Vex<string> vd(string("d"));
    Vex<string> ve(string("e"));
    Vex<string> vt(string("*"));
    Vex<string> vp(string("+"));


    g.InsertVex(vt);
    g.InsertVex(vp);
    g.InsertVex(vt);
    g.InsertVex(vp);
    g.InsertVex(va);
    g.InsertVex(vb);
    g.InsertVex(vt);
    g.InsertVex(vp);
    g.InsertVex(vc);
    g.InsertVex(vd);
    g.InsertVex(vt);
    g.InsertVex(ve);

    g.InsertArc(0, 1);
    g.InsertArc(0, 10);
    g.InsertArc(1, 10);
    g.InsertArc(1, 2);
    g.InsertArc(2, 3);
    g.InsertArc(2, 6);
    g.InsertArc(3, 4);
    g.InsertArc(3, 5);
    g.InsertArc(6, 5);
    g.InsertArc(6, 7);
    g.InsertArc(7, 8);
    g.InsertArc(7, 9);
    g.InsertArc(10, 7);
    g.InsertArc(10, 11);

    int* trace = new int[g.count];
    memset(trace, 0, sizeof(int)*g.count);
    cout << Calc(trace, g, 0);
}

int main()
{
    CalcTest();

}