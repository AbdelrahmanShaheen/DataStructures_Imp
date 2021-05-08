#include <iostream>
#include"stack.h"
using namespace std;
//test stack...
int main() {
    stack s;
    if (s.IsEmpty())
        cout << "empty stack\n";
    else
        cout << "not an empty stack\n";
    s.Push(1000);
    cout << "the elements in the stack are : \n";
    s.Display();
    s.Push(2000);
    cout << "the elements in the stack are : \n";
    s.Display();
    cout << "the element in the top is  :  " << s.Peek() << endl;
    s.Pop();
    cout << "the elements in the stack are : \n";
    s.Display();
    cout << "size of stack : " << s.Size() << endl;
    s.Pop();
    cout << "size of stack : " << s.Size() << endl;
    s.Push(100);
    s.Push(200);
    s.Push(300);
    s.Display();
    cout << "size of stack : " << s.Size() << endl;
    s.Clear();
    cout << "size of stack : " << s.Size() << endl;
}

