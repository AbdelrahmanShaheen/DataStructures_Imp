#include "circular_doubly.cpp"

int main()
{
    cout<<"hello geeks\n";
    InsertFirst(500);
    Display();
    InsertFirst(1000);
    Display();
    InsertEnd(2000);
    Display();
    InsertEnd(40000);
    Display();
    DeleteFirst();
    Display();
    cout<<Length()<<endl;
    InsertNth(1000 ,2);
    Display();
    InsertNth(999 ,1);
    Display();
    InsertNth(7000 ,6);
    Display();
    if(InsertNth(55555 ,9) == -1)cout<<"Invalid position\n";
    Display();
    DeleteNth(2);
    Display();
    DeleteNth(Length());
    Display();
    DeleteNth(3);
    Display();
    DeleteNth(1);
    Display();
}