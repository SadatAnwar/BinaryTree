//
// Created by Syed Sadat Anwar on 24/08/2015.
//

#include <iostream>
#include "../headder/Node.h"

Node::Node(int key) {
    this->key = key;
    this->leftChild = nullptr;
    this->rightChild = nullptr;

}

void Node::addChild(Node *child) {
    if (child->getValue() > this->key) {
        this->rightHeight++;
        if (this->rightChild != nullptr) {
            this->rightChild->addChild(child);
        }
        else {
            this->rightChild = child;
        }
    } else {
        this->leftHeight ++;
        if (this->leftChild != nullptr) {
            this->leftChild->addChild(child);
        } else {
            this->leftChild = child;
        }
    }
}

int Node::getValue() {
    return this->key;
}

void Node::print() {
    if (this->leftChild != nullptr) {
        this->leftChild->print();
    }
    std::cout << this->key << std::endl;
    if (this->rightChild != nullptr) {
        this->rightChild->print();
    }

}

Node::~Node() {
    if (this->leftChild != nullptr) {
        this->leftChild->~Node();
    }
    if (this->rightChild != nullptr) {
        this->rightChild->~Node();
    }
    free(this);
}

Node *Node::search(int value) {
    if(this->key == value){
        return this;
    } else{
        if(this->key < value){
            if(this->rightChild!= nullptr){
                return this->rightChild->search(value);
            }
        }
        else {
            if (this->leftChild != nullptr){
                return this->leftChild->search(value);
            }
        }
    }
    return nullptr;
}

int Node::getHeight() {
    if(this->leftHeight>this->rightHeight){
        return this->leftHeight;
    } else{
        return this->rightHeight;
    }
}

void Node::rotateRight() {


}
