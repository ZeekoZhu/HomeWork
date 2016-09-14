#pragma once
#include <iostream>

template <typename T> class List;

/// <summary>
/// 线性结构节点类
/// </summary>
template <typename T>
class Node
{
	friend class List<T>;
public:
	static int _total;
protected:
	Node<T>* _before;
	Node<T>* _next;
	T data;
	Node()
	{
		_total++;
	}
	~Node()
	{
		_total--;
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
		cout << "Init a List!" << endl;
		head = tail = nullptr;
		Length = 0;
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

	/// <summary>
	/// 下标访问
	/// </summary>
	/// <param name="n">The n.</param>
	/// <returns></returns>
	T& operator[] (std::size_t n)
	{
		return this->GetNodeAt(n).data;
	}

	List<T>& RemoveAt(size_t index)
	{
	}




};