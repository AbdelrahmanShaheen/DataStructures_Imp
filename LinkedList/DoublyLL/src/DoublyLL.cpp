#include "DoublyLL.h"

DoublyLL::DoublyLL(Node *h, int l) : head(h), length(l) {} //constructor.
bool DoublyLL::Empty() {
    if (!head)
        return true;
    else
        return false;
}

void DoublyLL::Display() {
    Node *ptr = head;
    while (ptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void DoublyLL::InsertFirst(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    length++;
    if (Empty()) {
        head = newNode;
        newNode->next = nullptr;
        newNode->pre = nullptr;
    } else {
        newNode->next = head;
        head = newNode;
        newNode->next->pre = newNode;
        newNode->pre = nullptr;
    }
}

void DoublyLL::InsertEnd(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    length++;
    Node *ptr;
    if (Empty()) {
        head = newNode;
        newNode->next = nullptr;
        newNode->pre = nullptr;
    } else {
        ptr = head;
        while (ptr->next) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->next = nullptr;
        newNode->pre = ptr;
    }
}

void DoublyLL::InsertNth(int value, int pos) {

    Node *newNode = new Node;
    newNode->data = value;
    Node *ptr = head;
    if (pos == 1)  //insert in first pos.
    {
        InsertFirst(value);
    } else  //insert before the given pos.
    {
        int i;
        for (i = 0; i < pos - 1; i++) {
            ptr = ptr->next;
        }
        newNode->next = ptr;
        newNode->pre = ptr->pre;
        ptr->pre->next = newNode;
        newNode->next->pre = newNode;
        length++;
    }
}

void DoublyLL::DeleteFirst() {
    Node *ptr;
    ptr = head;
    if (!Empty()) {
        if (ptr->next)//if there is more than the first node in the list.
        {
            head = ptr->next;
            ptr->next->pre = nullptr;
        } else //if there is one node in the list
            head = nullptr;

        delete ptr;
        length--;
    }
}

void DoublyLL::DeleteEnd() {
    Node *ptr = head;
    if (Empty())
        return;
    while (ptr->next) {
        ptr = ptr->next;
    }
    if (Length() > 1)
        ptr->pre->next = nullptr;

    delete ptr;
    length--;
}

void DoublyLL::DeleteNth(int pos) {
    if (Empty() || pos > Length()) //if pos is out of bound.
        return;
    Node *ptr = head;
    if (pos == 1) DeleteFirst(); //delete first node
    else if (pos == Length()) DeleteEnd(); //delete last node.
      else {
        int i;
        for (i = 0; i < pos - 1; i++) {
            ptr = ptr->next;
        }
        ptr->pre->next = ptr->next;
        ptr->next->pre = ptr->pre;
        delete ptr;
        length--;
    }
}

int DoublyLL::Length() {
    return length;
}

