#include<iostream>
#include <ctime>
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
        int tmp;
        cin >> tmp;
        for (int i = 0; i < tmp; i++)
        {
            nums.Add(rand());
        }
        auto begin = clock();
        List<int> sorted = nums.Sort([](int a, int b)->bool 
        {
            return a > b;
        });
        auto end = clock();
        cout << "total time: " << (double)(end - begin) / CLOCKS_PER_SEC << endl;
        sorted.ForEach([](int a)->void
        {
            cout << a << " ";
        });
    }

    void CollectionTest::HuffmanTest()
    {
        cout << "source string is aaabbcd" << endl << "and code table will be shown below" << endl;

        Huffman h("aaabbcd");
        cout << "Encode: " << h.Encode() << endl;
        cout << "Decode: " << h.Decode("0001010110111") << endl;
    }