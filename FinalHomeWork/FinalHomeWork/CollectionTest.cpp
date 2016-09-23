#include<iostream>
#include "Collection.h"
using namespace std;

class CollectionTest
{
public:
	static void Test()
	{
		cout << "Hello Fucking man!";
		List<int> list;
		list.Add(5).Add(23).Add(34);
		cout << endl;
		list.Map<int>([](int i)->int { return ++i; })
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
			.Where([](int& i)-> bool
		{
			return i % 2 != 0;
		})
			->ForEach([](int& i)-> void
		{
			cout << endl << i << " ";
		});
	}
};