#include <iostream>
#include "BST.h"

using namespace std;

int main() {
    BST test;
    test.RInsert(50);
    test.RInsert(10);
    test.RInsert(40);
    test.RInsert(20);
    test.RInsert(30);
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
    test.Delete(50);
    test.InOrder();
    cout<<endl;
}