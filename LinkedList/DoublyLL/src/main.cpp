#include <iostream>
#include "DoublyLL.h"

using namespace std;

int main() {
    //here i test functions of single linked list.

    DoublyLL test;
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
    test.InsertEnd(8000);
    test.Display();// 1000 2000 8000
    if (!test.Empty()) {
        test.DeleteEnd();
    } else {
        cout << "you cannot delete cauze there is no element to delete\n";
    }
    test.Display();// 1000 2000
    test.InsertNth(5000, 2);
    test.Display();// 1000 5000 2000
    if (!test.Empty()) {
        test.DeleteNth(2);
    } else {
        cout << "you cannot delete cauze there is no element to delete\n";
    }
    test.Display();//1000 20000
    test.InsertNth(9900, 1);
    test.Display();//9900 1000 2000
    test.InsertNth(8800, 3);
    test.Display();//9900 1000 8800 2000
    test.DeleteEnd();
    test.Display();//9900 1000 8800
    if (test.Empty())cout << "empty\n";
    cout << test.Length() << endl;// 3
    test.DeleteNth(3);
    test.Display();//9900 1000
    cout << test.Length() << endl;// 2
    test.DeleteFirst();
    test.DeleteEnd();
    cout << test.Length() << endl;// 0
}

