#include "BST.h"
#include <iostream>

using namespace std;

BST::BST(Node *r) : root(r) {} //constructor.
void BST::IterativeInsert(int value) {

    Node *newNode, *ptr, *ptr2; //ptr2 : is a pointer points to the place that i must insert the value in it.
    newNode = new Node;
    newNode->data = value;
    newNode->rchild = nullptr;
    newNode->lchild = nullptr;
    if (root == nullptr) //if i will insert the first element.
    {
        root = newNode;
        return;
    }
    ptr = root;

    while (ptr != nullptr) {
        ptr2 = ptr;
        if (ptr->data == value)
            return; //we don`t need duplicate in the bst.
        else if (ptr->data > value)
            ptr = ptr->lchild;
        else
            ptr = ptr->rchild;

    }
    if (newNode->data > ptr2->data)
        ptr2->rchild = newNode;
    else
        ptr2->lchild = newNode;
}

void BST::InOrder() {
    InOrder(root);
}

void BST::InOrder(Node *ptr) {
    if (ptr) {
        InOrder(ptr->lchild);
        cout << ptr->data << " ";
        InOrder(ptr->rchild);
    }
}

void BST::RInsert(int value) {
    RInsert(value, root);
}

Node *BST::RInsert(int value, Node *ptr) {
    Node *newNode;

    if (root == nullptr) //for the first element i will insert.
    {
        //create a node :
        newNode = new Node;
        newNode->data = value;
        newNode->rchild = nullptr;
        newNode->lchild = nullptr;

        root = newNode;
        return newNode;
    }

    if (ptr == nullptr) //for all elements after the first insertion.
    {
        //create a node :
        newNode = new Node;
        newNode->data = value;
        newNode->rchild = nullptr;
        newNode->lchild = nullptr;
        return newNode;
    }
    if (value < ptr->data) {
        ptr->lchild = RInsert(value, ptr->lchild);
    } else if (value > ptr->data) {
        ptr->rchild = RInsert(value, ptr->rchild);
    }

    return ptr;
}

Node *BST::IterativeSearch(int value) {

    Node *ptr = root;

    while (ptr) {
        if (ptr->data == value)
            return ptr;
        else if (ptr->data > value) {
            ptr = ptr->lchild;
        } else {
            ptr = ptr->rchild;
        }
    }
    return nullptr; //if the value is not found.
}

Node *BST::RSearch(int value, Node *ptr) {

    if (ptr == nullptr) //if element is not found.
        return nullptr;

    if (ptr->data == value)//if the element is found.
        return ptr;

    if (ptr->data > value)
        return RSearch(value, ptr->lchild);
    else if (ptr->data < value)
        return RSearch(value, ptr->rchild);
}

Node *BST::RSearch(int value) {
    return RSearch(value, root);
}

void BST::Delete(int value) {
    root = Delete(value ,root);
}

Node *BST::Delete(int value, Node *ptr) {
    Node *ptr2;

    if(ptr == nullptr) //for empty BST.
        return nullptr;

    if(value < ptr->data)
        ptr->lchild = Delete(value ,ptr->lchild); //go left.
    else if(value > ptr->data)
        ptr->rchild = Delete(value ,ptr->rchild); //go right.
    else
    {
        if(ptr->lchild == nullptr && ptr->rchild == nullptr) //for a leaf node.
        {
            delete ptr;
            return nullptr;
        }
        if(Height(ptr->lchild) > Height(ptr->rchild)) //for non leaf node .
        {
            ptr2 = InPre(ptr->lchild);
            ptr->data = ptr2->data;
            ptr->lchild = Delete(ptr2->data ,ptr->lchild);
        }
        else{ //for non leaf node.
            ptr2 = InSucc(ptr->rchild);
            ptr->data = ptr2->data;
            ptr->rchild = Delete(ptr2->data ,ptr->rchild);
        }
    }
    return ptr;
}

int BST::Height(Node *ptr) {
    int x;
    int y;
    if (ptr == nullptr){
        return 0;
    }
    x = Height(ptr->lchild);
    y = Height(ptr->rchild);
    return x > y ? x + 1 : y + 1;
}

Node *BST::InSucc(Node *ptr) {
    if(ptr->lchild != nullptr)
        return InSucc(ptr->lchild);

    return ptr;
}

Node *BST::InPre(Node *ptr) {
    if(ptr->rchild != nullptr)
        return InPre(ptr->rchild);

    return ptr;
}
