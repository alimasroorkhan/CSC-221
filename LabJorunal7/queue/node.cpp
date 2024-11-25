#include "node.h"

node::node()
{
	val = 0;
	next = nullptr;
}

node::node(int x)
{
	val = x;
	next = nullptr;
}

node::~node()
{

}

