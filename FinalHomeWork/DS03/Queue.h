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
    
    /// <summary>
    /// 插入一个元素
    /// </summary>
    /// <param name="value">The value.</param>
    /// <returns></returns>
    Queue<T>& PushBack(T value)
    {
        if (IsFull())
        {
            return *this;
        }
        _data[++Rear % _size] = value;
        Length++;
        return *this;
    }
    
    /// <summary>
    /// 弹出队首元素
    /// </summary>
    /// <returns></returns>
    T PopFront()
    {
        if (Length == 0)
        {
            throw length_error("queue is empty");
        }
        else
        {
            return _data[(Rear - (Length--) + 1 + _size) % _size];
        }
    }
    
    /// <summary>
    /// 判断队列是否满了
    /// </summary>
    /// <returns></returns>
    bool IsFull()
    {
        return Length == _size;
    }

private:
    int _size;
    T* _data;
};
#endif