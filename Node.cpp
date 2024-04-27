//
// Created by issa on 21/04/24.
//

#include "Node.h"

Node::Node() : v{-1} {}

Node::Node(int val) : v{val >= -1 ? val : -1} {}

void Node::value(int val) { v = val; }

int Node::value() const {
    return v;
}
int Node::connectionsCount() {
    return c;
}
void Node::addConnection() {
    ++c;
}
void Node::removeConnection() {
    --c;
}




