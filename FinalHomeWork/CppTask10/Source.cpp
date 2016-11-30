#include <iostream>
#include <string>

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

    T& operator[](int index)
    {
        if (index < 0 || index >= Length)
        {
            throw out_of_range("无中生有的下标，你去访问，等于你也有责任的吧，识唔识得啊？！");
        }
        return data[index];
    }

    ~Vector()
    {
        delete[] data;
    }
};

template<typename Tdata>
void Processer(Vector<Tdata>& vector)
{
    string step;
    while (step.compare("quit") != 0)
    {
        cin >> step;
        if (!step.compare("push"))
        {
            Tdata tmp;
            cin >> tmp;
            vector.Push(tmp);
        }
        else if (!step.compare("put"))
        {
            int index;
            Tdata tmp;
            cin >> index >> tmp;
            vector[index] = tmp;
        }
        else if (step == "fetch")
        {
            int index;
            cin >> index;
            try
            {
                cout << " " << vector[index];
            }
            catch (const std::out_of_range&)
            {
                cout << " invalid index:" << index;
            }
        }
        else if (step == "quit")
        {
            cout << endl;
            return;
        }
    }
}

int main()
{
    string command;
    while (cin >> command)
    {

        if (command == "int")
        {
            int capacity;
            cin >> capacity;
            Vector<int> vi(capacity);
            Processer<int>(vi);
        }
        else if (command == "string")
        {
            int capacity;
            cin >> capacity;
            Vector<string> vs(capacity);
            Processer<string>(vs);
        }
        else
        {
            throw new invalid_argument(command + " :Invalid command");
        }

    }
    return 0;
}