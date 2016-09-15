#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	cout << "Hello Fucking man!";
	List<int> list;
	list.Add(5).Add(23).Add(34);
	cout << endl;
	list = list.Map<int>([](int i)->int { return ++i; });
	list.ForEach([](int& i)-> void
	{
		cout << i << " ";
	});
	cout << endl << list[1];
	list.RemoveAt(1);
	list.Remove([](int& i) -> bool
	{
		return i == 5;
	});
	try
	{
		List<int>* pList = &list;
		delete pList;
	}
	catch (const std::exception& e)
	{
		cout << e.what();
	}
	return 0;
}