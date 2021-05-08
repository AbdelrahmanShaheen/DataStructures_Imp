#include"stack.h"
stack::stack(node *_top, int _capasity) : top(_top), capasity(_capasity) { }
void stack::Pop()
{
    node *ptr;
    ptr = top;
    top = top->next;
    delete ptr;
    capasity--;
}
void stack::Display()const
{
    node *ptr = top;
    while(ptr)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}
void stack::Push(const int &value)
{
    node *newNode = new node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    capasity++;
}
int stack::Peek()const
{
    return top->data;
}
bool stack::IsEmpty()const
{
    if(top == nullptr)
        return true;
    else
        return false;
}
bool stack::IsFull()const
{
    return 0;
}
int stack::Size()const
{
    return capasity;
}
void stack::Clear()
{
    node *ptr;
    while(top != nullptr)
    {
        ptr = top;
        top = top->next;
        delete ptr;
    }
    capasity = 0;
}

