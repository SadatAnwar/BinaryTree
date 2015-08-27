//
// Created by Syed Sadat Anwar on 24/08/2015.
//

#ifndef BINARYTREE_NODE_H
#define BINARYTREE_NODE_H


#include <vector>

class Node {
public:
    Node(int children);

    Node(int key, int children);
    int getValue();
    int getHeight();

    Node **getChildren();

    void addChild(Node *child, int pos);
    void rotateRight();

private:
    int key;
    Node **children;
public:
    void setHeight(int height) {
        Node::height = height;
    }

private:
    int height = 0;
    int leftHeight = 0;
    int rightHeight = 0;

    void setChildrenSize(int size);
};


#endif //BINARYTREE_NODE_H
