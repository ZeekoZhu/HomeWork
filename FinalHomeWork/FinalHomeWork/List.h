#pragma once
#include <iostream>
#include <functional>

template <typename T> class List;

/// <summary>
/// 线性结构节点类
/// </summary>
template <typename T>
class ListNode
{
	friend class List<T>;
public:
	static int _total;
protected:
	ListNode<T>* _before;
	ListNode<T>* _next;
	T data;
	ListNode()
	{
		_before = _next = nullptr;
		_total++;
	}
	~ListNode()
	{
		_total--;
		cout << endl << "delete a node : " << ListNode<T>::_total;
	}
};


/// <summary>
/// 全部的未销毁的节点个数
/// </summary>
template <typename T>
int ListNode<T>::_total = 0;




/// <summary>
/// 链表
/// </summary>
template <typename T>
class List
{
protected:
	ListNode<T>* head;
	ListNode<T>* tail;

	/// <summary>
	/// 获取数据节点.
	/// </summary>
	/// <param name="index">The index.</param>
	/// <returns></returns>
	ListNode<T>& GetNodeAt(size_t index)
	{
		ListNode<T>* that = this->head;
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

	List<T>& RemoveNode(ListNode<T>& that)
	{
		ListNode<T>* before = that._before;
		ListNode<T>* after = that._next;
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
		cout << "Init a List!" << endl;
		head = tail = nullptr;
		Length = 0;
	}

	~List()
	{
		Total--;
		cout << "list count : " << Total;
	}


	/// <summary>
	/// 向末尾添加一个元素。
	/// </summary>
	/// <param name="value">The value.</param>
	/// <returns></returns>
	List<T>& Add(T value)
	{
		ListNode<T>* next = new ListNode<T>();
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
		ListNode<T>& that = this->GetNodeAt(index);
		RemoveNode(that);
		return *this;
	}

	List<T>& Remove(std::function<bool(T&)> predicate)
	{
		ListNode<T>* that = this->head;
		ListNode<T>* next = nullptr;
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
		ListNode<T>* that = this->head;
		ListNode<T>* next = nullptr;
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
			ListNode<T>* target = new ListNode<T>();
			target->data = value;
			ListNode<T>& that = this->GetNodeAt(index);
			target->_before = that._before;
			that._before = target;
			target->_next = &that;
			this->Length++;
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
		ListNode<T>* that = this->head;
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
		ListNode<T>* that = this->head;
		while (that != nullptr)
		{
			TRes temp = action(that->data);
			result->Add(temp);
			that = that->_next;
		}

		return result;
	}

	static int Total;
};

template <typename T> int List<T>::Total = 0;