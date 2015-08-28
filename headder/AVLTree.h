//
// Created by Syed Sadat Anwar on 27/08/15.
//

#ifndef BINARYTREE_AVLTREE_H
#define BINARYTREE_AVLTREE_H

#include "BinaryTree.h"

/*
 * An AVL tree is a special type of a Binary Tree, it has a self balancing property, you can find out more here
 * https://en.wikipedia.org/wiki/AVL_tree
 * In an AVL Tree when an element is inserted, the tree also checks if the element after insertion does not violate
 * the balancing property, and if this is violated, the tree does a self balancing by performing one of the operations
 *
 * 1. Rotate Left Left
 * 2. Rotate Left Right
 * 3. Rotate Right Right
 * 4. Rotate Right Left
 *
 */
class AVLTree : public BinaryTree {
private:
    Node * insert(Node *parent, Node *child);

public:
    void insert(int key);

    Node * rotateRight(Node *pNode);

    Node *rotateRightLeft(Node *pNode);

    Node *rotateLeftRight(Node *pNode);

    Node *rotateLeft(Node *pNode);
};


#endif //BINARYTREE_AVLTREE_H
