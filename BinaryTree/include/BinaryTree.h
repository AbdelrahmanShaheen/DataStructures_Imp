class Node {
public:
    int data;
    Node *rchild; //pointer to right child
    Node *lchild; //pointer to left child
};

class BinaryTree {
private:
    Node *root;
public:
    void CreatTree();

    void PreOrder(Node *); // Print in preorder (recursively)
    void PreOrder();

    void InOrder(Node *);// Print in Inorder (recursively)
    void InOrder();

    void PostOrder(Node *); // Print in postorder (recursively)
    void PostOrder();

    void LevelOrder(Node *); // Print in levelorder (iterative method).
    void LevelOrder();

    int Count(Node *); //count number of nodes.
    int Count();

    // print in preorder (iterative method).
    void IteratePreOrder();

    // print in inorder(iterative method).
    void IterateInOrder();

    //print in postorder (iterative method).
    void IteratePostOrder();

};



