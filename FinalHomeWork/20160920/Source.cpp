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
/// <returns>第 m 项的值.</returns>
int ComputeFibonacci(int k, int m)
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

/// <summary>
/// 成绩记录类
/// </summary>
class Record
{
public:    
    /// <summary>
    /// 项目
    /// </summary>
    string Subject;    
    /// <summary>
    /// 性别
    /// </summary>
    bool Gender;    
    /// <summary>
    /// 学校
    /// </summary>
    string School;    
    /// <summary>
    /// 成绩
    /// </summary>
    double Grade;    
    /// <summary>
    /// 得分
    /// </summary>
    double Score;

    Record()
    {
    }
    
    /// <summary>
    /// Initializes a new instance of the <see cref="Record"/> class.
    /// </summary>
    /// <param name="subject">项目</param>
    /// <param name="gender">if set to <c>true</c> male.</param>
    /// <param name="school">学校</param>
    /// <param name="grade">成绩</param>
    /// <param name="score">得分</param>
    Record(string subject, bool gender, string school, double grade, double score)
    {
        Subject = subject;
        Gender = gender;
        School = school;
        Grade = grade;
        Score = score;
    }
    
    /// <summary>
    /// Initializes a new instance of the <see cref="Record"/> class.
    /// </summary>
    /// <param name="dataStr">The data string.</param>
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

    /// <summary>
    /// 将对象写入到文件中。
    /// </summary>
    /// <param name="path">The path.</param>
    void WriteToFile(string path)
    {
        string sperator = "||";
        ofstream fout(path,ios::out|ios::app);
        if (fout.is_open())
        {
            fout << Subject << sperator << Gender << sperator << School << sperator << Grade << sperator << Score << endl;
            fout.close();
        }
    }

    /// <summary>
    /// 从指定文件读取数据。
    /// </summary>
    /// <param name="path">The path.</param>
    /// <returns></returns>
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

/// <summary>
/// Initializes the data.
/// </summary>
void InitData()
{
    (new Record("sport||1||A||94||5"))->WriteToFile("data.txt");
    (new Record("sport||0||A||23||2"))->WriteToFile("data.txt");
    (new Record("sport||1||A||34||3"))->WriteToFile("data.txt");
    (new Record("sport||1||B||76||8"))->WriteToFile("data.txt");
    (new Record("sport||0||B||85||9"))->WriteToFile("data.txt");
    (new Record("sport||0||B||45||5"))->WriteToFile("data.txt");
    (new Record("sport||1||C||87||9"))->WriteToFile("data.txt");
    (new Record("sport||1||C||56||6"))->WriteToFile("data.txt");
    (new Record("sport||0||C||53||5"))->WriteToFile("data.txt");
    (new Record("sport||1||D||89||9"))->WriteToFile("data.txt");
    (new Record("sport||0||D||34||3"))->WriteToFile("data.txt");
    (new Record("sport||0||D||78||8"))->WriteToFile("data.txt");
    (new Record("sport||1||E||90||9"))->WriteToFile("data.txt");
    (new Record("sport||1||E||63||6"))->WriteToFile("data.txt");
    (new Record("sport||0||E||78||8"))->WriteToFile("data.txt");
    (new Record("sport||1||A||48||5"))->WriteToFile("data.txt");
    (new Record("sport||0||B||62||6"))->WriteToFile("data.txt");
    (new Record("sport||1||C||94||9"))->WriteToFile("data.txt");
    (new Record("sport||1||D||82||8"))->WriteToFile("data.txt");
    (new Record("sport||0||E||48||5"))->WriteToFile("data.txt");
}


int main()
{
    cout << ComputeFibonacci(3, 12) << endl;
    InitData();
    List<Record> records = Record::ReadFile("data.txt");
    List<string> schools;
    schools.Add("A").Add("B").Add("C").Add("D").Add("E")
        .ForEach([&records](string& s)->void
    {
        double boy = records.Where([s](Record& r)->bool
        {
            return r.Gender && r.School.compare(s) == 0;
        })
            ->Sum([](Record& r)->double
        {
            return r.Score;
        });
        double girl = records.Where([s](Record& r)->bool
        {
            return !r.Gender && r.School.compare(s) == 0;
        })
            ->Sum([](Record& r)->double
        {
            return r.Score;
        });
        cout << s << "学校的男生总分：" << boy << endl;
        cout << s << "学校的女生总分：" << girl << endl;
        cout << s << "学校的总体总分：" << boy + girl << endl;
    });
}