#include "circular_linkedlist.cpp"

int main() {
    cout << "hello geeks:)\n";
    insert_first(500);
    if (display() == -2)cout << "empty\n";
    insert_first(6000);
    if (display() == -2)cout << "empty\n";
    cout << length() << endl;

    if (insert_nth(400, 3) == -1)cout << "invalid position\n";
    display();

    if (delete_nth(2) == -1)cout << "invalid position\n";
    display();
}