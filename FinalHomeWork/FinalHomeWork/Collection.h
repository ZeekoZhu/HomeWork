#pragma once
#include <iostream>
#include <functional>

#ifndef MYLIST_H
#define MYLIST_H
template <typename T> class List;
template <typename T> class Stack;

/// <summary>
/// 线性结构节点类
/// </summary>
template <typename T>
class Node
{
    friend class List<T>;
    friend class Stack<T>;
public:
    static int _total;
protected:
    Node<T>* _before;
    Node<T>* _next;
    T data;
    Node()
    {
        _before = _next = nullptr;
        _total++;
    }
    ~Node()
    {
        _total--;
        //cout << endl << "delete a node : " << Node<T>::_total;
    }
};


/// <summary>
/// 全部的未销毁的节点个数
/// </summary>
template <typename T>
int Node<T>::_total = 0;




/// <summary>
/// 链表
/// </summary>
template <typename T>
class List
{
protected:
    Node<T>* head;
    Node<T>* tail;

    /// <summary>
    /// 获取数据节点.
    /// </summary>
    /// <param name="index">The index.</param>
    /// <returns></returns>
    Node<T>& GetNodeAt(size_t index)
    {
        Node<T>* that = this->head;
        for (int i = 0; i < Length; i++)
        {
            if (i == index)
            {
                return *that;
            }
            that = that->_next;
        }
        throw length_error("Segement fault");
    }

    List<T>& RemoveNode(Node<T>& that)
    {
        Node<T>* before = that._before;
        Node<T>* after = that._next;
        if (before != nullptr)
        {
            before->_next = after;
        }
        else
        {
            this->head = after;
        }

        if (after != nullptr)
        {
            after->_before = before;
        }
        else
        {
            this->tail = before;
        }
        delete &that;
        Length--;
        return *this;
    }
public:

    /// <summary>
    /// 获取元素个数
    /// </summary>
    int Length;

    /// <summary>
    /// Initializes a new instance of the <see cref="List"/> class.
    /// </summary>
    List()
    {
        Total++;
        //cout << "Init a List!" << endl;
        head = tail = nullptr;
        Length = 0;
    }

    List<T>(List<T>& other)
    {
        head = tail = nullptr;
        Length = 0;
        this->AddRange(other);
    }

    ~List()
    {
        Total--;
        //cout << "list count : " << Total;
    }


    /// <summary>
    /// 向末尾添加一个元素。
    /// </summary>
    /// <param name="value">The value.</param>
    /// <returns></returns>
    List<T>& Add(T value)
    {
        Node<T>* next = new Node<T>();
        next->data = value;
        if (head == nullptr)
        {
            head = tail = next;
        }
        else
        {
            tail->_next = next;
            next->_before = tail;
            tail = next;
        }
        Length++;
        return *this;
    }

    List<T>& AddRange(List<T>& other)
    {
        other.ForEach([this](T value)->void
        {
            this->Add(value);
        });
        return *this;
    }



    List<T>& operator=(List<T>& other)
    {
        while (this->head != nullptr)
        {
            Node<T>* that = head;
            head = head->_next;
            RemoveNode(*that);
        }
        this->AddRange(other);
        return *this;
    }

    /// <summary>
    /// 下标访问
    /// </summary>
    /// <param name="n">The n.</param>
    /// <returns></returns>
    T& operator[] (std::size_t n)
    {
        return this->GetNodeAt(n).data;
    }

    /* const T& operator[] (std::size_t n)
     {
         return this->GetNodeAt(n).data;
     }*/

    List<T>& RemoveAt(size_t index)
    {
        Node<T>& that = this->GetNodeAt(index);
        RemoveNode(that);
        return *this;
    }

    List<T>& Remove(std::function<bool(T&)> predicate)
    {
        Node<T>* that = this->head;
        Node<T>* next = nullptr;
        while (that->_next != nullptr)
        {
            next = that->_next;
            if (predicate(that->data))
            {
                RemoveNode(*that);
            }
            that = next;
        }
        return *this;
    }

