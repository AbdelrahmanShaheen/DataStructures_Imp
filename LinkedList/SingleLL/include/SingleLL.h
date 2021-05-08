#include<iostream>
#include <stddef.h>
using namespace std;

class  Node{
public:
    int data;
    Node *next;
};
class LinkedList {
private:
    Node *head;
    int length;
public:
    LinkedList(Node *head = NULL ,int length = 0); //constructor.
    bool Empty();
    void Display();
    //insert functions :
    void InsertFirst(int);
    void InsertEnd(int);
    void InsertNth(int ,int); //insert before nth position.
    //delete functons :
    void DeleteFirst();
    void DeleteEnd();
    void DeleteNth(int);
    int Length();
};
