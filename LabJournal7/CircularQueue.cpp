#include "CircularQueue.h"

CircularQueue::CircularQueue(int capacity) 
{
    size = capacity;
    arr = new int[size];
    front = -1;
    tail = -1;
}

CircularQueue::~CircularQueue()
{
    delete[] arr;
}

bool CircularQueue::Enqueue(int val)
{
    if (Full())
    {
        cout << "IS FULL!!!!" << val << "." << endl;
        return false;
    }

    if (Empty())
    {
        front = 0; 
    }

    tail = (tail + 1) % size; 
    arr[tail] = val;

    return true;
}

int CircularQueue::Dequeue()
{
    if (Empty())
    {
        cout << "IS EMPTY!!!" << endl;
        return -1;
    }

    int val = arr[front];

    if (front == tail) 
    {
        front = -1;
        tail = -1;
    }
    else 
    {
        front = (front + 1) % size; 
    }

    return val;
}

bool CircularQueue::Empty()
{
    return front == -1;
}

bool CircularQueue::Full()
{
    return (tail + 1) % size == front;
}

int CircularQueue::getFront() 
{
    if (Empty())
    {
        cout << "IS EMPTY!!!" << endl;
        return -1;
    }
    return arr[front];
}
