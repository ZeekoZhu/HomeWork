#include <iostream>
#include <iomanip>
using namespace std;



int main()
{
	int n;
	cin >> n;
	int martix[100][100];
	int x = n / 2;
	int y = 0;
	for (int i = 1; i <= n*n; i++)
	{
		martix[x][y] = i;
		x = (++x) % n;
		y = (--y) < 0 ? n - 1 : y;
		if (martix[x][y] > 0)
		{
			y = (++y) >= n ? 0 : y;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(3) << martix[j][i];
		}
		cout << endl;
	}

	return 0;
}