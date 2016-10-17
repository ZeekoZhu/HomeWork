#include <iostream>
#include <string>
#include "Collection.h"

using namespace std;

bool IsMatch(std::string &input);
int main()
{
    string input;
    cin >> input;
    cout << (IsMatch(input) ? "Æ¥Åä" : "²»Æ¥Åä");
    return 0;
}

bool IsMatch(std::string &input)
{
    Stack<char> stack;
    for (int i = 0; i < input.length(); i++)
    {
        char tmp = input[i];
        if (tmp == '[')
        {
            stack.Push(tmp);
        }
        else if (tmp == ']')
        {
            stack.Pop();
        }
    }
    return stack.Length == 0;
}
