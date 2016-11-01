#include <iostream>
#include <string>

using namespace std;

/// <summary>
/// Reverses the specified string
/// </summary>
/// <param name="src">The string.</param>
/// <returns>result</returns>
string Reverse(string src)
{
    string result;
    for (auto c : src)
    {
        result.insert(0, 1, c);
    }
    return result;
}

/// <summary>
/// Method for 4.11
/// </summary>
/// <param name="target">The target.</param>
/// <param name="src">The source.</param>
void SubChar(string &src, string& target)
{
    for (int i = 0; i < target.length(); i++)
    {
        for (int j = 0; j < src.length(); j++)
        {
            if (src.at(j) == target.at(i))
            {
                src.at(j) = 'O';
            }
        }
    }
}

int RemoveSub(string &str, const string src)
{
    int count = 0;
    string::size_type pos = 0;
    while ((pos = str.find(src, pos)) != string::npos)
    {
        str.erase(pos, src.size());
        ++count;
    }
    return count;
}


int main()
{
    string str = "hello";
    cout << Reverse(str) << endl;

    string s = "hello world";
    string t = "hello";
    SubChar(s, t);

    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != 'O'&&s.find(s.at(i)) >= i)
        {
            cout << "index of '" << s.at(i) << "' is " << i << endl;
        }
    }

    string a = "there is a fire started in my heart";
    string b = "is";
    RemoveSub(a, b);
    cout << endl << a;
}