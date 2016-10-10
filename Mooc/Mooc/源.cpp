#include <iostream>
#include <iomanip>

using namespace std;

class Node
{
public:
	int Data;
	int Next;
	int Address;
};
Node* FindIn(Node* nodes, int length, int address)
{
	for (int i = 0; i < length; i++)
	{
		if (nodes[i].Address == address)
		{
			return &nodes[i];
		}
	}
	return nullptr;
}

void FuckLink()
{
	int first;
	int total;
	int reverseIndex;
	cin >> first >> total >> reverseIndex;
	Node* nodes = new Node[total];
	for (int i = 0; i < total; i++)
	{
		cin >> nodes[i].Address >> nodes[i].Data >> nodes[i].Next;
	}

	Node* nodesSorted = new Node[total];
	int address = first;
	int validCount = 0;
	for (int i = 0; i < total; i++)
	{
		if (address == -1)
		{
			break;
		}
		nodesSorted[i] = *FindIn(nodes, total, address);
		validCount++;
		address = nodesSorted[i].Next;
	}

	for (int i = 0; i < validCount; i++)
	{
		if (i < reverseIndex)
		{
			int targetIndex = reverseIndex - 1 - i;
			nodes[i] = nodesSorted[targetIndex];
		}
		else
		{
			nodes[i] = nodesSorted[i];
		}
		if (i != 0)
		{
			nodes[i - 1].Next = nodes[i].Address;
		}
		if (i == validCount - 1)
		{
			nodes[i].Next = -1;
		}
	}

	for (int i = 0; i < validCount; i++)
	{
		cout << setw(5) << setfill('0') << nodes[i].Address << " " << nodes[i].Data << " ";
		if (i != validCount - 1)
		{
			cout << setw(5) << setfill('0') << nodes[i].Next << endl;
		}
		else
		{
			cout << nodes[i].Next << endl;
		}
	}
}
int main()
{
	Node* nodes = new Node[100000];
	int first;
	int total;
	int reverseIndex;
	cin >> first >> total >> reverseIndex;
	for (int i = 0; i < total; i++)
	{
		int index = 0;
		cin >> index;
		cin >> nodes[index].Data;
		cin >> nodes[index].Next;
		nodes[index].Address = index;
	}
	int validCount = 0;
	int* sortedIndex = new int[total];
	int address = first;
	for (int i = 0; i < total; i++)
	{
		if (address==-1)
		{
			break;
		}
		sortedIndex[i] = address;
		address = nodes[address].Next;
		validCount++;
	}
	for (int i = 0; i < reverseIndex / 2; i++)
	{
		int targetIndex = reverseIndex - i - 1;
		int tmp = sortedIndex[i];
		sortedIndex[i] = sortedIndex[targetIndex];
		sortedIndex[targetIndex] = tmp;
	}

	for (int i = 0; i < validCount; i++)
	{
		if (i != 0)
		{
			cout << setw(5) << setfill('0') << nodes[sortedIndex[i]].Address << endl;
		}
		cout << setw(5) << setfill('0') << sortedIndex[i] << " " << nodes[sortedIndex[i]].Data << " ";
	}
	cout << "-1";

}
