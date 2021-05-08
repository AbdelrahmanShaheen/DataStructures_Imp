#include "../include/BinaryTree.h"
#include <iostream>
#include <queue>
#include <stack>
#include <stddef.h>

using namespace std;

void BinaryTree::CreatTree() {
    queue<Node *> q;
    Node *newNode;
    Node *nodePtr;
    double value;
    root = new Node;
    cout << "Enter data of the root :" << endl;
    cin >> value;

    root->lchild = NULL;
    root->rchild = NULL;
    root->data = (int)value;
    q.push(root);

    while (!q.empty()) {
        nodePtr = q.front();
        q.pop();
        //Left Node :
        cout << "Enter data of left child node of " << nodePtr->data << " : " << endl;
        cin >> value;
        if (value != -1) // -1 means that there is no data to push in the node so there is no node.
        {
            newNode = new Node;
            newNode->data = (int)value;
            newNode->lchild = NULL;
            newNode->rchild = NULL;
            nodePtr->lchild = newNode;
            q.push(newNode);
        }
        //Right Node :
        cout << "Enter data of right child node of " << nodePtr->data << " : " << endl;
        cin >> value;
        if (value != -1) {
            newNode = new Node;
            newNode->data = (int)value;
            newNode->rchild = NULL;
            newNode->lchild = NULL;
            nodePtr->rchild = newNode;
            q.push(newNode);
        }
    }
}

void BinaryTree::PreOrder(Node *ptr) {
    if (ptr) {
        cout << ptr->data << " ";
        PreOrder(ptr->lchild);
        PreOrder(ptr->rchild);
    }
}

void BinaryTree::PreOrder() {
    PreOrder(root);
}

void BinaryTree::InOrder() {
    InOrder(root);
}

void BinaryTree::InOrder(Node *ptr) {
    if (ptr) {
        InOrder(ptr->lchild);
        cout << ptr->data << " ";
        InOrder(ptr->rchild);
    }
}

void BinaryTree::PostOrder(Node *ptr) {
    if (ptr) {
        PostOrder(ptr->lchild);
        PostOrder(ptr->rchild);
        cout << ptr->data << " ";
    }
}

void BinaryTree::PostOrder() {
    PostOrder(root);
}

void BinaryTree::LevelOrder() {
    LevelOrder(root);
}

void BinaryTree::LevelOrder(Node *ptr) {
    queue<Node *> qu;
    qu.push(ptr);
    cout << ptr->data << " ";
    while (!qu.empty()) {
        ptr = qu.front();
        qu.pop();
        if (ptr->lchild) {
            cout << ptr->lchild->data << " ";
            qu.push(ptr->lchild);
        }

        if (ptr->rchild) {
            cout << ptr->rchild->data << " ";
            qu.push(ptr->rchild);
        }
    }
    cout << endl;
}

int BinaryTree::Count() {
    Count(root);
}

int BinaryTree::Count(Node *ptr) {
    static int num = 0;
    if (ptr) {
        num++;
        Count(ptr->lchild);
        Count(ptr->rchild);
    }
    return num;
}


void BinaryTree::IteratePreOrder() {
    Node *ptr = root;
    stack<Node *> st; //contain addresses of the nodes .
    while (ptr || !st.empty()) {
        if (ptr) {
            cout << ptr->data << " ";
            st.push(ptr);
            ptr = ptr->lchild;
        } else {
            ptr = st.top();
            st.pop();
            ptr = ptr->rchild;
        }
    }

}

void BinaryTree::IterateInOrder() {
    Node *ptr = root;
    stack<Node *> st; //contain addresses of the nodes .
    while (ptr || !st.empty()) {
        if (ptr) {
            st.push(ptr);
            ptr = ptr->lchild;
        } else {
            ptr = st.top();
            st.pop();
            cout << ptr->data << " ";
            ptr = ptr->rchild;
        }
    }
}

void BinaryTree::IteratePostOrder() {
    Node *ptr = root;
    stack<long int> st; //contain addresses of the nodes .
    long int temp;
    while (ptr || !st.empty()) {
        if (ptr) {
            st.push((long int) ptr);
            ptr = ptr->lchild;
        } else {

            temp = st.top();
            st.pop();
            if (temp > 0) {
                st.push(-temp);
                ptr = ((Node *) temp)->rchild;
            } else if (temp < 0) {
                cout << ((Node *) -temp)->data << " ";
                ptr = NULL;
            }
        }
    }
}

