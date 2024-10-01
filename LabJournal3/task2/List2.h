#pragma once
#include "Node.h"
using namespace std;

class List
{
public:
	node* head;

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
};

