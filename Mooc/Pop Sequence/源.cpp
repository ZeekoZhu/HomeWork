#include <iostream>
#include <stack>

using namespace std;



bool Check(int N, int M)
{
	int* test = new int[N];
	int orderedIndex = 1;
	stack<int> tmpStack;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		if (tmp == orderedIndex&&orderedIndex <= N)
		{
			orderedIndex++;
			continue;
		}
		else if (!tmpStack.empty() && tmp == tmpStack.top())
		{
			tmpStack.pop();
		}
		else if (tmp > orderedIndex)
		{
			while (tmpStack.size() < M && orderedIndex != tmp&&orderedIndex <= N)
			{
				tmpStack.push(orderedIndex++);
			}
			if (orderedIndex != tmp)
			{
				return false;
			}
			orderedIndex++;
		}
	}

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