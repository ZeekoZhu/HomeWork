#include <iostream>
using namespace std;

template<typename T>
class Vector
{
    T* data;
    int length;
public:
    Vector<T>() :length(0),data(NULL)
    {
    }

    Vector(const Vector<T>& other)
    {
        if (data!=NULL)
        {
            delete[] data;
        }
        
    }
};

int main()
{

}