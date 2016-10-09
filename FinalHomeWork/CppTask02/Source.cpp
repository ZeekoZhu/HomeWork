#include <iostream>

using namespace std;

class Node
{
public:
	int Position;
	Node* Next;
	Node() :Next(nullptr)
	{}
};

Node* InitJosephus(int n)
{
	Node* head = new Node();
	head->Position = 0;
	Node* that = head;
	for (int i = 1; i < n; i++)
	{
		Node* next = new Node();
		next->Position = i;
		that->Next = next;
		that = next;
	}
	that->Next = head;
	return head;
}

void RemoveNext(Node* that)
{
	Node* temp = that->Next;
	cout << temp->Position + 1 << endl;
	that->Next = temp->Next;
	delete temp;
}

int Josephus(int begin, int n, int k)
{

	Node* head = InitJosephus(n);
	if (begin > n)
	{
		return -1;
	}
	while (begin-- > 0)
	{
		head = head->Next;
	}
	while (head->Next != head)
	{
		for (int i = 0; i < k - 2; i++)
		{
			head = head->Next;
		}
		RemoveNext(head);
		head = head->Next;
	}
	return head->Position;
}

class Stack
{
public:

	Stack(int n) :_datas(new int[n]), _length(n), _top(-1)
	{}

	Stack() :_datas(new int[10]), _length(10), _top(-1)
	{}

	void Push(int value)
	{
		if (_top == _length - 1)
		{
			int* datas = new int[_length * 2];
			for (int i = 0; i < _length; i++)
			{
				datas[i] = _datas[i];
			}

			_length *= 2;
			int* that = _datas;
			_datas = datas;
			delete that;
		}
		_datas[++_top] = value;
	}

	void Pop()
	{
		_top--;
	}

	int Top()
	{
		return _datas[_top];
	}
private:
	int* _datas;
	int _length;
	int _top;
};


int main()
{
	cout << "Winner: " << Josephus(0, 10, 3) + 1;
	Stack s = Stack(3);
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	cout << s.Top() << endl;
	s.Pop();
	cout << s.Top() << endl;
	s.Pop();
	cout << s.Top() << endl;
	s.Pop();
	cout << s.Top() << endl;
	return 0;
}