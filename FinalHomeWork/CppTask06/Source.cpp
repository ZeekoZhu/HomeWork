#include<iostream>
#include<string>

using namespace std;

class String
{
public:
    int length;

    String():length(0),content(NULL)
    {
    }

    String(string& s)
    {
        length = s.length();
        content = new char[length + 1];
        memcpy(content, s.c_str(), sizeof(char)*length + 1);
    }

    void Print()
    {
        cout << content << endl;
    }

    String& operator= (String& s)
    {
        if (content != NULL)
        {
            delete content;
        }
        content = new char[s.length + 1];
        memcpy(content, s.content, sizeof(char)*s.length + 1);
        length = s.length;
        return *this;
    }

    String& Contact(String& s)
    {
        String* result = new String();
        result->content = new char[s.length + length + 1];
        memcpy(result->content, content, sizeof(char)*length);
        memcpy(result->content + length, s.content, sizeof(char)*s.length + 1);
        result->length = length + s.length;
        return *result;
    }

    String& SubString(int begin, int len)
    {
        String* result = new String();
        result->content = new char[len + 1];
        memcpy(result->content, content + begin, sizeof(char)*len);
        result->length = len;
        result->content[len] = '\0';
        return *result;
    }


private:
    char* content;
};


int main()
{
    String strs[4];
    string tmp;
    cin >> tmp;
    strs[0] = String(tmp);
    cin >> tmp;
    strs[1] = String(tmp);
    while (cin >> tmp)
    {
        int i, j, k, l, s;
        switch (tmp[0])
        {
        case 'P':
            cin >> i;
            strs[i - 1].Print();
            break;
        case 'A':
            cin >> i >> j;
            strs[j - 1] = strs[i - 1];
            break;
        case 'C':
            cin >> i >> j >> k;
            strs[k - 1] = strs[i - 1].Contact(strs[j - 1]);
            break;
        case 'F':
            cin >> i >> s >> l >> k;
            strs[k - 1] = strs[i - 1].SubString(s, l);
            break;
        }
    }

    return 0;
}