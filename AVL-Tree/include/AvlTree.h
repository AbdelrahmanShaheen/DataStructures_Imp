#include <stddef.h>

class Node {
public:
    int data;
    int height;
    Node *lchild;
    Node *rchild;
};

class AvlTree {
private:
    Node *root;
public:
    AvlTree(Node *root = NULL); //constructor.

    Node *Insert(int, Node *);

    void Insert(int);

    void InorOrder();

    void InorOrder(Node *);

    Node *InPre(Node *); //used in delete method.

    Node *InSucc(Node *); //used in delete method.

    Node *Delete(int, Node *);

    void Delete(int);

    int Height(Node *); //Iterative method.

    int BalanceFactor(Node *);

    //rotations for insertion and deletion:
    Node *LLRotaion(Node *);

    Node *RRRotation(Node *);

    Node *LRRotation(Node *);

    Node *RLRotation(Node *);
};
