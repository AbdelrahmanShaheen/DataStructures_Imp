#include"stack.h"
//Array bassed implementation
stack::stack(int _top) : top(_top) {}
void stack::Pop() {
    top--;
}

void stack::Display() const {
    for (int start = top; start >= 0; start--) {
        cout << elements[start] << " ";
    }
    cout << endl;
}

void stack::Push(const int &value) {
    top++;
    elements[top] = value;
}

int stack::Peek() const {
    return elements[top];
}

bool stack::IsFull() const {
    if (top == MAX_SIZE - 1)
        return true;
    else
        return false;
}

bool stack::IsEmpty() const {
    if (top == -1)
        return true;
    else
        return false;
}

int stack::Size() const {
    return top + 1;
}

void stack::Clear() {
    top = -1;
}
