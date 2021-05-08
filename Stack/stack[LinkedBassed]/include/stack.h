#include <iostream>
using namespace std;

class node{
public:
        int data;
        node *next;
};

class stack
{
private :
    node *top;
    int capasity;
public :
    stack(node *_top = nullptr,int _capasity = 0);
    void Pop();
    void Display()const;
    void Push(const int &value);
    int Peek()const;
    bool IsFull()const;
    bool IsEmpty()const;
    int Size()const;
    void Clear();
};

