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


int Node::getValue() {
    return this->key;
}


int Node::getHeight() {
    if(this->leftHeight>this->rightHeight){
        return this->leftHeight;
    } else{
        return this->rightHeight;
    }
}

/*
 * THe rotate function is supposed to rotate the child nodes,
 * so for the rotate right:
 *  If there exists a left child,
 */
void Node::rotateRight() {

}

Node **Node::getChildren() {
    return children;
}

/*
 * Insert a child at a specific position in the list of children
 */
void Node::addChild(Node *child, int pos) {
    children[pos] = child;

}
