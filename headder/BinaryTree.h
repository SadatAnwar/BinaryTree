//
// Created by Syed Sadat Anwar on 24/08/2015.
//

#ifndef BINARYTREE_TREE_H
#define BINARYTREE_TREE_H


#include "Node.h"

#define CHILD_NODES 2

class BinaryTree {
public:
    BinaryTree();

    ~BinaryTree();

    void insert(Node *node, int value);

    void insert(int value);
    void print();
    Node* search(int key);
    int getDepth ();

private:
    Node* root;

    void print(Node *node);
};


#endif //BINARYTREE_TREE_H
