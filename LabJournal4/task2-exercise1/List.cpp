#include "list.h"

list::list()
{
	head = new node;
	head->data = 0; // Dummy head node
	head->next = nullptr;
}

list::~list()
{
	while (!emptyList()) {
		delete_begin(); // Clean up all nodes
	}
	delete head; // Delete the dummy head
}

bool list::emptyList()
{
	return head->next == nullptr; // Check if the list is empty
}

void list::insert_begin(int value)
{
	node* newnode = new node;
	newnode->data = value;
	newnode->next = head->next; // Set new node's next to current first node
	head->next = newnode; // Update head to new node
}

void list::insert_end(int value)
{
	node* newnode = new node;
	newnode->data = value;
	newnode->next = nullptr;

	if (emptyList()) {
		head->next = newnode; // If list is empty, set head's next to new node
	}
	else {
		node* temp = head->next; // Start from the first real node
		while (temp->next != nullptr) {
			temp = temp->next; // Traverse to the end
		}
		temp->next = newnode; // Link the new node at the end
	}
}

void list::insert_after(int oldV, int newV)
{
	node* temp = head->next; // Start from the first real node

	while (temp != nullptr && temp->data != oldV) {
		temp = temp->next; // Find the node with oldV
	}

	if (temp != nullptr) {
		node* nodex = new node();
		nodex->data = newV;
		nodex->next = temp->next;
		temp->next = nodex; // Insert after found node
	}
	else {
		std::cout << "Value " << oldV << " not found in the list." << std::endl;
	}
}

void list::delete_Node(int value) 
{
	if (emptyList()) return;

	node* temp = head->next; // Start from the first real node
	node* prev = head; // Keep track of the previous node (head)

	while (temp != nullptr && temp->data != value) {
		prev = temp; // Update previous
		temp = temp->next; // Move to next
	}

	if (temp != nullptr) { // Value found
		prev->next = temp->next; // Unlink the node to delete
		delete temp; // Free memory
	}
}

void list::delete_begin()
{
	if (emptyList()) {
		std::cout << "List is empty" << std::endl;
		return;
	}

	node* toDelete = head->next; // Get the current first node
	head->next = toDelete->next; // Move head's next to the next node
	delete toDelete; // Delete the old first node
}

void list::delete_end()
{
	if (emptyList()) {
		std::cout << "List is empty" << std::endl;
		return;
	}

	if (head->next->next == nullptr) { // If there's only one node
		delete head->next; // Delete the only node
		head->next = nullptr; // Reset head's next
		return;
	}

	node* temp = head->next; // Start from the first real node
	while (temp->next->next != nullptr) {
		temp = temp->next; // Traverse to the second last node
	}

	delete temp->next; // Delete the last node
	temp->next = nullptr; // Unlink the last node
}

void list::traverse()
{
	if (emptyList())
	{
		std::cout << "Empty list: nothing to display" << std::endl;
		return;
	}

	node* temp = head->next; // Start from the first real node
	while (temp != nullptr) {
		std::cout << "Value: " << temp->data << " ";
		temp = temp->next; // Move to the next node
	}
}

int main()
{
	list y;

	y.insert_begin(5);
	y.insert_begin(4);
	y.insert_begin(3);
	y.insert_begin(2);
	y.insert_begin(1);
	y.traverse();

	cout << endl;

	y.insert_after(2, 10); 
	y.traverse();

	cout << endl;
	y.delete_end();
	y.traverse();

	return 0;
}
