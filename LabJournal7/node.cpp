#include "node.h"

Node::Node()
{
    val = 0;
    next = nullptr;
}

Node::Node(int x)
{
    val = x;
    next = nullptr;
}


Node::~Node()
{
}
