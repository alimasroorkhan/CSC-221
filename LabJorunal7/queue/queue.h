#pragma once

#include <iostream>
using namespace std;

class queue
{
    int size;       
    int* arr;      
    int front = 0; 
    int tail = -1; 

public:
    /**
     * @brief Constructor to initialize the queue with a given size.
     * @param x The maximum size of the queue.
     */
    queue(int x);

    /**
     * @brief Destructor to free the dynamically allocated memory.
     */
    ~queue();

    /**
     * @brief Adds an element to the end of the queue.
     * @param val The value to be added to the queue.
     */
    void Enqueue(int val);

    /**
     * @brief Removes and returns the element from the front of the queue.
     * @return The value at the front of the queue, or -1 if the queue is empty.
     */
    int Dequeue();

    /**
     * @brief Checks if the queue is empty.
     * @return True if the queue is empty, false otherwise.
     */
    bool Empty();

    /**
     * @brief Checks if the queue is full.
     * @return True if the queue is full, false otherwise.
     */
    bool Full();

    /**
     * @brief Gets the element at the front of the queue without removing it.
     * @return The value at the front of the queue, or -1 if the queue is empty.
     */
    int getFront();
};
