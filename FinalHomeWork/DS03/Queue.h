#ifndef MYQUEUE_H
#define MYQUEUE_H

template<typename T>
class Queue
{
public:
    int Rear;
    int Length;

    Queue<T>(int size)
    {
        Rear = -1;
        Length = 0;
        _data = new T[size];
        _size = size;
    }

    Queue<T>& PushBack(T value)
    {
        if (IsFull())
        {
            return *this;
        }
        _data[Rear++ / _size] = value;
        Length++;
        return *this;
    }

    T PopFront()
    {
        if (Length==0)
        {
            throw length_error("queue is empty");
        }
        else
        {
            return _data[Rear - Length];
        }
    }

    bool IsFull()
    {
        return Length==_size;
    }

private:
    int _size;
    T _data[];
};
#endif