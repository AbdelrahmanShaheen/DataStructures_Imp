#include "../include/SingleLL.h"
#include <stddef.h>

bool LinkedList::Empty() {
    if (head != NULL)
        return false;
    else
        return true;
}

void LinkedList::Display() {
    Node *ptr = head;
    while (ptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void LinkedList::InsertFirst(int value) {
//creat new node .
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    length++;
    if (Empty()) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void LinkedList::InsertEnd(int value) {
    Node *newNode = new Node, *ptr = head;
    newNode->data = value;
    newNode->next = NULL;
    length++;
    if (Empty()) {
        head = newNode;
    } else {
        while (ptr->next) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }

}

void LinkedList::InsertNth(int value, int pos) {
    Node *newNode = new Node;
    Node *ptr1 = head;
    Node *ptr2 = head;
    newNode->data = value;
    newNode->next = NULL;
    int i;
    length++;
    for (i = 0; i < pos - 1 && ptr2; i++) {
        ptr1 = ptr2;
        ptr2 = ptr2->next;
    }
    if (i) {
        newNode->next = ptr2;
        ptr1->next = newNode;
    } else {
        newNode->next = ptr1;
        head = newNode;
    }

}

void LinkedList::DeleteFirst() {
    Node *ptr;
    ptr = head;
    if (!Empty()) {
        head = ptr->next;
        delete ptr;
        length--;
    }
}

void LinkedList::DeleteEnd() {
    Node *ptr1;
    Node *ptr2;
    ptr1 = head;
    ptr2 = head;
    if (!Empty()) {
        while (ptr2->next) {
            ptr1 = ptr2;
            ptr2 = ptr2->next;
        }
        ptr1->next = NULL;
        delete ptr2;
        length--;
    }
}

void LinkedList::DeleteNth(int pos) {
    Node *ptr1 = head;
    Node *ptr2 = head;
    if (length <= 0 || pos > length)
        return;
    else if (pos == 1) {
        head = head->next;
        delete ptr2;
        length--;
    } else {
        int i;
        for (i = 0; i < pos - 1; i++) {
            ptr1 = ptr2;
            ptr2 = ptr2->next;
        }
        ptr1->next = ptr2->next;
        delete ptr2;
        length--;
    }

}

LinkedList::LinkedList(Node *h, int l) : head(h), length(l) {}

int LinkedList::Length() {
    return length;
}