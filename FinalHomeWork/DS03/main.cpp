#include <iostream>
#include <string>
#include "Collection.h"
#include "Queue.h"

using namespace std;

bool IsMatch(std::string &input);

bool IsPalindrome(string& input);
int main()
{
    /*string input;
    cin >> input;
    cout << (IsMatch(input) ? "匹配" : "不匹配");*/


    /*Queue<int> q(4);
    q.PushBack(1).PushBack(2).PushBack(3);
    cout << q.PopFront() << endl;
    cout << q.PopFront() << endl;
    q.PushBack(4).PushBack(5);
    cout << q.PopFront() << endl;
    cout << q.PopFront() << endl;*/
    string str;
    cin >> str;
    cout << (IsPalindrome(str) ? "是回文" : "不是回文");

    return 0;
}

/// <summary>
/// 遇到左中括号就进栈，右中括号就出栈，最后栈空了，就说明中括号是匹配的
/// </summary>
/// <param name="input">The input.</param>
/// <returns></returns>
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

/// <summary>
/// 判断所给字符串是否是回文
/// </summary>
/// <param name="input">The input.</param>
/// <returns></returns>
bool IsPalindrome(string & input)
{
    string reverse = "";
    for (auto c : input)
    {
        reverse.insert(0, 1, c);
    }
    return input.compare(reverse) == 0;
}
