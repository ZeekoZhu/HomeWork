#include <iostream>
#include <string>

using namespace std;

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
        _before = _next = NULL;
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
        if (before != NULL)
        {
            before->_next = after;
        }
        else
        {
            this->head = after;
        }

        if (after != NULL)
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
        head = tail = NULL;
        Length = 0;
    }

    List<T>(List<T>& other)
    {
        head = tail = NULL;
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
        if (head == NULL)
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
        for (int i = 0; i < other.Length; i++)
        {
            this->Add(other[i]);
        }
        return *this;
    }



    List<T>& operator=(List<T>& other)
    {
        while (this->head != NULL)
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

    List<T>& Clear()
    {
        Node<T>* that = this->head;
        Node<T>* next = NULL;
        while (that != NULL)
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
        _top = NULL;
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
        if (_top != NULL)
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

class Number
{
public:
    List<int> Data;

    Number();

    Number(string number);

    string ToString();

    Number operator +(Number& other);
    Number operator-(Number & other);
    bool operator>(Number & other);
};


Number::Number()
{
}

Number::Number(string number)
{
    for (int i = 0; i < number.length(); i++)
    {
        Data.Add(number[i] - '0');
    }
}

/// <summary>
/// 将数字转换到字符串
/// </summary>
/// <returns></returns>
string Number::ToString()
{
    string result;
    bool valid = Data.Length == 1;
    for (int i = 0; i < Data.Length; i++)
    {
        if (Data[i] < 0)
        {
            result.append(1, '-');
        }
        else
        {
            char c = Data[i] + '0';
            if (c != '0' || valid)
            {
                valid = true;
                result.append(1, c);
            }
        }
    }
    return result;
}

/// <summary>
/// 加法
/// </summary>
/// <param name="other">The other.</param>
/// <returns></returns>
Number Number::operator+(Number& other)
{
    Number result;
    result.Data.Clear();
    int tmp = 0;
    int i = Data.Length - 1;
    int j = other.Data.Length - 1;
    while (i >= 0 && j >= 0)
    {
        int a = Data[i];
        int b = other.Data[j];
        result.Data.InsertAt((a + b + tmp) % 10, 0);
        tmp = (a + b + tmp) / 10;
        i--;
        j--;
    }
    while (i >= 0)
    {
        result.Data.InsertAt((Data[i] + tmp) % 10, 0);
        tmp = (Data[i] + tmp) / 10;
        i--;
    }
    while (j >= 0)
    {
        result.Data.InsertAt((other.Data[j] + tmp) % 10, 0);
        tmp = (other.Data[j] + tmp) / 10;
        j--;
    }
    if (tmp)
    {
        result.Data.InsertAt(1, 0);
    }
    return result;
}

/// <summary>
/// 减法
/// </summary>
/// <param name="other">The other.</param>
/// <returns></returns>
Number Number::operator-(Number& other)
{
    Number result;
    bool isZero = true;
    bool isNagetive = other > *this;
    Number na = isNagetive ? other : *this;
    Number nb = isNagetive ? *this : other;
    int i = na.Data.Length - 1;
    int j = nb.Data.Length - 1;
    while (i >= 0 && j >= 0)
    {
        int a = na.Data[i];
        int b = nb.Data[j];
        int tmp = a - b;
        if (tmp != 0)
        {
            isZero = false;
        }
        if (tmp < 0)
        {
            if (i - 1 < 0)
            {
                isNagetive = true;
            }
            else
            {
                na.Data[i - 1]--;
                tmp += 10;
            }
        }
        result.Data.InsertAt(tmp, 0);
        i--; j--;
    }
    while (i >= 0)
    {
        isZero = false;
        result.Data.InsertAt(na.Data[i], 0);
        i--;
    }
    while (j >= 0)
    {
        isZero = false;
        result.Data.InsertAt(nb.Data[j], 0);
        j--;
    }
    if (isZero)
    {
        result.Data.Clear().Add(0);
    }
    if (isNagetive && !isZero)
    {
        result.Data.InsertAt(-1, 0);
    }
    return result;
}


bool Number::operator>(Number& other)
{
    if (Data.Length == other.Data.Length)
    {
        for (int i = 0; i < Data.Length; i++)
        {
            if (Data[i] != other.Data[i])
            {
                return Data[i] > other.Data[i];
            }
        }
    }
    else
    {
        return Data.Length > other.Data.Length;
    }
}

int main()
{

    string sa = "123123";
    string sb = "123124";
    cin >> sa >> sb;
    Number a(sa);
    Number b(sb);
    Number c = a + b;
    Number d = a - b;
    cout << c.ToString() << endl;
    cout << d.ToString();

    return 0;
}
