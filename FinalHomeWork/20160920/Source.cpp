#include<iostream>
#include<fstream>
#include <string>
#include "../FinalHomeWork/Collection.h"

using namespace std;

int FuckFibonacci(int k, int m)
{
	if (m < k - 1)
	{
		return 0;
	}
	else if (m == k - 1)
	{
		return 1;
	}
	else
	{
		int first = 1;
		int second = 1;
		m = m - k;
		while (m > 0)
		{
			second += first;
			first = second - first;
			m--;
		}
		return second;
	}
}

class Record
{
public:
	string Subject;
	bool Gender;
	string School;
	double Grade;
	double Score;

	Record(string subject, bool gender, string school, double grade, double score)
	{
		//Subject
	}

	void WriteToFile(string path)
	{
		string sperator = "||";
		ofstream fout(path);
		if (fout.is_open())
		{
			fout << Subject << sperator << Gender << sperator << School << sperator << Grade << sperator << Score << sperator << endl;
			fout.close();
		}
	}
};


int main()
{
	//cout << FuckFibonacci(6, 12);
	List<Record> records;
	//records.Add();
}