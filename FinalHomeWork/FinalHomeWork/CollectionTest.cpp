#include<iostream>
#include "Collection.h"
#include "CollectionTest.h"
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