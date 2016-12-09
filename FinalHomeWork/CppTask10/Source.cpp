#include <iostream>
#include <string>
#include <vector>
#include <limits>

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

    Vector<T>(int size) : Length(size), Capacity(size * 2)
    {
        data = new T[size * 2];

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

void VectorTest()
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
}

void Init(int ** source, int m, int n);

void PixelTest();

struct Point
{
    int M;
    int N;
    Point(int m, int n) :M(m), N(m) {};
};

void PixelTest()
{
    int m, n, m1, n1;
    cin >> m >> n;
    // initialize the source graph
    int** source = new int*[m];
    Init(source, m, n);

    // initialize the subgraph
    cin >> m1 >> n1;
    int** target = new int*[m1];
    Init(target, m1, n1);

    // index range
    int rm = m - m1;
    int rn = n - n1;

    int distance = 0;

    int min = INT_MAX;
    vector<Point> results;

    for (int dm = 0; dm <= rm; dm++)
    {
        for (int dn = 0; dn <= rn; dn++)
        {
            distance = 0;
            for (int i = 0; i < m1; i++)
            {
                for (int j = 0; j < n1; j++)
                {
                    distance += abs(source[dm + i][dn + j] - target[i][j]);
                }
            }
            if (min > distance)
            {
                min = distance;
                results.clear();
                results.push_back(Point(dm, dn));
            }
            else if (min == distance)
            {
                results.push_back(Point(dm, dn));
            }
        }
    }

    cout << min << endl;
    for (int i = 0; i < results.size(); i++)
    {
        cout << "<" << results[i].M + 1 << "," << results[i].N + 1 << ">" << endl;
    }
}

void Pixel()
{
    PixelTest();


}

void Init(int ** source, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        source[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> source[i][j];
        }
    }
}

int main()
{
    //VectorTest();
    Pixel();
    return 0;
}