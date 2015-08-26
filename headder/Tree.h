//
// Created by Syed Sadat Anwar on 26/08/2015.
//

#ifndef BINARYTREE_TREE_H
#define BINARYTREE_TREE_H


#include "Node.h"

class Tree {
    Node *root = nullptr;
public:
    virtual void insert(int key) = 0;

    virtual Node *search(int key) = 0;

    virtual void print() = 0;
};


#endif //BINARYTREE_TREE_H