    List<T>& Clear()
    {
        Node<T>* that = this->head;
        Node<T>* next = nullptr;
        while (that != nullptr)
        {
            next = that->_next;
            RemoveNode(*that);
            that = next;
        }
        return *this;
    }

    List<T>& InsertAt(T value, int index)
    {
        if (index < 0 || index > Length)
        {
            throw length_error("Segement fault!");
        }
        else if (index == Length)
        {
            this->Add(value);
        }
        else
        {
            Node<T>* target = new Node<T>();
            target->data = value;
            Node<T>& that = this->GetNodeAt(index);
            target->_before = that._before;
            that._before = target;
            target->_next = &that;
            this->Length++;
            if (index == 0)
            {
                this->head = target;
            }
        }
        return *this;
    }

    /// <summary>
    /// 对集合中所有元素执行操作
    /// </summary>
    /// <param name="action">The action.</param>
    /// <returns></returns>
    List<T>& ForEach(std::function<void(T&)> action)
    {
        Node<T>* that = this->head;
        while (that != nullptr)
        {
            action(that->data);
            that = that->_next;
        }
        return *this;
    }


    /// <summary>
    /// 参见 https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/map
    /// </summary>
    /// <param name="action">The action.</param>
    /// <returns></returns>
    template <typename TRes>
    List<T>* Map(std::function<TRes(T&)> action)
    {
        List<TRes>* result = new List<TRes>();
        Node<T>* that = this->head;
        while (that != nullptr)
        {
            TRes temp = action(that->data);
            result->Add(temp);
            that = that->_next;
        }

        return result;
    }

    List<T>* Where(std::function<bool(T&)> predicate)
    {
        List<T>* result = new List<T>();
        Node<T>* that = this->head;
        while (that != nullptr)
        {
            if (predicate(that->data))
            {
                result->Add(that->data);
            }
            that = that->_next;
        }
        return result;
    }

    double Sum(std::function<double(T&)> propertySelector)
    {
        double result = 0.0;
        this->ForEach([&result, &propertySelector](T& item)->void
        {
            result += propertySelector(item);
        });
        return result;
    }

    List<T>& Sort(std::function<bool(T&, T&)> comparer)
    {
        List<T>* result = new List<T>();
        result = *this;
        Node<T>* begin = result->head;
        Node<T>* end = result->tail;
        QSort(begin, end, comparer);

    }

    void QSort(Node<T>* begin, Node<T>* end, std::function<bool(T&, T&)> comparer)
    {
        if (begin == end || begin == nullptr || end == nullptr)
        {
            return;
        }
        Node<T>* initBegin = begin;
        Node<T>* initEnd = end;
        Node<T> base = *begin;
        Node<T>* current = begin;

        while (begin != end)
        {
            // 先找一个比 base 小的
            while (comparer(end->data, base.data) && end != begin)
            {
                end = end->_before;
            }
            current->data = end->data;
            current = end;
            // 再找一个比 base 大的
            while (!comparer(begin->data, base.data) && begin != end)
            {
                begin = begin->_next;
            }
            current->data = begin->data;
            current = begin;
        }
        current->data = base.data;
        QSort(initBegin, current);
        QSort(current, initEnd);
    }

    static int Total;
};

template <typename T> int List<T>::Total = 0;



template<typename T> class Stack
{
private:
    Node<T>* _top;
public:
    int Length;
    Stack()
    {
        Length = 0;
        _top = nullptr;
    }
    Stack<T>& Push(T data)
    {
        Node<T>* value = new Node<T>();
        value->data = data;
        value->_before = this->_top;
        Length++;
        _top = value;
        return *this;
    }
    T Pop()
    {
        T result;
        if (_top != nullptr)
        {
            result = _top->data;
            _top = _top->_before;
            Length--;
        }
        else
        {
            throw length_error("Segament Error!");
        }
        return result;
    }
};

#endif