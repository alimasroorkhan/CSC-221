#pragma once
#include "Node.h";
using namespace std;

class List
{
public:
	node* head;

	List();
	~List();

	/*
	@breif : checks if head == nullptr
	@premp : it ensures whether there is a node already present or not
	*/
	bool isempty();

	/* 
	@breif : this function assigns data of type int to the 
	new node, the node is inserted into the "first" location
	of the list.
	@premp : 
	*/
	void push(int);

	/*
	@breif : this function deletes the value on top 
	of the stack, deletes the first node.
	@premp :
	*/
	int pop();

	/*
	@breif : this function prints the first node, the top
	of the stack.
	@premp :
	*/
	int peek();

	/*
	@breif : this function uses a counter that is incremented
	using a while loop, the count value is then returned.
	@premp :
	*/
	int size();
	
};

