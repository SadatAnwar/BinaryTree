//
// Created by Syed Sadat Anwar on 24/08/2015.
//

#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H


#include "Node.h"
#include "Tree.h"

#define CHILD_NODES 2

class BinaryTree : public Tree {
public:
    BinaryTree();
    ~BinaryTree();

    void insert(int value);
    void print();
    Node* search(int key);
    int getDepth ();

private:
    Node* root;

    void insert(Node *node, int value);
    void print(Node *node);
};


#endif //BINARYTREE_TREE_H
