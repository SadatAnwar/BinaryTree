//
// Created by Syed Sadat Anwar on 24/08/2015.
//

#ifndef BINARYTREE_TREE_H
#define BINARYTREE_TREE_H


#include "Node.h"

class Tree {
public:
    Tree();
    ~Tree() ;
    void insert(Node* node);
    void insert(int key);
    void print();
    Node* search(int key);
    int getDepth ();

private:
    Node* root;

};


#endif //BINARYTREE_TREE_H
