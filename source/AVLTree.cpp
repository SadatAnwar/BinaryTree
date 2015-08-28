//
// Created by Syed Sadat Anwar on 27/08/15.
//

#include <stdlib.h>
#include "../headder/AVLTree.h"


/*
 * The insert function is similar to the insert in a Binary Tree only here we check for balancing
 */
Node *AVLTree::insert(Node *parent, Node *childNode) {
    parent->updateHeight();
    if (parent->getValue() < childNode->getValue()) {
        // if the new value is greater than the value of current node
        if (parent->getChildren()[1] == nullptr) {
            //if there exists no child0 create a new node and add it as child 0
            parent->addChild(childNode, 1);
            return parent;
        } else {
            //insert new node into child1 and update the height of the parent
            parent->addChild(insert(parent->getChildren()[1], childNode), 1);
            int rightChild = parent->getChildren()[1]->getHeight();
            int leftChild = 0;
            if (parent->getChildren()[0] != nullptr) {
                leftChild = parent->getChildren()[0]->getHeight();
            }
            int childHeightDiff = abs(leftChild - rightChild);
            if (childHeightDiff > 1) {
                if (leftChild > rightChild) {
                    // Rotate Right-Right
                    // We first check if we do a rotate right-right or a rotate right-left
                    if (childNode->getValue() < parent->getChildren()[0]->getValue()) {
                        // This is a rotate right-right case
                        parent = rotateRight(parent);
                    } else {
                        parent = rotateLeftRight(parent);
                    }
                } else {
                    if (childNode->getValue() > parent->getChildren()[1]->getValue()) {
                        // This is a rotate right-right case
                        parent = rotateLeft(parent);
                    } else {
                        parent = rotateRightLeft(parent);
                    }
                }
            }
        }
    } else {
        if (parent->getChildren()[0] == nullptr) {
            parent->addChild(childNode, 0);
            return parent;
        } else {
            parent->addChild(insert(parent->getChildren()[0], childNode), 0);
            int leftChild = parent->getChildren()[0]->getHeight();
            int rightChild = 0;
            if (parent->getChildren()[1] != nullptr) {
                rightChild = parent->getChildren()[1]->getHeight();
            }
            int childHeightDiff = abs(leftChild - rightChild);
            if (childHeightDiff > 1) {
                if (leftChild > rightChild) {
                    // Rotate Right-Right
                    // We first check if we do a rotate right-right or a rotate right-left
                    if (childNode->getValue() < parent->getChildren()[0]->getValue()) {
                        // This is a rotate right-right case
                        parent = rotateRight(parent);
                    } else {
                        parent = rotateLeftRight(parent);
                    }
                } else {
                    if (childNode->getValue() > parent->getChildren()[1]->getValue()) {
                        // This is a rotate right-right case
                        parent = rotateLeft(parent);
                    } else {
                        parent = rotateRightLeft(parent);
                    }
                }
            }

        }
    }
    return parent;
}

/*
 * public insert function
 */
void AVLTree::insert(int value) {
    if (root == nullptr) {
        root = new Node(value, CHILD_NODES);
    } else {
        Node *newChild = new Node(value, CHILD_NODES);
        root = insert(root, newChild);
    }
}


/*
 * Thins function performs a rotate right for pNode
 * assuming our tree looks like this:
 *
 *              X                                L1
 *            /   \                            /    \
 *           L1    R1  Rotate Right          L2      X
 *          /  \       ------------>        /  \   /   \
 *         L2   A                          L4  L5 A    R1
 *        /  \
 *       L4   L5
 *
 */
Node * AVLTree::rotateRight(Node *pNode) {
    Node *l1 = pNode->getChildren()[0];
    Node *a = l1->getChildren()[1];
    Node *x1 = new Node(pNode->getValue(), CHILD_NODES);
    Node *r1 = pNode->getChildren()[1];
    if (a != nullptr) {
        x1->addChild(a, 0);
    }
    if (r1 != nullptr) {
        x1->addChild(r1, 1);
    }
    l1->addChild(x1, 1);
    return l1;
}


/*
 * Rotate the element Left
 *   z                                y
 *  /  \                            /   \
 * T1   y     Left Rotate(z)       z      x
 *     /  \   - - - - - - - ->    / \    / \
 *    T2   x                     T1  T2 T3  T4
 *        / \
 *      T3  T4
 *
 */
Node *AVLTree::rotateLeft(Node *pNode) {
    Node *y = pNode->getChildren()[1];
    Node *t2 = y->getChildren()[0];
    Node *z1 = new Node(pNode->getValue(), CHILD_NODES);
    Node *t1 = pNode->getChildren()[0];
    if (t1 != nullptr) {
        z1->addChild(t1, 0);
    }
    if (t2 != nullptr) {
        z1->addChild(t2, 1);
    }
    y->addChild(z1, 0);
    return y;


}

/*
 * Perform a rotate Left and then a rotate right
 *      z                               z                           x
 *     / \                            /   \                        /  \
 *    y   T4  Left Rotate (y)        x    T4  Right Rotate(z)    y      z
 *   / \      - - - - - - - - ->    /  \      - - - - - - - ->  / \    / \
 * T1   x                          y    T3                    T1  T2 T3  T4
 *     / \                        / \
 *   T2   T3                    T1   T2
 */
Node *AVLTree::rotateLeftRight(Node *pNode) {
    Node *y = pNode->getChildren()[0];
    pNode->addChild(y, 0);
    return rotateRight(pNode);
}


/*
 * Rotate Right left
 *    z                            z                            x
 *   / \                          / \                          /  \
 * T1   y   Right Rotate (y)    T1   x      Left Rotate(z)   z      y
 *     / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
 *    x   T4                      T2   y                  T1  T2  T3  T4
 *   / \                              /  \
 * T2   T3                           T3   T4
 */
Node *AVLTree::rotateRightLeft(Node *pNode) {
    Node *y = pNode->getChildren()[1];
    pNode->addChild(y, 1);
    return rotateLeft(pNode);
}