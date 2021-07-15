#include<iostream>

struct node{
    int data;
    node *next;
    node *previous;
};
node *root = NULL;


bool empty();

void display();

//insert functions :
void insert_first(int);

void insert_end(int);

void insert_nth(int, int); //insert before nth position.
//delete functons :
void delete_first();

void delete_end();

void delete_nth(int);