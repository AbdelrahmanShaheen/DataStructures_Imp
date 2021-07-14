#include "../include/Single_LinkedList.h"

using namespace std;


bool es_empty() {
    if (root == NULL)
        return true;
    else
        return false;
}

node *insert_end(int value) {
    node *newNode = new node;
    newNode->data = value;
    newNode->next = NULL;

    if (es_empty()) {
        root = newNode;
    } else {
        node *ptr = root;
        while (ptr->next) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

void delete_end() {
    node *ptr = root;
    if (es_empty()) //if ll is empty.
        return ;
    else if (!(ptr->next)) //if the last node is the first node(there is one node in the list).
    {
        delete ptr;
        root = NULL;
    } else {
        node *ptr1;
        while (ptr->next) {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        delete ptr;
        ptr1->next = NULL;
    }
}

void insert_first(int value) {
    node *newNode = new node;
    newNode->data = value;
    newNode->next = NULL;
    if (es_empty()) //special case.
    {
        root = newNode;
        return;
    }
    node *ptr = root;
    newNode->next = ptr;
    root = newNode;
}

void delete_first() {
    if (es_empty())//if its empty do nothing.
        return;

    node *ptr = root;
    root = ptr->next;
    delete ptr;
}

void insert_nth(int value, int index) {
    if (index == 1)
        insert_first(value);
        //there are many cases ,one of them is that if the pos greater than the length of list this function will insert the value in the end.
    else if (index > 1) {
        node *newNode = new node;
        newNode->data = value;
        node *ptr1, *ptr2;
        ptr2 = root;
        for (int i = 0; (i < index - 1) && (ptr2); i++) {
            ptr1 = ptr2;
            ptr2 = ptr2->next;
        }
        ptr1->next = newNode;
        newNode->next = ptr2;
    }
}

void delete_nth(int index) {
    if (es_empty())
        return;
    if (index == 1)
        delete_first();
    else {
        node *ptr1, *ptr2;
        ptr2 = root;
        for (int i = 0; (i < index - 1) && (ptr2); i++) {
            ptr1 = ptr2;
            ptr2 = ptr2->next;
        }
        if (ptr2->next == NULL) //delete the last node.
        {
            ptr1->next = NULL;
            delete ptr2;
        } else //delete a node that is between first and last node.
        {
            ptr1->next = ptr2->next;
            delete ptr2;
        }
    }
}

void display() {
    if (es_empty()) {
        cout << "Empty\n";
        return;
    }
    node *ptr = root;
    while (ptr) {
        cout << ptr->data << "  ";
        ptr = ptr->next;
    }
    cout << endl;
}