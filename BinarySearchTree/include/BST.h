class Node {
public:
    int data;
    Node *rchild;
    Node *lchild;
};

class BST {
private:
    Node *root;
public:
    BST(Node *root = NULL); //constructor.
    void IterativeInsert(int);

    //recursive insert.
    Node *RInsert(int, Node *);
    void RInsert(int);

    Node *IterativeSearch(int);

    //recursive search.
    Node *RSearch(int, Node *);
    Node *RSearch(int);

    //print the element of bst in inorder recursively.
    void InOrder(Node *);
    void InOrder();

    Node* Delete(int  ,Node*); //modify this func
    void Delete(int ); // or use getRoot function in main func.

    //all these functions used in delete fun :
    int Height(Node *);
    Node* InSucc(Node* );
    Node* InPre(Node* );

};