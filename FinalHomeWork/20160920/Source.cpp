#include<iostream>
#include<fstream>
#include <string>
#include <regex>
#include <stdio.h>
#include "Collection.h"

using namespace std;

/// <summary>
/// 计算斐波那契数列
/// </summary>
/// <param name="k">The k.</param>
/// <param name="m">The m.</param>
/// <returns></returns>
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

	Record()
	{}
	Record(string subject, bool gender, string school, double grade, double score)
	{
		Subject = subject;
		Gender = gender;
		School = school;
		Grade = grade;
		Score = score;
	}

	Record(string dataStr)
	{
		regex pattern("(\\w+)\\|\\|(\\w+)\\|\\|(\\w+)\\|\\|(\\w+)\\|\\|(\\w+)");
		match_results<std::string::const_iterator> result;
		if (regex_match(dataStr, result, pattern))
		{
			Subject = result[1];
			Gender = result[2].str()[0] == '1';
			School = result[3];
			sscanf(result[4].str().c_str(), "%lf", &Grade);
			sscanf(result[5].str().c_str(), "%lf", &Score);
		}
	}

	void WriteToFile(string path)
	{
		string sperator = "||";
		ofstream fout(path);
		if (fout.is_open())
		{
			fout << Subject << sperator << Gender << sperator << School << sperator << Grade << sperator << Score << endl;
			fout.close();
		}
	}

	static List<Record>& ReadFile(string path)
	{
		List<Record>* records = new List<Record>();
		ifstream sout;
		sout.open(path.c_str(), ios::in);
		string line;
		while (!sout.eof())
		{
			getline(sout, line);
			records->Add(*new Record(line));
		}
		sout.close();
		return *records;
	}

	
};


int main()
{
	//cout << FuckFibonacci(6, 12);
	List<Record> records = Record::ReadFile("test.txt");
	records.ForEach([](Record& r)->void
	{
		cout << r.Subject << " " << r.Gender << " " << r.School << " " << r.Grade << " " << r.Score << endl;
	});
	/*Record* r = new Record("fuck||1||hdu||1||346");
	r->WriteToFile("test.txt");*/
	//Record::ReadFile("test.txt");
	//records.Add();
}