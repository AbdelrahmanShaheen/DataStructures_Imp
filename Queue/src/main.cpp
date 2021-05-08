#include<iostream>
using namespace std;
#define LINKED_BASED_QUEUE
#include"queue.cpp"


int main()
{
   
  queue q;
  q.Enqueue(100);
  q.Enqueue(500);
  q.Enqueue(7000);
  q.Display();
  q.Dequeue();
  q.Display();
   return 0;
}