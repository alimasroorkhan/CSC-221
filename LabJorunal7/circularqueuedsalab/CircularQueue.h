#pragma once

#include <iostream>
using namespace std;


class CircularQueue
{
    int* arr;       
    int size;       
    int front;      
    int tail;      

public:
    /**
     * @brief Constructor to initialize the circular queue with a given size.
     * @param capacity The maximum capacity of the queue.
     */
    CircularQueue(int capacity);

    /**
     * @brief Destructor to free dynamically allocated memory.
     */
    ~CircularQueue();

    /**
     * @brief Adds an element to the queue.
     * @param val The value to be added.
     * @return True if the operation was successful, false if the queue is full.
     */
    bool Enqueue(int val);

    /**
     * @brief Removes and returns the front element from the queue.
     * @return The front element, or -1 if the queue is empty.
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
     * @brief Gets the front element without removing it.
     * @return The front element, or -1 if the queue is empty.
     */
    int getFront();
};
