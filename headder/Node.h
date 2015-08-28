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

    int getValue() {
        return key;
    };

    int getHeight() {
        return height;
    };

    void updateHeight();


    Node **getChildren() {
        return children;
    };

    void addChild(Node *child, int pos);

    void setHeight(int height) {
        Node::height = height;
    }


private:
    int key;

    Node **children;

    int height = 0;

    int numChildren = 0;

    void setChildrenSize(int size);
};


#endif //BINARYTREE_NODE_H
