#include "node.h"

node::node(int data) {
	this->data = data;
	next = NULL;
}

node::node() {

	data = 0;
	next = NULL;

}