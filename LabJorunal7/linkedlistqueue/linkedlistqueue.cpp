#include <iostream>
using namespace std;

class Node
{
public:

    int val;      
    Node* next;    
    Node(int x) : val(x), next(nullptr) {}
};


class LinkedQueue
{

public:
    Node* front;  
    Node* rear;   

    LinkedQueue();

    /**
     * @brief Checks if the queue is empty.
     * @return True if the queue is empty, false otherwise.
     */
    bool isEmpty();

    /**
     * @brief Adds an element to the rear of the queue.
     * @param val The value to enqueue.
     */
    void Enqueue(int val);

    /**
     * @brief Removes and returns the element from the front of the queue.
     * @return The value at the front of the queue, or -1 if the queue is empty.
     */
    int Dequeue();

    /**
     * @brief Gets the element at the front of the queue without removing it.
     * @return The value at the front of the queue, or -1 if the queue is empty.
     */
    int getFront();

    /**
     * @brief Displays all elements in the queue.
     */
    void Display();
};

LinkedQueue::LinkedQueue() 
{
    front = nullptr;
    rear = nullptr;
}


bool LinkedQueue::isEmpty() 
{
    return front == nullptr;
}


void LinkedQueue::Enqueue(int val) 
{
    Node* newNode = new Node(val);

    if (isEmpty()) {
        front = rear = newNode;
    }
    else 
    {
        rear->next = newNode;
        rear = newNode;
    }
    cout << "Enqueue value: " << val << endl;
}


int LinkedQueue::Dequeue() 
{
    if (isEmpty())
    {
        cout << "is empty!!" << endl;
        return -1;
    }

    Node* temp = front;
    int val = temp->val;
    front = front->next;

    if (front == nullptr) 
    {
        rear = nullptr;
    }

    delete temp;
    cout << "Dequeu value: " << val << endl;
    return val;
}


int LinkedQueue::getFront() 
{
    if (isEmpty()) 
    {
        cout << "Queue is empty." << endl;
        return -1;
    }
    return front->val;
}


void LinkedQueue::Display() 
{
    if (isEmpty()) 
    {
        cout << "IS EMPTY!!!" << endl;
        return;
    }

    Node* current = front;
    cout << "Display: ";
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() 
{
    LinkedQueue queue;

    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);
    queue.Display();

    return 0;
}
