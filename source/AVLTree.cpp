//
// Created by Syed Sadat Anwar on 27/08/15.
//

#include <stdlib.h>
#include <iostream>
#include "../headder/AVLTree.h"

/*
 * Default constructor, here we take all reference from the parent and give it to the child
 */
AVLTree::AVLTree() {

}


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
            int childHeight1 = parent->getChildren()[1]->getHeight();
            int childHeight0 = 0;
            if (parent->getChildren()[0] != nullptr) {
                childHeight0 = parent->getChildren()[0]->getHeight();
            }
            int childHeightDiff = abs(childHeight0 - childHeight1);
            if (childHeightDiff > 1) {
                std::cout << parent->getValue() << "Rotate Children" << std::endl;
            }
            if (parent->getHeight() < childHeight1 + 1) {
                //if the children's height is equal/greater to the parent's height
                // set the parents height to one greater than that of child
                parent->setHeight(childHeight1 + 1);
            }

        }
    } else {
        if (parent->getChildren()[0] == nullptr) {
            parent->addChild(childNode, 0);
            return;
        } else {
            insert(parent->getChildren()[0], childNode);
            int childHeight0 = parent->getChildren()[0]->getHeight();
            int childHeight1 = 0;
            if (parent->getChildren()[1] != nullptr) {
                childHeight1 = parent->getChildren()[1]->getHeight();
            }
            int childHeightDiff = abs(childHeight0 - childHeight1);
            if (childHeightDiff > 1) {
                std::cout << parent->getValue() << " Rotate Children" << std::endl;
            }
            if (parent->getHeight() < childHeight0 + 1) {
                //if the children's height is equal/greater to the parent's height
                // set the parents height to one greater than that of child
                parent->setHeight(childHeight0 + 1);
            }
        }
    }

}

void AVLTree::insert(int value) {
    if (root == nullptr) {
        root = new Node(value, CHILD_NODES);
    } else {
        Node *newChild = new Node(value, CHILD_NODES);
        insert(root, newChild);
    }
}

