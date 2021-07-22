#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node *previous;
}*head = NULL;
int Display();

bool IsEmpty();

int DeleteFirst();

int DeleteEnd();

int DeleteNth(int position);

void InsertFirst(int value);

void InsertEnd(int value);

int InsertNth(int value, int position);

int Length();

