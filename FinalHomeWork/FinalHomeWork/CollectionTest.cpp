#include<iostream>
#include "Collection.h"
#include "CollectionTest.h"
#include "Huffman.cpp"
using namespace std;

    void CollectionTest::Test()
    {
        cout << "Hello Fucking man!";
        List<int> list;
        list.Add(5).Add(23).Add(34);
        cout << endl;
        double res = list.Map<int>([](int i)->int { return ++i; })
            ->ForEach([](int& i)-> void
        {
            cout << i << " ";
        })
            .RemoveAt(1)
            .Remove([](int& i) -> bool
        {
            return i == 5;
        })
            .Clear()
            .InsertAt(233, 0)

            .Add(12).Add(23).Add(44)
            .Sum([](int& i)->double
        {
            return i;
        });
        cout << endl << res;
    }

    void CollectionTest::ListSortTest()
    {
        List<int>nums;
        nums.Add(5)
            .Add(1)
            .Add(4)
            .Add(6);
        List<int> sorted = nums.PopSort([](int a, int b)->bool 
        {
            return a > b;
        });
        sorted.ForEach([](int a)->void
        {
            cout << a << " ";
        });
    }

    void CollectionTest::HuffmanTest()
    {
        Huffman h("aaabbcd");
    }