#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	cout << "Hello Fucking man!";
	List<int> list;
	list.Add(5).Add(23).Add(34);
	cout << list[1];
	list.RemoveAt(1);
	list.Remove([](int& i) -> bool {return i == 5; });
	list.ForEach([](int& i)->void {cout << i << " "; })
	return 0;
}