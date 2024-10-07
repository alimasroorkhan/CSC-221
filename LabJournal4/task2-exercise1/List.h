#pragma once
#include "node.h"

class list
{
private:
	node* head;

public:
	/*
		@brief: Constructs an empty list.
	*/
	list();

	/*
		@brief: Destructor that frees the memory allocated for the list.
	*/
	~list();

	/*
		@brief: Checks if the list is empty.
		@return: Returns true if the list is empty, false otherwise.
	*/
	bool emptyList();

	/*
		@brief: Inserts a new node with value ‘newV’ after the node with value ‘oldV’ in the list.
		@params: oldV is the value to be searched for.
		@params: newV is the data to be added.
	*/
	void insert_after(int oldV, int newV);

	/*
		@brief: Inserts a new node with the given value at the beginning of the list.
		@params: value is the data to be added at the beginning.
	*/
	void insert_begin(int value);

	/*
		@brief: Inserts a new node with the given value at the end of the list.
		@params: value is the data to be added at the end.
	*/
	void insert_end(int value);

	/*
		@brief: Deletes the first node in the list that has the value ‘val’.
		@params: val is the value of the node to be deleted.
	*/
	void delete_Node(int val);

	/*
		@brief: Deletes the first node at the beginning of the list.
	*/
	void delete_begin();

	/*
		@brief: Deletes the last node at the end of the list.
	*/
	void delete_end();

	/*
		@brief: Traverses the list and prints the values of the nodes.
	*/
	void traverse();
};
