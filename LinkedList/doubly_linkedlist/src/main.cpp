#include "Doubly_LinkedList.cpp"
using namespace std;

int main()
{
  cout<<"hello world\n";
  cout<<"hello geeks\n";
  display();
  insert_end(5);
  display();
  insert_end(100);
  display();
  insert_end(200);
  display();
  delete_first();
  display();
  delete_first();
  display();
  delete_first();
  display();
  insert_first(400);
  display();
  insert_first(200);
  display();
  insert_end(600);
  display();
  delete_end();
  delete_end();
  display();
  delete_end();
  display();
  insert_first(46555);
  display();
  insert_nth(100000 ,1);
  display();
  insert_nth(200000 ,2);
  display();
  insert_nth(1 ,2);
  display();
  delete_nth(4);
  display();
  delete_nth(3);
  display();
  delete_first();
  display();
  delete_end();
  display();
}