#pragma once
#include <string>
#include "Collection.h"

using namespace std;
class Student
{
public:
    string Name;
    string StudentId;
    int Math;
    int Chinese;
    int English;

    static List<Student>& ReadFile(string path);
    static List<Student>& WriteFile(string path,List<Student>& stus);
    Student();
    ~Student();
};

