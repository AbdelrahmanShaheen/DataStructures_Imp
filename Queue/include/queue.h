#ifdef LINKED_BASED_QUEUE

class node{
  public :
   int Data;
   node *Next;
};
class queue
{
private :
 node *Front;
 node *Rear;
 int size;
public :
    queue(node *_Front = nullptr ,node *_Rear = nullptr,int _size=0);
    bool IsEmpty()const;
    bool IsFull()const;
    void Dequeue();
    void Enqueue(const int & value);
    void Display()const;
    int Size()const;
};
  
#else

#define SIZE 100

class queue
{
private :
    int Element[SIZE];
    int Front;
    int Rear;
public :
    queue(int _Front = -1,int _Rear = -1);
    bool IsEmpty()const;
    bool IsFull()const;
    void Dequeue();
    void Enqueue(const int & value);
    void Display()const;

};

#endif  