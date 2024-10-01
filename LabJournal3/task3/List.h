#pragma once
#include "Node.h"

class List
{
public:
    node* head;
    node* tail; // Added tail pointer for efficient operations

    List();
    ~List();

    /*
    @brief : Prints all the elements in the list in order
    @param : None
    */
    void print();

    /*
    @brief : Inserts a new integer value into the list in ascending order
    @param val : The integer value to be inserted into the list
    */
    void insert(int);

    /*
    @brief : Checks if the list is empty
    @param : None
    @return : true if the list is empty, false otherwise
    */
    bool isempty();

    /*
    @brief : Concatenates two linked lists and returns the head of the new list.
    @param : head1 - The head of the first linked list
    @param : head2 - The head of the second linked list
    @return : The head of the concatenated linked list
    */
    static node* concatenate(node* head1, node* head2);

    /*
    @brief : Finds the intersection of two linked lists and returns the head of the new list.
    @param : head1 - The head of the first linked list
    @param : head2 - The head of the second linked list
    @return : The head of the linked list containing common elements
    */
    static node* findIntersection(node* head1, node* head2);

    /*
    @brief : Compares two linked lists representing strings.
    @param : head1 - The head of the first linked list
    @param : head2 - The head of the second linked list
    @return : 0 if both strings are the same, 1 if first string is greater, -1 if second string is greater
    */
    static int compareStrings(node* head1, node* head2);
};
