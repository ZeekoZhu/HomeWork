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
        _next = NULL;
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
    LinkCollection & operator-(const LinkCollection & other);
    Node* FindPosotion(int value);
};

int main()
{
    int m, n;
    cin >> m >> n;
    LinkCollection c,b;
    for (int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        c.Add(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        b.Add(tmp);
    }
    LinkCollection d = c - b;
    cout << c.ToString() << endl;
    cout << b.ToString() << endl;
    cout << (c | b).ToString() << endl;
    cout << (c & b).ToString() << endl;
    cout << (c - b).ToString() << endl;

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
    while (that != NULL)
    {
        ss << that->_data;
        if (that->_next != NULL)
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
    Node* next = Head == NULL ? NULL : Head->_next;
    while (that != NULL && next != NULL)
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
    if (that == Head || that == NULL)
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
    while (ha != NULL && hb != NULL)
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
    while (ha != NULL && hb != NULL)
    {
        if (ha->_data == hb->_data)
        {
            result->Add(hb->_data);
            ha = ha->_next;
            hb = hb->_next;
        }
        else if (ha->_data < hb->_data)
        {
            result->Add(ha->_data);
            ha = ha->_next;
        }
        else
        {
            result->Add(hb->_data);
            hb = hb->_next;
        }
    }

    while (ha != NULL)
    {
        result->Add(ha->_data);
        ha = ha->_next;
    }
    while (hb != NULL)
    {
        result->Add(hb->_data);
        hb = hb->_next;
    }

    return *result;
}

LinkCollection& LinkCollection::operator-(const LinkCollection& other)
{
    LinkCollection* result = new LinkCollection();

    Node* ha = Head->_next;
    Node* hb = other.Head->_next;
    while (ha != NULL && hb != NULL)
    {
        if (hb->_data==ha->_data)
        {
            ha = ha->_next;
            hb = hb->_next;
        }
        else if (hb->_data<ha->_data)
        {
            hb = hb->_next;
        }
        else
        {
            result->Add(ha->_data);
            ha = ha->_next;
        }
    }

    while (ha != NULL)
    {
        result->Add(ha->_data);
        ha = ha->_next;
    }

    return *result;
}

