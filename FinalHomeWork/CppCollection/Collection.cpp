#include <string>
#include <iostream>

using namespace std;

class Collection
{
public:
    Collection();
    ~Collection();

    Collection& Add(int value);

    void InsertAt(int index, int value);

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
            right = middle - 1;
        }
        else
        {
            left = middle + 1;
        }
    }
    InsertAt(right + _data[right]<value, value);
    return *this;
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

int main()
{
    Collection c;
    c.Add(0).Add(5).Add(2);
    return 0;
}
