#include <iostream>

using namespace std;

template<typename T>
class Node
{
public:
	T Data;
	Node<T>* Next;
	Node<T>()
	{
		Next = nullptr;
	}
};

/// <summary>
/// 初始化一个单链表
/// </summary>
/// <param name="head">The head.</param>
/// <param name="count">The count.</param>
void InitLink(Node<int>* head, int count)
{
	Node<int>* that = head;
	for (int i = 0; i < count; i++)
	{
		that->Data = i;
		that->Next = new Node<int>();
		if (i == count - 1)
		{
			that->Next = nullptr;
		}
		else
		{
			that = that->Next;
		}
	}
}

/// <summary>
/// 原地反转一个链表.
/// </summary>
/// <param name="head">The head.</param>
void Reverse(Node<int>*& head)
{
	Node<int>* before = nullptr;
	Node<int>* next = head->Next;
	Node<int>* that = head;
	while (next != nullptr)
	{
		that->Next = before;
		before = that;
		that = next;
		next = next->Next;
	}
	that->Next = before;
	head = that;
}

/// <summary>
/// 连接两个单链表.
/// 时间复杂度 = Min(m,n)
/// </summary>
/// <param name="ha">The ha.</param>
/// <param name="ca">链表 a 的长度.</param>
/// <param name="hb">The hb.</param>
/// <param name="cb">链表 b 的长度.</param>
/// <returns></returns>
Node<int>* Contact(Node<int>* ha, int ca, Node<int>* hb, int cb)
{
	Node<int>* first = ca <= cb ? ha : hb;
	Node<int>* last = ca > cb ? ha : hb;
	int length = ca < cb ? ca : cb;
	for (int i = 0; i < length - 1; i++)
	{
		first = first->Next;
	}
	first->Next = last;
	return ca <= cb ? ha : hb;
}

/// <summary>
/// 合并两个单链表.
/// </summary>
/// <param name="ha">The ha.</param>
/// <param name="hb">The hb.</param>
/// <returns></returns>
Node<int>* And(Node<int>* ha, Node<int>* hb)
{
	Node<int>* result = nullptr;
	Node<int>* tail = result;
	while (ha != nullptr&&hb != nullptr)
	{
		
		if (ha->Data < hb->Data)
		{
			ha = ha->Next;
		}
		else if (ha->Data > hb->Data)
		{
			hb = hb->Next;
		}
		else
		{
			if (result==nullptr)
			{
				result = tail = new Node<int>();
			}
			else
			{
				tail->Next = new Node<int>();
				tail = tail->Next;
			}
			tail->Data = ha->Data;
			hb = hb->Next;
			ha = ha->Next;
		}
	}
	return result;
}

int main()
{
	Node<int>* ha = new Node<int>();
	int ca = 4;
	int cb = 3;
	Node<int>* hb = new Node<int>();
	InitLink(ha, ca);
	InitLink(hb, cb);

	//Node<int>* hc = Contact(ha, ca, hb, cb);
	Node<int>* hc = And(ha, hb);
	//Reverse(hc);
	while (hc!=nullptr)
	{
		cout << hc->Data << "  ";
		hc = hc->Next;
	}
	cout << endl << "时间复杂度 = Min(m,n)" << endl;
}