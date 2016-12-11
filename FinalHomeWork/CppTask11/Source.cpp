#include <iostream>
#include <string>

using namespace std;

template <typename T>
class CircularBuffer
{
private: T* _buffer;
         int _size;
         int _bufferSize;
         T* _head;
public:

    class Iterator
    {
    private:
        CircularBuffer<T>* _buffer;
        T* _current;
    public:
        typedef	T							value_type;
        typedef	random_access_iterator_tag	iterator_category;
        typedef int							difference_type;
        typedef int							distance_type;
        typedef T*							pointer;
        typedef T&							reference;
        typedef const T*					const_pointer;
        typedef const T&					const_reference;
        Iterator() {}
        Iterator(T* current, CircularBuffer<T>* buffer) :_current(current), _buffer(buffer) {}
        Iterator(const Iterator& it) :_current(it._current), _buffer(it._buffer) {}

        T& operator*()const
        {
            return *_current;
        }
        Iterator& operator++()
        {
            _current = _buffer->Move(_current, 1);
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator tmp(*this);
            _current = _buffer->Move(_current, 1);
            return tmp;
        }

        bool operator==(const Iterator& it)const
        {
            return this->_current == it._current;
        }

        bool operator!=(const Iterator& it)const
        {
            return this->_current != it._current;
        }
    };
    CircularBuffer() :_buffer(NULL), _size(0), _bufferSize(0), _head(NULL)
    {
    }

    CircularBuffer(int n) :_size(0), _bufferSize(n), _buffer(NULL)
    {
        if (_bufferSize > 0)
        {
            _buffer = new T[_bufferSize];
            _head = _buffer;
        }
    }

    ~CircularBuffer()
    {
        delete[] _buffer;
    }

    T PopFront()
    {
        if (IsEmpty())
        {
            throw new out_of_range("the buffer is empty");
        }
        T tmp = *_head;
        _head = Move(_head, 1);
        _size--;
        return tmp;
    }

    void PushBack(const T& value)
    {
        if (IsFull())
        {
            throw new out_of_range("the buffer is full");
        }
        T* tail = Move(_head, _size);
        *tail = value;
        _size++;
    }

    void Print()
    {
        Iterator it = this->Begin();
        Iterator end = this->End();
        while (it != end)
        {
            cout << " " << *it;
            it++;
        }
    }

    bool IsEmpty()
    {
        return _size <= 0;
    }

    bool IsFull()
    {
        return _size >= _bufferSize;
    }

    T* Move(T* ptr, int len)
    {
        return _buffer + (ptr - _buffer + len) % 5;
    }

    Iterator Begin()
    {
        return Iterator(_head, this);
    }

    Iterator End()
    {
        return Iterator(Move(_head, _size), this);
    }
};

template <typename T>
void Processer(int s)
{
    CircularBuffer<T> cb(s);
    string command;
    while (cin >> command)
    {
        if (command == "push")
        {
            T tmp;
            cin >> tmp;
            cb.PushBack(tmp);
        }
        else if (command == "pop")
        {
            cout << " " << cb.PopFront();
        }
        else if (command == "print")
        {
            cb.Print();
        }
        else if (command == "quit")
        {
            break;
        }
    }
    return;
}

int main()
{
    string command;
    int size;
    while (cin >> command >> size)
    {
        if (command == "int")
        {
            Processer<int>(size);
        }
        else if (command == "string")
        {
            Processer<string>(size);
        }
    }

}