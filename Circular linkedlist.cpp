#include<iostream>
#include<stdlib.h>
using namespace std;

class Queue {
    public:
    int rear, front;
    int size;
    int *circular_queue;

    Queue(int siz) {
       front = rear = -1;
       size = siz;
       circular_queue = new int[siz];
    }
   void enQueue(int elem);
    int deQueue();
    void displayQueue();
};

void Queue::enQueue(int elem)
{
    if ((front == 0 && rear == size-1) || (rear == (front-1)%(size-1)))  {
        cout<<"\nQueue is Full";
        return;
    }
    else if (front == -1) {
         front = rear = 0;
        circular_queue[rear] = elem;
    }
   else if (rear == size-1 && front != 0) {
        rear = 0;
        circular_queue[rear] = elem;
    }
    else {
        rear++;
        circular_queue[rear] = elem;
    }

}
int Queue::deQueue()
{
    if (front == -1)  {
        cout<<"\nQueue is Empty";
        return -1;
    }

    int data = circular_queue[front];
    circular_queue[front] = -1;
    if (front == rear)  {
        front = -1;
        rear = -1;
    }
    else if (front == size-1)
        front = 0;
    else
        front++;

    return data;
}

void Queue::displayQueue()
{
    if (front == -1) {
        cout<<"\nQueue is Empty"<<endl;
        return;
    }
    cout<<"\nCircular Queue elements: ";
    if (rear >= front) {
        for (int i = front; i <= rear; i++)
            cout<<circular_queue[i]<<" ";
    }
    else  {
        for (int i = front; i < size; i++)
            cout<<circular_queue[i]<<" ";

        for (int i = 0; i <= rear; i++)
            cout<<circular_queue[i]<<" ";
    }
}

int main()
{
    system("cls");
    Queue pq(7);
    pq.enQueue(6);
    pq.enQueue(8);
    pq.enQueue(2);
    pq.enQueue(6);

   pq.displayQueue();


    cout<<"\nElement Dequeued = "<<pq.deQueue();
    cout<<"\nElement Dequeued = "<<pq.deQueue();

    pq.displayQueue();

    pq.enQueue(12);
    pq.enQueue(16);
    pq.enQueue(11);

    pq.displayQueue();

    pq.enQueue(12);
    return 0;
}
