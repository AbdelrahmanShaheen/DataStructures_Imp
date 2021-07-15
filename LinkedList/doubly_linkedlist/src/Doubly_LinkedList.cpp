#include "../include/Doubly_LinkedList.h"
using namespace std;

bool empty() {
    if(root == NULL)
        return true;
    else
        return false;
}

void display() {
   if(empty())
       cout<<"Empty\n";
   else
   {
       node *ptr = root; //pointer to a node.
       while (ptr)
       {
           cout<<ptr->data<<" ";
           ptr = ptr->next;
       }
       cout<<"\n";
   }
}

void insert_first(int value) {
    //there are two cases here
    //1-when list is empty.
    //2- ``  ``   `` not empty.
    node *newNode = new node; //create a node.
    newNode->data = value;
    if(empty())
    {
        root = newNode;
        newNode->next = NULL;
        newNode->previous = NULL;
    }
    else
    {
        newNode->next = root;
        newNode->next->previous = newNode;
        newNode->previous = NULL;
        root = newNode;
    }
}

void insert_end(int value) {
    node *newNode = new node;
    newNode->data = value;
    newNode->next = NULL;
    if(empty())
    {
        root = newNode;
        newNode->previous = NULL;
    }
    else
    {
        node *ptr = root;
        while (ptr->next)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->previous = ptr;
    }
}

void insert_nth(int value, int index) {
   if(index == 1)
   {
       insert_first(value);
       return;
   }

       node *newNode = new node;
       newNode->data = value;
       node *ptr = root;
       for(int i=0 ;i<index-1; i++)
       {
           ptr = ptr->next;
       }
   newNode->next = ptr;
   newNode->previous = ptr->previous;
   ptr->previous->next = newNode;
   ptr->previous = newNode;
}

void delete_first() {
   //there are three cases here :
   //1-if its empty list delete nothing.
   //2-if there is one node make root point to null so it will be empty list then delete the node.
   //3-if there is more than one node make the root point to the next of the first node then and set the pre of
   //this node to null.
    if(empty())
       return;

   node *ptr = root;
   root = ptr->next;
   if(!empty())
   {
       ptr->next->previous = NULL;
   }
   delete ptr;
}

void delete_end() {
    if(empty())
        return;
    node *ptr = root;
    while (ptr->next)
    {
      ptr = ptr->next;
    }
    if(ptr->previous) //if there is more than one node.
    ptr->previous->next = NULL;
    else //if there is only the node you want to delete it.
        root = NULL;

    delete ptr;
}

void delete_nth(int index) {
   if(empty())
       return;
   if(index == 1)
       delete_first();
   else
   {
       node *ptr = root;
       for(int i=0 ;i<index-1; i++)
       {
         ptr = ptr->next;
       }
      if(!(ptr->next)) //if you want to delete the last node.
      {
          ptr->previous->next = NULL;
      }
      else
      {
          ptr->previous->next = ptr->next;
          ptr->next->previous = ptr->previous;
      }
      delete ptr;
   }
}