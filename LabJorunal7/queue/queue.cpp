#include "queue.h"

queue::queue(int x) 
{
    size = x;
    arr = new int[size];
}

queue::~queue()
{
    delete[] arr;
}

bool queue::Empty()
{
    return front > tail;
}

bool queue::Full() 
{
    return tail == size - 1;
}

int queue::getFront() 
{
    if (Empty())
    {
        cout << "Queue is empty!!" << endl;
        return -1;
    }
    return arr[front];
}

void queue::Enqueue(int val) 
{
    if (Full()) 
    {
        cout << "Array is full sorry!!" << endl;
    }
    else
    {
        arr[++tail] = val;
    }
}

int queue::Dequeue() 
{
    if (Empty())
    {
        cout << "Array is empty sorry!!" << endl;
        return -1;
    }
    return arr[front++];
}
