#include <iostream>
#include <string>

using namespace std;

string Reverse(string src)
{

	string result;
	for (auto c : src)
	{
		result.insert(0, 1, c);
	}
	return result;
}


int main()
{
	string fuck = "shit";
	cout << Reverse(fuck);
}