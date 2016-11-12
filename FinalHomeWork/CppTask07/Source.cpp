#include <iostream>
using namespace std;

template<typename T>
class Vector
{
    T* data;
public:
    int Length;
    int Capacity;
    Vector<T>() : Length(0), Capacity(10)
    {
        data = new T[10];
    }

    Vector<T>(int size) : Length(0), Capacity(size)
    {
        data = new T[size];
    }

    Vector<T>(const Vector<T>& other)
    {
        if (data != NULL)
        {
            delete[] data;
        }
        data = new T[other.Length * 2];
        Length = other.Length;
        Capacity = other.Length * 2;
        memcpy(data, other.data, sizeof(T)*Length);
    }

    Vector<T>& operator=(const Vector<T>& other)
    {
        if (data != NULL)
        {
            delete[] data;
        }
        data = new T[other.Length * 2];
        Length = other.Length;
        Capacity = other.Length * 2;
        memcpy(data, other.data, sizeof(T)*Length);
        return *this;
    }

    void Push(const T& value)
    {
        if (Length >= Capacity)
        {
            T* newData = new T[Capacity * 2];
            Capacity *= 2;
            memcpy(newData, data, sizeof(T)*Capacity);
            delete[] data;
            data = newData;
        }
        data[Length++] = value;
    }

    T operator[](int index)
    {
        return data[index];
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    Vector<int> vs[3];
    Vector<int>* pv = new Vector<int>(m);
    for (int i = 0; i < m; i++)
    {
        pv->Push(i + 1);
    }
    vs[0] = *pv;
    delete pv;
    pv = new Vector<int>(n);
    for (int i = 0; i < n; i++)
    {
        pv->Push(i * 2);
    }
    vs[1] = *pv;
    delete pv;
    vs[2] = vs[1];
    while (cin>>m)
    {
        cin >> n;
        vs[m - 1].Push(n);
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < vs[i].Length; j++)
        {
            cout << vs[i][j];
            if (j!=vs[i].Length-1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}