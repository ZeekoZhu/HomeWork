#include <iostream>

using namespace std;

class Monomials
{
public:
	int Factor;
	int Index;
};

class Node
{
public:
	Monomials Data;
	Node* Next;
	Node()
	{
		Next = nullptr;
		Data.Factor = Data.Index = 0;
	}
};

void InitMultinomial(int factorA, Node * &ma)
{
	for (int i = 0; i < factorA; i++)
	{
		if (i < (factorA - 1))
		{
			ma->Next = new Node();
		}

		cin >> ma->Data.Factor >> ma->Data.Index;
		ma = ma->Next;
	}
}

Node* Plus(Node* a, Node* b)
{
	Node* result = new Node();
	Node* rHead = result;
	while (a != nullptr || b != nullptr)
	{
		Node* temp = nullptr;
		if (a->Data.Index > b->Data.Index)
		{
			
		}
	}
}

int main()
{
	int factorA = 0;
	int factorB = 0;
	cin >> factorA;
	Node* ma = new Node();
	Node* ha = ma;
	InitMultinomial(factorA, ma);
	cin >> factorB;
	Node* mb = new Node();
	Node* hb = mb;
	InitMultinomial(factorB, mb);

}