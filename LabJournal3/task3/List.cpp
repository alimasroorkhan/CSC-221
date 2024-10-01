#include "List.h"
#include <iostream>
using namespace std;

List::List() {
    head = nullptr;
    tail = nullptr; // Initialize tail
}

List::~List() {
}

bool List::isempty() {
    return head == nullptr;
}

void List::insert(int val) {
    node* newnode = new node;
    newnode->data = val;
    newnode->next = nullptr;

    if (isempty() || head->data >= val) {
        newnode->next = head;
        head = newnode;
    }
    else {
        node* temp = head;
        while (temp->next != nullptr && temp->next->data < val) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

    if (tail == nullptr || tail->data <= val) {
        tail = newnode; // Update tail if new node is the largest
    }
}

void List::print() {
    node* temp = head;
    if (isempty()) {
        cout << "list is empty" << endl;
    }
    else {
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
        cout << endl;
    }
}

node* List::concatenate(node* head1, node* head2) {
    if (head1 == nullptr) {
        return head2; // If the first list is empty, return the second list
    }

    if (head2 == nullptr) {
        return head1; // If the second list is empty, return the first list
    }

    node* temp = head1;

    // Traverse to the end of the first list and link to the second list
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = head2;

    return head1;
}

node* List::findIntersection(node* head1, node* head2) {
    node* dummy = new node(); // Dummy node for building the result list
    node* tail = dummy;

    node* temp1 = head1;
    node* temp2 = head2;

    while (temp1 && temp2) {
        if (temp1->data == temp2->data) {
            tail->next = new node();
            tail->next->data = temp1->data; // Add common character
            tail = tail->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->data < temp2->data) {
            temp1 = temp1->next;
        }
        else {
            temp2 = temp2->next;
        }
    }

    return dummy->next; // Return the head of the intersection list
}

int List::compareStrings(node* head1, node* head2) {
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data < head2->data) {
            return -1; // First string is lexicographically smaller
        }
        if (head1->data > head2->data) {
            return 1; // First string is lexicographically greater
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    // If both strings have the same characters but one is longer
    if (head1 != nullptr) return 1; // First string is longer
    if (head2 != nullptr) return -1; // Second string is longer

    return 0; // Both strings are the same
}

// Main function for testing
int main() {
    List l1, l2;
    l1.insert(1);
    l1.insert(4);
    l1.insert(3);
    l1.insert(2);

    l2.insert(2);
    l2.insert(3);
    l2.insert(5);

    // Testing concatenation
    node* concatenatedList = List::concatenate(l1.head, l2.head);
    cout << "Concatenated List:" << endl;
    l1.head = concatenatedList; // Update l1's head to the concatenated list
    l1.print();

    // Testing intersection
    node* intersectionList = List::findIntersection(l1.head, l2.head);
    cout << "Intersection List:" << endl;
    l1.head = intersectionList; // Update l1's head to the intersection list
    l1.print();

    // Testing string comparison
    int result = List::compareStrings(l1.head, l2.head);
    if (result == 0) {
        cout << "Strings are the same" << endl;
    }
    else if (result == 1) {
        cout << "First string is greater" << endl;
    }
    else {
        cout << "Second string is greater" << endl;
    }

    return 0;
}
