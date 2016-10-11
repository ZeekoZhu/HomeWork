#include <iostream>
#include <stack>

using namespace std;



bool Check(int N, int M)
{
	// 表示下一个入栈的数
	int orderedIndex = 1;
	// 那个栈
	stack<int> tmpStack;

	for (int i = 0; i < N; i++)
	{
		// 读入一个出栈的数
		int tmp;
		cin >> tmp;

		// 如果要出栈的数与下一个入栈的数相等，辣么就跳过入栈的过程，直接弹出
		if (tmp == orderedIndex && orderedIndex <= N)
		{
			orderedIndex++;
			continue;
		}
		// 如果要出栈的数与栈顶元素相等，就弹出
		else if (!tmpStack.empty() && tmp == tmpStack.top())
		{
			tmpStack.pop();
		}
		// 如果要出栈的数大于下一个要进栈的数
		else if (tmp > orderedIndex)
		{
			// 就不断的让序列入栈，直到下一个要入栈的数与要出栈的数相等
			while (tmpStack.size() < M && orderedIndex != tmp && orderedIndex <= N)
			{
				tmpStack.push(orderedIndex++);
			}
			// 如果栈满了，但下一个要入栈的数与要出栈的数不等
			if (orderedIndex != tmp && tmpStack.size() == M)
			{
				// 说明这个出栈序列是错误的
				return false;
			}

			// 跳过入栈过程，直接弹出
			orderedIndex++;
		}
	}

	// 如果栈完全空了，辣么这个序列就是可行的
	return tmpStack.empty();
}


int main()
{
	int M; // stack capacity
	int N; // length of push sequence
	int K; // check times
	cin >> M;
	cin >> N;
	cin >> K;
	stack<int> tmpStack;
	for (int i = 0; i < K; i++)
	{
		cout << (Check(N, M) ? "YES" : "NO") << endl;
	}
}