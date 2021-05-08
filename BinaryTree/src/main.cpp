#include "BinaryTree.cpp"
#include <iostream>

using namespace std;

int main() {
    BinaryTree BT;
    BT.CreatTree();
    cout << "Print in preorder : ";
    BT.PreOrder();
    cout << endl;
    cout << "Print in inorder : ";
    BT.InOrder();
    cout << endl;
    cout << "Print in postorder : ";
    BT.PostOrder();
    cout << endl;
    cout << "print in levelorder : ";
    BT.LevelOrder();

    cout << "number of nodes : " << BT.Count() << endl;
    cout << "Print in preorder iteratively : ";
    BT.IteratePreOrder();
    cout << endl;
    cout << "print in inorder iteratively : ";
    BT.IterateInOrder();
    cout << endl;
    cout << "print in postorder iteratively : ";
    BT.IteratePostOrder();
    cout << endl;
}


