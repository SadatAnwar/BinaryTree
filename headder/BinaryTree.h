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

    void insert(Node *value);

    void printIncreasing();
    Node* search(int key);
    int getDepth ();

private:
    Node* root;

    void insert(Node *parent, Node *childNode);
    void print(Node *node);

    Node *search(Node *pNode, int i);
};


#endif //BINARYTREE_TREE_H
