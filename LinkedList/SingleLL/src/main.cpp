#include <iostream>
#include "SingleLL.cpp"
using namespace std;
int main() {
    //here i test functions of single linked list.

    LinkedList test;
    test.InsertFirst(500);
    test.InsertEnd(1000);
    test.InsertEnd(2000);
    test.Display(); //500 1000 2000

    if (!test.Empty()) {
        test.DeleteFirst();
    } else {
        cout << "you cannot delete cauze there is no element to delete\n";
    }
    test.Display(); //1000 2000
    test.InsertEnd(1000);
    test.Display();// 1000 2000 1000
    if (!test.Empty()) {
        test.DeleteEnd();
    } else {
        cout << "you cannot delete cauze there is no element to delete\n";
    }
    test.Display();// 1000 2000
    test.InsertNth(2000, 1);
    test.Display();// 2000 1000 2000
    test.InsertNth(5000, 2);
    test.Display();//2000 5000 1000 2000
    if (!test.Empty()) {
        test.DeleteNth(2);
    } else {
        cout << "you cannot delete cauze there is no element to delete\n";
    }
    test.Display();//2000 1000 2000
    test.DeleteEnd();
    test.Display();//2000 1000
    test.DeleteFirst();
    test.Display();
    test.DeleteFirst();
    if (test.Empty())cout << "empty\n";
    cout << test.Length() << endl;
}