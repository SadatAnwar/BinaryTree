#include <iostream>
#include "../headder/BinaryTree.h"

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
    binaryTree->printDecreasing();

    printf("Total time taken: %.5fs\n", (double)(clock() - insertStart)/CLOCKS_PER_SEC);
    return 0;

}