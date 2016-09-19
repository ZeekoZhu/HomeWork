#include <iostream>
#include "List.h"

using namespace std;

int main()
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
		.ForEach([](int& i)-> void
		{
			cout << endl << i << " ";
		});
	return 0;
}