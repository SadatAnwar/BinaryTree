//
// Created by Syed Sadat Anwar on 24/08/2015.
//

#ifndef BINARYTREE_NODE_H
#define BINARYTREE_NODE_H


#include <zconf.h>

class Node {
public:
    Node(int key);
    ~Node();
    void addChild(Node* child);
    int getValue();
    void print();
    Node* search(int value);
    int getHeight();
    void rotateRight();

private:
    int key;
    Node *leftChild;
    Node *rightChild;
    int leftHeight = 0;
    int rightHeight = 0;
};


#endif //BINARYTREE_NODE_H
