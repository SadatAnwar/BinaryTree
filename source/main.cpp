#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "../headder/BinaryTree.h"
#include "../headder/AVLTree.h"

using namespace std;

int main() {
    srand((unsigned int) time(NULL));
    BinaryTree *binaryTree = new BinaryTree();
    clock_t insertStart = clock();
    for (int i = 0; i<200; i++){
        int number = rand() % 80 +1;
        binaryTree->insert(number);
    }
    printf("Time taken for insert: %.5fs\n", (double) (clock() - insertStart) / CLOCKS_PER_SEC);
    binaryTree->search(78);
    //binaryTree->printDecreasing();

    printf("Total time taken: %.5fs\n", (double)(clock() - insertStart)/CLOCKS_PER_SEC);

    AVLTree *avlTree = new AVLTree();
    avlTree->insert(1);
    avlTree->insert(2);
    avlTree->insert(3);
    avlTree->insert(4);
    avlTree->search(3);
    avlTree->printIncreasing();

    return 0;

}