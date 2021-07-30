#include <iostream>
#include "BST.cpp"

using namespace std;

int main() {
    BST test;
    test.RInsert(3);
    test.RInsert(5);
    test.RInsert(4);
    test.RInsert(9);
    test.RInsert(7);
    test.RInsert(8);
    test.InOrder();
    cout << endl;
    if (test.RSearch(5))
        cout << "i found the element :)\n";
    else
        cout << "the element is not found ):\n";

    if (test.RSearch(20))
        cout << "i found the element :)\n";
    else
        cout << "the element is not found ):\n";
    test.Delete(9);
    test.InOrder();
    cout<<endl;
}