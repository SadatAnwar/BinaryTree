//
// Created by Syed Sadat Anwar on 24/08/2015.
//

#include <iostream>
#include "../headder/Tree.h"

Tree::Tree() {
    root = nullptr;

}

void Tree::insert(Node *node) {

    if(root == nullptr){
        this->root = node;
    } else {
        this->root->addChild(node);
    }

}

void Tree::insert(int node) {
    Node *child = new Node (node);
    this->insert(child);
}

void Tree::print() {
    root->print();

}

Tree::~Tree() {
    this->root->~Node();

}

Node *Tree::search(int key) {
    Node *node = this->root->search(key);
    if(node == nullptr){
        std::cout << "NOT FOUND" << std::endl;
    }
    else {
        std::cout << "FOUND" << std::endl;
        std::cout << "Height of Node " << node->getHeight() << std::endl;
    }
}

int Tree::getDepth() {
    return this->root->getHeight();
}
