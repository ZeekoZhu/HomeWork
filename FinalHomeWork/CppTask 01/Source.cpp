#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void Martix()
{
	int n;
	cin >> n;
	int martix[100][100];
	int x = n / 2;
	int y = 0;
	for (int i = 1; i <= n*n; i++)
	{
		martix[x][y] = i;
		if (i % n == 0)
		{
			y = (++y) % n;
		}
		else
		{
			x = (++x) % n;
			y = (--y) < 0 ? n - 1 : y;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(5) << martix[j][i];
		}
		cout << endl << endl;
	}
}

bool IsPrime(int num)
{
	if (num <= 0)
	{
		return false;
	}
	for (int i = 2; i < num / 2; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}


int main()
{
	vector<int> V;
	queue<int> Q;
	stack<int> S1, S2;
	int num;
	while (cin >> num)
	{
		if (num < 0)
		{
			V.push_back(num);
		}
		else if (num > 0)
		{
			if (IsPrime(num))
			{
				Q.push(num);
			}
			if (num % 2)
			{
				S2.push(num);
			}
			else
			{
				S1.push(num);
			}
		}
	}

	for (int i = 0;i<V.size();i++)
	{
		cout << V[i] << '\t';
	}
	cout << endl;

	while (!Q.empty())
	{
		cout << Q.front() << '\t';
		Q.pop();
	}
	cout << endl;

	while (!S1.empty())
	{
		cout << S1.top() << '\t';
		S1.pop();
	}
	cout << endl;

	while (!S2.empty())
	{
		cout << S2.top() << '\t';
		S2.pop();
	}

	return 0;
}