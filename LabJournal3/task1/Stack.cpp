// i have set the file name to "stack"
#include "List.h"

List::List()
{
    head = NULL;
}

List::~List()
{
    // destructor logic if needed
}

bool List::isempty()
{
    return head == nullptr;
}

void List::push(int val)
{
    node* newnode = new node; // new node " newnode "
    newnode->data = val; // value to the newnode
    newnode->next = head; // newnode points to head
    head = newnode; // head points to newnode ( indicates its first node )
}

int List::pop()
{
    node* temp = head;

    if (isempty())
    {
        cout << "N/A" << endl;
    }
    else
    {
        int x = head->data;
        head = head->next; // head is now equal to the next of head
        delete temp; // since temp is equal to head, we delete it freeing up the space
        return x;
    }

   
}

int List::peek()
{
    if (head == nullptr)
    {
        cout << "N/A";
    }
    else
    {
        return head->data;
    }
}

int List::size()
{
    node* temp = head;
    int count = 0;

    while (temp != nullptr)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

int main()
{
    List l;

    l.push(1); // push 1
    l.push(2); // push 2 on top of 1
    l.push(3); // push 3 on top of 2

    cout << "Peek : " << l.peek() << endl; // 3 2 1
    cout << "Size : " <<  l.size() << endl; // the size
    cout << "Pop  : " << l.pop() << endl; // pops '3', the top of stack

    cout << "Peek : " << l.peek() << endl; // since '3' was popped it should print 2

    return 0;
}


