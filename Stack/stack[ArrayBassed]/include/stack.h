#include <iostream>
using namespace std;
#define MAX_SIZE 100

class stack
{
private :
    int elements[MAX_SIZE];
    int top;
public :
    stack(int _top = -1);
    void Pop();
    void Display()const;
    void Push(const int &value);
    int Peek()const;
    bool IsFull()const;
    bool IsEmpty()const;
    void Clear();
    int Size() const;
};

