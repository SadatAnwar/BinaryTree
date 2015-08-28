#include <iostream>
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
    avlTree->insert(8);
    avlTree->insert(7);
    avlTree->insert(6);
    avlTree->insert(5);
    avlTree->insert(4);
    avlTree->printIncreasing();
    avlTree->printDecreasing();
    return 0;

}