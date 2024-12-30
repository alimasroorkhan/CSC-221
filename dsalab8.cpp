#include <iostream>
#include "node.h"

using namespace std;

// Function to compute the Ackermann function recursively
int ackermann(int m, int n) 
{
    if (m == 0) 
    {
        return n + 1; // Base case for Ackermann
    }
    else if (m > 0 && n == 0)
    {
        return ackermann(m - 1, 1); // Recursive call when n = 0
    }
    else if (m > 0 && n > 0) 
    {
        return ackermann(m - 1, ackermann(m, n - 1)); // Nested recursive call
    }
    else 
    {
        cerr << "Invalid inputs provided for Ackermann function." << endl;
        return -1; // Error case
    }
}

// Function to calculate the sum of elements in an array using recursion
int calculateSum(int arr[], int size) 
{
    return (size == 0) ? 0 : arr[0] + calculateSum(arr + 1, size - 1);
}

// Function to reverse a singly linked list recursively
node* reverseList(node* head) 
{
    if (!head || !head->next) 
    {
        return head; // Base case: list is empty or has one element
    }
    node* newHead = reverseList(head->next); // Reverse the rest of the list
    head->next->next = head; // Make the next node point back to the current node
    head->next = nullptr; // Remove the original forward link
    return newHead;
}

// Main function to test the exercises
int main() {
    // Exercise 1: Testing the Ackermann function
    cout << "!!!Testing Ackermann Function!!!" << endl;
    int ackResult = ackermann(2, 2);
    if (ackResult != -1) {
        cout << "Ackermann(2, 2) = " << ackResult << endl;
    }

    // Exercise 2: Computing the sum of an array recursively
    int numbers[] = { 1, 2, 3, 4 };
    int totalSum = calculateSum(numbers, 4);
    cout << "\n!!!Sum of Array using Recursion!!!" << endl;
    cout << "Sum of array elements = " << totalSum << endl;

    // Exercise 3: Reversing a linked list and displaying the result
    node* n1 = new node(1);
    node* n2 = new node(2);
    node* n3 = new node(3);
    node* n4 = new node(4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    cout << "\!!!Reversing a Linked List!!!" << endl;
    cout << "Original List: ";
    node* temp = n1;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    node* reversedHead = reverseList(n1);

    cout << "Reversed List: ";
    temp = reversedHead;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // cleaning up the dynamically allocated memory
    while (reversedHead)
    {
        node* nextNode = reversedHead->next;
        delete reversedHead;
        reversedHead = nextNode;
    }

    return 0;
}
