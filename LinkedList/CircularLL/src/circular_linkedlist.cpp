#include "../include/circular_linkedlist.h"

using namespace std;

bool empty() {
    if (head == NULL)
        return true;
    else
        return false;
}

node *insert_end(int value) {
    node *newNode = new node;
    newNode->data = value;

    if (empty()) {
        head = newNode;
        newNode->next = head;
    } else {
        node *ptr = head;
        while ((ptr->next) != head) {
            ptr = ptr->next;
        }
        newNode->next = ptr->next;   //newNode->next = head;
        ptr->next = newNode;
    }
}

int delete_end() {
    if (empty())
        return -2;
    node *ptr1, *ptr2;
    ptr1 = ptr2 = head;
    while (ptr1->next != head) {
        ptr2 = ptr1;
        ptr1 = ptr1->next;
    }
    if (ptr1 == head) //the last node is the first node (only one node there).
    {
        delete ptr1;
        head = NULL;
    } else {
        delete ptr1;
        ptr2->next = head;
    }
}

void insert_first(int value) {
    node *newNode = new node;
    newNode->data = value;

    if (empty()) {
        head = newNode;
        newNode->next = head;
    } else {
        newNode->next = head;
        node *ptr = head;

        while (ptr->next != head) {
            ptr = ptr->next;
        }

        head = newNode;
        ptr->next = newNode;
    }
}

int delete_first() {
    if (empty())
        return -2;

    node *ptr;
    ptr = head;
    while (ptr->next != head) {
        ptr = ptr->next;
    }
    if (ptr == head) //this means there is one node and it will be deleted so the list will be empty.
    {
        delete ptr;
        head = NULL;
    } else //there is more than one node and after deletion the list will not empty
    {
        ptr->next = head->next;
        delete head;
        head = ptr->next;
    }
}

int insert_nth(int value, int index) {

    if (index <= 0 || index > length() + 1)
        return -1;  //invalid index.

    if (index == 1) {
        insert_first(value);
    } else if (index == length() + 1) { //insert after the end position.
        insert_end(value);
    } else {  //insert between the first and last position.


        node *newNode = new node; //creat a node.
        newNode->data = value;

        node *ptr1, *ptr2;
        ptr1 = ptr2 = head;
        for (int i = 0; i < index - 1; i++) { //go to desired index.
            ptr1 = ptr2;
            ptr2 = ptr2->next;
        }
        newNode->next = ptr2;
        ptr1->next = newNode;
    }
}

int delete_nth(int index) {

    if (index <= 0 || index > length())
        return -1;   //invalid index.

    if (index == 1)
        delete_first();
    else {
        node *ptr1, *ptr2;
        ptr1 = ptr2 = head;
        for (int i = 0; i < index - 1; i++) {  //go to desired position.
            ptr1 = ptr2;
            ptr2 = ptr2->next;
        }
        if (ptr2->next == head) { //deleted the last node.
            delete ptr2;
            ptr1->next = head;
        } else { //delete a node between first and last node.
            ptr1->next = ptr2->next;
            delete ptr2;
        }
    }
}

int display() {
    if (empty())
        return -2;

    node *ptr = head;
    do {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head);
    cout << "\n";
}

int length() {
    node *ptr;
    ptr = head;
    int len = 0;
    if (head == NULL)
        return 0;
    while (ptr->next != head) {
        ptr = ptr->next;
        len++;
    }
    len++;
    return len;
}