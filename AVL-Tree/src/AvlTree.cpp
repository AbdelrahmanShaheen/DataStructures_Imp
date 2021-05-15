#include "../include/AvlTree.h"
#include <iostream>

using namespace std;

AvlTree::AvlTree(Node *r) : root(r) {}

void AvlTree::Insert(int value) {
    root = Insert(value, root);
}

Node *AvlTree::Insert(int value, Node *ptr) {
    Node *newNode;
    if (root == NULL) //if tree is empty.
    {
        //Create a newnode :
        newNode = new Node;
        newNode->data = value;
        newNode->height = 1;
        newNode->lchild = NULL;
        newNode->rchild = NULL;
        return newNode;
    }
    if (ptr == NULL) //for leaf nodes.
    {
        //Create a newnode :
        newNode = new Node;
        newNode->data = value;
        newNode->height = 1;
        newNode->lchild = NULL;
        newNode->rchild = NULL;
        return newNode;
    }
    if (value < ptr->data)
        ptr->lchild = Insert(value, ptr->lchild); //go to left child.
    else if (value > ptr->data)
        ptr->rchild = Insert(value, ptr->rchild); // go to right child.
    //update height after insert.
    ptr->height = Height(ptr);
    //rotations :
    if ((BalanceFactor(ptr) == 2) && (value < ptr->lchild->data))//right rotation.
    {
        ptr = LLRotaion(ptr);
    }
    if ((BalanceFactor(ptr) == -2) && (value > ptr->rchild->data))//left rotation.
    {
        ptr = RRRotation(ptr);
    }
    if ((BalanceFactor(ptr) == 2) && (value > ptr->lchild->data))//do right then left rotation.
    {
        ptr = LRRotation(ptr);
    }
    if ((BalanceFactor(ptr) == -2) && (value < ptr->rchild->data)) //do left then right rotation.
    {
        ptr = RLRotation(ptr);
    }
    return ptr;
}

void AvlTree::InorOrder() {
    InorOrder(root);
}

void AvlTree::InorOrder(Node *ptr) {
    if (ptr) {
        cout<<ptr->data<<endl;
        InorOrder(ptr->lchild);
        InorOrder(ptr->rchild);

    }
}

int AvlTree::BalanceFactor(Node *ptr) {
    return Height(ptr->lchild) - Height(ptr->rchild);
}

Node *AvlTree::LLRotaion(Node *ptr) {
    Node *ptr1, *ptr2;

    ptr1 = ptr;
    ptr2 = ptr->lchild;

    ptr1->lchild = !ptr2->rchild ? NULL : ptr2->rchild;
    ptr2->rchild = ptr1;
    //update height after rotation.
    ptr1->height = Height(ptr1);
    ptr2->height = Height(ptr2);

    return ptr2;
}

int AvlTree::Height(Node *ptr) {
    int hl;//height of left sub tree.
    int hr; //height of the right sub tree.

    if (!ptr)
        return 0;

    if (!ptr->lchild)
        hl = 0;
    else
        hl = ptr->lchild->height;

    if (!ptr->rchild)
        hr = 0;
    else
        hr = ptr->rchild->height;

    return hr > hl ? hr + 1 : hl + 1;
}

Node *AvlTree::RRRotation(Node *ptr) {
    Node *ptr1, *ptr2;
    ptr1 = ptr;
    ptr2 = ptr->rchild;

    ptr1->rchild = ptr2->lchild;
    ptr2->lchild = ptr1;

    //update the heights :
    ptr1->height = Height(ptr1);
    ptr2->height = Height(ptr2);
    //the new root of ptr subtree.
    return ptr2;
}

Node *AvlTree::LRRotation(Node *ptr) {
    Node *ptr1, *ptr2, *ptr3;
    ptr1 = ptr;
    ptr2 = ptr->lchild;
    ptr3 = ptr->lchild->rchild;

    ptr1->lchild = ptr3->rchild;
    ptr2->rchild = ptr3->lchild;
    ptr3->lchild = ptr2;
    ptr3->rchild = ptr1;

    //update heights :
    ptr1->height = Height(ptr1);
    ptr2->height = Height(ptr2);
    ptr3->height = Height(ptr3);
    //the new root of ptr subtree.
    return ptr3;
}

Node *AvlTree::RLRotation(Node *ptr) {
    Node *ptr1, *ptr2, *ptr3;
    ptr1 = ptr;
    ptr2 = ptr->rchild;
    ptr3 = ptr2->lchild;

    ptr1->rchild = ptr3->lchild;
    ptr2->lchild = ptr3->rchild;
    ptr3->rchild = ptr2;
    ptr3->lchild = ptr1;

    //update the heights :
    ptr1->height = Height(ptr1);
    ptr2->height = Height(ptr2);
    ptr3->height = Height(ptr3);
    //the new root of ptr subtree.
    return ptr3;
}


Node *AvlTree::InPre(Node *ptr) {
    if (ptr->rchild != NULL) {
        ptr = ptr->rchild;
    }
    return ptr;
}

Node *AvlTree::InSucc(Node *ptr) {
    if (ptr->lchild != NULL) {
        ptr = ptr->lchild;
    }
    return ptr;
}

Node *AvlTree::Delete(int value, Node *ptr) {
    Node *ptr2;

    if (ptr == NULL) //for empty BST.
        return NULL;

    if (value < ptr->data)
        ptr->lchild = Delete(value, ptr->lchild); //go left.
    else if (value > ptr->data)
        ptr->rchild = Delete(value, ptr->rchild); //go right.
    else {
        if (ptr->lchild == NULL && ptr->rchild == NULL) //for a leaf node.
        {
            delete ptr;
            return NULL;
        }
        if (Height(ptr->lchild) > Height(ptr->rchild)) //for non leaf node .
        {
            ptr2 = InPre(ptr->lchild);
            ptr->data = ptr2->data;
            ptr->lchild = Delete(ptr2->data, ptr->lchild);
        } else { //for non leaf node.
            ptr2 = InSucc(ptr->rchild);
            ptr->data = ptr2->data;
            ptr->rchild = Delete(ptr2->data, ptr->rchild);
        }
    }
    //update height after delete.
    ptr->height = Height(ptr);
    //do rotations to make avl tree balanced after deletion:
    if (((BalanceFactor(ptr) == 2) && (BalanceFactor(ptr->lchild) == 1)) ||
        ((BalanceFactor(ptr) == 2) && (BalanceFactor(ptr->lchild) == 0)))
    {
        ptr = LLRotaion(ptr); //right rotation.
    } else if (((BalanceFactor(ptr) == -2) && BalanceFactor(ptr->rchild) == -1) ||
               ((BalanceFactor(ptr) == -2) && BalanceFactor(ptr->rchild) == 0))
    {
        ptr = RRRotation(ptr); //left rotation.
    } else if ((BalanceFactor(ptr) == 2) && (BalanceFactor(ptr->lchild) == -1))
    {
        ptr = LRRotation(ptr); //do right then left rotation.
    } else if ((BalanceFactor(ptr) == -2) && (BalanceFactor(ptr->rchild) == 1))
    {
        ptr = RLRotation(ptr); //do left then right rotation.
    }
    return ptr;
}

void AvlTree::Delete(int value) {
    root = Delete(value, root);
}
