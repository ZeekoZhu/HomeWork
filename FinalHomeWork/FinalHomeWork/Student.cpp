#include "Student.h"
#include "Collection.h"
#include <fstream>
#include <iomanip>


List<Student>& Student::ReadFile(string path)
{
    List<Student>* result = new List<Student>();
    ifstream fin;
    fin.open(path, ios::in);
    while (!fin.eof())
    {
        Student* tmp = new Student();
        fin >> tmp->Name >> tmp->StudentId >> tmp->Chinese >> tmp->Math >> tmp->English;
        result->Add(*tmp);
    }
    return *result;
}

List<Student>& Student::WriteFile(string path, List<Student>& stus)
{
    ofstream fout;
    fout.open(path, ios::out);
    stus.ForEach([&fout](Student s)->void
    {
        fout << setw(8)<< s.Name << setw(8)<< s.StudentId << setw(8)<< s.Chinese << setw(8)<< s.Math << setw(8)<< s.English << endl;
    });
    fout.close();
    return stus;
}

Student::Student()
{
}


Student::~Student()
{
}
