#include "List.h"
using namespace std;

List::List() {
    head = nullptr;
}

List::~List() {
}

bool List::isempty()
{
    return head == nullptr;
}

void List::insert(int val) {
    node* newnode = new node;
    newnode->data = val;
    newnode->next = nullptr;

    if (isempty() || head->data >= val) 
    /* If the list is empty, the new node becomes the head.
    If the new node's value is smaller than the head's value, it replaces the head. */
    {
        newnode->next = head;
        head = newnode;
    }
    else 
    {
        node* temp = head;
        while (temp->next != nullptr && temp->next->data < val)
        {
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void List::print() 
{
    node* temp = head;
    if (isempty()) 
    {
        cout << "list is empty" << endl;
    }
    else 
    {
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{
    List l;
    l.insert(1);
    l.insert(4);
    l.insert(3);
    l.insert(2);

    l.print();

    return 0;
}
