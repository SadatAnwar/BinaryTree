//
// Created by Syed Sadat Anwar on 24/08/2015.
//

#include <iostream>
#include "../headder/BinaryTree.h"


BinaryTree::BinaryTree() {
    root = nullptr;

}

/*
 * The insert method is to insert a new node into the binary tree
 *  it checks if the value of the node is greater than the top node,
 *  if the value is greater, it inserts it at Node::children[0] and
 *  if not, it inserts it at children[1]
 *
 */
void BinaryTree::insert(Node *node, int value) {
    if (node->getValue() < value) {
        // if the new value is greater than the value of current node
        if (node->getChildren()[1] == nullptr) {
            //if there exists no child0 create a new node and add it as child 0
            node->addChild(new Node(value, CHILD_NODES), 1);
            return;
        } else {
            //insert new node into child0
            insert(node->getChildren()[1], value);
        }
    } else {
        if (node->getChildren()[0] == nullptr) {
            node->addChild(new Node(value, CHILD_NODES), 0);
            return;
        } else {
            insert(node->getChildren()[0], value);
        }
    }

}

void BinaryTree::insert(int value) {
    if (root == nullptr) {
        this->root = new Node(value, CHILD_NODES);
    } else {
        insert(root, value);
    }
}

void BinaryTree::print() {
    if (root != nullptr) {
        print(root);
    }
}

void BinaryTree::print(Node *node) {
    if (node->getChildren()[0] != nullptr) {
        print(node->getChildren()[0]);
    }
    std::cout << node->getValue() << std::endl;
    if (node->getChildren()[1] != nullptr) {
        print(node->getChildren()[1]);
    }
}

BinaryTree::~BinaryTree() {
    this->root->~Node();

}

Node *BinaryTree::search(int key) {
    //TODO
    Node *node = nullptr;
    if (node == nullptr) {
        std::cout << "NOT FOUND" << std::endl;
        return nullptr;
    }
    else {
        std::cout << "FOUND" << std::endl;
        std::cout << "Height of Node " << node->getHeight() << std::endl;
        return node;
    }
}

int BinaryTree::getDepth() {
    return this->root->getHeight();
}
