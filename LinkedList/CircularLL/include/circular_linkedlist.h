#include <iostream>
struct node{
    int data;
    node *next;
};
node *head = NULL;

bool empty();

node *insert_end(int value);

int delete_end();

void insert_first(int value);

int delete_first();

int insert_nth(int value, int index);

int delete_nth(int index);

int display();

int length();