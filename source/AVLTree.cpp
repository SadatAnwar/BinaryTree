//
// Created by Syed Sadat Anwar on 27/08/15.
//

#include <stdlib.h>
#include <iostream>
#include "../headder/AVLTree.h"


/*
 * The insert function is similar to the insert in a Binary Tree only here we check for balancing
 */
void AVLTree::insert(Node *parent, Node *childNode) {
    if (parent->getValue() < childNode->getValue()) {
        // if the new value is greater than the value of current node
        if (parent->getChildren()[1] == nullptr) {
            //if there exists no child0 create a new node and add it as child 0
            parent->addChild(childNode, 1);
            return;
        } else {
            //insert new node into child1 and update the height of the parent
            insert(parent->getChildren()[1], childNode);
            int rightChild = parent->getChildren()[1]->getHeight();
            int leftChild = 0;
            if (parent->getChildren()[0] != nullptr) {
                leftChild = parent->getChildren()[0]->getHeight();
            }
            int childHeightDiff = abs(leftChild - rightChild);
            if (childHeightDiff > 1) {
                std::cout << parent->getValue() << " Rotate Children" << std::endl;
            }
            if (parent->getHeight() < rightChild + 1) {
                //if the children's height is equal/greater to the parent's height
                // set the parents height to one greater than that of child
                parent->setHeight(rightChild + 1);
            }

        }
    } else {
        if (parent->getChildren()[0] == nullptr) {
            parent->addChild(childNode, 0);
            return;
        } else {
            insert(parent->getChildren()[0], childNode);
            int leftChild = parent->getChildren()[0]->getHeight();
            int rightChild = 0;
            if (parent->getChildren()[1] != nullptr) {
                rightChild = parent->getChildren()[1]->getHeight();
            }
            int childHeightDiff = abs(leftChild - rightChild);

            if (childHeightDiff > 1) {
                std::cout << parent->getValue() << "Rotate Children" << std::endl;
                if (leftChild > rightChild) {
                    // Rotate Right-Right
                    // We first check if we do a rotate right-right or a rotate right-left
                    if (childNode->getValue() < parent->getChildren()[0]->getValue()) {
                        // This is a rotate right-right case
                        parent = rotateRight(parent);
                    }
                }
            }
            if (parent->getHeight() < leftChild + 1) {
                //if the children's height is equal/greater to the parent's height
                // set the parents height to one greater than that of child
                parent->setHeight(leftChild + 1);
            }
        }
    }

}

/*
 * public insert function
 */
void AVLTree::insert(int value) {
    if (root == nullptr) {
        root = new Node(value, CHILD_NODES);
    } else {
        Node *newChild = new Node(value, CHILD_NODES);
        insert(root, newChild);
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
        x1->addChild(r1, 0);
    }
    l1->addChild(x1, 1);
    return l1;
}
