#include <iostream>
#include "Collection.h"
#include <string>
#include "NumSys.h"
#include "Number.h"

using namespace std;


int main()
{
	//CollectionTest::Test();
	/*cout << ConvertOctWithArray(2, "111") << endl;
	cout << FromOctToWithArray(16, 56);*/

	string sa = "123123";
	string sb = "123123";
    Number a(sa);
    Number b(sb);
    Number c = a + b;
    cout << c.ToString();
	return 0;
}