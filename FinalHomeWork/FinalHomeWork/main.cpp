#include <iostream>
#include "Collection.h"
#include <string>
#include "NumSys.h"
#include "Number.h"
#include <fstream>
#include "Student.h"

using namespace std;


int main()
{
    //CollectionTest::Test();
    /*cout << ConvertOctWithArray(2, "111") << endl;
    cout << FromOctToWithArray(16, 56);*/

    string sa = "123123";
    string sb = "123124";
    Number a(sa);
    Number b(sb);
    Number c = a + b;
    Number d = a - b;
    cout << d.ToString();

    /*ofstream fout("fuck.txt", ios::out | ios::app);
    if (fout.is_open())
    {
        fout << 12 << " " << "hello" << " " << 12.244;
        fout.close();
    }*/

    /*auto f1 = Student::ReadFile("1.txt");
    auto f2 = Student::ReadFile("2.txt");
    List<Student> f3 = f1;
    f3.AddRange(f2);
    Student::WriteFile("3.txt", f3);*/
    return 0;
}