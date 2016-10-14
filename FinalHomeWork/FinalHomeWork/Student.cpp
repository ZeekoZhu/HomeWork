#include "Student.h"
#include "Collection.h"
#include <fstream>


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

Student::Student()
{
}


Student::~Student()
{
}
