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
 *  if the value is greater, it inserts it at Node::children[1] and
 *  if not, it inserts it at children[0]
 *
 */
void BinaryTree::insert(Node *parent, Node *childNode) {
    if (parent->getValue() < childNode->getValue()) {
        // if the new value is greater than the value of current node
        if (parent->getChildren()[1] == nullptr) {
            //if there exists no child0 create a new node and add it as child 0
            parent->addChild(childNode, 1);
            return;
        } else {
            //insert new node into child1 and update the height of the parent
            insert(parent->getChildren()[1], childNode);
            int childHeight = parent->getChildren()[1]->getHeight();
            if (parent->getHeight() < childHeight + 1) {
                //if the children's height is equal/greater to the parent's height
                // set the parents height to one greater than that of child
                parent->setHeight(childHeight + 1);
            }
        }
    } else {
        if (parent->getChildren()[0] == nullptr) {
            parent->addChild(childNode, 0);
            return;
        } else {
            insert(parent->getChildren()[0], childNode);
            int childHeight = parent->getChildren()[0]->getHeight();
            if (parent->getHeight() < childHeight + 1) {
                //if the children's height is equal/greater to the parent's height
                // set the parents height to one greater than that of child
                parent->setHeight(childHeight + 1);
            }
        }
    }

}

void BinaryTree::insert(int value) {
    if (root == nullptr) {
        this->root = new Node(value, CHILD_NODES);
    } else {
        Node *newChild = new Node(value, CHILD_NODES);
        insert(root, newChild);
    }
}

void BinaryTree::insert(Node *newNode) {
    if (root == nullptr) {
        this->root = newNode;
    } else {
        insert(root, newNode);
    }
}

/*
 * Print the tree in increasing order
 */
void BinaryTree::printIncreasing() {
    if (root != nullptr) {
        printInc(root);
    }
}

/*
 * Private function to help with the printing
 */
void BinaryTree::printInc(Node *node) {
    if (node->getChildren()[0] != nullptr) {
        printInc(node->getChildren()[0]);
    }
    std::cout << node->getValue() << std::endl;
    if (node->getChildren()[1] != nullptr) {
        printInc(node->getChildren()[1]);
    }
}


/*
 * print the tree in Decreasing order
 */
void BinaryTree::printDecreasing() {
    if (root != nullptr) {
        printDec(root);
    }
}

/*
 * Private function to assist in the printing
 */
void BinaryTree::printDec(Node *node) {
    if (node->getChildren()[1] != nullptr) {
        printDec(node->getChildren()[1]);
    }
    std::cout << node->getValue() << std::endl;
    if (node->getChildren()[0] != nullptr) {
        printDec(node->getChildren()[0]);
    }
}

BinaryTree::~BinaryTree() {
    this->root->~Node();

}

/*
 * Search for a node of value key inside the tree
 */
Node *BinaryTree::search(int key) {
    if (root == nullptr) {
        std::cout << "EMPTY TREE" << std::endl;
        return nullptr;
    }
    else {
        search(root, key);
    }
}

/*
 * Search for a node that has value equal to key and is a child of pNode
 */
Node *BinaryTree::search(Node *pNode, int key) {
    if (pNode->getValue() == key) {
        std::cout << key << " FOUND" << std::endl;
        std::cout << "Height of Node " << pNode->getHeight() << std::endl;
        return pNode;
    }
    else {
        if (pNode->getValue() < key) {
            if (pNode->getChildren()[1] != nullptr) {
                search(pNode->getChildren()[1], key);
            } else {
                std::cout << key << " NOT FOUND" << std::endl;
            }
        } else {
            if (pNode->getChildren()[0] != nullptr) {
                search(pNode->getChildren()[0], key);
            } else {
                std::cout << key << " NOT FOUND" << std::endl;
            }
        }
    }
    return nullptr;
}


int BinaryTree::getDepth() {
    return this->root->getHeight();
}

