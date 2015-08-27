//
// Created by Syed Sadat Anwar on 24/08/2015.
//

#include "../headder/Node.h"

Node::Node(int size) {
    children = new Node *[size];
    //set all child nodes to null pointer
    for (int i = 0; i < size; i++) {
        children[i] = nullptr;
    }
}

void Node::setChildrenSize(int size) {
    children = new Node *[size];

    for (int i = 0; i < size; i++) {
        children[i] = nullptr;
    }
}

Node::Node(int value, int children) {
    setChildrenSize(children);
    key = value;
}

/*
 * Insert a child at a specific position in the list of children
 */
void Node::addChild(Node *child, int pos) {
    int newHeight = child->getHeight() + 1;
    if (height < newHeight) {
        height = newHeight;
    }
    children[pos] = child;
}
