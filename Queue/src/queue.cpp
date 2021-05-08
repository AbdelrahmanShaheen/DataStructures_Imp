
#ifdef LINKED_BASED_QUEUE

#include "../include/queue.h"

queue::queue(node *_Front, node *_Rear,int _size) : Front(_Front),Rear(_Rear),size(_size) { }
bool queue::IsEmpty()const
{
   if(Front == nullptr)return true;
   else
   return false;
}
bool queue::IsFull()const
{
  return false;
}
void queue::Dequeue()
{
  node *ptr = Front;
  Front = Front->Next;
  size--;
  delete ptr;
}
void queue::Enqueue(const int & value)
{
  node *newNode = new node;
  newNode->Data = value;
  newNode->Next = nullptr;
  if(IsEmpty())
  {
      Front = newNode;
      Rear = newNode;
  }
  else
  {
     Rear->Next = newNode;
     Rear = newNode;
  }
  size++;
}
void queue::Display()const
{
   node *ptr = Front;
   while(ptr)
   {
       cout<<ptr->Data<<" ";
       ptr = ptr->Next;
   }
   cout<<"\n";
}
int queue::Size()const
{
    return size;
}

#else

 #include"../include/queue.h"

queue::queue(int _Front, int _Rear) : Front(_Front),Rear(_Rear) { }
bool queue::IsEmpty()const
{
    if(Front == -1 && Rear == -1)
        return true;
    else
        return false;
}
bool queue::IsFull()const
{
    if((Front == 0 && Rear == SIZE-1) || (Front - Rear == 1))
        return true;
    else
        return false;
}
void queue::Dequeue()
{
    Front++;
    Front = Front % SIZE;
    if(Front > Rear)
    {
        Front = -1;
        Rear = -1;
    }
}
void queue::Enqueue(const int & value)
{

    if(IsEmpty())
    {
        Front++;
        Rear++;
        Element[Rear] = value;
    }
    else
    {
        Rear++;
        Rear = Rear % SIZE;
        Element[Rear] = value;
    }
}
void queue::Display()const
{
    if(Front <= Rear)
    {
        for(int i=Front ; i<=Rear; i++)cout<<Element[i]<<" ";
        cout<<"\n";
    }
    else
    {
        for(int i=Front ; i<SIZE; i++)cout<<Element[i]<<" ";
        for(int i=0 ; i<=Rear; i++)cout<<Element[i]<<" ";
        cout<<"\n";
    }
}
#endif