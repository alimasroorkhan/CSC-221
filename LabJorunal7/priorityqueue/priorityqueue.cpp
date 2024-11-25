#include <iostream>
#include <string>
using namespace std;

class ascending_priority
{
private:
    int* queue;
    int capacity;
    int size;

public:
    ascending_priority(int cap = 100);
    void Enqueue(int a);
    void Dequeue();
    void Display() const;
    ~ascending_priority();
};

ascending_priority::ascending_priority(int cap)
{
    capacity = cap;
    queue = new int[capacity];
    size = 0;
}

void ascending_priority::Enqueue(int a)
{
    if (size == capacity)
    {
        cout << "Queue is full! Cannot enqueue." << endl;
        return;
    }

    queue[size++] = a; 
}

void ascending_priority::Dequeue()
{
    if (size == 0)
    {
        cout << "Queue is empty!!." << endl;
        return;
    }

    int minIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (queue[i] < queue[minIndex])
        {
            minIndex = i;
        }
    }

    for (int i = minIndex; i < size - 1; i++)
    {
        queue[i] = queue[i + 1];
    }

    size--; 
}

void ascending_priority::Display() const
{
    if (size == 0)
    {
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << "Queue contents: ";
    for (int i = 0; i < size; i++)
    {
        cout << queue[i] << " ";
    }
    cout << endl;
}

ascending_priority::~ascending_priority()
{
    delete[] queue;
}

int main()
{
    ascending_priority x;

    x.Enqueue(10);
    x.Enqueue(5);
    x.Enqueue(30);
    x.Enqueue(20);

    cout << "Before:" << endl;
    x.Display();

    x.Dequeue(); 

    cout << "After:" << endl;
    x.Display();

    return 0;
}
