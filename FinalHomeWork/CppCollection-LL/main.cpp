#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class LinkCollection;

class Node
{
    friend class LinkCollection;
public:
    Node()
    {
        _next = nullptr;
    }

private:
    int _data;
    Node* _next;
};


class LinkCollection
{
public:
    Node* Head;
    LinkCollection();

    LinkCollection& Add(int value);

    string ToString();
    LinkCollection& Remove(int value);
    LinkCollection & operator&(const LinkCollection & other);
    LinkCollection & operator|(const LinkCollection & other);
    Node* FindPosotion(int value);
};

int main()
{
    LinkCollection c,b;
    c.Add(4).Add(3).Add(4);
    b.Add(4).Add(2);
    LinkCollection d = c & b;
    cout << d.ToString();
    return 0;
}



LinkCollection::LinkCollection()
{
    Head = new Node();
    Head->_data = INT_MIN;
}

LinkCollection & LinkCollection::Add(int value)
{
    Node* target = FindPosotion(value);
    if (target->_data != value)
    {
        Node* tmp = new Node();
        tmp->_data = value;
        tmp->_next = target->_next;
        target->_next = tmp;
    }

    return *this;
}

string LinkCollection::ToString()
{
    stringstream ss(ios::in | ios::out);
    ss << "{";
    Node* that = Head->_next;
    while (that != nullptr)
    {
        ss << that->_data;
        if (that->_next != nullptr)
        {
            ss << ",";
        }
        that = that->_next;
    }
    ss << "}";

    return ss.str();
}

Node * LinkCollection::FindPosotion(int value)
{
    Node* that = Head;
    Node* next = Head == nullptr ? nullptr : Head->_next;
    while (that != nullptr && next != nullptr)
    {
        if (that->_data == value)
        {
            return that;
        }
        if (that->_data < value)
        {
            if (next->_data > value)
            {
                return that;
            }
            else
            {
                that = next;
                next = next->_next;
            }
        }
    }
    return that;
}

LinkCollection& LinkCollection::Remove(int value)
{
    Node* that = FindPosotion(value - 1);
    if (that == Head || that == nullptr)
    {
        return *this;
    }
    else
    {
        if (that->_next->_data != value)
        {
            return *this;
        }
        Node* target = that->_next;
        that->_next = target->_next;
        delete target;
    }

    return *this;
}

LinkCollection& LinkCollection::operator&(const LinkCollection& other)
{
    LinkCollection* result = new LinkCollection();

    Node* ha = Head->_next;
    Node* hb = other.Head->_next;
    while (ha != nullptr && hb != nullptr)
    {
        if (ha->_data == hb->_data)
        {
            result->Add(ha->_data);
            ha = ha->_next;
            hb = hb->_next;
        }
        else if (ha->_data<hb->_data)
        {
            ha = ha->_next;
        }
        else
        {
            hb = hb->_next;
        }
    }

    return *result;
}

LinkCollection& LinkCollection::operator|(const LinkCollection& other)
{
    LinkCollection* result = new LinkCollection();

    Node* ha = Head->_next;
    Node* hb = other.Head->_next;
    while (ha != nullptr && hb != nullptr)
    {
        if (ha->_data == hb->_data)
        {
            result->Add(ha->_data);
            ha = ha->_next;
            hb = hb->_next;
        }
        else if (ha->_data < hb->_data)
        {
            ha = ha->_next;
        }
        else
        {
            hb = hb->_next;
        }
    }

    return *result;
}

