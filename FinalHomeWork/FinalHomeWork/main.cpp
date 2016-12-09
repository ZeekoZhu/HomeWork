#include <iostream>
#include <iomanip>
#include "Collection.h"
#include <string>
#include "NumSys.h"
#include "Number.h"
#include <fstream>
#include "Student.h"
#include "CollectionTest.h"
#include "Market.h"

using namespace std;

void four()
{
    auto f1 = Student::ReadFile("1.txt");
    auto f2 = Student::ReadFile("2.txt");
    List<Student> f3 = f1;
    f3.AddRange(f2);
    Student::WriteFile("3.txt", f3);
    cout << "Datas have been merged to 3.txt" << endl;
    List<Student>* again = f3.Where([](Student& s)->bool
    {
        return s.Chinese < 60 || s.English < 60 || s.Math < 60;
    });
    Student::WriteFile("4.txt", *again);
    cout << "Resit list has been written into 4.txt" << endl;
    // the second method to sort
    /*List<Student> sorted = again->PopSort([](Student s, Student b)->bool
    {
    int ss = s.Math + s.English + s.Chinese;
    int bs = b.Math + b.English + b.Chinese;
    return ss > bs;
    });*/
    List<Student> sorted = f3.Sort([](Student s, Student b)->bool
    {
        int ss = s.Math + s.English + s.Chinese;
        int bs = b.Math + b.English + b.Chinese;
        return ss > bs;
    });

    cout << setw(8) << "Name" << setw(8) << "StudentId" << setw(8) << "Chinese" << setw(8) << "Math" << setw(8) << "English" << endl;
    sorted.ForEach([](Student& s)->void
    {
        cout << setw(8) << s.Name << setw(8) << s.StudentId << setw(8) << s.Chinese << setw(8) << s.Math << setw(8) << s.English << endl;
    });
    string name;
    while (1)
    {
        cout << "please enter the student's name:" << endl;
        cin >> name;
        auto res = sorted.Where([&name](Student& s)->bool
        {
            return s.Name.compare(name) == 0;
        });
        cout << setw(8) << "Name" << setw(8) << "StudentId" << setw(8) << "Chinese" << setw(8) << "Math" << setw(8) << "English" << endl;
        res->ForEach([](Student& s)->void
        {
            cout << setw(8) << s.Name << setw(8) << s.StudentId << setw(8) << s.Chinese << setw(8) << s.Math << setw(8) << s.English << endl;
        });
        // the second method to search
        /*sorted.ForEach([&name](Student& s)->void
        {
        if (s.Name.compare(name) == 0)
        {
        cout << setw(8) << s.Name << setw(8) << s.StudentId << setw(8) << s.Chinese << setw(8) << s.Math << setw(8) << s.English << endl;
        }
        });*/
    }
}

int main()
{
    //four();
    //CollectionTest::Test();
    /*cout << ConvertOctWithArray(2, "111") << endl;
    cout << FromOctToWithArray(16, 56);*/

    /*string sa = "123123";
    string sb = "123123";
    Number a(sa);
    Number b(sb);
    Number c = a + b;
    cout << c.ToString();*/

    /*ofstream fout("fuck.txt", ios::out | ios::app);
    if (fout.is_open())
    {
        fout << 12 << " " << "hello" << " " << 12.244;
        fout.close();
    }*/


    //CollectionTest::HuffmanTest();
    CollectionTest::ListSortTest();
    //Dijkstra();
    return 0;
}