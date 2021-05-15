#include <iostream>
#include "AvlTree.cpp"

using namespace std;

int main() {
    AvlTree t;
    t.Insert(10);
    t.Insert(20);
    t.Insert(30);
    t.Insert(25);
    t.Insert(28);
    t.Insert(27);
    t.Insert(5);
    t.InorOrder();
}
/*algo of insert :
1-insert.
2-update the height.
3-check the balance of tree .
4-if it unbalanced do the suitable rotation.
5-update the heights.
*/
