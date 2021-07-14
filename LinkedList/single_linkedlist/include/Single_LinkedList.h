#include <iostream>

struct node {
    int data;
    node *next;
};
node *root = NULL;

bool es_empty();

node *insert_end(int value);

void delete_end();

void insert_first(int value);

void delete_first();

void insert_nth(int value, int index);

void delete_nth(int index);

void display();


