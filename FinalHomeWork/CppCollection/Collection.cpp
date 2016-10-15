#include <string>
#include <iostream>
#include <strstream>

using namespace std;

class Collection
{
public:
    Collection();
    ~Collection();

    Collection& Add(int value);

    bool Find(int value, int & out);

    Collection & Delete(int value);

    void RemoveAt(int index);

    void InsertAt(int index, int value);

    string ToString();

    Collection & operator|(const Collection & other);

    Collection & operator&(const Collection & other);

    Collection & operator-(const Collection & other);

    int operator[](const int & index);

private:
    int _data[100];
    size_t _length;
};

Collection::Collection() :_length(0)
{
}

Collection::~Collection()
{
}

Collection& Collection::Add(int value)
{
    if (_length == 5)
    {
        return *this;
    }
    if (_length == 0)
    {
        _data[0] = value;
        _length++;
        return *this;
    }
    int left = 0;
    int right = _length - 1;
    int middle = 0;
    while (left != right)
    {
        middle = (left + right) / 2;
        if (_data[middle] == value)
        {
            return *this;
        }
        else if (_data[middle] > value)
        {
            right = middle - 1 < 0 ? 0 : middle - 1;
        }
        else
        {
            left = middle + 1 > 4 ? 4 : middle + 1;
        }
    }
    if (_data[left] != value)
    {
        InsertAt(right + (_data[right] < value), value);
    }
    return *this;
}

bool Collection::Find(int value, int& outIndex)
{
    int left = 0;
    int right = _length - 1;
    int middle = 0;
    while (left != right)
    {
        middle = (left + right) / 2;
        if (_data[middle] == value)
        {
            outIndex = middle;
            return true;
        }
        else if (_data[middle] > value)
        {
            right = middle - 1 < 0 ? 0 : middle - 1;
        }
        else
        {
            left = middle + 1 > 4 ? 4 : middle + 1;
        }
    }
    if (_data[left] == value)
    {
        outIndex = left;
        return true;
    }
    else
    {
        return false;
    }
}

Collection& Collection::Delete(int value)
{
    int target = -1;
    if (Find(value, target))
    {
        RemoveAt(target);
    }
    return *this;
}

void Collection::RemoveAt(int index)
{
    if (index == _length - 1)
    {
        _length--;
        return;
    }
    memmove(_data + index, _data + index + 1, sizeof(int)*(_length - index - 1));
    _length--;
}



void Collection::InsertAt(int index, int value)
{
    if (index == _length)
    {
        _data[index] = value;
    }
    memmove(_data + index + 1, _data + index, sizeof(int)*(_length - index));
    _data[index] = value;
    _length++;
}

string Collection::ToString()
{
    string result = "{";
    string tmp;
    char buffer[7];
    strstream strs;
    for (size_t i = 0; i < _length; i++)
    {
        strs.clear();
        strs << _data[i] << "\0";
        sprintf(buffer, "%d", _data[i]);
        result += buffer;
        if (i != _length - 1)
        {
            result += ",";
        }
    }
    return result + "}";
}

Collection& Collection::operator| (const Collection& other)
{
    Collection* result = new Collection();
    int i = 0;
    int j = 0;
    int* target;
    while (i < _length&&j < other._length)
    {
        if (_data[i] > other._data[j])
        {
            result->Add(other._data[j++]);
        }
        else if (_data[i] < other._data[j])
        {
            result->Add(_data[i++]);
        }
        else
        {
            result->Add(_data[i++]);
            j++;
        }
    }
    while (i < _length)
    {
        result->Add(_data[i++]);
    }
    while (j < other._length)
    {
        result->Add(other._data[j++]);
    }
    return *result;
}

Collection& Collection::operator& (const Collection& other)
{
    Collection* result = new Collection();
    int i = 0;
    int j = 0;
    while (i < _length&&j < other._length)
    {
        if (_data[i] < other._data[j])
        {
            i++;
        }
        else if (_data[i] > other._data[j])
        {
            j++;
        }
        else
        {
            result->Add(_data[i]);
            i++;
            j++;
        }
    }
    return *result;
}

Collection& Collection::operator- (const Collection& other)
{
    Collection* result = new Collection();
    int i = _length - 1;
    int j = other._length - 1;
    while (i >= 0 && j >= 0)
    {
        if (_data[i] == other._data[j])
        {
            i--;
            j--;
        }
        else if (_data[i] > other._data[j])
        {
            result->Add(_data[i]);
            i--;
        }
        else
        {
            j--;
        }
    }
    while (i >= 0)
    {
        result->Add(_data[i--]);
    }
    return *result;
}

int Collection::operator[](const int& index)
{
    if (index>=_length)
    {
        throw length_error("Segament Fault");
    }
    return _data[index];
}
int main()
{
    Collection c;
    Collection co;
    int m;
    int n;
    cin >> m >> n;
    for (size_t i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        c.Add(tmp);
    }
    for (size_t i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        co.Add(tmp);
    }
    cout << c.ToString() << endl
        << co.ToString() << endl
        << (c | co).ToString() << endl
        << (c & co).ToString() << endl
        << (c - co).ToString();

        
    return 0;
}
