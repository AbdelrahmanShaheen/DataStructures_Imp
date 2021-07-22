#include "circular_doubly.h"


int Display() {
   if(IsEmpty())
       return -2;
   Node *ptr = head;
   do{
       cout<<ptr->data<<" ";
       ptr = ptr->next;
   }while (ptr !=head);
   cout<<"\n";
}

bool IsEmpty() {
    if(head == NULL)
        return true;
    else
        return false;
}

int DeleteFirst() {
   if(IsEmpty())
    return -1;
   else if((head->next) == head)
   {
       delete head;
       head = NULL;
   }
   else
   {
       Node *ptr = head;
       ptr->next->previous = head->previous;
       head->previous->next = ptr->next;
       head = ptr->next;
       delete ptr;
   }
}

int DeleteNth(int position) {

    if (position <= 0 || position > Length() + 1)
        return -1;  //invalid position.
    else if(position == 1)
        DeleteFirst();
    else
    {
        Node *ptr = head;
        for(int i=0 ;i<position-1 ;i++)
        {
            ptr = ptr->next;
        }
        if(ptr->next == head) //deleted the last node.
        {
           ptr->previous->next = head;
           head->previous = ptr->previous;
        }
        else //delete a node between first and last node.
        {
            ptr->previous->next = ptr->next;
            ptr->next->previous = ptr->previous;
        }
        delete ptr;
    }
}

void InsertFirst(int value) {  //O(1).
    Node *new_node = new Node;
    new_node->data = value;
    if(IsEmpty())
     {
       head = new_node;
       new_node->next = new_node;
       new_node->previous = new_node;
     }
    else
    {
        new_node->next = head;
        new_node->previous = head->previous;
        head->previous->next = new_node;
        head->previous = new_node;
        head = new_node;
    }
}

void InsertEnd(int value) {
    Node *new_node = new Node;
    new_node->data = value;
   if(IsEmpty())
   {
       head = new_node;
       new_node->next = new_node;
       new_node->previous = new_node;
   }
   else
   {
       new_node->next = head;
       new_node->previous = head->previous;
       head->previous->next = new_node;
       head->previous = new_node;
   }
}

int InsertNth(int value, int position) {

    if (position <= 0 || position > Length() + 1)
        return -1;  //invalid position.

    if (position == 1)
        InsertFirst(value);
    else if (position == Length() + 1) //insert after the end position.
        InsertEnd(value);
    else //insert between the first and last position.
    {
        Node *new_node = new Node;
        Node *ptr = head;
        new_node->data = value;
        for(int i=0 ;i<position-1 ;i++)
        {
            ptr = ptr->next;
        }
        new_node->next = ptr;
        new_node->previous = ptr->previous;
        ptr->previous->next = new_node;
        ptr->previous = new_node;
    }
}

int Length() {
    int len = 0;
    Node *ptr = new Node;
    ptr = head;
    if(IsEmpty())
        return 0;
    else
    {
        do
        {
          len++;
          ptr = ptr->next;
        }while (ptr != head);
        return len;
    }
}

int DeleteEnd() {
    if(IsEmpty())
        return -1;
    else if((head->next) == head)
    {
        delete head;
        head = NULL;
    }
    else
    {
        Node *ptr = head->previous;
        ptr->previous->next = head;
        head->previous = ptr->previous;
        delete ptr;
    }
}